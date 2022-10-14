#include <stdio.h>
#include <time.h>
#include <math.h>

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
	
	//���� a ������ ����, �� 1
	//���� a=b>c, �� 2
	//���� a=c>b, �� 3
	//���� a>b=c, �� 1
	//���� b ������ ����, �� 4
	//���� b=a>c, �� 2
	//���� b>a=c, �� 4
	//���� b=c>a, �� 5
	//���� c ������ ����, �� 6
	//���� c>a=b, �� 6
	//���� c=b>a, �� 5
	//���� c=a>b, �� 3
	//���� a=b=c, �� 0

	//5 - 4, 7 - 5, 8 - 6
	if (a > b)
	{
		if (a > c) return 1;
		else if (a == c) return 3;
		else return 6;
	}
	else if (a == b && a != c)
	{
		if (a > c) return 2;
		else return 6;
	}
	else if (b > a)
	{
		if (b > c) return 4;
		else if (b == c) return 5;
		else return 6;
	}
	else if (c > a)
	{
		if (c > b) return 8;
		else if (c == b) return 5;
		else return 4;
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
				mov d, 2;
				jmp EndIf;
			lessAC:
				mov d, 6;
				jmp EndIf;
		
		greaterAB:
			mov d, 1;
			cmp eax, c;
			je A_Equals_C_Greater_B;
			jg EndIf;
			jl lessAC;

			A_Equals_C_Greater_B:
				mov d, 3;
				jmp EndIf;
		
		lessAB: 
			mov d, 4;
			mov eax, b;
			cmp eax, c;

			je B_Equals_C_Greater_A;
			jg EndIf;
			jl lessAC;

			B_Equals_C_Greater_A:
				mov d, 5;
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

void changeElementsPlaceAssembler(int* a, int* b)
{
	int c = *a, d = *b;
	_asm 
	{
		mov eax, c;
		mov ebx, d;
		mov c, ebx;
		mov d, eax;
	}
	*a = c;
	*b = d;
}

int main(void)
{
	system("chcp 1251>n");
	int var1 = 3, var2 = 5, var3 = 10;
	int* var6 = &var1, * var7 = &var2;
	int n = 6;
	int* array = calloc(n, sizeof(int*));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < pow(n, i); j++)
		{
			changeElementsPlaceAssembler(var6, var7);
			printf("����� �������: %d %d ", *var6, *var7);
		}
		array[i-1] = clock();
	}
	
	for (int i = 0; i < n; i++)
	{
		printf("\n%d ", array[i]);
	}

	/*printf("�����: %d\n", amount(var1, var2)); // ������
	printf("�������: %d\n", difference(var1, var2)); // ������
	printf("���������: %d\n", multiply(var1, var2)); // ������
	printf("�������: %d\n", division(var1, var2)); //������
	printf("������� �� �������: %d\n", divisionRemainder(var1, var2)); //������
	printf("��������� ����: %d\n", comprasionTwo(var1, var2)); //������
	printf("��������� ����: %d\n", comprasionThree(var1, var2, var3)); //������

	printf("\n");

	int* var6 = &var1, * var7 = &var2;
	printf("�������� �� ����� �������: %d %d \n", *var6, *var7);
	
	changeElementsPlace(var6, var7);
	printf("����� �������: %d %d \n", *var6, *var7);

	changeElementsPlaceAssembler(var6, var7);
	printf("����� ������� �����������: %d %d \n", *var6, *var7);

	printf("\n���������\n");
	printf("����� �� ����������: %d\n", amountAssembler(var1, var2)); //������
	printf("������� �� ����������: %d\n", differenceAssembler(var1, var2)); // ������
	printf("��������� �� ����������: %d\n", multiplyAssembler(var1, var2)); // ������
	printf("������� �� ���������� %d\n", divisionAssembler(var1, var2)); //������
	printf("������� �� ������� �� ����������: %d\n", divisionRemainderAssembler(var1, var2)); //������
	printf("��������� ���� �� ����������: %d\n", comprasionTwoAssembler(var1, var2)); //������
	printf("��������� ���� �� ����������: %d\n", comprasionThreeAssembler(var1, var2, var3)); //������ */
	
	

}