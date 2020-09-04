#include <string>
#include <vector>
#include <map>

#include<iostream>

using namespace std;

int solution(vector<vector<string>> clothes);

int main() {
    vector<vector<string>> clothes;
    vector<string> v1, v2, v3;
    v1.push_back("yellow_hat");
    v1.push_back("headgear");
    v2.push_back("bluesunglasses");
    v2.push_back("eyewear");
    v3.push_back("green_turban");
    v3.push_back("headgear");
    clothes.push_back(v1);
    clothes.push_back(v2);
    clothes.push_back(v3);

    cout << solution(clothes);
}

int solution(vector<vector<string>> clothes) {
    int i, j;

    //  의복 유형, 종류별 개수
    map<string, int> clothes_type;
    int answer = 1; // 답

    for (i = 0; i < clothes.size();i++) {
        if (clothes_type.find(clothes[i][1]) == clothes_type.end()) {
            clothes_type.insert(make_pair(clothes[i][1], 0));
        }
        clothes_type[clothes[i][1]]++;
    }

    map<string, int>::iterator iter;
    for (iter = clothes_type.begin(); iter != clothes_type.end(); ++iter) {
        // 입지 않을 경우를 포함할 각 종류별 경우의 수 곱해주기
        answer *= (iter->second + 1);
    }

    answer -= 1; // 아무것도 입지 않았을 경우 빼주기
    return answer;
}
