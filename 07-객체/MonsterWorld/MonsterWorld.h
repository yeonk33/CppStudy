#pragma once
#include "Canvas.h"
#include "Monster.h"
#include <Windows.h>
#define DIM 40
#define MAXMONS 20

class MonsterWorld {
	int map[DIM][DIM];
	int xMax, yMax, nMon, nMove;
	Monster mon[MAXMONS];
	Canvas canvas;
	int& Map(int x, int y) { return map[y][x]; }
	bool isDone() { return countItems() == 0; }	// 맵에 남은 아이템 == 0 이면 종료
	int countItems() {							// 남아있는 아이템의 수
		int nItems = 0;
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				if (Map(x, y) > 0) nItems++;
		return nItems;
	}
	void print() {	//
		canvas.clear();		// 캔버스 지움
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				if (Map(x, y) > 0) canvas.draw(x, y, "■");
		for (int i = 0; i < nMon; i++)
			mon[i].draw(canvas);
		canvas.print("[ Moster World (Basic) ]");

		cerr << " 전체 이동 횟수 = " << nMove << endl;
		cerr << " 남은 아이템 수 = " << countItems() << endl;
		for (int i = 0; i < nMon; i++)
			mon[i].print();
	}
public:
	MonsterWorld(int w, int h) : canvas(w, h), xMax(w), yMax(h) {	// 생성자
		nMon = 0;
		nMove = 0;
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++) Map(x, y) = 1;
	}
	~MonsterWorld() { }
	void add(Monster m) {	// 몬스터 추가
		if (nMon < MAXMONS) mon[nMon++] = m;
	}
	void play(int maxwalk, int wait) {	// 최대 이동 횟수와 지연시간을 매개변수로, 엔터 입력시 몬스터 이동, 출력, 종료조건 검사
		print();
		cerr << " 엔터를 누르세요...";
		getchar();
		for (int i = 0; i < maxwalk; i++) {
			for (int k = 0; k < nMon; k++)
				mon[k].move(map, xMax, yMax);
			nMove++;
			print();
			if (isDone()) break;
			Sleep(wait);
		}
	}
};