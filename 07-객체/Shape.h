#pragma once
#include <iostream>
using namespace std;

struct Point {		// 화면상의 점을 표현하는 클래스 (모든 멤버를 공용(public)으로 사용할 수 있도록 struct로)
	int x, y;		// 점의 x, y 좌표 값
	Point(int xx = 0, int yy = 0) : x(xx), y(yy)
			{ cout << " 점(" << x << "," << y << ") 생성자\n"; }
	~Point() { cout << " 점(" << x << "," << y << ") 소멸자\n"; }
};

class Circle {
	Point center;	// 원 중심
	int radius;		// 원 반지름
public:
	Circle(int cx=0, int cy=0, int r=0) : center(cx, cy), radius(r)
	{ cout << " 원 (반지름 = " << radius << ") 생성자\n"; }
	~Circle() 
	{ cout << " 원 (반지름 = " << radius << ") 소멸자\n"; }
};