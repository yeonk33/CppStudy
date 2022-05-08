#include "MonsterWorld.h"
#include "VariousMonsters.h"
#include <time.h>
#include "Human.h"

void main() {
	srand((unsigned)time(NULL));	// 시드 랜덤
	int w = 16, h = 8;	// 맵 크기
	MonsterWorld game(w, h);

	game.add(new Zombie("좀비", "§", rand() % w, rand() % h));
	game.add(new Vampire("뱀파이어", "★", rand() % w, rand() % h));
	game.add(new KGhost("처녀귀신", "♥", rand() % w, rand() % h));
	game.add(new Jiangshi("강시(좌우)", "↔", rand() % w, rand() % h, true));
	game.add(new Jiangshi("강시(위아래)", "↕", rand() % w, rand() % h, false));
	game.add(new Human("인간", "♣", rand() % w, rand() % h));
	game.play(300, 100);
	printf("---------게임종료----------\n");

}