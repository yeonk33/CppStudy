#include <iostream>
using namespace std;

struct Point {		// ȭ����� ���� ǥ���ϴ� Ŭ���� (��� ����� ����(public)���� ����� �� �ֵ��� struct��)
	int x, y;		// ���� x, y ��ǥ ��
	Point(int xx = 0, int yy = 0) : x(xx), y(yy) { }	// ��� �ʱ�ȭ ����Ʈ�� ����� ������ �Լ�
};

Point readPoint() {
	Point p;
	cout << " ��ǥ�� �Է����ּ���(x,y): ";
	cin >> p.x >> p.y;
	return p;
}
void PrintPoint(Point p, const char* str = "Point") {
	cout << str << "= (" << p.x << "," << p.y << ")\n";
}
void main() {
	Point a;
	a = readPoint();
	PrintPoint(a, " �Է� ��ǥ ");
}