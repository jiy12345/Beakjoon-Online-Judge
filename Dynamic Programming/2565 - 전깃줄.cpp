#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

/*
1. 문제 분석
- 변수
N: 전깃줄의 수

- 변수 제한 사항
N: 1~100
위치의 번호: 1~500

- 문제 상황
전깃줄의 연결 형태가 주어질 때, 모든 전깃줄이 교차하지 않게 하기 위해 없애야 하는 전깃줄의 최소개수를 출력한다!

2. 풀이 계획
=> 가장 의문이 드는 것
 어떤것부터 삭제해야 하는가?

 가장 많이 겹치는 것들부터? => 그렇게 되면 뭐랑 겹치는 지 정보를 다 알아야함!
  => 왜냐하면 각각의 전깃줄을 삭제했을 때 바뀌는 정보를 계속 추적해야 하므로!



 부분 문제를 어떻게 설정해야 하는가?

 전체 문제가 k번째 전깃줄까지 고려했을 때 교차하지 않게 하기 위해 없애야 하는 전깃줄의 최소 개수

 => 그렇다면 이럴 때는 다음 줄이 들어왔을 때 삭제해야할 전깃줄이 늘어나는지 아닌지를 어떻게 체크할 것인가?

 삭제할 줄이 늘어나지 않는 경우: 기존의 줄들과 아예 겹치지 않을 경우


아니면 오히려 겹치지 않는 전깃줄의 수의 최대값을 구해서 전체에서 빼면 어떨까?

각각의 위치의 값을 겹치지 않는 전깃줄의 최대값이라고 할 때,

각 위치의 값과 A측과 B측에서의 위치의 최대값을 같이 저장해놔야 할듯 하다!

=> 그래야지 겹치는지 안겹치는지를 알 수 있다!

이전의 모든 위치에 대해 고려하되, 해당 줄까지 고려했을 때 A와 B의 최대값과 최

=> 겹치지 않는 것은 A를 기준으로 정렬하면, B가 이전 B보다 크다면 가능하다!

=> 이러한 역발상을 떠올리는데 시간이 걸렸고,

이렇게 저장할 때 정렬해서 문제를 간단히 해야한다는 것을 떠올리지 못했다!

*/


vector<pair<int, int>> wire;

// 각 위치까지 겹치지 않는 전깃줄 수의 최대값을 저장!
int dp[500];

int N;

int solution() {
	int max_num = 0;

	// A를 기준으로 정렬
	sort(wire.begin(), wire.end());

	for (int i = 0;i < wire.size();i++) {
		cout << wire[i].first << " " << wire[i].second << endl;
	}

	// 첫 위치는 자기 자신 포함해야 하므로!
	dp[0] = 1;

	for (int i = 1;i < N;i++) {
		for (int j = 0;j < i;j++) {
			if (wire[i].second > wire[j].second) {
				dp[i] = max(dp[i], dp[j]);
			}
		}
		// 자신은 무조건 포함!
		dp[i]++;
		// 계산된 값이 최대값인지 확인
		max_num = max(max_num, dp[i]);
	}
	
	for (int i = 0;i < wire.size();i++) {
		cout << dp[i] << endl;
	}

	// 전체 전깃줄의 수에서 겹치지 않는 전깃줄 들의 수를 빼면 됨!
	return N - max_num;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N;

	// 전깃줄 정보 입력받기
	for (int i = 0;i < N;i++) {
		pair<int, int> temp_wire;
		cin >> temp_wire.first >> temp_wire.second;
		wire.push_back(temp_wire);
	}

	cout << solution();
}
