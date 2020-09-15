#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long N;
int K, Q;

long long get_parent(long long x, int k);
int get_distance(long long u, long long v);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K >> Q;

    while (Q--)
    {
        long long u, v;
        cin >> u >> v;

        if (K == 1)
        {
            cout << llabs(u - v) << "\n";
            continue;
        }

        cout << get_distance(u, v) << "\n";
   }

    return 0;
}

long long get_parent(long long x, int k)
{
    return (x + k - 2) / k;
}

int get_distance(long long u, long long v)
{
    int distance = 0;

    while (u != v)
    {
        while (u > v)
        {
            u = get_parent(u, K);
            distance += 1;
        }

        while (v > u)
        {
            v = get_parent(v, K);
            distance += 1;
        }
    }

    return distance;
}
