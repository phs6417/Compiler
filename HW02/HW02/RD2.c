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

void popen()
{
	if (ch == '(')
		ch = getchar();
	else error();
}

void pclose()
{
	if (ch == ')')
		ch = getchar();
	else error();
}

void pplus()
{
	if (ch == '+')
		ch = getchar();
	else error();
}

void pmul()
{
	if (ch == '*')
		ch = getchar();
	else error();
}


/*
	E -> TE'		0
	E'-> +TE' | ���Ƿ�	1	2
	T -> FT'		3
	T'-> *FT' | ���Ƿ�	4	5
	F -> (E) | a		6	7

*/


void pE();
void pE2();
void pT();
void pT2();
void pF();



void pE()
{
	if (ch == 'a' || ch == '(' ) {
		puts("\tE --> TE\'");
		pT(); pE2();
	
	} else error();
}

void pT()
{
	switch (ch) {
	case 'a':
		puts("\tT --> FT\'");
		pF(); pT2();
		break;
	case '(':
		puts("\tT --> FT\'");
		pF(); pT2();
		break;
	default:
		error();
	}
}

void pF()
{
	switch (ch) {
	case 'a':
		puts("\tF --> a");
		pa();
		break;
	case '(':
		puts("\tF --> (E)");
		popen(); pE(); pclose();
		break;
	default:
		error();
	}
}

void pE2()
{
	switch (ch) {
	case '+':
		puts("\tE\' --> +TE\'");
		pplus(); pT(); pE2();
		break;
	case ')':
		puts("\tE\' --> �۽Ƿ�");
		break;
	case '$':
		puts("\tE\' --> �۽Ƿ�");
		break;
	case '\n':
		puts("\tE\' --> �۽Ƿ�");
		break;
	default:
		error();
	}
}

///////////////////////////

void pT2()
{
	switch (ch) {
	case '*':
		puts("\tT\' --> *FT\'");
		pmul(); pF(); pT2();
		break;
	case ')':
		puts("\tT\' --> �۽Ƿ�");
		break;
	case '$':
		puts("\tT\' --> �۽Ƿ�");
		break;
	case '\n':
		puts("\tT\' --> �۽Ƿ�");
		break;
	default:
		error();
	}
}



int main()
{
	puts("Production Rules:");
	puts("\tE --> TE\'");
	puts("\tE\' --> +TE\' | �۽Ƿ�");
	puts("\tT --> FT\'");
	puts("\tT\' --> *FT\' | �۽Ƿ�");
	puts("\tF --> (E) | a");
	printf("$�� ������ �Է½�Ʈ�� : ");

	ch = getchar();
	pE();

	if (!errflag && (ch == '$' || ch == '\n')) puts("OK");
	else error();
}
