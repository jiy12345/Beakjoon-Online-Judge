#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int get_max_num(vector<int> num_sequence, int N) {
	
	// 배열을 오름차순으로 정렬한다.
	sort(num_sequence.begin(), num_sequence.end());

	int max_num = 0; // 합한 최대값을 저장할 변수 
	int index = 0;
	
	vector<int> minus_sequence;
	vector<int> plus_sequence;

	int center_index = -1; // 1이상의 최소값이 저장된 위치를 보여주는 변수

	// 음수 -> 양수인 위치 찾기
	while (true) {
		if (index == N || num_sequence[index] > 0) {
			// 음수부(0포함)와 양수부로 나누어주기
			minus_sequence = vector<int>(num_sequence.begin(), num_sequence.begin() + index);
			plus_sequence = vector<int>(num_sequence.begin()+index, num_sequence.end());
			break;
		}
		index++;
	}

	// 음수 수열 더하기
	for (int i = 0; i < minus_sequence.size(); i+=2) {
		if (i + 1 == minus_sequence.size()) { // 끝에 하나만 남은경우에 하나만 더하기
			max_num += minus_sequence[i];
		}
		else { // 나머지 경우에는 두개씩 묶기
			max_num += (minus_sequence[i] * minus_sequence[i + 1]);
		}
	}


	// 양수 수열 더하기
	for (int i = plus_sequence.size() - 1; i >= 0; i -= 2) {
		if (i - 1 == -1) { // 끝에 하나만 남은경우에 하나만 더하기
			max_num += plus_sequence[i];
		}
		else { // 나머지 경우에는 두개씩 묶기
			if (plus_sequence[i - 1] == 1) { // 끝 수가 1일 경우에는 곱하는 것보다는 더하는게 더 크다!
				max_num += (plus_sequence[i] + plus_sequence[i - 1]);
			}
			else {
				max_num += (plus_sequence[i] * plus_sequence[i - 1]);
			}
		}
	}

	return max_num;
}

int main() {

	int N; // 수열의 크기

	cin >> N;

	// 수열의 크기에 맞게 배열 동적할당
	vector<int> num_sequence;

	// 수열의 각각의 값 입력받기
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		num_sequence.push_back(temp);
	}

	cout << get_max_num(num_sequence, N);

	return 0;
}
