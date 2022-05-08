#include <iostream>
using namespace std;

struct Point {		// 화면상의 점을 표현하는 클래스 (모든 멤버를 공용(public)으로 사용할 수 있도록 struct로)
	int x, y;		// 점의 x, y 좌표 값
	Point(int xx = 0, int yy = 0) : x(xx), y(yy){ }	// 멤버 초기화 리스트를 사용한 생성자 함수
	void print() { cout << "\t(" << x << "," << y << ")\n"; }
};

class Line {
	Point p1, p2;	// 선분 양 끝점
public:
	Line(int x1, int y1, int x2, int y2) : p1(x1, y1), p2(x2, y2){ } // 멤버 초기화 리스트를 사용한 생성자 함수
	void print() {
		cout << "Line:\n";
		p1.print();
		p2.print();
	}
};

//void main() {
//	Point p(1, 2);		// (1,2) 점
//	Line l(3, 4, 5, 6);	// 두 개의 점 (3,4) (5,6)를 양 끝점으로 하는 선분
//	p.print();
//	l.print();
//}