#include <iostream>

using namespace std;

int waterFill(int arr[], int n)
{
    int left_max = 0, right_max = 0;
    int left_index = 0, right_index = n - 1;

    int result = 0;

    while (left_index < right_index) {
        if (arr[left_index] < arr[right_index]) {
            if (arr[left_index] > left_max) {
                left_max = arr[left_index];
            } else {
                result += left_max - arr[left_index];
            }
            left_index += 1;
        } else {
            if (arr[right_index] > right_max) {
                right_max = arr[right_index];
            } else {
                result += right_max - arr[right_index];
            }
            right_index -= 1;
        }
    }

    return result;
}

int main()
{   
    int arr[] = {3, 0, 1, 3, 0, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << waterFill(arr, n) << endl;
}