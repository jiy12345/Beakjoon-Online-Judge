#include<iostream>
using namespace std;

//
// 변수
// X: 목표 길이
// 
// X: 1 ~ 64
// 
// 
//
// 막대의 길이 모두 더한다
// 
// 가지고 있는 막대 중 길이가 가장 짧은 것을 절반으로 자른다
//  => 잘리는 막대는 정해져 있다
//  
//

int X;

int solution() {
	int answer = 0;
	for (int i = 64; i > 0; i /= 2) {
		if (!X)
			break;
		if (i <= X) {
			answer++;
			X = X - i;
		}
	}
	return answer;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> X;

	cout << solution();

	return 0;
}