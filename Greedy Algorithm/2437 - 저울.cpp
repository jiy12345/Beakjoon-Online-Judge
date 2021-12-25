#include<iostream>
#include<algorithm>
using namespace std;

/*
1. 문제 분석

- 변수
N: 저울추의 개수

- 변수 제한 사항
N: 1~1,000
추의 무게: 1~1,000,000

 - 문제 상황
 추의 무개들이 주어졌을 때, 이 추들을 사용하여 측정할 수 없는 양의 정수 무게 중 최소값을 구하여라

2. 풀이 계획
이걸 어떻게 정렬해야 할까?

중복해서 뽑을 수 없고 순서가 상관 없으므로 조합 문제이긴 한데, 그렇다고 모든 조합을 다 구하기에는 2^N으로 지수적 시간복잡도를 보이므로 그렇게 구할 수는 없다.

그렇다면 어떻게?

정렬한 상태에서 누적합보다 크다면, 

Sn:

3. 계획 검증


*/


int N;
int weight[1000];


int solution() {
	sort(weight, weight + N);

	int cur_sum = 0;

	for (int i = 0; i < N; i++) {
		if (cur_sum + 2 <= weight[i]) {
			break;
		}

		cur_sum += weight[i];
	}
	
	return cur_sum + 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> weight[i];
	}

	cout << solution()';

	return 0;
}