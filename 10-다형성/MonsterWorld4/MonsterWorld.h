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
	Monster* pMon[MAXMONS];	// ���͵� �������� �Ұ��̹Ƿ� ������
	Canvas canvas;
	int& Map(int x, int y) { return world.elem(x, y); }
	bool isDone() { return countItems() == 0; }	// �ʿ� ���� ������ == 0 �̸� ����
	int countItems() {							// �����ִ� �������� ��
		int nItems = 0;
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				if (Map(x, y) > 0) nItems++;
		return nItems;
	}
	void print() {	//
		canvas.clear(". ");		// ĵ���� ����
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				if (Map(x, y) > 0) canvas.draw(x, y, "��");
		for (int i = 0; i < nMon; i++)
			pMon[i]->draw(canvas);
		canvas.print("[ Moster World (Dynamic World) ]");

		cerr << " ��ü �̵� Ƚ�� = " << nMove << endl;
		cerr << " ���� ������ �� = " << countItems() << endl;
		for (int i = 0; i < nMon; i++)
			pMon[i]->print();
	}
public:
	MonsterWorld(int w, int h) : world(h, w), xMax(w), yMax(h) {	// ������
		nMon = 0;
		nMove = 0;
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++) Map(x, y) = 1;
	}
	~MonsterWorld() {
		for (int i = 0; i < nMon; i++)
			delete pMon[i];				// �������� �����Ǿ��� ���͵��� �����ؾ���
	}
	void add(Monster* m) {	// ���� �߰�
		if (nMon < MAXMONS) pMon[nMon++] = m;
	}
	void play(int maxwalk, int wait) {	// �ִ� �̵� Ƚ���� �����ð��� �Ű�������, ���� �Է½� ���� �̵�, ���, �������� �˻�
		print();
		cerr << " ���͸� ��������...";
		getchar();
		for (int i = 0; i < maxwalk; i++) {
			for (int k = 0; k < nMon; k++)
				pMon[k]->move(world.Data(), xMax, yMax);	// pMon[k]�� �ڷ����� Monster*�̾ �θ��� Monster�� move()�� ����
			/*((Zombie*)pMon[0])->move(world.Data(), xMax, yMax);	// ���� ����ȯ, �� ������ �̵� ��Ĵ�� move��
			((Vampire*)pMon[1])->move(world.Data(), xMax, yMax);	// move�� �����Լ��� �����Ͽ��� ���� �ݺ������� �� ������ move ȣ�� ����
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