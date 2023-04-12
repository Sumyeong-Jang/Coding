#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string input, bomb;
string answer;
vector<char> str;

int matching_check(int i);

int main() {
	cin >> input >> bomb;

	for (int i = 0; i < input.size(); i++) {
		str.push_back(input[i]);
		if (str.size() >= bomb.size()) {
			if (str[str.size() - 1] == bomb[bomb.size() - 1]) {
				if (matching_check(str.size() - 1) == 1) {
					for (int j = 0; j < bomb.size(); j++)
						str.pop_back();
				}
			}
		}
	}
	if (str.size() == 0)
		printf("FRULA");
	else {
		for (int i = 0; i < str.size(); i++)
			printf("%c", str[i]);
	}
}

int matching_check(int i) {
	for (int t = 0; t < bomb.size(); t++) {
		if (str[i - t] != bomb[bomb.size() - 1 - t])
			return 0;
	}
	return 1;
}