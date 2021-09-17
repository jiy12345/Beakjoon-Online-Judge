#define _CRT_SECURE_NO_WARNINGS
#include<unordered_map>
#include<iostream>
using namespace std;

/*
1. 문제 분석

- 변수
N: 숫자 카드의 개수
M: 정수의 개수

- 변수 제한
1 <= N, M <= 500,000
-10,000,000 <= 숫자 카드에 적힌 수, 찾아야할 수 <= 10,000,000


- 문제 상황
첫째 줄에 입력으로 주어진 N개의 수에 대해 셋째 줄에 입력된 각 수가 적힌 숫자카드를 몇개 가지고 있는지 공백으로 구분하여 출력한다


2. 풀이 계획
 문제를 읽었을 때 C++의 unordered_map 자료구조를 사용하면 되겠다는 생각이 먼저 들었다.

map을 사용할 수도 있지만 map은 Binary Search Tree로 구현되므로 탐색 시간복잡도가 조금 더 높기 때문에 시간초과가 발생할 수 있겠다는 생각을했다.

따라서 자세한 과정은 다음과 같다.

1. 각 숫자를 하나씩 읽으며 입력되는 숫자를 키로하여 들어올 때마다 해당 키의 값을 하나 증가시킨다.
2. 입력된 각 숫자를 키로 하는 값을 하나씩 출력한다.

3. 문제 검증
 단순한 개수를 세는 문제이므로 알고리즘상의 문제는 딱히 없어보인다.

 시간복잡도 측면을 살펴보면, 탐색 시간복잡도가 logN인 map 자료구조에 비해 unordered_map은 hashtable을 사용하여 탐색시간 복잡도가 O(1)이다.

따라서 O(NlogN)의 시간복잡도를 가져 가장 큰 입력 크기(500,000)일때 시간초과가 발생할 수도 있는 map 자료구조에 비해,
un_orderedmap을 사용하면 O(N)의 시간복잡도를 가져 안정적으로 동작할 것으로 보인다.
(시간복잡도의 계산은 물론 입력할 때 N회, 출력할 때 M회의 탐색이 있지만, 2가 곱해져봐야 상수이므로 무시하였다.)

*/

void solution() {
	int N, M;
	int temp; // 입력을 받기 위한 임시 변수
	unordered_map<int, int> num_cards;

	cin >> N;

	for (int i = 0;i < N;i++) {
		scanf("%d", &temp);
		num_cards[temp]++;
	}

	cin >> M;

	for (int i = 0;i < M;i++) {
		scanf("%d", &temp);
		printf("%d ", num_cards[temp]);
	}
}

int main() {

	solution();

	return 0;
}