#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;

void solution() {
	// 각 값들의 정렬된 배열에서의 위치와 값을 연결해주기 위한 pair 배열
	vector<pair<int, int>> array_map;
	vector<int> A;

	// A 배열 입력받기
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		A.push_back(temp);
	}

	// 정렬되지 않은 상태 저장해놓기
	vector<int> unordered_A = A;

	// 정렬
	sort(A.begin(), A.end());

	// 정렬된 배열에서의 인덱스와 값 연결해놓기
	for (int i = 0; i < N; i++) {
		array_map.push_back(make_pair(i, A[i]));
	}

	// 정렬되지 않은 원본 배열의 값을 array_map에서 찾기
	for (int item : unordered_A) {
		for (int i = 0;i < array_map.size();i++) {
			if (array_map[i].second == item) {
				cout << array_map[i].first << " ";
				// 중복된 값이 다시 찾아지는 것을 막기 위해 지워주기
				array_map.erase(array_map.begin() + i);
				break;
			}
		}
	}

}

int main() {
	cin >> N;

	solution();
}
