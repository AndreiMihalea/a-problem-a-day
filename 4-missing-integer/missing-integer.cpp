#include <iostream>
#include <map>
using namespace std;

int main()
{
    int a[] = {3, 16, 2, 1, -22, -14, 77, 40, -54, 1207, 4, 5, 21, 6};
    
    // move the non positive elements at the beginning
    int counter = 0;
    for (int i = 0; i < sizeof(a)/sizeof(*a); i++) {
        if (a[i] <= 0) {
            int aux = a[i];
            a[i] = a[counter];
            a[counter] = aux;
            counter += 1;
        }
    }

    for (int i = counter; i < sizeof(a)/sizeof(*a); i++) {
        a[a[i]] = -1;
    }

    for (int i = counter; i < sizeof(a)/sizeof(*a); i++) {
        if (a[i] > 0) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}