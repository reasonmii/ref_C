#define _CRT_SECURE_NO_WARNINGS  // scanf
#include <stdio.h>

int main(void) {

	int a = 10, b = 10;
	int x1, y1;

	x1 = ++a;
	y1 = --b;

	// 전위연산자: 11, 9 -> 11, 9
	printf("전위연산자 : %d, %d -> %d, %d\n", a, b, x1, y1);

	int c = 10, d = 10;
	int x2, y2;

	x2 = c++;
	y2 = d--;

	//후위연산자 : 11, 9 -> 10, 10
	printf("후위연산자 : %d, %d -> %d, %d", c, d, x2, y2);

	return 0;

}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS  // scanf
#include <stdio.h>

int main(void) {

	// 관계 연산자

	int x, y;

	printf("두 개의 정수를 입력하시요 : ");
	scanf("%d", &x);
	scanf("%d", &y);

	printf("%d == %d의 결과 : %d\n", x, y, x == y);
	printf("%d != %d의 결과 : %d\n", x, y, x != y);
	printf("%d >  %d의 결과 : %d\n", x, y, x >  y);
	printf("%d <  %d의 결과 : %d\n", x, y, x <  y);
	printf("%d >= %d의 결과 : %d\n", x, y, x >=  y);
	printf("%d <= %d의 결과 : %d\n", x, y, x <= y);

	// -------------------------------------------
	// 조건 연산자

	int a, b;

	printf("첫 번째 수는? ");
	scanf("%d", &x);
	printf("두 번째 수는? ");
	scanf("%d", &y);

	// x가 y보다 크면 x 출력, 아니면 y 출력
	printf("큰수 = %d\n", (x > y) ? x : y);

	// x가 y보다 작으면 x 출력, 아니면 y 출력
	printf("작은수 = %d", (x < y) ? x : y);

	return 0;

}


