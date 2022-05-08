#include <cstdio>
class Point {
	int x, y;
	static int count;	// Point ��ü�� ����
public:
	static void printCount() { printf("PTCount=%d\n", count); }

	Point(int xx = 0, int yy = 0) : x(xx), y(yy) { count++; }
	~Point() { count--; }
	void print(const char* msg = " P=") {
		printf("%s(%d,%d)\n", msg, x, y);
	}
	void add(Point a, Point b) {
		x = a.x + b.x;
		y = a.y + b.y;
	}
	Point(const Point& p) : x(p.x), y(p.y) { count++; }	// ���� �����ڸ� ����������Ѵ�
};
int Point::count = 0;	// Point ��ü�� ����

void main() {
	Point p(1, 2), q(3, 4), r;	Point::printCount();	//��ü 3��
	p.print(" P = ");
	q.print(" Q = ");

	Point* pPt;					Point::printCount();	//3
	pPt = new Point(5, 6);		Point::printCount();	//4
	pPt->print(" pPt = ");
	delete pPt;					Point::printCount();	//3

	r.add(p, q);				Point::printCount();	//3
	r.print("P+Q= ");
}