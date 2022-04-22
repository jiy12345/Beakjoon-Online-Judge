#include<iostream>
#include<cstring>
using namespace std;


/*
1. ���� �м�
- ����
n: ��ȭ���� ���� ũ��
m: ��ȭ���� ���� ũ��

 - ���� ���� ����
n, m: 1 ~ 100

- ���� ��Ȳ
 ���� Ʈ���� ������ ���� ��Ģ�� ���� ��� ���� ��ȣ�� �پ��ִ� ���� ����� Ʋ �ӿ� �׸����� �Ѵ�.

1. ����Ʈ������ ���� ����(level)�� �ִ� ���� ���� �࿡ ��ġ�Ѵ�.
2. �� ������ �� ��常 �����Ѵ�.
3. ������ ����� ���� ��Ʈ��(left subtree)�� �ִ� ������ �ش� ��庸�� ������ ���� ��ġ�ϰ�, ������ ��Ʈ��(right subtree)�� �ִ� ������ �ش� ��庸�� �������� ���� ��ġ�Ѵ�.
4. ��尡 ��ġ�� ���� ���� ���� ������ �� ���̿� �ƹ� ��嵵 ���� ����ִ� ���� ����.

�� ������ �ʺ� �� ������ �Ҵ�� ��� �� ���� �����ʿ� ��ġ�� ����� �� ��ȣ���� ���� ���ʿ� ��ġ�� ����� �� ��ȣ�� �� �� ���ϱ� 1�� ������ ��,

�ʺ� ���� ���� ������ �� ������ �ʺ� ����ϴ� ���α׷��� �ۼ��϶�.

2. Ǯ�� ��ȹ

1. ���� ��ȸ�� �ϸ� �� ��尡 ��ġ�ؾ� �ϴ� ���� ��ȣ�� �ű��.
 => �� ��, �� ���� �ִ밪�� �ּҰ��� ����ؼ� �����Ѵ�.

- Ʋ�� �� �ִ� �κ�
 ���� ��ȣ? ���� ���� ���� ���ǹǷ� ���� ���� �� �ϴ�.
 ����?

2. ������ �ʺ� ���Ѵ�.
3. �ʺ��� �ִ밪�� ���Ѵ�.

��Ʈ ���� ��� ã�ƾ� �ұ�?


3. ��ȹ ����

 ���Կ� ���� ������������ ���ĵǾ� �����Ƿ�, ���� ���濡 ���� �� �ִ� �������� ���� ���濡�� ���� �� �ִ�. ���� �켱���� ť�� ���� ������� �������� ��� ��Ƶдٸ�, ���� ���濡 ���� �� �ִ� ���� �� ������ ���� ���� ������ �ְ� �� �� �ִ�.

*/

#define LEFT_CHILD 0
#define RIGHT_CHILD 1

#define MAX 10001

int N;
int binaryTree[MAX][2];

// ��Ʈ ��带 ã�� ���� �迭
bool isRoot[MAX];

// �� ���� �ִ밪�� �ּҰ��� ������ �迭
int maxInRow[MAX];
int minInRow[MAX];

int colNum = 1; // �� ����� �� ��ȣ�� �ű� �� ���
int max_depth = 0;

void inorder(int cur_node, int depth) {
	if (binaryTree[cur_node][LEFT_CHILD] != -1) inorder(binaryTree[cur_node][LEFT_CHILD], depth + 1);

	// �� ���� �ִ밪, �ּҰ� ����
	maxInRow[depth] = max(maxInRow[depth], colNum);
	minInRow[depth] = min(minInRow[depth], colNum);
	max_depth = max(max_depth, depth);
	colNum++;

	if (binaryTree[cur_node][RIGHT_CHILD] != -1)inorder(binaryTree[cur_node][RIGHT_CHILD], depth + 1);
}

void solution() {
	int maxWidth = 0;
	int maxWidthIndex = 0;

	for (int i = 0; i <= N; i++) {
		minInRow[i] = N;
	}

	int root = 0;

	for (int i = 1; i <= N; i++) {
		if (isRoot[i]) {
			root = i;
			break;
		}
	}

	inorder(root, 1);

	for (int i = 1; i <= max_depth; i++) {
		int curWidth = (maxInRow[i] - minInRow[i] + 1);
		if (maxWidth < curWidth) {
			maxWidth = curWidth;
			maxWidthIndex = i;
		}
	}

	cout << maxWidthIndex << " " << maxWidth;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	memset(isRoot, true, sizeof(isRoot));
	for (int i = 1; i <= N; i++) {
		int parent, left, right;
		cin >> parent >> left >> right;

		// �ڽ� ���� ������ ������ ��Ʈ�� �ƴ�
		if (left != -1) isRoot[left] = false;
		if (right != -1)isRoot[right] = false;

		binaryTree[parent][LEFT_CHILD] = left;
		binaryTree[parent][RIGHT_CHILD] = right;
	}

	solution();

	return 0;
}