#include <iostream>
using namespace std;

const int n = 4, k = 3;

int minCost(int costs[][k])
{
	int previous_min = 0;
	int previous_second_min = 0;
	int previous_color = -1;

	for (int i = 0; i < n; i++) {
		int current_min = 1e8;
		int current_second_min = 1e8;
		int current_color = 0;

		for (int j = 0; j < k; j++) {
			if (previous_color == j) {
				costs[i][j] += previous_second_min;
			} else {
				costs[i][j] += previous_min;
			}

			if (costs[i][j] < current_min) {
				current_second_min = current_min;
				current_min = costs[i][j];
				current_color = j;
			} else if (costs[i][j] < current_second_min) {
				current_second_min = costs[i][j];
			}
		}

		previous_min = current_min;
		previous_second_min = current_second_min;
		previous_color = current_color;
	}

	int res = 1e8;
	for (int i = 0; i < k; i++) {
		if (costs[n - 1][i] < res) {
			res = costs[n - 1][i];
		}
	}
	return res;
}

int main()
{
	int costs[n][k] = {
		13, 2, 1,
		4, 2, 1,
		4, 6, 8,
		2, 11, 19
	};
	cout << minCost(costs) << endl;
}