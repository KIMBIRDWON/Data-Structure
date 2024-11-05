# Data-structure

수업시간에 배운 토너먼트 방식으로 최대값을 구하는 방법에 배열이 사용될 경우 n개의 입력데이터에 대해 2n+1개의 공간이 필요하다. 공간을 절약하기 위해 n개의 공간만 필요한 변경된 토너먼트 방식을 구현하고자 한다.

수업시간에 배운 토너먼트와 마찬가지로 2진 트리 형태가 되며, 배열 1번, 즉 루트에 최대값을 갖는다. 이를 위해, 입력은 배열의 1번 인덱스부터 하나씩 증가하며 순차적으로 이루어지며, 1번에 최대값을 유지하기 위해 부모 노드와 비교하여 현재 입력된 데이터가 그 부모보다 크다면 부모와 자리 바꿈을 하고 루트까지 이를 반복한다.

*** 요구사항
토너먼트 배열은 makeTournament 함수에서 만들어지고, 배열은 main에서 선언되어 매개변수로 makeTournament 함수로 전달되며, tournament 배열의 실제 크기를 확인하여 출력하여야 한다.

int main(){
    int tournamentArray[200];
    makeTournament(tournamentArray);
}

*** 인덱스 i의 부모 : i/2

입력 : 10, 20, 5, 30, 15, 40

결과 :
[10]

[20] [10]

[20] [10] [5]

[30] [20] [5] [10]

[30] [20] [5] [10] [15]

[40] [20] [30] [10] [15] [5]
