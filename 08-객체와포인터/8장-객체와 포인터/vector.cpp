#include <iostream>
using namespace std;

class Vector {
	int dim;		// 벡터 차원
	double* arr;	// 벡터의 각 차원 데이터
public:
	Vector(int d = 0) : dim(d) { arr = new double[dim]; }	// 생성자 (메모리 동적 할당)
	~Vector() { delete[] arr; }								// 소멸자 (메모리 반납)

	void print(const char* str = "Vector") {		// 벡터의 데이터 출력
		cout << str << "[" << dim << "] = < ";
		for (int i = 0; i < dim; i++)
			cout << arr[i] << " ";
		cout << ">\n";
	}
	void setRand(int max = 100) {					// 벡터의 모든 항목 난수로 초기화 (소수점 한 자리까지)
		for (int i = 0; i < dim; i++)
			arr[i] = rand() % (max * 10) / 10.0;
	}
	//void add(Vector* a, Vector* b) {				// 매개변수로 객체의 주소를 복사 -> 객체가 복사되는 것이 아니므로 정상 작동
	//	for (int i = 0; i < dim; i++)
	//		arr[i] = a->arr[i] + b->arr[i];
	//}	
	void clone(Vector& a) {							// 매개변수를 참조형으로 (참조자는 기존 객체의 별명, 새 객체X) -> 깊은 복사
		if (dim > 0) delete[] arr;					// 기존 객체의 메모리 반납
		dim = a.dim;
		arr = new double[dim];						// 전달되는 객체의 크기만큼 동적 할당
		for (int i = 0; i < dim; i++)
			arr[i] = a.arr[i];						// 기존 객체안에 전달되는 객체의 내용을 복사
	}
	//수정버전
	void add(Vector a, Vector b) {
		for (int i = 0; i < dim; i++)
			arr[i] = a.arr[i] + b.arr[i];
	}
	void operator = (Vector& a) { clone(a); }		// 연산자 중복 (?)
	Vector(Vector& a) : dim(0) { clone(a); }
};

//void main() {
//	/*
//	Vector u(3), v(3), w(3);
//	u.setRand();
//	v.setRand();
//	u.print(" U ");
//	v.print(" V ");
//	//w.print(" W ");
//	//w.add(&u, &v);	// 주소 전달시 & 사용
//	w.print(" W = U + V ");
//	v.clone(u);		// v에 u를 복사
//	v.print(" V에 U를 복사 -> V ");
//	*/
//	Vector u(3), v, w(3);
//	u.setRand();
//	v = u;				// operator = 로 구현해서 그냥 = 을 사용한거
//	w.add(u, v);
//	u.print(" U ");
//	v.print(" U ");
//	w.print("U+V");
//
//}