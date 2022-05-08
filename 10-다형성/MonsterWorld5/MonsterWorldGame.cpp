#include "MonsterWorld.h"
#include "VariousMonsters.h"
#include <time.h>
#include "Human.h"

void main() {
	srand((unsigned)time(NULL));	// �õ� ����
	int w = 16, h = 8;	// �� ũ��
	MonsterWorld game(w, h);

	game.add(new Zombie("����", "��", rand() % w, rand() % h));
	game.add(new Vampire("�����̾�", "��", rand() % w, rand() % h));
	game.add(new KGhost("ó��ͽ�", "��", rand() % w, rand() % h));
	game.add(new Jiangshi("����(�¿�)", "��", rand() % w, rand() % h, true));
	game.add(new Jiangshi("����(���Ʒ�)", "��", rand() % w, rand() % h, false));
	game.add(new Human("�ΰ�", "��", rand() % w, rand() % h));
	game.play(300, 100);
	printf("---------��������----------\n");

}