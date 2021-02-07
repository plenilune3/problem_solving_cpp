#include <iostream>

using namespace std;

const int MAX = 1e6 + 1;

int N, A[MAX], temp[MAX];
long long answer;

void merge(int left, int right);
void merge_sort(int left, int right);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> A[i];

    merge_sort(0, N);

    cout << answer << "\n";

    return 0;
}

void merge(int left, int right)
{
    int mid = (left + right) / 2;
    int l = left, r = mid;

    for (int i = left; i < right; i++)
    {
        if (l == mid) temp[i] = A[r++];
        else if (r == right) temp[i] = A[l++];
        else if (A[l] <= A[r]) temp[i] = A[l++];
        else
        {
            temp[i] = A[r++];
            answer += (long long) mid - l;
        }
    }

    for (int i = left; i < right; i++)
        A[i] = temp[i];
}

void merge_sort(int left, int right)
{
    if (left + 1 == right)
        return;
    
    int mid = (left + right) / 2;

    merge_sort(left, mid);
    merge_sort(mid, right);
    merge(left, right);
}
