#include <iostream>
#include <string>
#include <algorithm>
#include <cstring> //memset
using namespace std;

/*
1. ���� �м�
- ����
N: ������ ����
k: ��ġ�� �� ��ǥ

- ���� ���� ����
N: 1~50

�迭�� �� ����: 1~1,000
- ���� ��Ȳ
 ���� P�� �迭 A�� ������ �迭 B��
 B[P[i]] = A[i]
 �񳻸�����: �ٷ� ���� ���ҿ� ���� ���� �ִ� ��������
 �迭 A�� �־����� ��, ���� P�� ������ ����� �񳻸��������� ���ĵǵ����ϴ� ���� P�� ���϶�
2. Ǯ�� ��ȹ
���� �ڼ��� ��ȹ�� ������ ����.
1. �迭�� �Է¹��� �� �����Ѵ�. ��Ī�� �迭�� Ȱ���ϱ� ���� ���� �迭�� ���´� �����Ѵ�.
2. ������ ������ �����ϰ�, ������ ������ �� �ε����� ��Ī�Ͽ� ������ �����.
3. ���� �� Ű�� ���� �Էµ� �迭�� ������� ����ִ´�.
3. ��ȹ ����
*/


const int MAX = 100 + 1;

int N, M;

string cache[MAX][MAX];



// long long �ڷ������� ó������ �ʴ� ������ ���� ó���ؾ� �ϹǷ�, ���ڿ��� ��ȯ�� �� ������ ����! 
string bigNumberAdd(string num1, string num2) {

    // �� �ڸ������� ���� ó���� ����
    int sum = 0;

    string result;
    //1�� �ڸ����� ���ϱ� �����Ѵ�
    while (!num1.empty() || !num2.empty() || sum) {

        if (!num1.empty()) {
            sum += num1.back() - '0';
            num1.pop_back();
        }

        if (!num2.empty()) {
            sum += num2.back() - '0';
            num2.pop_back();
        }

        //�ٽ� string ���·� ����� push_back
        result.push_back((sum % 10) + '0');

        // ���� 10�� �Ѿ� �÷��� �ϴ� �� ���� �ڸ� �� ��꿡 �ݿ�!
        sum /= 10;
    }

    //1�� �ڸ����� result�� �־����Ƿ� �������ֱ�
    reverse(result.begin(), result.end());

    return result;

}


// ������ ��������
// nCr = n-1Cr + n-1Cr-1
string combination(int n, int r){
    // �������
    if (n == r || r == 0)
        return "1";

    // nCr ��� ��� ����س���
    string& result = cache[n][r];

    if (result != "")

        return result;

    result = bigNumberAdd(combination(n - 1, r - 1), combination(n - 1, r));

    return result;
}



int main() {
    cin >> N >> M;
    cout << combination(N, M) << endl;

    return 0;

}