/*
Arguments 인수 vs. Parameters 매개변수
1) actual argument, actual parameter -> argument (values)
2) formal argument, formal parameter -> parameter (variables)
*/

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 함수생성
void sort_asc(int a, int b) {
	if (a > b) {
		int temp = a;
		a = b;
		b = temp;
	}
}

int main(void) {

	int a = 7, b = 5;
	sort_asc(a, b);           // 함수호출
	printf("%d <= %d\n\n", a, b);

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 함수생성
// 변수의 주소
void sort_asc(int *a, int *b) {
	if (a > b) {
		int temp = *a;
		*a = *b;
		*b = temp;
	}
}

int main(void) {

	int a = 7, b = 5;
	sort_asc(&a, &b);           // 함수호출
	printf("%d <= %d\n\n", a, b);

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void printLine(char c);    // 함수의 선언

int main(void) {

	// 작은 따옴표 사용 주의
	printLine('*');        // 함수호출
	printf("프로그램 결과\n");
	printLine('-');

	return 0;
}

// 함수의 정의
void printLine(char c) {
	for (int i = 0; i < 40; i++)
		printf("%c", c);
	printf("\n");
}

// 결과
// ****************************************
// 프로그램 결과
// ----------------------------------------

// ======================================================================

#include <stdio.h>

void draw(int n);

int main() {
	
	int i = 5;
	char c = '#';     // #을 정수로 변환하면 35
	float f = 7.1f;

	draw(i);      // 이 때 i는 5로 정의되어 있음 -> argument (values)
	draw(c);
	draw(f);
	//draw((int)c);
	//draw((int)f);

	return 0;
}

void draw(int n) {    // 이 때 n은 parameter (variables)

	while (n-- > 0)
		printf("*");  // asterisks
	printf("\n");
}

// ======================================================================

#include <stdio.h>
void say_hello(void);  // Function declaration

int main() {

	int i = 0;

	for (i = 0; i < 5; i++)
		say_hello();

	return 0;
}

void say_hello(void) {  // Function Definition
	printf("Hello, World\n");

	return;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>     // math 함수 활용하기

int main(void) {

	int a = 10;
	int b = 2;
	int c = 16;

	double result1 = pow(a, b);  // power : 제곱
	double result2 = sqrt(c);    // 제곱근

	// 10의   2승 =   100
	printf("%3d의 %3d승 = %5.0f\n", a, b, result1);

	// 16의 제곱근 =     4
	printf("%3d의 제곱근 = %5.0f\n", c, result2);

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>              // 난수함수 포함

int main(void) {

	int a;

	for (int i = 1; i <= 5; i++) {
		printf("%d회 난수 = %5d \n", i, rand());
	}

	// 범위 제한 : 1~10 난수
	for (int i = 1; i <= 5; i++) {
		printf("%d회 난수 = %5d \n", i, (rand() % 10) + 1);
	}

	return 0;

}

// ======================================================================

#include <stdio.h>

int tmp = 1;       // 전역변수
void funcTmp();    // 함수의 선언

int main(void) {
	int tmp = 10;                    // 지역변수

	printf("%d in main()\n", tmp);

	for (int i = 0; i < 5; i++) {
		int tmp = 0;                 // 지역변수
		printf("%d in for\n", tmp++);
	}
	
	funcTmp();                      // 함수의 호출

	printf("%d in main() \n", tmp);

	return 0;
}

// 함수의 정의
void funcTmp() {
	int tmp = 99;
	printf("%d in funcTmp()\n", tmp);
}

// 결과
// 10 in main()
// 0 in for
// 0 in for
// 0 in for
// 0 in for
// 0 in for
// 99 in funcTmp()
// 10 in main()

// ======================================================================

#include <stdio.h>
void func(void);
static int cntRunFunc = 0;

int main(void) {
	printf("함수의 실행 횟수 \t 함수의 변수값 \n");
	func();
	func();
	func();

	printf("이렇게 전역변수로 정의하면 사용 가능 %10d \n", ++cntRunFunc);  // 1

	return 0;
}

void func(void) {
	static int cntRunFunc = 0;
	int cntLocal = 0;
	printf("%7d \t\t", ++cntRunFunc);   // 1 -> 2 -> 3
	printf("%10d \n", ++cntLocal);      // 1 -> 1 -> 1
}

// ======================================================================
// 팩토리얼

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long factorial(int n);     // 함수선언

int main(void) {
	int n;
	printf("정수 입력 : ");
	scanf("%d", &n);
	printf("%d! = ", n);  // ex)  4! = 4 * 3 * 2 * 1
	factorial(n);

	return 0;
}

long factorial(int n) {
	printf("%d", n);
	if (n == 1)
		return 1;
	else {
		printf(" * ");
		return n * factorial(n - 1);
	}
}

// ======================================================================
// 하노이의 탑

#include <stdio.h>

void hanoi(int n, int start, int work, int target);

void main() {
	hanoi(3, 'A', 'B', 'C');
	getchar();
}

void hanoi(int n, int start, int work, int target) {
	if (n == 1)
		printf("%c에서 원반 %d를 %c로 옮김 \n", start, n, target);
	else {
		hanoi(n - 1, start, target, work);
		printf("*****");
		printf("%c에서 원반 %d를 %c로 옮김 \n", start, n, target);
		printf("#####");
		hanoi(n - 1, work, start, target);
		printf("=====");
	}
}

// 결과
// A에서 원반 1를 C로 옮김
// *****A에서 원반 2를 B로 옮김
// #####C에서 원반 1를 B로 옮김
// =====*****A에서 원반 3를 C로 옮김
// #####B에서 원반 1를 A로 옮김
// *****B에서 원반 2를 C로 옮김
// #####A에서 원반 1를 C로 옮김
// ==========
