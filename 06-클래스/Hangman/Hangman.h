#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>	// getch()
using namespace std;

class Hangman {
	string progress[64];	// 행맨 진행 상태 그림
	string problem;			// 문제
	string answer;			// 진행 중인 단어
	string guessed;			// 현재까지 예측 상황
	int nTries;				// 틀린 횟수
	const int maxTries = 7;	// 최대 도전 횟수 (고정)

	void load(const char* filename = "HangmanProgress.txt") {
		ifstream fs(filename);				// 저장을 위한 파일 열기
		if (fs) {							// 파일이 정상적으로 열렸으면
			getline(fs, progress[0]);		// 첫 행은 주석
			for (int i = 0; i < 64; i++)
				getline(fs, progress[i]);	// 한 행씩 읽음
		}
		//fs.close();
	}
	void print() {
		system("cls");
		cout << " <Hangman Game>\n";
		for (int i = 0; i < 8; i++)
			cout << '\t' << progress[nTries * 8 + i] << endl;
		cout << "\n\t" << answer;
		cout << "\n\t" << guessed;
	}
	int countMatched(char ch) {	// 예측한 문자가 정답과 일치하는 개수 반환
		int matched = 0;
		for (int pos = -1;;) {
			pos = problem.find(ch, pos + 1);
			if (pos < 0) break;
			answer[pos] = ch;
			matched++;
		}
		/*for (int i = 0;; i++) {
			if (problem[i] == ch) {
				matched++;
				answer[i] = ch;
			}			
			if (problem[i] == '\n') break;
		}*/
		return matched;
	}
	void guess() {
		char ch = _getch();	// 한 글자 입력 받고
		if (ch >= 'a' && ch <= 'z') {
			int pos = guessed.find(ch);
			if (pos < 0) {				// 아직 추측하지 않은 글자
				guessed[ch - 'a'] = ch;	// 정답으로 제출한 글자는 표시
				if (countMatched(ch) == 0) nTries++;	// 실패++
			}
		}
	}

public:
	void play(string prob) {
		load();
		problem = prob;
		answer = string(problem.length(), '-');	// 생성자 사용, 정답단어 길이만큼 - 표시
		guessed = string(24, '.');				// 생성자 사용, 알파벳 24개를 모두 .으로 표시
		nTries = 0;								// 실패 횟수 초기화
		while (nTries < maxTries && answer != problem) {
			print();
			guess();
		}
		print();	// 게임 종료 후 상태 출력
		cout<<"\n\t"<<((nTries == maxTries) ? "실패" : "정답") << endl;
	}
};