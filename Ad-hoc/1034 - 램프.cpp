#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

/*
1. 문제 분석
- 변수
N, M: 행의 개수, 열의 개수
K: 스위치를 누르는 횟수

- 변수 제한 사항
N, M: 1 ~ 50
K: 1,000


- 문제 상황
지민이의 탁자에 있는 램프의 상태와 K가 주어졌을 때, 스위치를 K번 누른 후에 켜져있는 행의 최댓값을 구하는 프로그램을 작성

2. 풀이 계획
일단 알아야 할 것은 각 열의 상태는 스위치를 짝수번(0번 포함) 누른 상태와 홀수번 누른 상태 두가지 밖에 없다는 것이다.

그럼에도 불구하고, 모든 열의 경우의 수를 고려하기 위해서는 2^N번(순열)의 연산이 필요하다.

따라서 시간 내에 해결할 수 없다.

그렇다면 어떻게 해결할 수 있을까?


추가적으로, 모든 열이 같이 꺼지고 켜지므로, 복잡하게 생각할 것 없이 같은 모양이어야 가능하다.

주어진 횟수로 모두 켜지게 만들 수 있는(주어진 횟수보다 적은 횟수가 필요 + 주어진 횟수와 홀 짝이 같음) 행 들 중 같은 행들의 개수를 세
이중 최대값을 구하면 될 듯 하다!

3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

#define MAX 50

int numOfZeros[MAX]; // 각 행의 0의 개수
string table[MAX];
map<string, int> numOfSameShape;

int K;
int N, M;

int solution() {
    int answer = 0;

    for (int i = 0; i < N; i++) {
        // 모두 켤 수 있는 행에 대해서만 연산
        if (numOfZeros[i] <= K && numOfZeros[i] % 2 == K % 2) {
            numOfSameShape[table[i]]++;
        }
    }

    map<string, int>::iterator it;
    for (pair<string, int> cur_pair : numOfSameShape) {
        answer = max(answer, cur_pair.second);
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> table[i];

        // 각 행의 0의 개수 세기
        for (int j = 0; j < M; j++)
            if (table[i][j] == '0') numOfZeros[i]++;
    }

    cin >> K;

    cout << solution();
}