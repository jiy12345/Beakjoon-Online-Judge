#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int ATM_min(int N, vector<int> time) {
	int min = 0; // 최소값을 저장할 변수

	// 2. 정렬함수를 통해 배열 정렬
	sort(time.begin(), time.end());

	for (int i = 0; i < N; i++) {
		min += time[i] * (time.size() - i);
	}

	return min;
}

int main() {
	int N; // ATM에 줄 서있는 사람의 수
	
	int temp_time;
	vector<int> time; // 사람들이 인출에 걸리는 시간을 받을 벡터

	int min = 0; // 최소값을 저장할 변수

	cin >> N;

	// 1. 들어온 값 벡터에 받기
	for (int i = 0; i < N; i++) {
		cin >> temp_time;
		time.push_back(temp_time);
	}

	min = ATM_min(N, time);

	cout << min;
	return 0;
}
