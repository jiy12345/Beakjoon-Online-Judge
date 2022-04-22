#include<iostream>
#include<cstring>
using namespace std;

#define LEFT_CHILD 0
#define RIGHT_CHILD 1

#define MAX 10001

int N;
int binaryTree[MAX][2];

// 루트 노드를 찾기 위한 배열
bool isRoot[MAX];

// 각 행의 최대값과 최소값을 저장할 배열
int maxInRow[MAX];
int minInRow[MAX];

int colNum = 1; // 각 노드의 열 번호를 매길 때 사용
int max_depth = 0;

void inorder(int cur_node, int depth) {
	if (binaryTree[cur_node][LEFT_CHILD] != -1) inorder(binaryTree[cur_node][LEFT_CHILD], depth + 1);

	// 각 행의 최대값, 최소값 갱신
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

		// 자식 노드로 등장한 노드들은 루트가 아님
		if (left != -1) isRoot[left] = false;
		if (right != -1)isRoot[right] = false;

		binaryTree[parent][LEFT_CHILD] = left;
		binaryTree[parent][RIGHT_CHILD] = right;
	}

	solution();

	return 0;
}
