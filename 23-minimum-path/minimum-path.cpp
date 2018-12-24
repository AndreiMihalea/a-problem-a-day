#include <iostream>
#include <queue>
#include <utility>
#include <math.h>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int height = 4, width = 4;

class Compare
{
public:
    bool operator() (pair<pair<int, int>, double> p1, pair<pair<int, int>, double> p2) {
        double d1 = p1.second;
        double d2 = p2.second;
        if (d1 < d2) {
            return false;
        }
        return true;
    }
};

double euclideanDist(pair<int, int> p1, pair<int, int> p2)
{
    double dx = p1.first - p2.first;
    double dy = p1.second - p2.second;
    return sqrt(dx * dx + dy * dy);
}

vector<pair<int, int>> getNeighbours(bool map[][width], pair<int, int> current)
{
    int x = current.first;
    int y = current.second;

    vector<pair<int, int>> neighbours;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (((i == 0 && j != 0) || (i != 0 && j == 0)) && x + i >= 0 && x + i < height &&
                    y + j >= 0 && y + j < width && map[x + i][y + j] == false) {
                neighbours.push_back(make_pair(x + i, y + j));
            }
        }
    }

    return neighbours;
}

int astar(bool map[][width], pair<int, int> start, pair<int, int> end,
        double (*heuristic)(pair<int, int>, pair<int, int>))
{
    priority_queue<pair<pair<int, int>, double>, vector<pair<pair<int, int>, double>>, Compare> pq;
    
    unordered_map<int, pair<pair<int, int>, double>> discovered;
    discovered[start.first * width + start.second] = make_pair(make_pair(-1, -1), 0);

    pq.push(make_pair(start, 0));

    while (!pq.empty()) {
        pair<int, int> current = pq.top().first;
        pq.pop();

        if (current == end) {
            break;
        }

        vector<pair<int, int>> neighbours = getNeighbours(map, current);
        for (auto& n : neighbours) {
            double new_cost = discovered[current.first * width + current.second].second;
            if (discovered.find(n.first * width + n.second) == discovered.end() ||
                     new_cost < discovered[n.first * width + n.second].second) {
                discovered[n.first * width + n.second] = make_pair(current, new_cost);
                double priority = new_cost = heuristic(end, n);
                pq.push(make_pair(n, priority));
            }
        }
    }

    vector<pair<int, int>> path;
    pair<int, int> current = end;

    while (current != make_pair(-1, -1)) {
        path.push_back(current);
        if (discovered.find(current.first * width + current.second) != discovered.end()) {
            current = discovered[current.first * width + current.second].first;
        } else {
            return 0;
        }
    }

    reverse(path.begin(), path.end());

    for (auto& p : path) {
        cout << p.first << " " << p.second << endl;
    }

    return path.size() - 1;
}

int main()
{
    bool map[height][width] = {
        {false, false, false, false},
        {true, true, false, true},
        {false, false, false, false},
        {false, false, false, false}
    };
    
    pair<int, int> start = make_pair(3, 0);
    pair<int, int> end = make_pair(0, 0);

    cout << astar(map, start, end, euclideanDist) << endl;
}