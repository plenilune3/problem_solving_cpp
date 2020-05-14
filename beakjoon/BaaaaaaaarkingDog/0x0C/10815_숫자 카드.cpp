#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

bool binary_search(int* a, int target)
{
    int left = 0;
    int right = N - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (a[mid] == target)
            return true;
        
        if (a[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return false;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    int* a = new int[N];
    for (int i = 0; i < N; i++)
        cin >> a[i];
    
    sort(&a[0], &a[0] + N);

    cin >> M;
    int* b = new int[M];
    for (int i = 0; i < M; i++)
        cin >> b[i];
    
    for (int i = 0; i < M; i++)
        cout << binary_search(a, b[i]) << " ";
    
    return 0;
}
