#include<cstdio>
using namespace std;

#define MAX 1000000

int solution() {
    int answer = 0;;

    char prevNum, curNum;
    prevNum = getchar();

    while (true) {
        curNum = getchar();
        if (prevNum != curNum)
            answer++;
        if (curNum == '\n') break;
        prevNum = curNum;
    }

    return answer / 2;
}

int main() {
    printf("%d", solution());
}