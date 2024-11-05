#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void makeTournament(int tournamentArray[]);
void swap(int*, int*);

int main() {
	int tournamentArray[200];
	makeTournament(tournamentArray);
}
void makeTournament(int tournamentArray[]) {
	int index = 1; //index 1부터 시작
	int num; //삽입할 값
	while (1) {
		printf("\n배열에 삽입할 값을 입력하시오 : ");
		scanf("%d", &num);
		tournamentArray[index] = num;
		int i = index; //index 값 유지하기 위해 index 대신 사용할 변수 i 생성

		while (i / 2 >= 1 && tournamentArray[i / 2] < tournamentArray[i]) {
			swap(&tournamentArray[i / 2], &tournamentArray[i]);
			i = i / 2; //root까지 swap하기 위해 i 재설정
		}

		for (int i = 1; i <= index; i++) { //배열 출력
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