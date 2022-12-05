#include<iostream>
using namespace std;

#define MALE 1
#define FEMALE 2
int number_of_switch;
int number_of_students;
bool switches[100];

void solution() {
	for (int i = 0; i < number_of_students; i++) {
		int sex, switch_number;
		cin >> sex >> switch_number;
		switch (sex) {
		case MALE:
			for (int j = switch_number - 1; j < number_of_switch; j += switch_number) {
				switches[j] = !switches[j];
			}
			break;
		case FEMALE:
			int center_index = switch_number - 1;
			switches[center_index] = !switches[center_index];
			int num_iter = min(center_index - 0, number_of_switch - center_index - 1);
			for (int j = 1; j <= num_iter; j++) {
				int right_index = center_index + j;
				int left_index = center_index - j;
				if (switches[right_index] != switches[left_index]) break;
				switches[right_index] = !switches[right_index];
				switches[left_index] = !switches[left_index];
			}
			break;
		}
	}

	for (int i = 1; i <= number_of_switch;i++) {
		cout << switches[i - 1] << " ";
		if (i % 20 == 0) cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> number_of_switch;
	for (int i = 0; i < number_of_switch; i++) {
		cin >> switches[i];
	}

	cin >> number_of_students;

	solution();
}