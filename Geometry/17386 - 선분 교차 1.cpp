#include<iostream>
#include<utility>
using namespace std;

/*
1. 문제 분석
- 변수
L1, L2: 두개의 선분
L1의 양 끝 점은 (x1, y1), (x2, y2)
L2의 양 끝 점은 (x3, y3), (x4, y4)

- 변수 제한 사항
-1,000,000 ≤ x1, y1, x2, y2, x3, y3, x4, y4 ≤ 1,000,000
x1, y1, x2, y2, x3, y3, x4, y4는 정수

- 문제 상황
두개의 선분의 양 끝점들이 주어질 때, 두 선이 교차하는지 판정하라

2. 풀이 계획y1
일단 x 구간이 겹치는지부터 체크한다.

=> 그러려면 각 점들의 위치관계 부터 정리되어야 한다.
=> 모든 조건을 다 체크하려면 4개를 순서에 상관있게 배치해야 하므로, 4! = 24이다!

1. 겹치는 범위를 확인
L1의 우측과 L2의 좌측을 비교하고,
L2의 우측과 L1의 좌측을 비교하여, 
두 경우 모두 우측이 커야지만 겹쳐있다고 볼 수 있다.

2. 대상이 되는 범위 구하기
L1의 우측과 L2의 우측 비교하여 더 작은 값 저장
L1의 좌측과 L2의 우측 비교하여 더 큰 값 저장


3. 겹치는지 여부 확인
두 선분의 공식을 각각 구하고, 두 선분의 공식간의 뺄셈을 진행한 후, 앞서 구해놓은 왼쪽 끝과 오른쪽 끝을 대입한 후, 두 값을 곱하여 0보다 작거나 같은지 확인한다!



3. 계획 검증
*/


long long x1, y_1, x2, y2, x3, y3, x4, y4;

int ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
    int result = x1*y2+x2*y3+x3*y1;
	result = result - y1 * x2 - y2 * x3 - y3 * x1;
	if (result > 0) {
		return 1;
	}
	else if (result < 0) {
		return -1;
	}
	else {
		return 0;
	}
}

int solution(){

	int result1 = ccw(x1, y_1, x2, y2, x3, y3);
	int result2 = ccw(x1, y_1, x2, y2, x4, y4);
	int result3 = ccw(x3, y3, x4, y4, x1, y_1);
	int result4 = ccw(x3, y3, x4, y4, x2, y2);
	
	// 한 선분에서 다른 선분의 양 끝점까지의 방향이 서로 달라야!
	if (result1 * result2 < 0 && result3 * result4 < 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	cin >> x1 >> y_1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;

	cout << solution();
}