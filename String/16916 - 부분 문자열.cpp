#include<vector>
#include<iostream>
using namespace std;

string  S, P;

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

int KMP(string S, string P) {
    vector<int> table = makeTable(P);
    int j = 0;

    for (int i = 0; i < S.length(); i++) {
        while (j > 0 && S[i] != P[j]) {
            j = table[j - 1];
        }
        if (S[i] == P[j]) {
            if (j == P.length() - 1) return 1;
            else j += 1;
        }
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> S;
    cin >> P;

    cout << KMP(S, P);
}
