#include <iostream>
#include <vector>

using namespace std;

const int MAX = 6;
const int M = 1000;

int N;
vector< vector<int> > A(MAX, vector<int> (MAX, 0));
long long B;

vector< vector<int> > product(vector< vector<int> > &A, vector< vector<int> > &B);
vector< vector<int> > pow(long long b);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> B;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
            A[i][j] %= M;
        }
    
    vector< vector<int> > R = pow(B);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << R[i][j] << " ";
        cout << "\n";
    }

    return 0;
}

vector< vector<int> > product(vector< vector<int> > &A, vector< vector<int> > &B)
{
    vector< vector<int> > R(MAX, vector<int> (MAX, 0));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
            {
                R[i][j] += (A[i][k] * B[k][j]);
                R[i][j] %= M;
            }
    
    return R;
}

vector< vector<int> > pow(long long b)
{
    if (b == 1)
        return A;
    
    if (b % 2 == 0)
    {
        vector< vector<int> > n = pow(b / 2);
        return product(n, n);
    }
    else
    {
        vector< vector<int> > n = pow(b - 1);
        return product(n, A);
    }
}
