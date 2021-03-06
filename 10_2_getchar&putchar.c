/*
입출력함수     설명      버퍼사용여부     에코여부    응답성     문자수정여부
getchar()   <stdio.h>       사용          에코      줄단위        가능
_getch()    <conio.h>       사용X         에코X    문자단위      불가능
_getche()   <conio.h>       사용X         에코     문자단위      불가능
*/

// ======================================================================
// 버퍼를 사용하고 에코가 있는 방식
// int getchar(void) : 한 문자 읽어서 반환
// void putchar(int c) : 변수 c에 저장된 문자 출력
//                       (버퍼에 저장된 문자들이 프로그램으로 전달)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    char ch;

    ch = getchar();
    putchar(ch);

    return 0;
}

// ======================================================================

#include <stdio.h>

int main(void) {
	
	int ch;

	// 문자열 입출력
	printf("한 문자씩 입력하세요 (종료 : q)\n");
	while ((ch = getchar()) != 'q')
		putchar(ch);

	return 0;

}

// ======================================================================

#include <stdio.h>

int main(void) {

	char ch;

	// Filter a specific character
	// 1) convert f/F -> X
	// 2) convert numbers to asterisks
	while ((ch = getchar()) != '\n') {

		if (ch == 'f' || ch == 'F')
			ch = 'X';
		else if (ch >= '0' && ch <= '9')
			ch = '*';

		putchar(ch);
	}

	return 0;
}

// ======================================================================

#include <stdio.h>

int main(void) {

	char ch;

	// Lower/Upper to upper/Lower characters
	while ((ch = getchar()) != '\n') {

		// ASCII : 'A' = 65, 'a' = 97

		if (ch >= 'a' && ch <= 'z')
			ch -= 'a' - 'A';
		else if (ch >= 'A' && ch <= 'Z')
			ch += 'a' - 'A';

		putchar(ch);
	}

	return 0;
}

// ======================================================================

#include <stdio.h>

int main(void) {

	char ch;

	// 소문자 → 대문자, 대문자 → 소문자, 숫자 → *
	while ((ch = getchar()) != '\n') {
		if (islower(ch))
			ch = toupper(ch);
		else if (isupper(ch))
			ch = tolower(ch);
		
		if (isdigit(ch) != 0)
			ch = '*';

		putchar(ch);
	}
	
	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

    int count = 0;

    while (1) {
        printf("Current count is %d. Continue? (y/n)\n", count);

        int c = getchar();

        if (c == 'n')
            break;
        else if (c == 'y')
            count++;
        else
            printf("Please input y or n\n");

        // ※ 여러 문자를 입력했을 때
        // 같은 줄에 있는 첫 글자 외 모든 글자 무시       
        while (getchar() != '\n')
             continue;
    }

    return 0;
}

// ======================================================================
// 버퍼를 사용하지 않고 에코가 없는 방식
// int _getch(int c) : 한 문자 읽어서 반환
// void _putch(int c) : 변수 c에 저장된 문자 출력

// _getch(), _getche() : buffer 미사용
// e : echo의 약자

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>   // _getch(), _getche() 

int main() {
    char c;

    // ※ buffer 사용 시 : hello 입력 -> hello 출력
    // buffer 미사용 시 한 글자 입력할 때마다 매번 출력
    // ex) result : hheelllloo
    while ((c = _getche()) != '.')
        putchar(c);

    return 0;
}

// ======================================================================

#include <stdio.h>
#include <conio.h>

int main(void) {
	
	int ch;

	// 문자열 입출력
	printf("한 문자씩 입력하세요 (종료 : q)\n");
	while ((ch = _getch()) != 'q')
		_putch(ch);

	return 0;
}

// ======================================================================
// char * gets_s(char *s, int size) : 한 줄의 문자열을 읽어서 문자 배열 s[]에 저장
// int puts(const char *s) : 배열 s[]에 저장되어 있는 한 줄의 문자열을 추력

#include <stdio.h>

int main(void) {

	char name[20];

	printf("이름 : ");

	// scanf("%s", name);
	gets_s(name, sizeof(name));

	// printf(name);
	puts(name);

	return 0;
}

// ======================================================================
/*
scanf는 특정 buffer를 만들어 놓고
입력한 것을 출력한 후에도 buffer가 남으면 빈 공간으로 buffer를 모두 출력함
이처럼 콘솔 창 실행 시 무의미한 빈 공간들이 출력되는 현상을 막기 위해 아래 코드 사용
★ while (getchar() != '\n') continue;
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void display(char cr, int lines, int width);

int main() {

    char c;
    int rows, cols;

    printf("Input one character and two integers:\n");

    while ((c = getchar()) != '\n') {
        scanf("%d %d", &rows, &cols);
        while (getchar() != '\n') continue;

        display(c, rows, cols);
        printf("Input another character and two integers:\n");
        printf("Press Enter to quit.\n");
    }

    return 0;
}

void display(char cr, int lines, int width) {

    int row, col;

    for (row = 1; row <= lines; row++) {
        for (col = 1; col <= width; col++)
            putchar(cr);
        putchar('\n');
    }
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	// Input : Hello 123 3.14

	char str[255];
	int i, i2;
	double d;

	// Output : Hello 123 3.140000
	scanf("%s %d %lf", str, &i, &d);
	printf("%s %d %f\n", str, i, d);

	// Output : Hello 123 3
	scanf("%s %d %d", str, &i, &i2);
	printf("%s %d %d\n", str, i, i2);

	// 위에서 input 내용 중 마지막 3.14에서
	// 3까지만 읽혀지니, buffer에 .14가 남게 됨
	// 이를 getchar가 문자로 받아들여서 그대로 출력함
	// Output : .14
	char c;
	while ((c = getchar()) != '\n')
		putchar(c);
	printf("\n");
	
	return 0;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void custom_put(const char* str);
int custom_put2(const char* str);

int main() {

	// Just Do it!
	custom_put("Just ");
	custom_put("Do it!");
	printf("\n\n");

	// 12345
	// 5
	printf("%d\n", custom_put2("12345"));

	return 0;
}

// puts() which doesn't add a new line at the end
// Use pointer increment operator and putchar()
void custom_put(const char* str) {
	while (*str != '\0')
		putchar(*str++);
	return;
}

int custom_put2(const char* str) {
	int count = 0;
	while (*str) {
		putchar(*str++);
		count++;
	}
	putchar('\n');
	return count;
}

// ======================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

get_long(void);

int main() {

	long number;

	while (1) {

		// between : 해당 숫자 포함하지 않음
		// between 1 and 100 -> 2 ~ 99
		printf("Please input an integer between 1 and 100.\n");

		// 사용자로부터 안전하게
		// long type의 정수만 입력받을 수 있는 방법
		number = get_long();
		
		if (number > 1 && number < 100) {
			printf("OK. Thank you.\n");
			break;
		}
		else
			printf("Wrong input. Please try again.\n");
	}

	printf("Your input %d is between 1 and 100. Thank you.\n", number);
	return 0;
}

get_long(void) {

	printf("Please input an integer and press enter.\n");

	long input;
	char c;

	// 큰 정수도 받을 수 있게 long으로 받음
	// 입력이 한 개만 있으면 while문으로 들어가지 않음
	while (scanf("%ld", &input) != 1) {
		printf("Your input - ");

		// input left in buffer
		while ((c = getchar()) != '\n')
			putchar(c);

		printf(" - is not an integer. Please try again.\n");
	}

	printf("Your input %ld is an integer. Thank you.\n", input);

	return input;
}
