#include <cstdio>
class Point {
	int x, y;
public:
	Point(int x = 0, int y = 0) {
		this->x = x;				// �º��� this->x �� ������� x�� �ǹ�, �캯�� x�� �Ű����� x�� �ǹ�
		this->y = y;
	}
	void print(const char* msg = " P=") {
		printf("%s(%d,%d)\n", msg, this->x, this->y);
	}
	void whereAmI() {
		printf(" �ּ�=%x\n", this);
	}
};
void main() {
	Point p(1, 2), q(3, 4);
	p.print();
	p.whereAmI();
	q.print(" Q=");
	q.whereAmI();
}
//this = ��ü �ڽ��� �޸𸮻��� �ּҸ� ��Ÿ���� ������