#pragma once
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#define NUM_MVP 5
struct PlayInfo {
	char name[200];		//선수 이름
	int nMove;			//움직인 횟수
	double tElapsed;	//경기 소요 시간
};
class RankingBoard 
{
	PlayInfo MVP[NUM_MVP];	// 랭킹 배열
	int nMVP = NUM_MVP;		// 랭킹 배열의 길이
	void init() {			// 랭킹 배열 초기화
		PlayInfo noname = { "c++좋아요", 1000, 1000.0 };
		for (int i = 0; i < nMVP; i++)
			MVP[i] = noname;
	}
public:
	void load(const char* fname) {	//저장되어있는 파일에서 랭킹 읽어오는 함수
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
	void store(const char* fname) {	//파일에 현재 랭킹 쓰는 함수
		FILE* fp;
		fopen_s(&fp, fname, "w");
		if (fp == NULL) return;
		for (int i = 0; i < nMVP; i++)
			fprintf(fp, "%d %s %.1f\n", MVP[i].nMove, MVP[i].name, MVP[i].tElapsed);
		fclose(fp);
	}
	void print() {					//화면에 랭킹 출력
		for (int i = 0; i < nMVP; i++)
			printf(" [%2d위] %4d %-16s %.1f\n", i + 1, MVP[i].nMove, MVP[i].name, MVP[i].tElapsed);
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
			printf(" [%3d회]   %d위 입니다. 이름을 입력하세요: ", nMove, pos + 1);
			scanf_s("%s", MVP[pos].name, (unsigned)_countof(MVP[pos].name));
			return pos + 1;
		}
		else printf(" [%3d회]   순위권 밖입니다. 분발하세요\n", nMove);
		return 0;
	}
};