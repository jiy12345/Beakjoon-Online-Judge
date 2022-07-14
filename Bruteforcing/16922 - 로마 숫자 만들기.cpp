#include<iostream>
using namespace std;

/*
1. 문제 분석
- 변수
N: 사용할 수 있는 문자의 개수

- 변수 제한 사항
N: 1 ~ 20
I, V, X, L을 사용한다. 각 문자는 1, 5, 10, 50을 의미

- 문제 상황
문자열이 나타내는 값은, 각 문자가 의미하는 수를 모두 합한 값이라 할 때,

로마 숫자 N개를 사용하여 만들 수 있는 서로 다른 수의 개수를 출력하라

2. 풀이 계획
 중복 조합 문제로 볼 수 있다.
 
 => 어차피 수들을 다 합하는 것이므로, 정수의 덧셈은 교환법칙이 성립하므로, 굳이 순서만 다른 경우를 고려하지 않아도 된다!

 순서 상관 없이 중복되도록 N개의 수를 뽑은 후, 같은 수를 체크하기 위해 방문 표시를 진행하면 될 듯 하다.
  => 나올수 있는 값의 최대값은 50(L) x 20(N의 최대값) = 1,000이므로, 1,000크기의 배열을 만들어 체크하면 될 듯 하다.

3. 계획 검증
 1. 알고리즘 측면

 2. 시간복잡도 측면

 3. 공간복잡도 측면
*/

int N;

int romanNum[4] = { 1, 5, 10, 50 };
bool isVisited[20 * 50 + 1];

int perm_comb(int curIndex, int curPicked, int curSum) {
	int answer = 0;
	if (curPicked == N) {
		if (isVisited[curSum] == false) {
			isVisited[curSum] = true;
			return 1;
		}
		return 0;
	}

	for (int i = curIndex; i < 4; i++) {
		answer += perm_comb(i, curPicked + 1, curSum + romanNum[i]);;
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	cout << perm_comb(0, 0, 0);
}