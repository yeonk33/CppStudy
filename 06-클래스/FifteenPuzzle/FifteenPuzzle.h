#pragma once
#include "Ranking.h"
#include <windows.h>	// Sleep()�Լ�
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#define DIM 4		// 4x4 ����
enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };
const int DirKey[4] = { Left, Right, Up, Down };
class FifteenPuzzle
{
	int map[DIM][DIM];	// �����
	int x, y;			// �� ĭ�� ��ġ
	int nMove;			// �̵� Ƚ��
	clock_t tStart;		// ���� �ð�

	void init() {
		for (int i = 0; i < DIM * DIM - 1; i++)
			map[i / DIM][i % DIM] = i + 1;		// ���� ä���ֱ� [  1  2  3  4 ]
		map[DIM - 1][DIM - 1] = 0;				//				[  5  6  7  8 ]
		x = DIM - 1; y = DIM - 1;				//				[  9 10 11 12 ]
												//				[ 13 14 15 () ] () = ��ĭ, ���� x y��ġ
		srand(time(NULL));	// ����
		tStart = clock();	// ���� �ð�
		nMove = 0;			// �̵� Ƚ�� �ʱ�ȭ
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
		printf("\n\t�̵� Ƚ��: %6d\n\t�ҿ� �ð�: %6.1f\n\n", nMove, d);
	}

	bool move(int dir) {
		if (dir == Right && x > 0) {			// �� ���� ������ �˻�
			map[y][x] = map[y][x - 1];
			map[y][--x] = 0;
		}
		else if (dir == Left && x < DIM - 1) {	// �� ������ ������ �˻�
			map[y][x] = map[y][x + 1];
			map[y][++x] = 0;
		}
		else if (dir == Up && y < DIM - 1) {	// �� �Ʒ� ������ �˻�
			map[y][x] = map[y + 1][x];
			map[++y][x] = 0;
		}
		else if (dir == Down && y > 0) {		// �� �������� �˻�
			map[y][x] = map[y - 1][x];
			map[--y][x] = 0;
		}
		else return false;	// �̵� ���н� false

		nMove++;
		return true;		// �̵� ������ �̵� Ƚ�� �����ϰ� true
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
		//���� ���� ��
		RankingBoard board;
		board.load(filename);	// ���� �����ϸ� ��ŷ ����
		init();
		display();
		board.print();			// ���� ��ŷ ���

		//��������
		printf("\n ������ �����ּ���(����).. ");
		_getche();
		shuffle(100);
		printf("\n ������ ���۵˴ϴ�...");
		_getche();

		nMove = 0;
		tStart = clock();
		while (!isDone()) {
			move(getDirKey());
			display();
		}
		clock_t t1 = clock();
		double d = (double)(t1 - tStart) / CLOCKS_PER_SEC;

		//���� ���� ��
		board.add(nMove, d);	// ��ŷ�� ���� ��� �߰�
		board.store(filename);	// ���� ��ŷ�� ���Ͽ� ����
	}
};
