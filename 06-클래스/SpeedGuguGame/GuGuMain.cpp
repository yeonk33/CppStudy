#include "SpeedGuGu.h"

void main() {
	SpeedGuguGame game;
	srand((unsigned)time(NULL));
	printf("스피드 구구단 게임을 시작합니다!\n");

	int nPlay = 10;
	printf("%d개의 문제가 출제됩니다.\n", nPlay);
	printf("준비되면 엔터를 누르세요...");
	getchar();
	system("cls"); //콘솔 화면 클리어

	double score = game.play(nPlay);
	printf("\n점수 = %4.1lf점", score);
	printf("\n소요시간 = %4.1lf초", game.tElapsed);
}