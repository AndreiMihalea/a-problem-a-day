#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
	srand(time(NULL));
	cout.precision(10);
	int inside = 0;
	int N = 1e8;
	for (int i = 0; i < N; i++) {
		double x = (double)rand() / (double)RAND_MAX;
		double y = (double)rand() / (double)RAND_MAX;
		if (x * x + y * y <= 1) {
			inside += 1;
		}
	}

	cout << 4 * (double)inside / N<< endl;
}