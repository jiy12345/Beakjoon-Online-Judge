#include<iostream>
#include<vector>
#include<sstream>
#include<deque>
using namespace std;

void solution(int T) {

	// 1. 들어온 값 벡터에 받기
	for (int i = 0; i < T; i++) {
		bool is_reversed = false; // true면 뒤집힌 것!
		int j;

		// AC 입력받기
		string AC;
		cin >> AC;

		deque<int> num_array;

		int n;
		cin >> n;

		string num_array_string;
		cin >> num_array_string;

		num_array_string = num_array_string.substr(1, num_array_string.size() - 2); // 대괄호 제거
		
		stringstream sstream(num_array_string);
		string word;


		if (!num_array_string.empty()) {
			while (getline(sstream, word, ','))
			{
				num_array.push_back(stoi(word));
			}
		}


		for (j = 0; j < AC.size(); j++) {
			if (AC[j] == 'R') {
				is_reversed = !is_reversed;
			}
			else if(AC[j] == 'D') {
				if (num_array.empty()) { // D가 나왔는데 배열이 비어있을 경우 error
					cout << "error" << endl;
					break;
				}
				if (is_reversed) { // 뒤집힌 상태일 경우
					//cout << "pop_front" << endl;
					num_array.pop_back();
				}
				else { // 똑바른 상태일 경우
					//cout << "pop_back" << endl;
					num_array.pop_front();
				}
			}
		}

		if (j != AC.size()) { // 반복문을 끝까지 돌지 않았을 경우 = error가 중간에 발생했을 경우 => 출력하지 않음
			continue;
		}

		int array_size = num_array.size();

		if (is_reversed) { // 뒤집혀있을 경우 뒤부터 출력
			cout << "[";
			for (j = 0; j < array_size; j++) {
				if (j == array_size - 1) {
					cout << num_array[array_size - (j + 1)];
					break;
				}
				else {
					cout << num_array[array_size - (j + 1)]<<",";
				}
			}
			cout << "]" << endl;
		}
		else { // 뒤집히지 않아있을 경우 앞부터 
			cout << "[";
			for (j = 0; j < array_size; j++) {
				if (j == array_size - 1) {
					cout << num_array[j];
					break;
				}
				else {
					cout << num_array[j] << ",";
				}
			}
			cout << "]" << endl;
		}
	}
}

int main() {
	int T; // 테스트 케이스의 수

	cin >> T;

	solution(T);

	return 0;
}
