#include <iostream>
#include <map>
using namespace std;

int main()
{
	int a[] = {3, 16, 2, 1, 77, 40, 12071, 4, 5, 21, 6};
	std::map<char,int> table;
	for (int i = 0; i < (sizeof(a)/sizeof(*a)); i++) {
		table[a[i]] = 1;
	}

	int counter = 1;
	while (1) {
		if (table.find(counter) == table.end()) {
			break;
		} else {
			counter += 1;
		}
	}

	cout << counter << endl;
	return 0;
}