#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 3e5 + 1;

int D, N;
int oven[MAX], dough[MAX];

int get_top();
int find_depth(int left, int depth);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> D >> N;

    for (int i = 0; i < D; i++)
        cin >> oven[i];
    
    for (int i = 0; i < N; i++)
        cin >> dough[i];
    
    int min_oven = oven[0];

    for (int i = 0; i < D; i++)
    {
        min_oven = min(min_oven, oven[i]);
        oven[i] = min_oven;
    }

    sort(oven, oven + D);

    int top = get_top();

    if (top)
        cout << D - top + 1 << "\n";
    else
        cout << 0 << "\n";

    return 0;
}

int get_top()
{
    int left = -1;

    for (int i = 0; i < N; i++)
    {
        left = find_depth(left + 1, dough[i]);

        if (left == -1)
            return 0;
    }

    return left + 1;
}

int find_depth(int left, int target)
{
    int result = -1;
    int right = D - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (oven[mid] >= target)
        {
            result = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }

    return result;
}
