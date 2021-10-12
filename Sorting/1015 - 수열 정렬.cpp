#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

/*
1. 문제 분석
- 변수
N: 배열의 크기

- 변수 제한 사항
N: 1~50
배열의 원소: 1~1,000

- 문제 상황
 수열 P를 배열 A에 적용한 배열 B는

 B[P[i]] = A[i]

 비내림차순: 바로 앞의 원소와 같을 수도 있는 오름차순

 배열 A가 주어졌을 때, 수열 P를 적용한 결과가 비내림차순으로 정렬되도록하는 수열 P를 구하라



2. 풀이 계획

따라서 자세한 계획은 다음과 같다.

1. 배열을 입력받은 후 정렬한다. 매칭한 배열을 활용하기 위해 현재 배열의 상태는 유지한다.
2. 정렬한 내용을 유지하고, 정렬한 내용을 각 인덱스와 매칭하여 맵으로 만든다.
3. 맵을 각 키를 원래 입력된 배열의 순서대로 집어넣는다.



3. 계획 검증

*/

int N;

void solution() {
	map<int, int> array_map;
	vector<int> A;

	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		A.push_back(temp);
	}

	vector<int> unordered_A = A;

	sort(A.begin(), A.end());

	for (int i = 0; i < N; i++) {
		array_map[A[i]] = i;
	}


	for (int i : unordered_A) {
		cout << array_map[i] << " ";
	}

}

int main() {
	cin >> N;

	solution();
}