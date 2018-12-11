#include <iostream>
using namespace std;

int max_sum(int arr[], int n)
{
	int sum_with = 0, sum_without = 0;
	for (int i = 0; i < n; i++) {
		int max_sum_without = max(sum_without, sum_with);
		sum_with = sum_without + arr[i];
		sum_without = max_sum_without;
	}

	return max(sum_with, sum_without);
}

int main()
{
	int arr[] = {5, 1, 1, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	int res = max_sum(arr, n);
	cout << res << endl;
}