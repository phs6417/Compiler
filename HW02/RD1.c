#include <stdio.h>

char ch;
int errflag = 0;

void error()
{
	if (!errflag) {
		puts("FAIL");
		errflag = 1;
	}
}

void pa()
{
	if (ch == 'a')
		ch = getchar();
	else error();
}

void pcomma()
{
	if (ch == ',')
		ch = getchar();
	else error();
}


/*
	A --> BC
	C --> ,BC | ¾Û½Ç·Ð
	B --> a
*/


void pA();
void pB();
void pC();



void pA()
{
	if (ch == 'a') {
		puts("\tA --> BC");
		pB(); pC();
	} else error();
}

void pB()
{
	switch (ch) {
	case 'a':
		pa();
		puts("\tB --> a");
		break;
	default:
		error();
	}
}
void pC()
{
	switch (ch) {
	case ',':
		puts("\tC --> ,BC");
		pcomma(); pB(); pC();
		break;
	case 'a':
		puts("\tC --> ¾Û½Ç·Ð");
		break;
	case '$':
		puts("\tC --> ¾Û½Ç·Ð");
		break;
	case '\n':
		puts("\tC --> ¾Û½Ç·Ð");
		break;
	
	
	default:
		error();
	}
}

int main()
{
	puts("Production Rules:");
	puts("\tA --> BC");
	puts("\tC --> ,BC | ¾Û½Ç·Ð");
	puts("\tB --> a");
	printf("$·Î ³¡³ª´Â ÀÔ·Â½ºÆ®¸µ : ");

	ch = getchar();
	pA();

	if (!errflag && (ch == '$' || ch == '\n')) puts("OK");
	else error();
}
