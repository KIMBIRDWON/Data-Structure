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
		printf("배열에 삽입할 값을 입력하시오(-1 입력 시 종료) : "); //5 20 10 30 15 40 50
		scanf("%d", &num);

		if (num > -1) {
			tournament[index] = num;
			index++;
		}
	}
	index = index - 1; //-1 입력 이전에 index++ 로 인해 배열이 하나 증가한 것을 감소시킴

	return index;
}

void makeTournament(int size, int tournament[]) {
	int index = size; //7
	int mom = 0;
	int son = 0;

	for(int i = index / 2; i >= 1; i--) { //3 2 1
		mom = i; //mom = index / 2
		//마지막 for loop에서 부모가 아래 while loop의 조건에 위반되면 for loop 종료됨
		while (mom <= index / 2) { //mom이 index / 2 보다 작아야 함(크면 단말노드임)
			if (tournament[mom * 2] > tournament[mom * 2 + 1]){ //자식 둘 중 더 큰 것의 index를 son으로 둠
				son = mom * 2;
				}
			else {
				son = mom * 2 + 1;
			}

			if (tournament[mom] < tournament[son]) { //부모와 자식을 비교해서 자식이 더 크면 swap
				swap(&tournament[mom], &tournament[son]);
				mom = son; //부모의 index를 바뀐 위치(자식의 index)로 최신화하여 자식을 추가 탐색함
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