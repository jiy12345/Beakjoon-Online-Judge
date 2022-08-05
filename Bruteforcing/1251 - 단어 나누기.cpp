#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//
// 조합
// 
// 단어의 길이가 n일 때, 1부터 N - 1 까지의 수 중 2개 조합하여 나눌 위치 2자리 뽑고
// 
// 나누어 합친 결과를 현재 저장되어 있는 내용과 비교
//

string input;

string solution() {
	int N = input.size();

	string answer(N, 'z');

	for (int i = 1; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			string firstPart = input.substr(0, i);
			string secondPart = input.substr(i, j - i);
			string thirdPart = input.substr(j);

			reverse(firstPart.begin(), firstPart.end());
			reverse(secondPart.begin(), secondPart.end());
			reverse(thirdPart.begin(), thirdPart.end());

			string curString = firstPart + secondPart + thirdPart;

			answer = (answer < curString) ? answer : curString;
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> input;

	cout << solution();

	return 0;
}