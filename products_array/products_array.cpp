#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;

#define EPS 1e-9

void product_array(int n, int array[])
{
    int left[n], right[n];
    left[0] = 1;
    right[n - 1] = 1;

    for (int i = 1; i < n; i++) {
        left[i] = array[i - 1] * left[i - 1];
    }

    for (int i = n - 2; i >= 0; i--) {
        right[i] = right[i + 1] * array[i + 1];
    }

    for (int i = 0; i < n; i++) {
        cout << left[i] * right[i] << " ";
    }

    cout << endl;
    return;
}

/*
 * O(1) space solution
 * Using sum of logarithms instead of prodcut
 */
void product_array_log(int n, int array[])
{
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (float)log10(array[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << pow((float)10, sum - log10(array[i])) << " ";
    }

    cout << endl;
    return;
}

int main()
{
    ifstream inFile;
    inFile.open("test.txt");

    int n, x;
    inFile >> n;
    int array[n];

    for (int i = 0; i < n; i++) {
        inFile >> x;
        array[i] = x;
    }
    
    product_array(n, array);
    product_array_log(n, array);
}