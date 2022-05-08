#pragma once
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#define NUM_MVP 5
struct PlayInfo {
	char name[200];		//���� �̸�
	int nMove;			//������ Ƚ��
	double tElapsed;	//��� �ҿ� �ð�
};
class RankingBoard 
{
	PlayInfo MVP[NUM_MVP];	// ��ŷ �迭
	int nMVP = NUM_MVP;		// ��ŷ �迭�� ����
	void init() {			// ��ŷ �迭 �ʱ�ȭ
		PlayInfo noname = { "c++���ƿ�", 1000, 1000.0 };
		for (int i = 0; i < nMVP; i++)
			MVP[i] = noname;
	}
public:
	void load(const char* fname) {	//����Ǿ��ִ� ���Ͽ��� ��ŷ �о���� �Լ�
		FILE* fp;
		fopen_s(&fp, fname, "r");
		if (fp == NULL)
			init();
		else {
			for (int i = 0; i < nMVP; i++) {
				fscanf_s(fp, "%d", &MVP[i].nMove);
				fscanf_s(fp, "%s", MVP[i].name, (unsigned)_countof(MVP[i].name));
				fscanf_s(fp, "%lf", &MVP[i].tElapsed);
			}
				

			fclose(fp);
		}
		
	}
	void store(const char* fname) {	//���Ͽ� ���� ��ŷ ���� �Լ�
		FILE* fp;
		fopen_s(&fp, fname, "w");
		if (fp == NULL) return;
		for (int i = 0; i < nMVP; i++)
			fprintf(fp, "%d %s %.1f\n", MVP[i].nMove, MVP[i].name, MVP[i].tElapsed);
		fclose(fp);
	}
	void print() {					//ȭ�鿡 ��ŷ ���
		for (int i = 0; i < nMVP; i++)
			printf(" [%2d��] %4d %-16s %.1f\n", i + 1, MVP[i].nMove, MVP[i].name, MVP[i].tElapsed);
	}
	int add(int nMove, double tElap) {
		if (nMove < MVP[nMVP - 1].nMove) {
			int pos = nMVP - 1;
			for (; pos > 0; pos--) {
				if (nMove >= MVP[pos - 1].nMove) break;
				MVP[pos] = MVP[pos - 1];
			}
			MVP[pos].nMove = nMove;
			MVP[pos].tElapsed = tElap;
			printf(" [%3dȸ]   %d�� �Դϴ�. �̸��� �Է��ϼ���: ", nMove, pos + 1);
			scanf_s("%s", MVP[pos].name, (unsigned)_countof(MVP[pos].name));
			return pos + 1;
		}
		else printf(" [%3dȸ]   ������ ���Դϴ�. �й��ϼ���\n", nMove);
		return 0;
	}
};