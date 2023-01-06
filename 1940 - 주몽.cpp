#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
int element_num[15000];

int solution() {
	int num_of_armor = 0;
	sort(element_num, element_num + N);

	int left_index = 0;
	int right_index = N - 1;

	while (true) {
		if (element_num[left_index] + element_num[right_index] > M) {
			right_index--;
		}
		else if (element_num[left_index] + element_num[right_index] < M) {
			left_index++;
		}
		else {
			left_index++;
			right_index--;

			num_of_armor++;
		}

		if (left_index >= right_index) break;
	}

	return num_of_armor;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	cin >> M;

	for (int i = 0; i < N; i++) {
		cin >> element_num[i];
	}
	cout << solution();
}