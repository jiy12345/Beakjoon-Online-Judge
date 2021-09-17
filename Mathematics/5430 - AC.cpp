#include<iostream>
#include<vector>
#include<sstream>
#include<deque>
using namespace std;

/*
1. 문제 분석

 - 변수
T: 테스트 케이스의 개수
p: 각 테스트 케이스가 수행할 함수
n: 배열에 있는 수의 개수


- 변수 제한 사항
1 <= T <= 100
1 <= pd의 길이 <= 100,000   => 따라서 매번 뒤집는 것에는 무리가 있어보인다1
1 <= n <= 10,000

p의 길이의 합과 nd의 합은 700,000을 넘지 않음

 - 문제 상황
AC에서 R은 배열 숫자의 순서를 뒤집고, D는 첫번째 숫자를 버린다! 배열이 비어있는데 D를 사용하면 오류가 발생한다!

2. 풀이 계획
매번 뒤집으며 반복을 진행하면 상당히 오래 걸릴것이다!

따라서 is_reversed 변수를 선언하여 뒤집힌 상태인지 똑바로 된 상태인지 를 표시하고

수를 하나 버릴때는 뒤집힌 상태라면 앞에서 하나를 버리고, 뒤집히지 않은 상태라면 뒤에서 하나를 버린다!
 => 앞 뒤에서 모두 삭제가 이루어지므로 deque를 사용하는 것이 효율적일 듯 하다!
마지막에는 뒤집힌 상태라면 뒤집어서 출력한다!

1. 테스트 케이스 변수를 입력받는다.
2. 테스트 케이스 변수의 크기만큼 반복문을 돌리며, AC와 배열을 입력받는다.
3. 배열을 입력받을 때는  2n+1(대괄호와 쉼표를 포함하여) 개의 문자를 읽어 정수면 벡터에 저장하도록 한다.


다음과 같은 과정을 거치자


3. 계획 검증

*/

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

		if (is_reversed) {
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
		else {
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
	int T; // ATM에 줄 서있는 사람의 수

	cin >> T;

	solution(T);

	return 0;
}