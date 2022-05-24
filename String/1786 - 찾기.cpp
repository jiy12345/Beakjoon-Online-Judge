#include<vector>
#include<iostream>
#include<string>
using namespace std;

string  S, P;

// KMP 구현
// 실패함수 구현(접두사와 접미사 최대 일치 길이 비교)
vector<int> makeTable(string pattern) {
    int patternSize = pattern.size();

    vector<int> table(patternSize, 0);

    int j = 0;
    for (int i = 1; i < patternSize; i++) {

        // j 인덱스가 0이상인데, i번째와 j번째 문자가 일치하지 않는다면, 
        while (j > 0 && pattern[i] != pattern[j]) {
            j = table[j - 1]; // 한 칸 뒤로 백 
        }

        if (pattern[i] == pattern[j]) {
            table[i] = ++j;
        }
    }

    return table;
}

void KMP(string S, string P, vector<int> &locations) {
    vector<int> table = makeTable(P);
    int j = 0;

    int patternSize = P.size();
    int stringSize = S.size();

    for (int i = 0; i < stringSize; i++) {
        while (j > 0 && S[i] != P[j]) 
            j = table[j - 1];
        
        if (S[i] == P[j]) {
            if (j == patternSize - 1) {
                locations.push_back(i - patternSize + 1);
                j = table[j];
            }
            else j++;
        }
    }
}

void solution() {
    vector<int> locations;

    KMP(S, P, locations);

    cout << locations.size() << '\n';
    for (int location : locations)
        cout << location + 1 << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);


    getline(cin, S);
    getline(cin, P);

    solution();
}
