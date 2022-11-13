#include<iostream>
#include<cstring>
using namespace std;

int T;
int R, C;
char polyhedron[52][52];

int di[4] = { 0, 1, 0, -1 };
int dj[4] = { 1, 0, -1, 0 };

int solution() {
	int answer = 0;

	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++) {
			if (polyhedron[i][j] != 0) answer += 2;

			for (int k = 0; k < 4; k++) {
				int adj_i = i + di[k];
				int adj_j = j + dj[k];

				answer += max(0, polyhedron[i][j] - polyhedron[adj_i][adj_j]);
			}
		}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> R >> C;

		memset(polyhedron, 0, sizeof(polyhedron));
		for (int j = 1; j <= R; j++)
			for (int k = 1; k <= C; k++) {
				cin >> polyhedron[j][k];
				polyhedron[j][k] -= '0';
			}


		cout << solution() << '\n';
	}
}