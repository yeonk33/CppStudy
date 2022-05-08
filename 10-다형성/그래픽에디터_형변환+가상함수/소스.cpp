#include "Shapes.h"

// Shapes.h의 15행 draw함수를 virtual 가상함수로 수정한 프로젝트

void main() {
	Canvas myCanvas(25, 15);
	Shape* list[100];	// Shape를 상속받은 객체들을 저장할 배열
	int nShape = 0;

	while (true) {
		myCanvas.print(" <그래픽 편집기>");
		char str[200], type;
		int v[4];
		printf("Input ==> ");
		gets_s(str, sizeof(str));
		int ret = sscanf_s(str, "%c%d%d%d%d", &type, sizeof(str), v, v + 1, v + 2, v + 3);	// str을 읽어들여 각각 type, v, v+1, ..에 저장하고 읽어들인 개수 ret에 저장

		if (type == 'l' && ret == 5)	// 선분을 입력한 경우
			list[nShape++] = new Line(v[0], v[1], v[2], v[3]);
		else if (type == 'v' && ret == 4)	// v선분을 입력한 경우
			list[nShape++] = new VLine(v[0], v[1], v[2]);
		else if (type == 'h' && ret == 4)	// h선분을 입력한 경우
			list[nShape++] = new HLine(v[0], v[1], v[2]);
		else if (type == 'c' && ret == 4)	// 원
			list[nShape++] = new Circle(v[0], v[1], v[2]);
		else if (type == 'r' && ret == 5)	// 사각형
			list[nShape++] = new Rect(v[0], v[1], v[2], v[3]);
		else if (type == 's' && ret == 4)	// 정사각형
			list[nShape++] = new Square(v[0], v[1], v[2]);
		else if (type == 'q') break;	// 종료

		myCanvas.clear();
		for (int i = 0; i < nShape; i++)
			list[i]->draw(myCanvas);	// list의 자료형이 Shape*이기 때문에 부모 클래스(Shape)의 draw를 호출, 제대로 모양 그리지 않음
	}
	for (int i = 0; i < nShape; i++)
		delete list[i];	// 객체 소멸

}