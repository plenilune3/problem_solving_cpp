#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e5;

int N, S;
int seq[MAX];
int p[MAX + 1];

int find_min_length();
void prefix_sum();
int get_prefix_sum(int x, int y);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> S;

    for (int i = 0; i < N; i++)
        cin >> seq[i];
    
    prefix_sum();

    int answer = find_min_length();

    if (answer != MAX + 1)
        cout << answer << "\n";
    else
        cout << 0 << "\n";

    return 0;
}

int get_prefix_sum(int x, int y)
{
    return p[y + 1] - p[x];
}

void prefix_sum()
{
    for (int i = 1; i <= N; i++)
        p[i] = p[i - 1] + seq[i - 1];
}

int find_min_length()
{
    int left = 1, right = N;
    int min_length = MAX + 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        bool is_possible = false;

        for (int i = 0; i < N; i++)
        {
            int prefix_sum = get_prefix_sum(i, i + (mid - 1));

            if (prefix_sum >= S)
            {
                is_possible = true;
                break;
            }
        }

        if (is_possible)
        {
            min_length = min(min_length, mid);
            right = mid - 1;
        }
        else
            left = mid + 1;
    }

    return min_length;
}
