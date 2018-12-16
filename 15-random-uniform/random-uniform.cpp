#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int getRandom(int num)
{
	static int count = 0;
	static int final;

	count += 1;

	if (count == 1) {
		final = num;
	} else {
		int r = rand() % count;
		if (r == count - 1) {
			final = num;
		}
	}

	return final;
}

int main()
{
	srand(time(NULL)); 
	int stream[] = {1, 5, 6, 3, 11, 7, 23};
	for (int i = 0; i < sizeof(stream) / sizeof(stream[0]); i++) {
		cout << "Step: " << i + 1 << "; Number: " << getRandom(stream[i]) << endl;
	}
	return 0;
}