#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq;
int N, dasom;

int solution() {
    int answer = 0;

    while (!pq.empty() && pq.top() >= dasom) {
        int t = pq.top(); 
        pq.pop();
        t--; 
        answer++; 
        dasom++;
        pq.push(t);
    }

    return answer;
}

void input() {
    cin >> N;
    cin >> dasom;
    N--;
    while (N--) {
        int input;
        cin >> input;
        if (input >= dasom) pq.push(input);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    
    cout << solution();

    return 0;
}