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
	C --> ,BC | �۽Ƿ�
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
		puts("\tC --> �۽Ƿ�");
		break;
	case '$':
		puts("\tC --> �۽Ƿ�");
		break;
	case '\n':
		puts("\tC --> �۽Ƿ�");
		break;
	
	
	default:
		error();
	}
}

int main()
{
	puts("Production Rules:");
	puts("\tA --> BC");
	puts("\tC --> ,BC | �۽Ƿ�");
	puts("\tB --> a");
	printf("$�� ������ �Է½�Ʈ�� : ");

	ch = getchar();
	pA();

	if (!errflag && (ch == '$' || ch == '\n')) puts("OK");
	else error();
}
