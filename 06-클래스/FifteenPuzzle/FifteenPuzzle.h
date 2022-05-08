#pragma once
#include "Ranking.h"
#include <windows.h>	// Sleep()함수
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#define DIM 4		// 4x4 퍼즐
enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };
const int DirKey[4] = { Left, Right, Up, Down };
class FifteenPuzzle
{
	int map[DIM][DIM];	// 퍼즐맵
	int x, y;			// 빈 칸의 위치
	int nMove;			// 이동 횟수
	clock_t tStart;		// 기준 시각

	void init() {
		for (int i = 0; i < DIM * DIM - 1; i++)
			map[i / DIM][i % DIM] = i + 1;		// 숫자 채워넣기 [  1  2  3  4 ]
		map[DIM - 1][DIM - 1] = 0;				//				[  5  6  7  8 ]
		x = DIM - 1; y = DIM - 1;				//				[  9 10 11 12 ]
												//				[ 13 14 15 () ] () = 빈칸, 현재 x y위치
		srand(time(NULL));	// 난수
		tStart = clock();	// 기준 시각
		nMove = 0;			// 이동 횟수 초기화
	}

	void display() {
		system("cls");
		printf("\tFifteen Puzzle\n\t");
		printf("--------------\n\t");
		for (int r = 0; r < DIM; r++) {
			for (int c = 0; c < DIM; c++) {
				if (map[r][c] > 0)
					printf("%3d", map[r][c]);
				else printf("   ");
			}
			printf("\n\t");
		}
		printf("--------------\n\t");
		clock_t t1 = clock();
		double d = (double)(t1 - tStart) / CLOCKS_PER_SEC;
		printf("\n\t이동 횟수: %6d\n\t소요 시간: %6.1f\n\n", nMove, d);
	}

	bool move(int dir) {
		if (dir == Right && x > 0) {			// 맨 왼쪽 열인지 검사
			map[y][x] = map[y][x - 1];
			map[y][--x] = 0;
		}
		else if (dir == Left && x < DIM - 1) {	// 맨 오른쪽 열인지 검사
			map[y][x] = map[y][x + 1];
			map[y][++x] = 0;
		}
		else if (dir == Up && y < DIM - 1) {	// 맨 아래 행인지 검사
			map[y][x] = map[y + 1][x];
			map[++y][x] = 0;
		}
		else if (dir == Down && y > 0) {		// 맨 윗행인지 검사
			map[y][x] = map[y - 1][x];
			map[--y][x] = 0;
		}
		else return false;	// 이동 실패시 false

		nMove++;
		return true;		// 이동 성공시 이동 횟수 증가하고 true
	}

	void shuffle(int nShuffle) {
		for (int i = 0; i < nShuffle; i++) {
			int key = DirKey[rand() % 4];
			if (move(key) == false) { i--; continue; }
			display();
			Sleep(50);
		}
	}

	bool isDone() {
		for (int r = 0; r < DIM; r++) {
			for (int c = 0; c < DIM; c++) {
				if (map[r][c] != r * DIM + c + 1)
					return (r == DIM - 1) && (c == DIM - 1);
			}
		}
		return true;
	}

	int getDirKey() { return _getch() == 224 ? _getche() : 0; }

public:
	void play(const char* filename) {
		//게임 시작 전
		RankingBoard board;
		board.load(filename);	// 게임 시작하면 랭킹 읽음
		init();
		display();
		board.print();			// 현재 랭킹 출력

		//게임진행
		printf("\n 퍼즐을 섞어주세요(엔터).. ");
		_getche();
		shuffle(100);
		printf("\n 게임이 시작됩니다...");
		_getche();

		nMove = 0;
		tStart = clock();
		while (!isDone()) {
			move(getDirKey());
			display();
		}
		clock_t t1 = clock();
		double d = (double)(t1 - tStart) / CLOCKS_PER_SEC;

		//게임 종료 후
		board.add(nMove, d);	// 랭킹에 게임 결과 추가
		board.store(filename);	// 현재 랭킹을 파일에 저장
	}
};
