#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100000;

int N, M;
int A[MAX], B[MAX];

bool is_existed(int num);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    cin >> M;

    for (int i = 0; i < M; i++)
        cin >> B[i];
    
    sort(&A[0], &A[0] + N);

    for (int i = 0; i < M; i++)
        cout << is_existed(B[i]) << "\n";

    return 0;
}

bool is_existed(int num)
{
    int left = 0, right = N - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (A[mid] == num)
            return true;
        
        else if (A[mid] < num)
            left = mid + 1;
        
        else 
            right = mid - 1;
    }

    return false;
}
