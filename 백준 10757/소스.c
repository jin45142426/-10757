#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
//문자열 길이
#include<string.h>

int main()
{
	//number = A 와 B를 입력받는 변수
	char number[2][10050] = { NULL };
	//number1[0] = A , number1[1] = B, number1[2] = A + B
	int number1[3][10050] = { 0 };
	
	//i,j 는 number1에 저장된 숫자들의 개수
	int i = 0, j = 0;
	//LEN은 A와 B의 문자길이 차이
	int LEN = 0, PM = 0;

	scanf("%s %s", number[0],number[1]);

	//두 문자간의 길이 차이
	LEN = strlen(number[0]) - strlen(number[1]);

	//A가 B보다 문자열이 길면 0 작으면 -1 그리고 LEN을 절대값으로 만들어준다.
	if (LEN < 0)
	{
		//절대값
		LEN = LEN * -1;
		//LEN이 음수라면 절대값으로 만들어준다.
		PM = -1;
	}
	
	//문자를 숫자로 변환
	while(1)
	{
		//number1[0]에 A의 문자를 숫자로 변환 후 저장
		if (number[0][i] != NULL)
		{
			//만약 B가 더 긴 숫자라면 LEN +1 자리부터 저장
			if (PM == -1)
				number1[0][i + LEN + 1] = number[0][i] - 48;
			else
				number1[0][i + 1] = number[0][i] - 48;
		}
		//number1[1]에 B의 문자를 숫자로 변환 후 저장
		if (number[1][i] != NULL)
		{
			////만약 A가 더 긴 숫자라면 LEN +1 자리부터 저장
			if(PM == 0)
				number1[1][i + LEN+1] = number[1][i] - 48;
			else
				number1[1][i + 1] = number[1][i] - 48;
		}
		//문자 변환을 완료했으면 반복문 탈출
		if (number[0][i] == NULL && number[1][i] == NULL)
			break;
		i++;
		j++;
	}

	//올림 및 number1[2]에 A + B의 값을 저장
	for (; j>= 0; j--)
	{
		number1[2][j] = number1[0][j] + number1[1][j];
		//각 자릿수별 합이 10을 넘겼으면 그 자릿수에 -10을 해주고 자릿수 -1에 1을 올림해준다.
		if (number1[0][j] + number1[1][j] >= 10) {
			number1[2][j] -= 10;
			number1[0][j - 1] += 1;
		}
	}
	//맨 앞자리가 1이상이면
	if (number1[2][0] >= 1)
		i++;
	//숫자 출력 
	for (int k = 0; k < i; k++) 
	{
		//맨 앞자리가 0이면 두번째 자리부터 출력
		if (number1[2][0] == 0)
			printf("%d", number1[2][k + 1]);
		else
			printf("%d", number1[2][k]);
	
	}
	return 0;
}