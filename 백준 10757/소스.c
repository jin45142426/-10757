#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
//���ڿ� ����
#include<string.h>

int main()
{
	//number = A �� B�� �Է¹޴� ����
	char number[2][10050] = { NULL };
	//number1[0] = A , number1[1] = B, number1[2] = A + B
	int number1[3][10050] = { 0 };
	
	//i,j �� number1�� ����� ���ڵ��� ����
	int i = 0, j = 0;
	//LEN�� A�� B�� ���ڱ��� ����
	int LEN = 0, PM = 0;

	scanf("%s %s", number[0],number[1]);

	//�� ���ڰ��� ���� ����
	LEN = strlen(number[0]) - strlen(number[1]);

	//A�� B���� ���ڿ��� ��� 0 ������ -1 �׸��� LEN�� ���밪���� ������ش�.
	if (LEN < 0)
	{
		//���밪
		LEN = LEN * -1;
		//LEN�� ������� ���밪���� ������ش�.
		PM = -1;
	}
	
	//���ڸ� ���ڷ� ��ȯ
	while(1)
	{
		//number1[0]�� A�� ���ڸ� ���ڷ� ��ȯ �� ����
		if (number[0][i] != NULL)
		{
			//���� B�� �� �� ���ڶ�� LEN +1 �ڸ����� ����
			if (PM == -1)
				number1[0][i + LEN + 1] = number[0][i] - 48;
			else
				number1[0][i + 1] = number[0][i] - 48;
		}
		//number1[1]�� B�� ���ڸ� ���ڷ� ��ȯ �� ����
		if (number[1][i] != NULL)
		{
			////���� A�� �� �� ���ڶ�� LEN +1 �ڸ����� ����
			if(PM == 0)
				number1[1][i + LEN+1] = number[1][i] - 48;
			else
				number1[1][i + 1] = number[1][i] - 48;
		}
		//���� ��ȯ�� �Ϸ������� �ݺ��� Ż��
		if (number[0][i] == NULL && number[1][i] == NULL)
			break;
		i++;
		j++;
	}

	//�ø� �� number1[2]�� A + B�� ���� ����
	for (; j>= 0; j--)
	{
		number1[2][j] = number1[0][j] + number1[1][j];
		//�� �ڸ����� ���� 10�� �Ѱ����� �� �ڸ����� -10�� ���ְ� �ڸ��� -1�� 1�� �ø����ش�.
		if (number1[0][j] + number1[1][j] >= 10) {
			number1[2][j] -= 10;
			number1[0][j - 1] += 1;
		}
	}
	//�� ���ڸ��� 1�̻��̸�
	if (number1[2][0] >= 1)
		i++;
	//���� ��� 
	for (int k = 0; k < i; k++) 
	{
		//�� ���ڸ��� 0�̸� �ι�° �ڸ����� ���
		if (number1[2][0] == 0)
			printf("%d", number1[2][k + 1]);
		else
			printf("%d", number1[2][k]);
	
	}
	return 0;
}