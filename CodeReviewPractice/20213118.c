#include <stdio.h>
int main() {
	int right=0;
	int bonusright = 0;
	int reallotto[7];
	int check = 0;
	int honglotto[5][6] = {
	{1,2,3,4,5,6},
	{10,15,25,35,40,42},
	{1,9,11,22,23,25},
	{9,28,31,34,35,36},
	{1,9,23,28,33,35}};
	printf("������ �ζ� ��ȣ�� �Է��ϼ���:");

	for (int i = 0; i < 6; i++) {
		scanf("%d", &reallotto[i]);
	}
	printf("\n���ʽ� ��ȣ�� �Է��ϼ���:");
	scanf("%d", &reallotto[6]);
	/*for (int i = 0; i < 6; i++) { �ζ� �Է� ��ȣ Ȯ�ο�
		printf("%d\n", reallotto[i]);
	}*/
	printf("\nȫ�浿���� �ζ� ��÷ ����Դϴ�.\n\n");
	for (int i = 0; i < 5; i++) {                         //��Ʈ ��ȣ ����
		for (int j = 0; j < 6; j++)						  //��Ʈ �������� ȫ�浿 ��ȣ ����
		{
			for (int k = 0; k < 6; k++){					  //��Ʈ �������� ȫ�浿 ��ȣ���� ������ �ζǳѹ��� �´��� üũ����
				if (honglotto[i][j] == reallotto[k])
				{
					right += 1;
				}
			}
			if (honglotto[i][j] == reallotto[6])
				{
				bonusright += 1;
				}
			
		}
		printf("%d��Ʈ ��ȣ<",i+1);
		for (int j = 0; j < 6; j++) {
			printf("%d ", honglotto[i][j]);
		}
		printf("> -> ");
		for (int j = 0; j < 6; j++)						  //��Ʈ �������� ȫ�浿 ��ȣ ����
		{
			for (int k = 0; k < 6; k++) {					  //��Ʈ �������� ȫ�浿 ��ȣ���� ������ �ζǳѹ��� �´��� üũ����
				if (honglotto[i][j] == reallotto[k])
				{
					check += 1;
				}
				
			}
			if (check == 1) {
				printf("%d ", honglotto[i][j]);
			}
			else {
				if (bonusright == 1 && right == 5)
					printf("%d ", honglotto[i][j]);
				else
					printf("x ");
			}
			check = 0;
		}
		if (right == 6) {
			printf("1��\n");
		}
		else if (right + bonusright == 6) {
			printf("2��\n");
		}
		else if (right == 5&& bonusright==0) {
			printf("3��\n");
		}
		else if (right == 4) {
			printf("4��\n");
		}
		else if (right == 3) {
			printf("5��\n");
		}
		else {
			printf("��\n");
		}
		//printf("right:%d, bonusright:%d\n", right, bonusright); right, bonusright ������
		
		right = 0;
		bonusright = 0;
	}
	return 0;
}