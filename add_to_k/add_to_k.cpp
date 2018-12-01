#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int main ()
{
    ifstream inFile;
    inFile.open("test.txt");

    int n, k, x;
    inFile >> k >> n;
    std::map<char,int> table;

    for (int i = 0; i < n; i++) {
        inFile >> x;
        table[x] = i;
        if (table.find(k - x) != table.end() && table[k - x] != i) {
            cout << "Found: " << x << " and " << k - x << endl;
            return 1;
        }
    }
    cout << "Not found\n";
    return 0;
}