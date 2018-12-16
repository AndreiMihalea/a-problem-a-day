#include <iostream>
#include <map>
using namespace std;

int kDistinctSubsequence(string s, int k)
{
    if (s.length() == 0 || k < 1) {
        return 0;
    }

    if (s.length() <= k) {
        return s.length();
    }

    int res = k;
    int first = 0;

    map<char, int> counter;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (counter.find(c) == counter.end()) {
            counter[c] = 1;
        } else {
            counter[c] += 1;
        }

        while(counter.size() > k) {
            char f = s[first];
            first += 1;
            counter[f] -= 1;
            if (counter[f] == 0) {
                counter.erase(f);
            }
        }

        res = max(res, i - first + 1);
    }

    return res;
}

int main()
{
    string s = "abbecebaabwb";
    int k = 2;
    cout << kDistinctSubsequence(s, k) << endl;
}