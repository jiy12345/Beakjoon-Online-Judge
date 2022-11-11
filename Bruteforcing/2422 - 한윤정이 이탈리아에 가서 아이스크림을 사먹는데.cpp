#include<iostream>
using namespace std;

int N, M;
bool isLinked[201][201];

int solution() {
    int answer = 0;
    for (int i = 1; i <= N; ++i)
        for (int j = i + 1; j <= N; ++j)
            if (!isLinked[i][j])
                for (int k = j + 1; k <= N; ++k) 
                    if (!isLinked[i][k] && !isLinked[j][k]) ++answer;
    return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int p, q;
        cin >> p >> q;
        isLinked[p][q] = isLinked[q][p] = true;
    }

	cout << solution();
}