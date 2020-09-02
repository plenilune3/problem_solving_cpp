#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

const int MAX = 1e6 + 1;

int N;
int A[MAX], L[MAX];
pair<int, int> R[MAX];

int find_LIS_length();
stack<int> make_LIS(int length);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    int length = find_LIS_length();
    stack<int> LIS = make_LIS(length);

    cout << length << "\n";

    while (!LIS.empty())
    {
        cout << LIS.top() << " ";
        LIS.pop();
    }

    cout << "\n";

    return 0;
}

stack<int> make_LIS(int length)
{
    stack<int> LIS;

    for (int i = N - 1; i >= 0; i--)
        if (R[i].first == length)
        {
            LIS.push(R[i].second);
            length--;
        }
    
    return LIS;
}

int find_LIS_length()
{
    int length = 0;
    L[length++] = INT_MIN;

    for (int i = 0; i < N; i++)
    {
        if (L[length - 1] < A[i])
        {
            L[length++] = A[i];
            R[i] = make_pair(length - 1, A[i]);
        }
        else
        {
            int pos = lower_bound(&L[0], &L[0] + length, A[i]) - &L[0];
            L[pos] = A[i];
            R[i] = make_pair(pos, A[i]);
        }
    }

    return length - 1;
}
