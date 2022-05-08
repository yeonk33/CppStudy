#pragma once
#include "Monster.h"
#include <conio.h>
enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };

class Human : public Monster {
public:
	Human(string n = "�ΰ�", string i = "��", int px = 0, int py = 0)
		: Monster(n, i, px, py) {}
	~Human() { cout << " Human "; }
	int getDirKey() { return _getche() == 224 ? _getche() : 0; }	// �Էµ� Ű�� ȭ��ǥ�̸� ȭ��ǥ Ű �� ��ȯ
	void move(int** map, int maxx, int maxy, char ch) {		
		//ch = getDirKey();
		//cout << "move����" << endl;
		if (ch == Left) x--;		// Ű���� ���⿡ ���� �̵�
		else if (ch == Right) x++;
		else if (ch == Up) y--;		// ���� y��ǥ�� �� ���� 0�̾
		else if (ch == Down) y++;
		else return;
		clip(maxx, maxy);
		eat(map);	
	}
};

class Tuman : public Human {
public:
	Tuman(string n = "�����ΰ�", string i = "��", int px = 0, int py = 0)
		: Human(n, i, px, py) {}
	~Tuman() { cout << " Tuman "; }
	void moveHuman(int** map, int maxx, int maxy, char ch) {
		//char ch = getDirKey();
		if (ch == 'a') x--;		// Ű���� ���⿡ ���� �̵�
		else if (ch == 'd') x++;
		else if (ch == 'w') y--;		// ���� y��ǥ�� �� ���� 0�̾
		else if (ch == 's') y++;	
		else if (ch == Left) x--;		// Ű���� ���⿡ ���� �̵�
		else if (ch == Right) x++;
		else if (ch == Up) y--;		// ���� y��ǥ�� �� ���� 0�̾
		else if (ch == Down) y++;
		else return;
		clip(maxx, maxy);
		eat(map);
	}
};