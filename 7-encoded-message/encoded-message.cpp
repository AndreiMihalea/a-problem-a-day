#include <iostream>
#include <string.h>
using namespace std;

int count_decoding(char *message, size_t len)
{
	int count[len + 1];
	count[0] = 1;
	count[1] = 1;
	for (int i = 2; i <= len; i++) {
		if (message[i - 2] == '1' || (message[i - 2] == '2' && message[i - 1] <= '6')) {
			count[i] = count[i - 1] + count[i - 2];
		} else if (message[i - 1] > '0') {
			count[i] = count[i - 1];
		} else {
			count[i] = 0;
		}
	}

	return count[len];
}

int main()
{
	char message[] = "1112";
	size_t len = strlen(message);
	cout << count_decoding(message, len) << endl;
}