#include <cstdio>
class Complex {
	double real, imag;						// ��� ����
public:
	//Complex() { real = imag = 0.0; }		// �⺻ ������
	//Complex(double r, double i) {			// �Ű������� �ִ� ������
	//	real = r;
	//	imag = i;
	//}
	//Complex(double r=0, double i=0) {			// ����Ʈ ������
	//	real = r;
	//	imag = i;
	//}
	Complex(double r=0, double i=0) : real(r),  imag(i){ }	// ��� �ʱ�ȭ ����Ʈ ������ 
	void print(const char* msg = " ���Ҽ� = ") {
		printf(" %s %4.2f + %4.2fi\n", msg, real, imag);
	}
};


//void main() {
//	Complex c1;		// �⺻ ������ ȣ�� (0.0 + 0.0i)
//	Complex c2(1.0, 2.0);	// �Ű������� �ִ� ������ ȣ�� (1.0 + 2.0i)
//	c1.print(" c1 = ");
//	c2.print(" c2 = ");
//
//}