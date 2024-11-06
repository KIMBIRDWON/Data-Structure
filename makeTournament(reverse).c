#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int read_Data(int tournament[]);
void makeTournament(int size, int tournament[]);
void swap(int* x, int* y);

int main() {
	int size;
	int tournament[200] = { 0 };
	size = read_Data(tournament);
	makeTournament(size, tournament);
}

int read_Data(int tournament[]) {
	int index = 1;
	int num = 0;

	while (num != -1) {
		printf("�迭�� ������ ���� �Է��Ͻÿ�(-1 �Է� �� ����) : "); //5 20 10 30 15 40 50
		scanf("%d", &num);

		if (num > -1) {
			tournament[index] = num;
			index++;
		}
	}
	index = index - 1; //-1 �Է� ������ index++ �� ���� �迭�� �ϳ� ������ ���� ���ҽ�Ŵ

	return index;
}

void makeTournament(int size, int tournament[]) {
	int index = size; //7
	int mom = 0;
	int son = 0;

	for(int i = index / 2; i >= 1; i--) { //3 2 1
		mom = i; //mom = index / 2
		//������ for loop���� �θ� �Ʒ� while loop�� ���ǿ� ���ݵǸ� for loop �����
		while (mom <= index / 2) { //mom�� index / 2 ���� �۾ƾ� ��(ũ�� �ܸ������)
			if (tournament[mom * 2] > tournament[mom * 2 + 1]){ //�ڽ� �� �� �� ū ���� index�� son���� ��
				son = mom * 2;
				}
			else {
				son = mom * 2 + 1;
			}

			if (tournament[mom] < tournament[son]) { //�θ�� �ڽ��� ���ؼ� �ڽ��� �� ũ�� swap
				swap(&tournament[mom], &tournament[son]);
				mom = son; //�θ��� index�� �ٲ� ��ġ(�ڽ��� index)�� �ֽ�ȭ�Ͽ� �ڽ��� �߰� Ž����
			}
		}
		for (int j = 1; j <= index; j++) {
			printf("%d ", tournament[j]);
		}
		printf("\n");
	}
}

void swap(int* x, int* y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}