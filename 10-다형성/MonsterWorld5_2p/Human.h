#pragma once
#include "Monster.h"
#include <conio.h>
enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };

class Human : public Monster {
public:
	Human(string n = "인간", string i = "♧", int px = 0, int py = 0)
		: Monster(n, i, px, py) {}
	~Human() { cout << " Human "; }
	int getDirKey() { return _getche() == 224 ? _getche() : 0; }	// 입력된 키가 화살표이면 화살표 키 값 반환
	void move(int** map, int maxx, int maxy, char ch) {		
		//ch = getDirKey();
		//cout << "move실행" << endl;
		if (ch == Left) x--;		// 키보드 방향에 따라 이동
		else if (ch == Right) x++;
		else if (ch == Up) y--;		// 맵의 y좌표가 맨 위가 0이어서
		else if (ch == Down) y++;
		else return;
		clip(maxx, maxy);
		eat(map);	
	}
};

class Tuman : public Human {
public:
	Tuman(string n = "왼쪽인간", string i = "♣", int px = 0, int py = 0)
		: Human(n, i, px, py) {}
	~Tuman() { cout << " Tuman "; }
	void moveHuman(int** map, int maxx, int maxy, char ch) {
		//char ch = getDirKey();
		if (ch == 'a') x--;		// 키보드 방향에 따라 이동
		else if (ch == 'd') x++;
		else if (ch == 'w') y--;		// 맵의 y좌표가 맨 위가 0이어서
		else if (ch == 's') y++;	
		else if (ch == Left) x--;		// 키보드 방향에 따라 이동
		else if (ch == Right) x++;
		else if (ch == Up) y--;		// 맵의 y좌표가 맨 위가 0이어서
		else if (ch == Down) y++;
		else return;
		clip(maxx, maxy);
		eat(map);
	}
};