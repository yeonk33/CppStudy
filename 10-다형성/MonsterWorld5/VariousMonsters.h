#pragma once
#include "Monster.h"

class Zombie : public Monster {
public:
	Zombie(string n = "허접좀비", string i = "§", int x = 0, int y = 0)
		: Monster(n, i, x, y) { }
	~Zombie() { cout << "Zombie"; }
};

class Vampire : public Monster {
public:
	Vampire(string n = "뱀파이어", string i = "★", int x = 0, int y = 0)
		: Monster(n, i, x, y) { }
	~Vampire() { cout << "Vampire"; }

	void move(int** map, int maxx, int maxy) {
		int dir = rand() % 4;	// 뱀파이어는 상하좌우 4방향으로만 움직임
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
	KGhost(string n = "처녀귀신", string i = "♥", int x = 0, int y = 0)
		: Monster(n, i, x, y) { }
	~KGhost() { cout << "KGhost"; }

	void move(int** map, int maxx, int maxy) {
		x = rand() % maxx;	// 처녀귀신은 맵 어디로든 순간이동 가능
		y = rand() % maxy;
		clip(maxx, maxy);
		eat(map);
	}
};

class Jiangshi : public Monster {
	bool bHori;	// true = 좌우로 이동, false = 위아래로 이동
public:
	Jiangshi(string n = "대륙강시", string i = "↔", int x = 0, int y = 0, bool bH = true)
		: Monster(n, i, x, y), bHori(bH) { }
	~Jiangshi() { cout << "Jiangshi"; }

	void move(int** map, int maxx, int maxy) {
		int dir = rand() % 2;	// 강시는 좌우 혹은 위아래로만 움직임
		int jump = rand() % 2 + 1;	// 강시는 한번에 최대 2칸까지 이동가능
		if (bHori) x += ((dir == 0) ? -jump : jump);	// dir=0 : 왼쪽, dir=1 : 오른쪽
		else y+= ((dir == 0) ? -jump : jump);			// dir=0 : 아래, dir=1 : 위
		clip(maxx, maxy);
		eat(map);
	}
};
