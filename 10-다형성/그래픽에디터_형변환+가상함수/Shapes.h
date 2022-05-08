#pragma once
#include "Canvas.h"

class Point {
public:
	int x, y;
	Point(int xx = 0, int yy = 0) : x(xx), y(yy) {}	// ������
	void move(int dx, int dy) { x += dx; y += dy; }
};
class Shape {
protected:
	Point p;
public:
	Shape(int x = 0, int y = 0) : p(x, y) {}
	virtual ~Shape() { cout << "Shape �Ҹ���\n"; }	// �θ��� Shape���Ը� virtual ���̸� ��
	virtual void draw(Canvas& canvas, string color = "��") {		// draw�� �����Լ��� ����
		canvas.draw(p.x, p.y, color);
	}
	void move(int dx, int dy) { p.move(dx, dy); }	// ���ϴ°���
};

//���а� ���õ� Ŭ������
inline int Abs(int x) { return x > 0 ? x : -x; }		// ����
inline int Max(int x, int y) { return x > y ? x : y; }	// �ִ밪 ã��
inline int Round(double x) { return (int)(x + 0.5); }	// �ݿø�
class Line : public Shape {		// ������ �ΰ��� �� �ʿ�
	Point q;		// ������ �ٸ� �� ���� (���� ������ p)
public:
	Line(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0) 
		: Shape(x1, y1), q(x2, y2) { }
	~Line() { cout << "Line �Ҹ���\n"; }
	void draw(Canvas& canvas, string color = "��") {		// DDA(Digital Differential Analyzer) �˰���
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

class HLine : public Line {		// ���� ���� ����, Line�� ���
public:
	HLine(int x = 0, int y = 0, int len = 0) :Line(x, y, x + len, y) {}
	~HLine() { cout << "HLine �Ҹ���\n"; }
};
class VLine : public Line {		// ���� ���� ����, Line�� ���
public:
	VLine(int x = 0, int y = 0, int len = 0) :Line(x, y, x, y + len) {}
	~VLine() { cout << "VLine �Ҹ���\n"; }
};

class Rect : public Shape {
	int w, h;		// �簢�� ����, ���� ����
public:
	Rect(int x = 0, int y = 0, int ww = 0, int hh = 0) 
		: Shape(x, y), w(ww), h(hh) { }
	~Rect() { cout << "Rect �Ҹ���\n"; }
	void draw(Canvas& canvas, string color = "��") {
		for (int i = p.x; i <= p.x + w; i++) {
			canvas.draw(i, p.y, color);		// �簢�� ����
			canvas.draw(i, p.y + h, color);	// �簢�� �Ʒ���
		}
		for (int i = p.y; i <= p.y + h; i++) {
			canvas.draw(p.x, i, color);		// �簢�� ���ʺ�
			canvas.draw(p.x + w, i, color);	// �簢�� �����ʺ�
		}
	}
};
class Square : public Rect {	// ���簢��, ���̴� �� ���� �־����� ��
public:
	Square(int x = 0, int y = 0, int w = 0) : Rect(x, y, w, w) {  }
	~Square() { cout << "Square �Ҹ���\n"; }
};

class Circle : public Shape {
	int r;
public:
	Circle(int x = 0, int y = 0, int rr = 0)	// �� �߽ɰ� ������ �ʱ�ȭ
		:Shape(x, y), r(rr) { }
	~Circle() { cout << "Circle �Ҹ���\n"; }
	void draw(Canvas& canvas, string color = "��") {			// �� �߽ɿ��� ��������ŭ �����¿� ���� �׸��� ������ ��ü
		Line(p.x, p.y, p.x, p.y + r).draw(canvas, color);
		Line(p.x, p.y, p.x, p.y - r).draw(canvas, color);
		Line(p.x, p.y, p.x + r, p.y).draw(canvas, color);
		Line(p.x, p.y, p.x - r, p.y).draw(canvas, color);
	}
};