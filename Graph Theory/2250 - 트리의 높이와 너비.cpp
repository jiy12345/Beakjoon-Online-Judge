#include<iostream>
#include<cstring>
using namespace std;


/*
1. 문제 분석
- 변수
n: 도화지의 세로 크기
m: 도화지의 가로 크기

 - 변수 제한 사항
n, m: 1 ~ 100

- 문제 상황
 이진 트리를 다음과 같은 규칙에 따라 행과 열에 번호가 붙어있는 격자 모양의 틀 속에 그리려고 한다.

1. 이진트리에서 같은 레벨(level)에 있는 노드는 같은 행에 위치한다.
2. 한 열에는 한 노드만 존재한다.
3. 임의의 노드의 왼쪽 부트리(left subtree)에 있는 노드들은 해당 노드보다 왼쪽의 열에 위치하고, 오른쪽 부트리(right subtree)에 있는 노드들은 해당 노드보다 오른쪽의 열에 위치한다.
4. 노드가 배치된 가장 왼쪽 열과 오른쪽 열 사이엔 아무 노드도 없이 비어있는 열은 없다.

각 레벨의 너비를 그 레벨에 할당된 노드 중 가장 오른쪽에 위치한 노드의 열 번호에서 가장 왼쪽에 위치한 노드의 열 번호를 뺀 값 더하기 1로 정의할 때,

너비가 가장 넓은 레벨과 그 레벨의 너비를 출력하는 프로그램을 작성하라.

2. 풀이 계획

1. 중위 순회를 하며 각 노드가 위치해야 하는 열의 번호를 매긴다.
 => 이 때, 각 행의 최대값과 최소값을 계속해서 갱신한다.

- 틀릴 수 있는 부분
 열의 번호? 왼쪽 노드들 부터 계산되므로 문제 없을 듯 하다.
 깊이?

2. 레벨의 너비를 구한다.
3. 너비의 최대값을 구한다.

루트 노드는 어떻게 찾아야 할까?


3. 계획 검증

 무게에 대해 오름차순으로 정렬되어 있으므로, 이전 가방에 넣을 수 있는 보석들은 다음 가방에도 넣을 수 있다. 따라서 우선순위 큐에 현재 고려중인 보석들을 모두 담아둔다면, 현재 가방에 넣을 수 있는 보석 중 가격이 가장 높은 보석을 넣게 될 수 있다.

*/

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