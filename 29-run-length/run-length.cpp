#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

string encode(string text)
{
	if (text == "") {
		return string();
	}

	int current_count = 1;
	char current_char = text[0];
	string res;

	for (int i = 1; i < text.length(); i++) {
		if (text[i] == current_char) {
			current_count += 1;
		} else {
			res += to_string(current_count);
			res += current_char;
			current_count = 1;
			current_char = text[i];
		}
	}
	res += to_string(current_count);
	res += current_char;

	return res;
}

string decode(string text)
{
	int current_count = 1;
	int current_sum = 0;
	string res = string();

	for (int i = 0; i < text.length(); i++) {
		int c = int(text[i]);
		if (c >= 48 && c <= 57) {
			current_sum += current_count * (c - 48);
			current_count *= 10;
		} else {
			for (int j = 0; j < current_sum; j++) {
				res += text[i];
			}
			current_count = 1;
			current_sum = 0;
		}
	}

	return res;
}

int main()
{
	string text = "AAAABBBCCDAA";
	cout << encode(text) << endl;
	cout << decode(encode(text)) << endl;
}