#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 2e5;

int N, H;
int stalagmite[MAX / 2], stalactite[MAX / 2];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> H;

    for (int i = 0; i < N / 2; i++)
        cin >> stalagmite[i] >> stalactite[i];
    
    sort(&stalagmite[0], &stalagmite[0] + N / 2);
    sort(&stalactite[0], &stalactite[0] + N / 2);

    int min_obstacle = 2e5 + 1, count = 0;

    for (int i = 1; i <= H; i++)
    {
        int lower = lower_bound(&stalagmite[0], &stalagmite[0] + N / 2, i) - &stalagmite[0];
        int upper = upper_bound(&stalactite[0], &stalactite[0] + N / 2, H - i) - &stalactite[0];
        int lower_count = (N / 2) - lower, upper_count = (N / 2) - upper;
        int obstacle = lower_count + upper_count;

        if (obstacle == min_obstacle)
            count += 1;
        else if (obstacle < min_obstacle)
        {
            min_obstacle = obstacle;
            count = 1;
        }
    }

    cout << min_obstacle << " " << count << "\n";

    return 0;
}