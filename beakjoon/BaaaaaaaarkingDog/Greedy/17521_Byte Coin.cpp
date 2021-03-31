#include <iostream>

using namespace std;

const int MAX = 16;

int N;
long long W, S[MAX];

int main(int argc, char const *argv[])
{
    cin >> N >> W;

    for (int i = 0; i < N; i++)
        cin >> S[i];
    
    bool flag = false;
    long long C = 0;

    for (int i = 0; i < N - 1; i++)
    {
        long long temp = S[i] - S[i + 1];

        if (temp < 0 && !flag)
        {
            C = W / S[i];
            W = W % S[i];
            flag = true;
        }
        else if (temp > 0 && flag)
        {
            W += C * S[i];
            C = 0;
            flag = false;
        }
    }
    W += C * S[N - 1];

    cout << W << "\n";
    
    return 0;
}
