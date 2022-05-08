#include <cstdio>
class Complex {
	double real, imag;						// 멤버 변수
public:
	//Complex() { real = imag = 0.0; }		// 기본 생성자
	//Complex(double r, double i) {			// 매개변수가 있는 생성자
	//	real = r;
	//	imag = i;
	//}
	//Complex(double r=0, double i=0) {			// 디폴트 생성자
	//	real = r;
	//	imag = i;
	//}
	Complex(double r=0, double i=0) : real(r),  imag(i){ }	// 멤버 초기화 리스트 생성자 
	void print(const char* msg = " 복소수 = ") {
		printf(" %s %4.2f + %4.2fi\n", msg, real, imag);
	}
};


//void main() {
//	Complex c1;		// 기본 생성자 호출 (0.0 + 0.0i)
//	Complex c2(1.0, 2.0);	// 매개변수가 있는 생성자 호출 (1.0 + 2.0i)
//	c1.print(" c1 = ");
//	c2.print(" c2 = ");
//
//}