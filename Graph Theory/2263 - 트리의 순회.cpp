#include <iostream>

using namespace std;

#define MAX 100001

int indexInInorder[MAX];
int inorder[MAX];
int postorder[MAX];
int n;

// 중위 순회: 양쪽 부분 트리를 나누는 기준을 찾기 위해 사용
// 후위 순회: 루트의 값을 찾기 위해 사용
void printPreorder(int inorder_start, int inorder_end, int postorder_start, int postorder_end) {
    if (inorder_start > inorder_end || postorder_start > postorder_end) return;

    int rootIndex = indexInInorder[postorder[postorder_end]];
    int leftTreeSize = rootIndex - inorder_start;
    cout << inorder[rootIndex] << ' ';

    printPreorder(inorder_start, rootIndex - 1, postorder_start, postorder_start + leftTreeSize - 1);
    printPreorder(rootIndex + 1, inorder_end, postorder_start + leftTreeSize, postorder_end - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> inorder[i];
        indexInInorder[inorder[i]] = i;
    }

    for (int i = 1; i <= n; i++)
        cin >> postorder[i];

    printPreorder(1, n, 1, n);
    return 0;
}