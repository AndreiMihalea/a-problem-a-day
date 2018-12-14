#include <iostream>
using namespace std;

int staircase(int n, int steps[], int size)
{
	int arr[n + 1];
	for (int i = 0; i < n + 1; i++) {
		arr[i] = 0;
	}
	arr[0] = 1;

	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < size; j++) {
			int x = steps[j];
			if (i - x >= 0) {
				arr[i] += arr[i - x];
			}
		}
	}

	return arr[n];
}

int main()
{
	int steps[] = {1, 2, 3, 4};
	int n = 4;
	cout << staircase(n, steps, sizeof(steps) / sizeof(steps[0])) << endl;
}