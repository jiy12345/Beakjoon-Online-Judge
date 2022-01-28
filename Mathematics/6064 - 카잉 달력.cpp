#include<iostream>
using namespace std;

/*
1. 문제 분석
- 변수
<M:N>: 카잉 달력의 마지막 해
<x:y>: 연도를 알아내려는 해

- 변수 제한 사항
N, M: 1~40,000
x: 1~M
y: 1~N

- 문제 상황
  첫 번째 해: <1:1>
  두 번째 해: <2:2>
  <x:y>의 다음 해: <x':y'>  x < M 이면 x' = x + 1이고, 그렇지 않으면 x' = 1
                           y < N 이면 y' = y + 1이고, 그렇지 않으면 y' = 1
  <M:N>: 달력의 마지막 해

2. 풀이 계획

현재의 연도를 정수로 표현한 값을 k라 할 때,

 현재의 x값은 k를 M으로 나눈 나머지
 현재의 y값은 k를 N으로 나눈 나머지

 M:N은 MxN이다!

 따라서 MxN 이내에 

 k를 M으로 나눈 나머지가 x가 되며, k를 N으로 나눈 나머지가 y가 되는 k를 구하는 것이 목표라고 할 수 있다!

3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

int M, N;
int x, y;

int gcd(int a, int b) {
	if (a < b) swap(a, b);
	
	int n;

	while (b != 0) {
		n = a % b;
		
		a = b;
		b = n;
	}
	return a;
}

int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

int solution() {
	if (y == N) y = 0;
	int maxNum = lcm(M, N);

	for (int i = x; i <= maxNum; i += M)
		if (i % N == y) return i;
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;

	cin >> T;
	
	for (int i = 0; i < T; i++) {
		cin >> M >> N >> x >> y;

		cout << solution() << '\n';
	}

}