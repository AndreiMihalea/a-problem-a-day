#include <iostream>
#include <string>

using namespace std;

int editDistance(string s1, string s2)
{
	int n = s1.length(), m = s2.length();
	int mat[n + 1][m + 1];

	for (int i = 0; i <=n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0) {
				mat[i][j] = j;
			} else if (j == 0) {
				mat[i][j] = i;
			} else if (s1[i - 1] == s2[j - 1]) {
				mat[i][j] = mat[i - 1][j - 1];
			} else {
				mat[i][j] = 1 + min(min(mat[i - 1][j], mat[i][j - 1]), mat[i - 1][j - 1]);
			}
		}
	}

	return mat[n][m];
}

int main()
{
	string s1 = "kitten";
	string s2 = "sitting";
	cout << editDistance(s1, s2) << endl;
}