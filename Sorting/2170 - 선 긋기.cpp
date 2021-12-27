#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
1. ���� �м�

- ����
N: ���� ��
x, y: ���� ���� �� ������ �� ���� ��ġ

- ���� ���� ����
N: 1~1,000,000
x, y: -1,000,000,000~1,000,000,000

 - ���� ��Ȳ
 ���� �������� �־����� ��, �� �ߵ��� ����Ͽ� ������ �� ���� ���� ���� ���� �� �ּҰ��� ���Ͽ���

2. Ǯ�� ��ȹ
�̰� ��� �����ؾ� �ұ�?

�ߺ��ؼ� ���� �� ���� ������ ��� �����Ƿ� ���� �����̱� �ѵ�, �׷��ٰ� ��� ������ �� ���ϱ⿡�� 2^N���� ������ �ð����⵵�� ���̹Ƿ� �׷��� ���� ���� ����.

�׷��ٸ� ���?

DP, ���տ��� ��Ű� �־��µ�, ������ �� �׸���� ������ ǥ���� ������ ���̾���!

������ ���¿��� �����պ��� ũ�ٸ�,

�����Ͽ� �����ϱ�!
https://plplim.tistory.com/59
https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=hongjg3229&logNo=221627349685

Sn:

3. ��ȹ ����


*/

int N;
vector<pair<int, int>> locations;

int solution() {
	int answer = 0;

	sort(locations.begin(), locations.end());

	int cur_start = locations[0].first;
	int cur_end = locations[0].second;

	for (int i = 1; i < N; i++) {
		if (cur_end < locations[i].first) {
			answer += (cur_end - cur_start);
			cur_start = locations[i].first;
			cur_end = locations[i].second;
		}
		else {
			cur_end = max(cur_end, locations[i].second);
		}
	}

	answer += (cur_end - cur_start);

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;

		locations.push_back(make_pair(x, y));

	}

	cout << solution();

	return 0;
}