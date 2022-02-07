#include<iostream>
#include<cmath>
#include<vector>
using namespace std;


/*
1. 문제 분석
- 변수
N: 1부터 N까지의 수로 이루어진 순열을 구하기 위한 범위

- 변수 제한 사항
N: 1~10,000

- 문제 상황
 입력으로 주어진 순열의 다음 순열을 출력한다.

2. 풀이 계획

일단 10,000이 입력의 최대 크기이므로, 무작정 처음부터 돌리는 것은 불가능하다.

따라서 다음 순열을 실제 구해야 하는데, 다음 순열이라는 것은 어떻게 표현할까?

=> 정렬되는 과정이라고 볼 수도 있겠다.

3. 계획 검증


*/

int N;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void prev_permutation(vector<int> curPermutation) {
	int length = curPermutation.size();
	int firstIndex = -1;
	int secondIndex = - 1;

	// 1. arr[k] > arr[k + 1]을 만족하는 가장 큰 k를 구한다.
	for (int k = length - 2; k >= 0; --k) {
		if (curPermutation[k] > curPermutation[k + 1]) {
			firstIndex = k;
			break;
		}
	}

	// i를 찾지 못하면 현재 순열이 마지막 순열이다.
	if (firstIndex == -1) {
		cout << -1;
		return;
	}

	// 2. i >= 1인 i중 arr[k] < arr[i]를 만족하는 가장 큰 i 구한다.
	for (int i = length - 1; i >= 1; --i) {
		if (curPermutation[i] < curPermutation[firstIndex]) {
			secondIndex = i;
			break;
		}
	}

	// 3. arr[k]와 arr[i]를 바꾼다.
	swap(curPermutation[firstIndex], curPermutation[secondIndex]);

	// 4. k 다음 위치부터, 즉 arr[k + 1] ~ arr[end]의 값들을 뒤집는다(좌우반전)
	int left = firstIndex + 1;
	int right = length - 1;

	while (left < right) {
		swap(curPermutation[left], curPermutation[right]);
		left++;
		right--;
	}

	// 모든 처리가 끝난 순열 출력
	for (int i = 0; i < length; i++) {
		cout << curPermutation[i] << " ";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	// 순열 입력받기
	vector<int> curPermutation;

	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		curPermutation.push_back(temp);
	}

	prev_permutation(curPermutation);
}