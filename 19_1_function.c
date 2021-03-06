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
/*
********************
      Yuna Lee
    Seoul, Korea
********************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>   // strlen()
#include <stdbool.h>

#define WIDTH   20
#define NAME    "Yuna Lee"
#define ADDRESS "Seoul, Korea"

// 자료형만 넣어서 선언해도 되지만
// 한 눈에 잘 알기 위해 보통 변수명도 같이 넣어서 선언함
// void print_bar(char, int, bool);
void print_bar(char c, int n_stars, bool print_newline);  // prototype
void print_center(char str[]);

int main() {

	// 함수에 실제로 넣는 값 : Argument
	// (actual argument/parameter)
	print_bar('*', WIDTH, true);

	print_center(NAME);
	print_center(ADDRESS);

	print_bar('*', WIDTH, false);

	return 0;
}

// 함수에 공식적으로 넣는 값 : Parameter (formal argument/parameter)
void print_bar(char c, int n_stars, bool print_newline) {
	for (int i = 0; i < n_stars; ++i)
		printf("%c", c);     // putchar(c)

	if (print_newline)
		printf("\n");
}

void print_center(char str[]) {

	int n_blanks = 0;
	n_blanks = (WIDTH - strlen(str)) / 2;
	print_bar(' ', n_blanks, false);
	printf("%s\n", str);
}

// ======================================================================
// 최소값 구하기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 아래와 같이 정수형 반환 자료형인 경우만 생략 가능
// int_min(int, int)
int int_min(int, int);

int main() {

	int i1, i2;

	while (1) {
		printf("Input two integers : ");
		if (scanf("%d %d", &i1, &i2) != 2) break;
		int lesser = int_min(i1, i2);
		printf("The lesser of %d and %d is %d\n", i1, i2, lesser);
	}

	printf("End.\n");
}

// int_min(int i, int j) {
int int_min(int i, int j) {

	// 방법1 : 삼항연산자
	return (i < j) ? i : j;

	// 방법2
	/*if (i < j)
		return i;
	else
		return j;*/
}

// ======================================================================
// 최대값 구하기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int int_max(int i, int j);

int main() {

	int i1, i2;

	while (1) {
		printf("Input two integers : ");
		if (scanf("%d %d", &i1, &i2) != 2) break;
		int lesser = int_min(i1, i2);
		printf("The lesser of %d and %d is %d\n", i1, i2, lesser);
	}

	printf("End.\n");
}

int int_max(int i, int j) {
	int m = (i > j) ? i : j;
	return m;
}

// ======================================================================
// 제곱수 구하기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int compute_pow(int base, int exp);

int main() {

	int base, exp;
	int result;

	while (scanf("%d %d", &base, &exp) == 2) {
		result = compute_pow(base, exp);
		printf("Result = %d\n", result);
	}

	return 0;
}

int compute_pow(int base, int exp) {

	int i, result;

	result = 1;
	for (i = 0; i < exp; ++i)
		result *= base;

	return result;
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
