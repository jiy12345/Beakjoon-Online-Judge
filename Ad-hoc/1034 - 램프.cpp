#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

#define MAX 50

int numOfZeros[MAX]; // 각 행의 0의 개수
string table[MAX];
map<string, int> numOfSameShape;

int K;
int N, M;

int solution() {
    int answer = 0;

    for (int i = 0; i < N; i++) {
        // 모두 켤 수 있는 행에 대해서만 연산
        if (numOfZeros[i] <= K && numOfZeros[i] % 2 == K % 2) {
            numOfSameShape[table[i]]++;
        }
    }

    map<string, int>::iterator it;
    for (pair<string, int> cur_pair : numOfSameShape) {
        answer = max(answer, cur_pair.second);
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> table[i];

        // 각 행의 0의 개수 세기
        for (int j = 0; j < M; j++)
            if (table[i][j] == '0') numOfZeros[i]++;
    }

    cin >> K;

    cout << solution();
}
