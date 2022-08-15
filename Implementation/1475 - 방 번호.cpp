#include<cstdio>
#include<algorithm>
using namespace std;

int numOfNum[10];

int solution() {
    int answer = 0;
    int answerNum = 0;

    char curNum;
    while (true) {
        curNum = getchar();
        if (curNum == '\n') break;
        numOfNum[curNum - '0']++;
    }

    numOfNum[6] += numOfNum[9];
    ++numOfNum[6] /= 2;

    for (int i = 0; i < 9; i++)
        answer = max(answer, numOfNum[i]);

    return answer;
}

int main() {
    printf("%d", solution());
}