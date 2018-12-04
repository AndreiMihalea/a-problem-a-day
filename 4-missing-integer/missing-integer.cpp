#include <iostream>
#include <map>
using namespace std;

int main()
{
    int a[] = {3, 16, 2, 2, -22, -14, 77, 40, -54, 120, 4, 5, 21, 6, 1};
    
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

    std::copy(a + counter, a + sizeof(a)/sizeof(*a), a);

    for (int i = 0; i < sizeof(a)/sizeof(*a); i++) {
        if(abs(a[i]) - 1 < sizeof(a)/sizeof(*a) && a[abs(a[i]) - 1] > 0) {
            a[abs(a[i]) - 1] = -a[abs(a[i]) - 1];
        }
    }

    for (int i = 0; i < sizeof(a)/sizeof(*a); i++) {
        if (a[i] > 0) {
            cout << i + 1 << endl;
            break;
        }
    }

    return 0;
}