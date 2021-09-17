#include<iostream>
#include<string>
#include<cmath>
#include<queue>
using namespace std;

/*
1. 문제 분석

 - 변수
N: 카드 묶음의 개수

 - 변수, 값에 대한 제한
카드 묶음의 개수는 1~100,000개이다.


 - 문제 상황
각 묶음의 카드의 수를 A, B라 할 때 두 묶음을 합쳐 하나로 만드는데 A + B번의 비교를 해야한다.


2. 풀이 계획
 두 묶음을 합하는데 드는 횟수는 다른 묶음과 다시 합할 때 같은 값이 다시 더해지게 된다.
 => 따라서 처음에 합해지는 값을 최대한 작게 해야한다.
 => 따라서 합하는 카드 뭉치를 선택하는 것을 하나의 동작으로 하는 그리디 알고리즘을 떠올릴 수 있다.

 또한 카드 뭉치를 합쳐서 생기는 새로운 카드 뭉치에 대해서도 고려해줘야 하므로, 새로운 값을 추가하여도 정렬된 상태를 유지하는 priority queue를 사용해야 한다!

따라서 자세한 과정은 다음과 같다.

1. 카드 묶음의 카드 수를 priority queue에 저장한다.
2. 현재까지의 합을 저장한 변수에 (현재까지의 합 + 현재 인덱스의 값)을 더한다.

3. 계획 검증
위의 풀이 계획은 그리디 알고리즘을 선택하였으므로, 이 문제에 대한 그리디 알고리즘의 정당성만 증명된다면 계획이 검증되는 것으로 볼 수 있다.
 1) 탐욕적 선택속성 증명: "가장 카드 수가 적은 카드 묶음(Smin)을 포함하는 최적해가 반드시 존재한다."는 명제를 증명해야 한다.
1. 일단, S의 최적해 중 Smin을 포함하지 않는 최적해가 있음을 가정한다.
2. Smin을 포함하지 않는 최적해에서 가장 먼저 카드 수가 적은 카드 묶음을 지우고 Smin을 추가하여 새로운 카드 정렬 순서를 만든다.
3. Smin은 S에서 가장 먼저 카드수가 가장 적은 카드 묶음이므로, 지워진 원래의 최적해에서 가장 카드수가 적은 카드 묶음보다도 카드 수가 적다.
4. 카드수가 더 적은 카드 묶음을 먼저 선택하면, 전체 정렬에 필요한 비교횟수는 줄어든다.
4. 따라서 Smin을 포함하여야만 최적해를 가질 수 있다.
 => Smin을 선택하지 않은 최적해는 존재할 수 없으므로, 가장 카드 수가 적은 카드 묶음을 선택하였을 때 최적해를 얻는 것이 불가능해지는 경우가 없음을 보여준다.

 2) 최적 부분구조
 첫번째 카드 묶음을 잘 선택였다면, 남은 카드 묶음 중 하나를 선택하는 부분 문제를 얻을 수 있는데, 이 때 또한 같은 기준을 적용하여 가장 비교횟수를 최소로 하는 것이 좋으므로 최적 부분 구조는 자명하게 성립한다.

*/

int get_min_num(priority_queue<int, vector<int>, greater<int>> num_cards, int N) {

	int min_num1, min_num2; // 각 반복에서의 최소값을 저장할 변수
	int min_num = 0;

	while (num_cards.size() != 1) {

		min_num1 = num_cards.top(); num_cards.pop();
		min_num2 = num_cards.top(); num_cards.pop();

		min_num += (min_num1 + min_num2);
		num_cards.push(min_num1 + min_num2);
	}
	return min_num;
}

int main() {

	int N; // 카드 뭉치의 수

	cin >> N;

	priority_queue<int, vector<int>, greater<int>> num_cards;

	for (int i = 0; i < N; i++) {
		int num_cards_temp;
		cin >> num_cards_temp;
		num_cards.push(num_cards_temp);
	}

	cout << get_min_num(num_cards, N);

	return 0;
}