#include <iostream>

using namespace std;

const int MAX = 1e5 + 1;

int N;
int A[MAX];

long long find_max(int left, int right);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    cout << find_max(0, N - 1) << "\n";

    return 0;
}

long long find_max(int left, int right)
{
    if (left == right)
        return A[left];
    
    int mid = (left + right) / 2;
    long long ret = max(find_max(left, mid), find_max(mid + 1, right));

    int l = mid, r = mid;
    long long w = 1;
    long long min_num = min(A[l], A[r]);
    ret = max(ret, w * min_num);

    while (l > left || r < right)
    {
        if (r < right && (l == left || A[l - 1] < A[r + 1]))
            min_num = min(min_num, (long long) A[++r]);
        else
            min_num = min(min_num, (long long) A[--l]);
        
        ret = max(ret, ++w * min_num);
    }

    return ret;
}