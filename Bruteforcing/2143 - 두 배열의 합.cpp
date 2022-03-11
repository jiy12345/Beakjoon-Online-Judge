#include<iostream>
#include<unordered_map>
#include<vector>
#include<numeric>

using namespace std;

/*
1. ���� �м�
- ����
n: ���� A�� ���� ����
m: ���� B�� ���� ����
T: ��ǥ�� �� ��

- ���� ���� ����
T: -1,000,000,000 ~ 1,000,000,000
n, m: 1 ~ 1,000
�迭�� ����: -1,000,000 ~ 1,000,000


- ���� ��Ȳ
 �� �迭�� ��� �迭�� ���ӵ� ������ ���̶�� �ϸ�,

 �� �迭�� �־��� �� �� �迭�� �ι迭�� ���� T�� �Ǵ� ��� �� �迭 ���� ������ ���ϴ� ���α׷��� �ۼ��϶�!

2. Ǯ�� ��ȹ

map�� ����ϸ� �� �� �ϰ�, 

2�� �ݺ����� ���� �������� ���ϸ� �� �� �ϴ�.

3. ��ȹ ����


*/


int n, m, T;
vector<int> A(1000, 0);
vector<int> B(1000, 0);
unordered_map<int, int>subSum;

int solution() {
    long long answer = 0;

    // A�� �յ� ���
    int prevSum = accumulate(A.begin(), A.begin() + n, 0);

    for (int i = 0; i < n; i++) {
        int curSum = prevSum;
        
        subSum[curSum]++;

        // A���� �Ѱ��� ������ �ʴ� ���� ����� �ϹǷ� -1
        for (int j = 0; j < n - i - 1; j++) {
            curSum -= A[n - 1 - j];
            subSum[curSum]++;
        }
        prevSum -= A[i];
    }

    prevSum = accumulate(B.begin(), B.begin() + m, 0);
    for (int i = 0; i < m; i++) {
        int curSum = prevSum;

        answer += subSum[T - curSum];

        // B���� �Ѱ��� ������ �ʴ� ���� ����� �ϹǷ� -1
        for (int j = 0; j < m - i - 1; j++) {
            curSum -= B[m - 1 - j];
            answer += subSum[T - curSum];
        }
        prevSum -= B[i];
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }    

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }

    cout << solution();

    return 0;
}
