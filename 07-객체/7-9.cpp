#include <iostream>
using namespace std;

struct Point {		// 화면상의 점을 표현하는 클래스 (모든 멤버를 공용(public)으로 사용할 수 있도록 struct로)
	int x, y;		// 점의 x, y 좌표 값
	Point(int xx = 0, int yy = 0) : x(xx), y(yy) { }	// 멤버 초기화 리스트를 사용한 생성자 함수
};

Point readPoint() {
	Point p;
	cout << " 좌표를 입력해주세요(x,y): ";
	cin >> p.x >> p.y;
	return p;
}
void PrintPoint(Point p, const char* str = "Point") {
	cout << str << "= (" << p.x << "," << p.y << ")\n";
}
void main() {
	Point a;
	a = readPoint();
	PrintPoint(a, " 입력 좌표 ");
}