#pragma once
#include <iostream>
#include <string>
#define MAXLINES 100
using namespace std;

class Canvas {
	string line[MAXLINES];	// 화면 출력을 위한 문자열
	int xMax, yMax;			// 맵의 크기
public:
	Canvas(int nx=10, int ny=10) : xMax(nx), yMax(ny) {		// 생성자
		for (int y = 0; y < yMax; y++)
			line[y] = string(xMax * 2, ' ');	// 각 라인을 ' '로 초기화, xMax*2 인 이유는? ■(특수문자)의 크기 = 2
	}
	void draw(int x, int y, string val) {
		if (x >= 0 && y >= 0 && x < xMax && y < yMax)
			line[y].replace(x * 2, 2, val);	// (x,y)위치에 val을 복사, 캔버스의 모든 화소는 2byte로 저장됨
	}
	void clear(string val = ". ") {			// 지정하지 않으면 점과 공백으로 채움
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				draw(x, y, val);
	}
	void print(const char* title = "<My Canvas>") {
		system("cls");
		cout << title << endl;
		for (int y = 0; y < yMax; y++)
			cout << line[y] << endl;
		cout << endl;
	}
};
