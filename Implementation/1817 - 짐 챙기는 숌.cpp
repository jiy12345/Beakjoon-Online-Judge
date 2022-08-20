#include<iostream>
using namespace std;

// 책은 차례대로 넣을 수밖에 없다.
// => 입력된 순서대로 체크하면 된다.

// 각각의 책은 무게가 있다.
// 모든 박스는 같은 넣을 수 있는 무게를 가진다.
// 
// N: 책의 개수 0 ~ 50
// M: 박스에 넣을 수 잇는 최대 무게 0 ~ 1,000
// 
// 1. 입력된 책에 대해 반복문을 돌리며, 필요한 박스의 개수를 센다.
//  => 현재 박스에 들어간 무게를 체크한다.
//  => 현재 박스에 들어간 무게 + 현재 책의 무게가 박스의 한계치를 넘어서면 다음 박스에 책을 담는다.
//

int N, M;

int solution() {
	int answer = 0;
	int curBox = M;

	for (int i = 0; i < N; i++) {
		int bookWeight;
		cin >> bookWeight;

		if (curBox + bookWeight > M) {
			answer++;
			curBox = bookWeight;
		}
		else
			curBox += bookWeight;
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	cout << solution();

	return 0;
}