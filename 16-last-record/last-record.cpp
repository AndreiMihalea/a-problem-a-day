#include <iostream>
#include <map>
using namespace std;


int counter = 0;
const int N = 4;
int buffer[N];
bool inserted = false;

void record(int order_id)
{
	buffer[counter] = order_id;
	counter += 1;
	if (counter == N) {
		counter = 0;
	}
	inserted = true;
}

void get_last(int i)
{
	if (!inserted) {
		return;
	}
	
	int last_index = counter - 1;

	if (last_index == -1) {
		last_index = N - 1;
	}

	if (last_index - i < 0) {
		for (int it = N - (i - last_index - 1); it < N; it++) {
			cout << buffer[it] << " ";
		}
		for (int it = 0; it < last_index + 1; it++) {
			cout << buffer[it] << " ";
		}
	} else {
		for (int it = last_index - i + 1; it < last_index + 1; it++) {
			cout << buffer[it] << " ";
		}
	}

	cout << endl;
}

int main()
{
	record(6);
	record(3);
	record(1);
	record(5);
	record(9);
	record(11);
	record(27);
	record(31);
	record(6);
	get_last(3);
}