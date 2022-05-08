#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
// 행(ㅡ, row) 열(|, column)
class Matrix {
	int rows, cols;
	int** mat;
public:
	Matrix(int r = 0, int c = 0) : rows(r), cols(c), mat(NULL) {	// 생성자
		mat = new int* [rows];
		for (int i = 0; i < rows; i++)
			mat[i] = new int[cols];
	}
	~Matrix() {								// 소멸자
		if (mat != NULL) {
			for (int i = 0; i < rows; i++)
				delete[] mat[i];			// 각 행 메모리 반환
			delete[] mat;					// 열 메모리 반환
		}
	}
	int& elem(int x, int y) { return mat[y][x]; }	// 참조자를 반환, l-value로 사용 가능
	int Rows() { return rows; }		// 행 반환
	int Cols() { return cols; }		// 열 반환
	int** Data() { return mat; };	// mat 반환  외부에서 편하게 사용하려고 만든것
	void print(const char* str = "Mat") {
		cout << str << " " << rows << "x" << cols << endl;	// 몇 by 몇 행렬인지 출력
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++)
				cout << setw(4) << mat[i][j];	// 값 출력
			cout << "\n";
		}
	}
	void setRand(int val = 100) {					// 난수 행렬 만듦
		if (mat != NULL) {
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < cols; j++)
					mat[i][j] = (rand() % val);
		}
	}

};