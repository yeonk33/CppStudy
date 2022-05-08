#pragma once
#include "Monster.h"

class Zombie : public Monster {
public:
	Zombie(string n = "��������", string i = "��", int x = 0, int y = 0)
		: Monster(n, i, x, y) { }
	~Zombie() { cout << "Zombie"; }
};

class Vampire : public Monster {
public:
	Vampire(string n = "�����̾�", string i = "��", int x = 0, int y = 0)
		: Monster(n, i, x, y) { }
	~Vampire() { cout << "Vampire"; }

	void move(int** map, int maxx, int maxy) {
		int dir = rand() % 4;	// �����̾�� �����¿� 4�������θ� ������
		if (dir == 0) x--;
		else if (dir == 1)x++;
		else if (dir == 2) y--;
		else y++;
		clip(maxx, maxy);
		eat(map);
	}
};

class KGhost : public Monster {
public:
	KGhost(string n = "ó��ͽ�", string i = "��", int x = 0, int y = 0)
		: Monster(n, i, x, y) { }
	~KGhost() { cout << "KGhost"; }

	void move(int** map, int maxx, int maxy) {
		x = rand() % maxx;	// ó��ͽ��� �� ���ε� �����̵� ����
		y = rand() % maxy;
		clip(maxx, maxy);
		eat(map);
	}
};

class Jiangshi : public Monster {
	bool bHori;	// true = �¿�� �̵�, false = ���Ʒ��� �̵�
public:
	Jiangshi(string n = "�������", string i = "��", int x = 0, int y = 0, bool bH = true)
		: Monster(n, i, x, y), bHori(bH) { }
	~Jiangshi() { cout << "Jiangshi"; }

	void move(int** map, int maxx, int maxy) {
		int dir = rand() % 2;	// ���ô� �¿� Ȥ�� ���Ʒ��θ� ������
		int jump = rand() % 2 + 1;	// ���ô� �ѹ��� �ִ� 2ĭ���� �̵�����
		if (bHori) x += ((dir == 0) ? -jump : jump);	// dir=0 : ����, dir=1 : ������
		else y+= ((dir == 0) ? -jump : jump);			// dir=0 : �Ʒ�, dir=1 : ��
		clip(maxx, maxy);
		eat(map);
	}
};
