#pragma once
#include <iostream>
#include <string>
#define MAXLINES 100
using namespace std;

class Canvas {
	string line[MAXLINES];	// ȭ�� ����� ���� ���ڿ�
	int xMax, yMax;			// ���� ũ��
public:
	Canvas(int nx=10, int ny=10) : xMax(nx), yMax(ny) {		// ������
		for (int y = 0; y < yMax; y++)
			line[y] = string(xMax * 2, ' ');	// �� ������ ' '�� �ʱ�ȭ, xMax*2 �� ������? ��(Ư������)�� ũ�� = 2
	}
	void draw(int x, int y, string val) {
		if (x >= 0 && y >= 0 && x < xMax && y < yMax)
			line[y].replace(x * 2, 2, val);	// (x,y)��ġ�� val�� ����, ĵ������ ��� ȭ�Ҵ� 2byte�� �����
	}
	void clear(string val = ". ") {			// �������� ������ ���� �������� ä��
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
