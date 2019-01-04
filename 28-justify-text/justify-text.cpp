#include <iostream>
#include <string>
#include <vector>

using namespace std;

void addSpaces(vector<string> current_line, int k)
{
    /* I only print the lines and put "_" instead of spaces */

    int line_length = 0;
    for (auto &it: current_line) {
        line_length += it.length();
    }

    if (current_line.size() == 1) {
        cout <<  current_line[0];
        int rest = k - line_length;
        for (int i = 0; i < rest; i++) {
            cout << "_";
        }
        cout << endl;
        return;
    }

    int rest = k - line_length;
    int space_each = rest / (current_line.size() - 1);
    int spaces_left = rest % (current_line.size() - 1);

    for (int i = 0; i < current_line.size(); i++) {
        cout << current_line[i];
        if (i != current_line.size() - 1) {
            for (int j = 0; j < space_each; j++) {
                cout << "_";
            }
        }
        if (i < spaces_left) {
            cout << "_";
        }
    }
    cout << endl;
}

void justifyText(string arr[], int n, int k)
{
    int current_size = 0;
    vector<string> current_line;

    for (int i = 0; i < n; i++) {
        current_size += arr[i].length() + 1;
        if (current_size <= k + 1) {
            current_line.push_back(arr[i]);
        } else {
            addSpaces(current_line, k);
            current_line.clear();
            current_line.push_back(arr[i]);
            current_size = arr[i].length() + 1;
        }
    }
    addSpaces(current_line, k);
}

int main()
{
    string arr[] = {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
    int k = 16;
    int n = sizeof(arr) / sizeof(arr[0]);
    justifyText(arr, n, k);

    cout << endl;
    string arr2[] = {"the", "quick", "brown", "agile", "fox", "jumps", "over", "the", "lazy", "dog"};
    n = sizeof(arr2) / sizeof(arr2[0]);
    justifyText(arr2, n, k);
}