#include<iostream>
#include<vector>
using namespace std;

int N;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void next_permutation(vector<int> curPermutation) {
	int length = curPermutation.size();
	vector<int>nextPermutation(curPermutation);
	int firstIndex = -1;
	int secondIndex = -1;

	// 1. ﻿arr[k] < arr[k + 1]을 만족하는 가장 큰 k를 구합니다.﻿
	for (int k = length - 2; k >= 0; --k) {
		if (nextPermutation[k] < nextPermutation[k + 1]) {
			firstIndex = k;
			break;
		}
	}

	// k 를 찾지 못하면 현재 순열이 마지막 순열입니다.
	if (firstIndex == -1) {
		cout << -1;
		return;
	}

	// ﻿2. arr[k] < arr[i]를 만족하는 가장 큰 i를 구합니다.﻿
	int i = length - 1;
	while (true) {
		if (nextPermutation[i] > nextPermutation[firstIndex]) {
			secondIndex = i;
			break;
		}
		i--;
	}
	
	// 3. arr[k]와 arr[i]를 바꿉니다.
	swap(nextPermutation[firstIndex], nextPermutation[secondIndex]);

	// 4. ﻿k + 1 위치부터 끝 위치까지, 즉 arr[k + 1] ~ arr[N]까지를 서로 교환합니다.(좌우반전)﻿
	int left = firstIndex + 1;
	int right = length - 1;
	while (left < right) {
		swap(nextPermutation[left], nextPermutation[right]);
		left++;
		right--;
	}

	// 모든 처리가 끝난 순열 출력
	for (int i = 0; i < length; i++) {
		cout << nextPermutation[i] << " ";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> curPermutation;

	cin >> N;

	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		curPermutation.push_back(temp);
	}

	next_permutation(curPermutation);
}
