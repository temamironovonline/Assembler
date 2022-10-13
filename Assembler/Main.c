#include <stdio.h>

int amount(int, int);
int difference(int, int);
int multiply(int, int);
int division(int, int);
int divisionRemainder(int, int);
int comprasionTwo(int, int);
int comprasionThree(int, int, int);
void changeElementsPlace(int*, int*);

//https://codetown.ru/assembler/delenie-umnozhenie/

int amountAssembler(int, int);
int differenceAssembler(int, int);
int multiplyAssembler(int, int);
int divisionAssembler(int, int);
int divisionRemainderAssembler(int, int);
int comprasionTwoAssembler(int, int);
int comprasionThreeAssembler(int, int, int);
void changeElementsPlaceAssembler(int*, int*);

int amount(int a, int b)
{
	int c = a + b;
	return c;
}

int amountAssembler(int a, int b)
{
	int c;
	_asm 
	{
		mov eax, a;
		add eax, b;
		mov c, eax;
	}
	return c;
}


int difference(int a, int b)
{
	int c = a - b;
	return c;
}

int differenceAssembler(int a, int b)
{
	int c;
	_asm
	{
		mov eax, a;
		sub eax, b;
		mov c, eax;
	}
	return c;
}

int multiply(int a, int b)
{
	int c = a * b;
	return c;
}

int multiplyAssembler(int a, int b)
{
	int c;
	_asm
	{
		mov eax, a;
		mov ebx, b;
		mul ebx;
		mov c, eax;
	}
	return c;
}


int division(int a, int b)
{
	int c = a / b;
	return c;
}

int divisionAssembler(int a, int b)
{
	int c;
	_asm
	{
		mov eax, a;
		mov edx, 0;
		mov ebx, b;
		div ebx;
		mov c, eax;
	}
	return c;
}

int divisionRemainder(int a, int b)
{
	int c = a % b;
	return c;
}

int divisionRemainderAssembler(int a, int b)
{
	int c;
	_asm
	{
		mov eax, a;
		mov edx, 0;
		mov ebx, b;
		div ebx;
		mov c, edx;
	}
	return c;
}

int comprasionTwo(int a, int b)
{
	if (a > b) return 1;
	else if (b > a) return 2;
	else return 0;
}

int comprasionTwoAssembler(int a, int b)
{
	int c;
	_asm
	{
		mov eax, a
		cmp eax, b

		je equal
		jg greater
		jl less
	
		equal : mov c, 0
			jmp EndIf
		greater : mov c, 1
			jmp EndIf
		less : mov c, 2
			jmp EndIf
		
		EndIf:

	}
	return c;
}

int comprasionThree(int a, int b, int c)
{
	a = 4;
	b = 1;
	c = 4;
	//���� a ������ ����, �� 1
	//���� a>b=c, �� 2
	//���� a=b>c, �� 3
	//���� b ������ ����, �� 4
	//���� b>a=c, �� 5
	//���� b=c>a, �� 6
	//���� c ������ ����, �� 7
	//���� c>a=b, �� 8
	//���� a=b=c, �� 0
	if (a > b)
	{
		if (a > c) return 1;
		else if (a == c) return 2;
		else return 8;
	}
	else if (a == b)
	{
		if (a > c) return 3;
		else return 7;
	}
	else if (b > a)
	{
		if (b > c) return 4;
		else if (b == c) return 6;
		else return 3;
	}
	else if (c > a)
	{
		if (c > b) return 3;
		else if (c == b) return 6;
		else return 2;
	}
	else return 0;
}

int comprasionThreeAssembler(int a, int b, int c)
{
	int d;
	_asm
	{
		mov eax, a;
		cmp eax, b;

		je equalAB;
		jg greaterAB;
		jl lessAB;

		equalAB : 
			cmp eax, c;
				je equalAC;
				jg greaterAC;
				jl lessAC;

			equalAC:
				mov d, 0;
				jmp EndIf;
			greaterAC:
				mov d, 1;
				jmp EndIf;
			lessAC:
				mov d, 3;
				jmp EndIf;
		
		greaterAB:
			mov d, 1;
			cmp eax, c;
			je EndIf;
			jg EndIf;
			jl lessAC;


			
		
		
		lessAB: mov c, 2;
			jmp EndIf;

		EndIf :

	}
	return d;
}

void changeElementsPlace(int* a, int* b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

int main(void)
{
	system("chcp 1251>n");
	int var1 = 3, var2 = 5, var3 = 10;
	printf("�����: %d\n", amount(var1, var2));
	printf("�������: %d\n", difference(var1, var2));
	printf("���������: %d\n", multiply(var1, var2));
	printf("�������: %d\n", division(var1, var2));
	printf("������� �� �������: %d\n", divisionRemainder(var1, var2));
	printf("��������� ����: %d\n", comprasionTwo(var1, var2));
	printf("��������� ����: %d\n", comprasionThree(var1, var2, var3));

	

	int* var6 = &var1, * var7 = &var2;
	printf("%d %d ", *var6, *var7);

	//changeElementsPlace(var6, var7);
	//printf("%d %d ", *var6, *var7);


	printf("\n���������\n");
	printf("����� �� ����������: %d\n", amountAssembler(var1, var2));
	printf("������� �� ����������: %d\n", differenceAssembler(var1, var2));
	printf("��������� �� ����������: %d\n", multiplyAssembler(var1, var2));
	printf("������� �� ���������� %d\n", divisionAssembler(var1, var2));
	printf("������� �� ������� �� ����������: %d\n", divisionRemainderAssembler(var1, var2));
	printf("��������� ���� �� ����������: %d\n", comprasionTwoAssembler(var1, var2));
}