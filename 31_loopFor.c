#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int start = 1;
	int end = 10;
	int sum = 0;
	int i = start;

	for (i = start; i <= end; i = i + 2)
		sum = sum + i;

	printf("%d ~ %d의 홀수합 = %3d", start, end, sum);

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int start = 3, i;

	for (i = 1; i < 10; i++)
		printf("구구단 : %3d * %d = %3d\n", start, i, start * i);

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int dan, i;

	// 구구단 전체 : 2 ~ 9단
	for (dan = 2; dan <= 9; dan++) {
		printf("\n\n\n===================== %d단 =====================\n", dan);
		for (i = 2; i <= 9; i++)
			printf("%d * %d = %d\n", dan, i, dan * i);
	}

	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int sum = 0;
	int i, inData;

	// 5개 정수 입력해서 더하기
	for (i = 0; i < 5; i++) {
		printf("%d번째 정수 입력 : ", i + 1);
		scanf("%d", &inData);
		sum = sum + inData;
	}

	printf("합 = %2d \n", sum);

	return 0;
}
