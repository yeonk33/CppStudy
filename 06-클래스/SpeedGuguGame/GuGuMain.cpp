#include "SpeedGuGu.h"

void main() {
	SpeedGuguGame game;
	srand((unsigned)time(NULL));
	printf("���ǵ� ������ ������ �����մϴ�!\n");

	int nPlay = 10;
	printf("%d���� ������ �����˴ϴ�.\n", nPlay);
	printf("�غ�Ǹ� ���͸� ��������...");
	getchar();
	system("cls"); //�ܼ� ȭ�� Ŭ����

	double score = game.play(nPlay);
	printf("\n���� = %4.1lf��", score);
	printf("\n�ҿ�ð� = %4.1lf��", game.tElapsed);
}