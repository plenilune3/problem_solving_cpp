#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 2e5;

int N, C;
int house[MAX];

int find_distance();

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> N >> C;

    for (int i = 0; i < N; i++)
        cin >> house[i];
    
    sort(&house[0], &house[0] + N);

    int answer = find_distance();

    cout << answer << "\n";

    return 0;
}

int find_distance()
{
    int left = 1, right = house[N - 1] - house[0];
    int max_distance = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        int count = 1, prev = house[0];

        for (int i = 1; i < N; i++)
        {
            int distance = house[i] - prev;

            if (distance >= mid)
            {
                count += 1;
                prev = house[i];
            }
        }

        if (count >= C)
        {
            max_distance = max(max_distance, mid);
            left = mid + 1;
        }
        else
            right = mid - 1;
    }

    return max_distance;
}
