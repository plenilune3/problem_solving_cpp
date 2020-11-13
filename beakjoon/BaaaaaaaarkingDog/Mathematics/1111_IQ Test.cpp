#include <iostream>

using namespace std;

const int MAX = 51;

int N, a, b;
int A[MAX];

string find_last();

int main(int argc, char const *argv[])
{
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    cout << find_last() << "\n";

    return 0;
}

string find_last()
{
    if (N == 1)
        return "A";
    else if (N == 2)
    {
        if (A[0] == A[1]) return to_string(A[0]);
        else return "A";
    }
    
    int a, b;

    if (A[0] == A[1]) a = 0;
    else a = (A[2] - A[1]) / (A[1] - A[0]);

    b = A[1] - A[0] * a;

    for (int i = 1; i < N; i++)
        if (A[i] != A[i - 1] * a + b)
            return "B";
    
    return to_string(A[N - 1] * a + b);
}
