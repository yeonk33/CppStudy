#include "MonsterWorld.h"
#include <time.h>
void main() {
	srand((unsigned)time(NULL));
	int w = 16, h = 8;	// �� ũ��

	MonsterWorld game(w, h);
	game.add(new Monster("����", "��", rand() % w, rand() % h));
	game.add(new Monster("������", "��", rand() % w, rand() % h));
	game.add(new Monster("���״�", "��", rand() % w, rand() % h));
	game.add(new Monster("��Ʈ", "��", rand() % w, rand() % h));
	game.play(500, 10);
	// ���� <�� �� �� ��> �� 4������ �����ϰ� �����̸鼭 �ʵ��� ������(��)�� ��� ������ ���� ����
	printf("-------��������----------\n");

	//string str = " ";
	//cout << str.size();
}