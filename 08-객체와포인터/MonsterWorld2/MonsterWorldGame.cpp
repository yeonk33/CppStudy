#include "MonsterWorld.h"
#include <time.h>
void main() {
	srand((unsigned)time(NULL));
	int w = 16, h = 8;	// 맵 크기

	MonsterWorld game(w, h);
	game.add(new Monster("몬스터", "※", rand() % w, rand() % h));
	game.add(new Monster("도깨비", "§", rand() % w, rand() % h));
	game.add(new Monster("별그대", "★", rand() % w, rand() % h));
	game.add(new Monster("고스트", "♥", rand() % w, rand() % h));
	game.play(500, 10);
	// 몬스터 <※ § ★ ♥> 총 4마리가 랜덤하게 움직이면서 필드의 아이템(■)을 모두 먹으면 게임 종료
	printf("-------게임종료----------\n");

	//string str = " ";
	//cout << str.size();
}