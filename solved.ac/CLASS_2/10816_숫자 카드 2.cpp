#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 5e5 + 1;

int N, M;
int cards[MAX];

int lower_bound_(int target);
int upper_bound_(int target);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> cards[i];
    
    sort(cards, cards + N);

    cin >> M;

    while (M--)
    {
        int target; cin >> target;
        int left = lower_bound_(target);
        int right = upper_bound_(target);

        if (right == N && cards[right - 1] != target)
            cout << 0 << "\n";
        else
            cout << (right - left) << " ";
    }

    cout << "\n";

    return 0;
}

int lower_bound_(int target)
{
    int left = 0, right = N - 1;
    int bound = 0;

    while (left <= right)
    {
        long long mid = (left + right) / 2;

        if (cards[mid] < target)
            left = mid + 1;
        else
        {
            bound = mid;
            right = mid - 1;
        }
    }

    return bound;
}

int upper_bound_(int target)
{
    int left = 0, right = N - 1;
    int bound = N;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (cards[mid] <= target)
            left = mid + 1;
        else
        {
            bound = mid;
            right = mid - 1;
        }
    }

    return bound;
}
