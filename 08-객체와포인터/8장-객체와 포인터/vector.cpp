#include <iostream>
using namespace std;

class Vector {
	int dim;		// ���� ����
	double* arr;	// ������ �� ���� ������
public:
	Vector(int d = 0) : dim(d) { arr = new double[dim]; }	// ������ (�޸� ���� �Ҵ�)
	~Vector() { delete[] arr; }								// �Ҹ��� (�޸� �ݳ�)

	void print(const char* str = "Vector") {		// ������ ������ ���
		cout << str << "[" << dim << "] = < ";
		for (int i = 0; i < dim; i++)
			cout << arr[i] << " ";
		cout << ">\n";
	}
	void setRand(int max = 100) {					// ������ ��� �׸� ������ �ʱ�ȭ (�Ҽ��� �� �ڸ�����)
		for (int i = 0; i < dim; i++)
			arr[i] = rand() % (max * 10) / 10.0;
	}
	//void add(Vector* a, Vector* b) {				// �Ű������� ��ü�� �ּҸ� ���� -> ��ü�� ����Ǵ� ���� �ƴϹǷ� ���� �۵�
	//	for (int i = 0; i < dim; i++)
	//		arr[i] = a->arr[i] + b->arr[i];
	//}	
	void clone(Vector& a) {							// �Ű������� ���������� (�����ڴ� ���� ��ü�� ����, �� ��üX) -> ���� ����
		if (dim > 0) delete[] arr;					// ���� ��ü�� �޸� �ݳ�
		dim = a.dim;
		arr = new double[dim];						// ���޵Ǵ� ��ü�� ũ�⸸ŭ ���� �Ҵ�
		for (int i = 0; i < dim; i++)
			arr[i] = a.arr[i];						// ���� ��ü�ȿ� ���޵Ǵ� ��ü�� ������ ����
	}
	//��������
	void add(Vector a, Vector b) {
		for (int i = 0; i < dim; i++)
			arr[i] = a.arr[i] + b.arr[i];
	}
	void operator = (Vector& a) { clone(a); }		// ������ �ߺ� (?)
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
//	//w.add(&u, &v);	// �ּ� ���޽� & ���
//	w.print(" W = U + V ");
//	v.clone(u);		// v�� u�� ����
//	v.print(" V�� U�� ���� -> V ");
//	*/
//	Vector u(3), v, w(3);
//	u.setRand();
//	v = u;				// operator = �� �����ؼ� �׳� = �� ����Ѱ�
//	w.add(u, v);
//	u.print(" U ");
//	v.print(" U ");
//	w.print("U+V");
//
//}