#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX = 1e6;

int N;
int seq[MAX], L[MAX];

int find_lower_bound(int L[MAX], int length, int num);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> seq[i];
    
    int length = 0;
    L[length++] = INT_MIN;
    
    for (int i = 0; i < N; i++)
    {
        if (L[length-1] < seq[i])
            L[length++] = seq[i];
        else
        {
            int index = find_lower_bound(L, length, seq[i]);
            L[index] = seq[i];
        }
    }

    cout << length - 1 << "\n";

    return 0;
}

int find_lower_bound(int L[MAX], int length, int num)
{
    int left = 0, right = length - 1;

    while (left < right)
    {
        int mid = (left + right) / 2;

        if (L[mid] >= num)
            right = mid;
        else
            left = mid + 1;
    }

    return right;
}
