#include <iostream>
#include <string>

using namespace std;

bool regexMatch(string regex, string str)
{
	int rlen = regex.length();
	int slen = str.length();

	if (rlen == 0 && slen == 0) {
		return true;
	}
	
	if (regex[1] == '*') {
		if (regexMatch(regex.substr(2), str)) {
			return true;
		}
		int index = 0;
		while (index < slen && (str[index] == regex[0] || regex[0] == '.')) {
			if (regexMatch(regex.substr(2), str.substr(index + 1))) {
				return true;
			}
			index += 1;
		}

		return false;
	} else {
		if (slen == 0) {
			return false;
		}
		if (str[0] != regex[0] && regex[0] != '.') {
			return false;
		} else {
			return regexMatch(regex.substr(1), str.substr(1));
		}
	}

	return false;
}

int main()
{
	string regex = ".*at";
	string str = "chat";
	cout << regexMatch(regex, str) << endl;
}