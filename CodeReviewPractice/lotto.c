// �ǽ����� �ߴ� �Ͱ��� ���� �ٸ��� ���� �������� �����ϰ� ��. ���� : ���� �ʹ� ���� ����

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void check(int a[6], int b[][6], int c)
{
	for (int i = 0; i < 5; i++)
	{
		printf("%d��Ʈ ��ȣ<%d %d %d %d %d %d>", i + 1, b[i][0], b[i][1], b[i][2], b[i][3], b[i][4], b[i][5]);
		int sum = 0;
		for (int j = 0; j < 6; j++)
		{
			if (b[i][j] == a[0] || b[i][j] == a[1] || b[i][j] == a[2] || b[i][j] == a[3] || b[i][j] == a[4] || b[i][j] == a[5])
			{
				printf("%d ", b[i][j]);
			}
			else
			{
				printf("X ");
				sum++;
			}
		}
		if (sum == 1 && (b[i][0] == a[6] || b[i][1] == a[6] || b[i][2] == a[6] || b[i][3] == a[6] || b[i][4] == a[6] || b[i][5] == a[6]))
		{
			printf("+ %d ", a[6]);
			sum++;
		}
		if (sum == 0)
			printf("1��");
		else if (sum == 1)
			printf("3��");
		else if (sum == 2)
			printf("2��");
		else if (sum == 3)
			printf("4��");
		else if (sum == 4)
			printf("5��");
		else
			printf("��");
		printf("\n");
	}

}
void Sorting(int(*b)[6])
{
	int temp = 0;

	for (int k = 0; k < 5; ++k) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < (6 - i) - 1; j++) {
				if (b[k][j] > b[k][j + 1]) {
					temp = b[k][j];
					b[k][j] = b[k][j + 1];
					b[k][j + 1] = temp;
				}
			}
		}
	}
}
int main(void)
{
	int a[7];
	int b[5][6];
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			b[i][j] = rand() % 45 + 1;
			for (int k = 0; k < j; k++)
			{
				if (b[i][j] == b[i][k])
					j--;
			}
		}
	}
	Sorting(b);
	printf("������ �ζ� ��ȣ�� �Է��ϼ��� -> ");
	scanf("%d%d%d%d%d%d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5]);
	printf("���ʽ� ��ȣ�� �Է��ϼ��� -> ");
	scanf("%d", &a[6]);
	check(a, b, 6);
	return 0;
}
