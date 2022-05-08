#include "Shapes.h"

// Shapes.h�� 15�� draw�Լ��� virtual �����Լ��� ������ ������Ʈ

void main() {
	Canvas myCanvas(25, 15);
	Shape* list[100];	// Shape�� ��ӹ��� ��ü���� ������ �迭
	int nShape = 0;

	while (true) {
		myCanvas.print(" <�׷��� ������>");
		char str[200], type;
		int v[4];
		printf("Input ==> ");
		gets_s(str, sizeof(str));
		int ret = sscanf_s(str, "%c%d%d%d%d", &type, sizeof(str), v, v + 1, v + 2, v + 3);	// str�� �о�鿩 ���� type, v, v+1, ..�� �����ϰ� �о���� ���� ret�� ����

		if (type == 'l' && ret == 5)	// ������ �Է��� ���
			list[nShape++] = new Line(v[0], v[1], v[2], v[3]);
		else if (type == 'v' && ret == 4)	// v������ �Է��� ���
			list[nShape++] = new VLine(v[0], v[1], v[2]);
		else if (type == 'h' && ret == 4)	// h������ �Է��� ���
			list[nShape++] = new HLine(v[0], v[1], v[2]);
		else if (type == 'c' && ret == 4)	// ��
			list[nShape++] = new Circle(v[0], v[1], v[2]);
		else if (type == 'r' && ret == 5)	// �簢��
			list[nShape++] = new Rect(v[0], v[1], v[2], v[3]);
		else if (type == 's' && ret == 4)	// ���簢��
			list[nShape++] = new Square(v[0], v[1], v[2]);
		else if (type == 'q') break;	// ����

		myCanvas.clear();
		for (int i = 0; i < nShape; i++)
			list[i]->draw(myCanvas);	// list�� �ڷ����� Shape*�̱� ������ �θ� Ŭ����(Shape)�� draw�� ȣ��, ����� ��� �׸��� ����
	}
	for (int i = 0; i < nShape; i++)
		delete list[i];	// ��ü �Ҹ�

}