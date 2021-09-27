#include<iostream>
#include<vector>
#include<string>
using namespace std;

int N; // 단어의 개수
int K; // 배울 알파벳의 개수
vector<int> word_bits; // 각 단어에 사용된 모든 알파벳을 비트에 마킹하여 저장한 

int solution(int cur_bit, int cur_index, int cur_alpha) {

  int i, j;

	if (K < 5) {
		return 0;
	}

	// 기저사례: 알파벳 K개를 선택했을 경우
	if (cur_alpha == K) {
		// cout << cur_bit << endl;
		int readable = 0;
		for (i = 0;i < word_bits.size();i++) {
			// & 비트연산을 진행하면 둘 다 1일 때만 1을 반환하므로
			// 해당 단어를 읽을 수 있으려면 둘다 1이어야 한다.
			// 따라서 &연산을 했을 시 같은 값이 나와야 해당 단어를 읽을 수 있는 것!
			if (((cur_bit & word_bits[i])) == word_bits[i]) readable++;
		}
		return readable;
	}


	int max = 0;
	for (int i = cur_index;i < 26;i++) {
		if ((cur_bit & ((1 << i))) == (1 << i)) continue; // 이미 마킹된 알파벳일 경우 다음으로 진행하지 않음
		
		// cur_bit에 배우는 알파벳에 대한 값을 추가해주기!
		int temp = solution((cur_bit | (1<<i)), i + 1, cur_alpha + 1);

		// 최대값이 변화되었다면 변경해주기
		if (temp > max) {
			max = temp;
		}
	}
	return max;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string temp;
	cin >> N >> K;

	for (int i = 0;i < N;i++) {
		cin >> temp;
		temp = temp.substr(4, temp.size() - 8);
		int new_bit = 0;
		// 각 단어별 비트 마킹
		for (char c : temp) {
			// or 연산이니까 둘중 1인 것은 1
			// => 문자가 이미 마킹 되어 있을 경우 1인 상태가 유지되며, 그렇지 않을경우 1로 바뀜!
			new_bit |= (1 << (c - 97));
		}
		// 마킹한 비트를 words 벡터에 넣어주기
		word_bits.push_back(new_bit);
	}

	// anta, tica에 포함된 알파벳은 미리 
	int cur_bit = 0; 
	cur_bit |= (1 << ('a' - 'a'));
	cur_bit |= (1 << ('c' - 'a'));
	cur_bit |= (1 << ('i' - 'a'));
	cur_bit |= (1 << ('n' - 'a'));
	cur_bit |= (1 << ('t' - 'a'));


	cout << solution(cur_bit, 0, 5);

	return 0;
}
