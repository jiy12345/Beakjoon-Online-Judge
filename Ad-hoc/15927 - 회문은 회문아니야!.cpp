#include<iostream>
using namespace std;

string s;

bool isPalindrome() {
    for (int i = 0; i < s.size() / 2; i++)
        if (s[i] != s[s.size() - 1 - i])
            return false;
    return true;
}

bool isOneAlphabet() {
    char first_char = s[0];
    for (char cur_char:s) 
        if(cur_char != first_char) return false;
    
    return true;
}

int solution() {
    if (isOneAlphabet()) return -1;

    if (isPalindrome()) return s.size() - 1;
    else return s.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s;
    cout << solution();
}
