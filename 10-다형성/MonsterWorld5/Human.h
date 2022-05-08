#pragma once
#include "Monster.h"
#include <conio.h>
enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };

class Human : public Monster {
public:
	Human(string n = "�ΰ�", string i = "��", int px = 0, int py = 0)
		: Monster(n, i, px, py) {}
	~Human() { cout << " [Human ]"; }
	int getDirKey() { return _getche() == 224 ? _getche() : 0; }	// �Էµ� Ű�� ȭ��ǥ�̸� ȭ��ǥ Ű �� ��ȯ
	void move(int** map, int maxx, int maxy) {
		if (_kbhit()) {	// Ű���� �Է� ����
			char ch = getDirKey();
			if (ch == Left) x--;		// Ű���� ���⿡ ���� �̵�
			else if (ch == Right) x++;
			else if (ch == Up) y--;		// ���� y��ǥ�� �� ���� 0�̾
			else if (ch == Down) y++;
			else return;
			clip(maxx, maxy);
			eat(map);
		}
	}
};