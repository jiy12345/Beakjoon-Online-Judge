#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

/*
1. 문제 분석
- 변수
N: 순열을 구성하는 수의 개수

- 변수 제한 사항
N: 1~10,000

- 문제 상황
 순열 하나가 주어질 때, 그 다음에 위치할 순열을 출력하라


2. 풀이 계획
수의 개수가 10,000개이므로, 전체를 해보는 것은 10,000! 가지의 경우의 수가 있으므로 불가능할 듯 보인다.

따라서 규칙성을 찾아 이전 순열만 보고 그다음 순열을 찾을 수 있는 방법을 구해야 한다!

다음 순열을 어떻게 구해야할 지 떠오르지 않아 곤란했는데, 이미 존재하는 알고리즘이 있었다.

그 알고리즘은 다음과 같다.

1. arr[k] < arr[k+1]을 만족하는 가장 큰 k를 구한다.
2. k 다음 위치부터 arr[k] < arr[i]를 만족하는 가장 큰 i를 구한다.
3. arr[k]와 arr[i]를 바꾼다.
4. k 다음 위치부터, arr[k+1] ~ arr[end]의 값들을 뒤집는다(좌우반전)


3. 계획 검증

*/

int N;

void next_permutation() {
	// 순열 입력받기
	vector<int> arr;

	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	if (N == 1) {
		cout << -1;
		return;
	}

	int k = N - 2;
	// 1. arr[k] < arr[k+1]을 만족하는 가장 큰 k를 구한다.
	while (arr[k] > arr[k + 1]) {
		if (k == 0) {
			// 반대로 정렬되어 있을 경우 -1 출력
			cout << -1;
			return;
		}
		k--;
	}

	int i = N - 1;
	while (arr[k] > arr[i]) {
		i--;
		if (i == k + 1) {
			break;
		}
	}

	// 3. arr[k]와 arr[i]를 바꾼다.
	temp = arr[k];
	arr[k] = arr[i];
	arr[i] = temp;

	// 4. k 다음 위치부터, arr[k + 1] ~arr[end]의 값들을 뒤집는다(좌우반전)
	for (int i = 1; i < (int)floor((N - k - 1)/2) + 1; i++) {
		temp = arr[k + i];
		arr[k + i] = arr[N - i];
		arr[N - i] = temp;
	}

	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
}

int main() {
	cin >> N;

	next_permutation();
}