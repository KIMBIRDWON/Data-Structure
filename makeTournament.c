#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void makeTournament(int tournamentArray[]);
void swap(int*, int*);

int main() {
	int tournamentArray[200];
	makeTournament(tournamentArray);
}
void makeTournament(int tournamentArray[]) {
	int index = 1; //index 1���� ����
	int num; //������ ��
	while (1) {
		printf("\n�迭�� ������ ���� �Է��Ͻÿ� : ");
		scanf("%d", &num);
		tournamentArray[index] = num;
		int i = index; //index �� �����ϱ� ���� index ��� ����� ���� i ����

		while (i / 2 >= 1 && tournamentArray[i / 2] < tournamentArray[i]) {
			swap(&tournamentArray[i / 2], &tournamentArray[i]);
			i = i / 2; //root���� swap�ϱ� ���� i �缳��
		}

		for (int i = 1; i <= index; i++) { //�迭 ���
			printf("[%d] ", tournamentArray[i]);
		}
		index++;
	}
}
void swap(int* x, int* y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
//2024.11.06. KIMSEWON