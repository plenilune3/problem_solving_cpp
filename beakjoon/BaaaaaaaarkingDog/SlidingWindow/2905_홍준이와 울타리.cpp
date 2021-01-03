#include <iostream>
#include <deque>

using namespace std;

const int MAX = 1e6 + 1;

int N, X, count, height[MAX];
long long area;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> X; 

    for (int i = 0; i < N; i++)
    {
        cin >> height[i];
        area += height[i];
    }

    deque< pair<int, int> > window_min;

    int base = 0, standard = 0; 

    for (int i = 0; i <= N; i++)
    {
        while (!window_min.empty() && window_min.back().second > height[i])
            window_min.pop_back();

        window_min.push_back(make_pair(i, height[i]));

        if (i < X - 1)
        {
            standard = window_min.front().second;
            continue;
        }

        while (!window_min.empty() && window_min.front().first <= i - X)
        {
            int temp = window_min.front().first;
            window_min.pop_front();

            if (standard != window_min.front().second)
            {
                count += (temp - base) / X + 1;
                area -= (long long) (temp - base + 1) * standard;
                base = temp + 1, standard = window_min.front().second;
            }
        }

        if (!window_min.empty() && standard != window_min.front().second)
        {
            count += (i - base - 1) / X + 1;
            area -= (long long) (i - base) * standard;
            base = i, standard = window_min.front().second;
        }
    }

    cout << area << "\n";
    cout << count << "\n";

    return 0;
}
