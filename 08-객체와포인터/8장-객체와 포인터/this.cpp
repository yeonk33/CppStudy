#include <cstdio>
class Point {
	int x, y;
public:
	Point(int x = 0, int y = 0) {
		this->x = x;				// 좌변의 this->x 는 멤버변수 x를 의미, 우변의 x는 매개변수 x를 의미
		this->y = y;
	}
	void print(const char* msg = " P=") {
		printf("%s(%d,%d)\n", msg, this->x, this->y);
	}
	void whereAmI() {
		printf(" 주소=%x\n", this);
	}
};
void main() {
	Point p(1, 2), q(3, 4);
	p.print();
	p.whereAmI();
	q.print(" Q=");
	q.whereAmI();
}
//this = 객체 자신의 메모리상의 주소를 나타내는 포인터