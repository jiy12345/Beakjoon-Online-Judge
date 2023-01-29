#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int N;

struct StudentInfo {
	string name;
	int kor;
	int eng;
	int math;
};

StudentInfo student_info[100000];

bool cmp(const StudentInfo& lhs, const StudentInfo& rhs) {
	if (lhs.kor == rhs.kor) {
		if (lhs.eng == rhs.eng) {
			if (lhs.math == rhs.math) {
				return lhs.name <= rhs.name;
			}
			return lhs.math > rhs.math;
		}
		return lhs.eng < rhs.eng;
	}
	return lhs.kor > rhs.kor;
}

void solution() {
	sort(student_info, student_info + N, cmp);

	for (int i = 0;i < N;i++) {
		cout << student_info[i].name << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0;i < N;i++) {
		cin >> student_info[i].name >> student_info[i].kor >> student_info[i].eng >> student_info[i].math;
	}

	solution();

}