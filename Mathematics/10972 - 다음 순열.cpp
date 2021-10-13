#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int N;

void next_permutation() {
	// 순열 입력받기
	vector<int> arr;

	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		arr.push_back(temp);
	}
	
	// 1짜리 순열은 항상 마지막 위치의 순열이므로, 무조건 -1 출력하고 끝내기
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

	// 모든 처리가 끝난 순열 출력
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
}

int main() {
	cin >> N;

	next_permutation();
}
