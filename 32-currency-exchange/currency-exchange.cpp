#include <iostream>
#include <math.h>
#include <limits>

using namespace std;
const int N = 3;

bool negative_cycle(double exchange_rates[N][N])
{
    double inf = numeric_limits<double>::infinity();

    double distances[N];

    for (int i = 0; i < N; i++) {
        distances[i] = inf;
    }

    distances[0] = 0;

    // relax
    for (int r = 0; r < N - 1; r++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (distances[j] > distances[i] + exchange_rates[i][j]) {
                    distances[j] = distances[i] + exchange_rates[i][j];
                }
            }
        }
    }

    // if we can still relax, there is a negative cycle
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (distances[j] > distances[i] + exchange_rates[i][j]) {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    double exchange_rates[N][N] = {{1, 2, 3}, {1./2, 1, 3./2}, {1./3, 2./3, 1}};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            exchange_rates[i][j] = -log(exchange_rates[i][j]);
        }
    }

    // problem is equivalent to finding a negative cycle
    cout << negative_cycle(exchange_rates) << endl;
}