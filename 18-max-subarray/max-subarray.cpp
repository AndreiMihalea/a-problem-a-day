#include <iostream>
#include <deque>
using namespace std;

void maxSubarray(int array[], int n, int k)
{
    deque<int> q(k);

    for (int i = 0; i < k; i++) {
        while (!q.empty() && array[i] >= array[q.back()]) {
            q.pop_back();
        }
        q.push_back(i);
    }

    for (int i = k; i < n; i++) {
        cout << array[q.front()] << " ";

        while (!q.empty() && i - k >= q.front()) {
            q.pop_front();
        }
        
        while (!q.empty() && array[i] >= array[q.back()]) {
            q.pop_back();
        }

        q.push_back(i);
    }

    cout << array[q.front()] << endl;
}

int main()
{
    int array[] = {10, 5, 2, 7, 8, 7};
    int n = sizeof(array) / sizeof(array[0]);
    int k = 3;

    maxSubarray(array, n, k);
}