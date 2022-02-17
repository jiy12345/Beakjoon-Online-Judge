#include<iostream>
#include<vector>
using namespace std;

vector<int> friends[2000];
bool isVisited[2000];

bool solution(int numSelected, int curPickedNode) {
	if (numSelected == 5) {
		return true;
	}

	for (int i = 0; i < friends[curPickedNode].size(); i++) {
		int curFriend = friends[curPickedNode][i];
		if (isVisited[curFriend] == false) {
			isVisited[curFriend] = true;

			if (solution(numSelected + 1, curFriend))
				return true;

			isVisited[curFriend] = false;
		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {
		isVisited[i] = true;
		if (solution(1, i)) {
			cout << 1; 
			return 0;
		}
		isVisited[i] = false;
	}

	cout << 0;

	return 0;
}
