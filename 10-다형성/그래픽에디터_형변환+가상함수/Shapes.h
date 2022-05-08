#pragma once
#include "Canvas.h"

class Point {
public:
	int x, y;
	Point(int xx = 0, int yy = 0) : x(xx), y(yy) {}	// 생성자
	void move(int dx, int dy) { x += dx; y += dy; }
};
class Shape {
protected:
	Point p;
public:
	Shape(int x = 0, int y = 0) : p(x, y) {}
	virtual ~Shape() { cout << "Shape 소멸자\n"; }	// 부모인 Shape에게만 virtual 붙이면 됨
	virtual void draw(Canvas& canvas, string color = "★") {		// draw를 가상함수로 수정
		canvas.draw(p.x, p.y, color);
	}
	void move(int dx, int dy) { p.move(dx, dy); }	// 왜하는거지
};

//선분과 관련된 클래스들
inline int Abs(int x) { return x > 0 ? x : -x; }		// 절댓값
inline int Max(int x, int y) { return x > y ? x : y; }	// 최대값 찾기
inline int Round(double x) { return (int)(x + 0.5); }	// 반올림
class Line : public Shape {		// 선분은 두개의 점 필요
	Point q;		// 선분의 다른 쪽 끝점 (한쪽 끝점은 p)
public:
	Line(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0) 
		: Shape(x1, y1), q(x2, y2) { }
	~Line() { cout << "Line 소멸자\n"; }
	void draw(Canvas& canvas, string color = "선") {		// DDA(Digital Differential Analyzer) 알고리즘
		int len = Max(Abs(p.x - q.x), Abs(p.y - q.y));	// 
		double x = p.x; double y = p.y;
		double dx = (q.x - p.x) / (double)len, dy = (q.y - p.y) / (double)len;
		for (int i = 0; i <= len; i++) {
			canvas.draw(Round(x), Round(y), color);
			x += dx;
			y += dy;
		}		
	}
	void move(int dx, int dy) { p.move(dx, dy); q.move(dx, dy); }
};

class HLine : public Line {		// 가로 방향 선분, Line을 상속
public:
	HLine(int x = 0, int y = 0, int len = 0) :Line(x, y, x + len, y) {}
	~HLine() { cout << "HLine 소멸자\n"; }
};
class VLine : public Line {		// 세로 방향 선분, Line을 상속
public:
	VLine(int x = 0, int y = 0, int len = 0) :Line(x, y, x, y + len) {}
	~VLine() { cout << "VLine 소멸자\n"; }
};

class Rect : public Shape {
	int w, h;		// 사각형 가로, 세로 길이
public:
	Rect(int x = 0, int y = 0, int ww = 0, int hh = 0) 
		: Shape(x, y), w(ww), h(hh) { }
	~Rect() { cout << "Rect 소멸자\n"; }
	void draw(Canvas& canvas, string color = "■") {
		for (int i = p.x; i <= p.x + w; i++) {
			canvas.draw(i, p.y, color);		// 사각형 윗변
			canvas.draw(i, p.y + h, color);	// 사각형 아랫변
		}
		for (int i = p.y; i <= p.y + h; i++) {
			canvas.draw(p.x, i, color);		// 사각형 왼쪽변
			canvas.draw(p.x + w, i, color);	// 사각형 오른쪽변
		}
	}
};
class Square : public Rect {	// 정사각형, 길이는 한 변만 주어지면 됨
public:
	Square(int x = 0, int y = 0, int w = 0) : Rect(x, y, w, w) {  }
	~Square() { cout << "Square 소멸자\n"; }
};

class Circle : public Shape {
	int r;
public:
	Circle(int x = 0, int y = 0, int rr = 0)	// 원 중심과 반지름 초기화
		:Shape(x, y), r(rr) { }
	~Circle() { cout << "Circle 소멸자\n"; }
	void draw(Canvas& canvas, string color = "◎") {			// 원 중심에서 반지름만큼 상하좌우 직선 그리는 것으로 대체
		Line(p.x, p.y, p.x, p.y + r).draw(canvas, color);
		Line(p.x, p.y, p.x, p.y - r).draw(canvas, color);
		Line(p.x, p.y, p.x + r, p.y).draw(canvas, color);
		Line(p.x, p.y, p.x - r, p.y).draw(canvas, color);
	}
};