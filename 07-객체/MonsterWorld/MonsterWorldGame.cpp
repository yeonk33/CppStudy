#include "MonsterWorld.h"
#include <time.h>
void main() {
	srand((unsigned)time(NULL));
	int w = 16, h = 8;	// �� ũ��

	MonsterWorld game(w, h);
	Monster m("����", "��", rand() % w, rand() % h);
	game.add(m);
	game.add(Monster("������", "��", rand() % w, rand() % h));
	game.add(Monster("���״�", "��", rand() % w, rand() % h));
	game.add(Monster("��Ʈ", "��", rand() % w, rand() % h));
	game.play(500, 10);
	// ���� <�� �� �� ��> �� 4������ �����ϰ� �����̸鼭 �ʵ��� ������(��)�� ��� ������ ���� ����
	printf("-------��������----------\n");

	//string str = " ";
	//cout << str.size();
}