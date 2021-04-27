#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 5e4 + 2;

int N, S, A[MAX], B[MAX];

void calculate_dist(int N, int A[MAX]);
int calculdate_max_dist(int N, int B[MAX]);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        S += A[i];
    }
    
    calculate_dist(N, A);

    int answer = calculdate_max_dist(N, B);

    cout << answer << "\n";

    return 0;
}

int calculdate_max_dist(int N, int B[MAX])
{
    int result = min(B[1] - B[0], S - (B[1] - B[0]));
    int left = 0, right = 0;

    while (true)
    {
        int p = B[right + 1] - B[left];
        int q = S - p;

        if (p > q)
            left += 1;
        else if (right == N)
            break;
        else
            right += 1;
        
        result = max(result, min(p, q));
    }

    return result;
}

void calculate_dist(int N, int A[MAX])
{
    for (int i = 1; i < N + 1; i++)
        B[i] = A[i - 1] + B[i - 1];
}
