#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int longestPath(string input)
{
	stringstream ss(input);
	string current_line;
	int res = 0;

	vector<int> lengths;
	lengths.push_back(0);

	while(getline(ss, current_line, '\n')) {
		int level = 0;
		
		while(current_line[level++] == '\t');

		int line_size = current_line.length() - level + 1;

		if (current_line.find('.') != string::npos) {
			if (lengths[level - 1] + line_size > res) {
				res = lengths[level - 1] + line_size;
			}
		} else {
			if (lengths.size() <= level) {
				lengths.push_back(0);
			}
			lengths[level] = lengths[level - 1] + line_size + 1;
		}
	}

	return res;
}

int main()
{
	string input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";	
	cout << longestPath(input) << endl;
}