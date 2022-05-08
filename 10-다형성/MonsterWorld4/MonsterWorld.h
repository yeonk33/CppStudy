#pragma once
#include "Canvas.h"
#include "Monster.h"
#include <Windows.h>
#include "Matrix.h"
#include "VariousMonsters.h"
#define MAXMONS 8

class MonsterWorld {
	Matrix world;
	//int map[DIM][DIM];
	int xMax, yMax, nMon, nMove;
	//Monster mon[MAXMONS];
	Monster* pMon[MAXMONS];	// 몬스터도 동적으로 할것이므로 포인터
	Canvas canvas;
	int& Map(int x, int y) { return world.elem(x, y); }
	bool isDone() { return countItems() == 0; }	// 맵에 남은 아이템 == 0 이면 종료
	int countItems() {							// 남아있는 아이템의 수
		int nItems = 0;
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				if (Map(x, y) > 0) nItems++;
		return nItems;
	}
	void print() {	//
		canvas.clear(". ");		// 캔버스 지움
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				if (Map(x, y) > 0) canvas.draw(x, y, "■");
		for (int i = 0; i < nMon; i++)
			pMon[i]->draw(canvas);
		canvas.print("[ Moster World (Dynamic World) ]");

		cerr << " 전체 이동 횟수 = " << nMove << endl;
		cerr << " 남은 아이템 수 = " << countItems() << endl;
		for (int i = 0; i < nMon; i++)
			pMon[i]->print();
	}
public:
	MonsterWorld(int w, int h) : world(h, w), xMax(w), yMax(h) {	// 생성자
		nMon = 0;
		nMove = 0;
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++) Map(x, y) = 1;
	}
	~MonsterWorld() {
		for (int i = 0; i < nMon; i++)
			delete pMon[i];				// 동적으로 생성되었던 몬스터들을 해제해야함
	}
	void add(Monster* m) {	// 몬스터 추가
		if (nMon < MAXMONS) pMon[nMon++] = m;
	}
	void play(int maxwalk, int wait) {	// 최대 이동 횟수와 지연시간을 매개변수로, 엔터 입력시 몬스터 이동, 출력, 종료조건 검사
		print();
		cerr << " 엔터를 누르세요...";
		getchar();
		for (int i = 0; i < maxwalk; i++) {
			for (int k = 0; k < nMon; k++)
				pMon[k]->move(world.Data(), xMax, yMax);	// pMon[k]의 자료형이 Monster*이어서 부모인 Monster의 move()를 실행
			/*((Zombie*)pMon[0])->move(world.Data(), xMax, yMax);	// 강제 형변환, 각 몬스터의 이동 방식대로 move함
			((Vampire*)pMon[1])->move(world.Data(), xMax, yMax);	// move를 가상함수로 구현하여서 이제 반복문으로 각 몬스터의 move 호출 가능
			((KGhost*)pMon[2])->move(world.Data(), xMax, yMax);
			((Jiangshi*)pMon[3])->move(world.Data(), xMax, yMax);
			((Jiangshi*)pMon[4])->move(world.Data(), xMax, yMax); */
			nMove++;
			print();
			if (isDone()) break;
			Sleep(wait);
		}
	}
};