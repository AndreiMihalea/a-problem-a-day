#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

int minRooms(pair<int, int> intervals[], int n)
{
	vector<pair<int, char>> all_events;

	for (int i = 0; i < n; i++) {
		int start, end;
		tie(start, end) = intervals[i];
		all_events.push_back(make_pair(start, 's'));
		all_events.push_back(make_pair(end, 'e'));
	}

	sort(all_events.begin(), all_events.end());

	int res = 0;
	int rooms = 0;

	for (int i = 0; i < 2 * n; i++) {
		if (all_events[i].second == 's') {
			rooms += 1;
		} else {
			rooms -= 1;
		}
		if (rooms > res) {
			res = rooms;
		}
	}

	return res;
}

int main()
{
	pair<int, int> intervals[] = {make_pair(30, 75), make_pair(0, 50), make_pair(60, 150)};
	cout << minRooms(intervals, sizeof(intervals) / sizeof(intervals[0])) << endl;
}
