#include <iostream>

using namespace std;

const int MAX = 1e6 + 1;

int N, M;
bool is_prime[MAX];

void eratos(int n);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> M >> N;

    eratos(N);

    for (int i = M; i <= N; i++)
        if (is_prime[i])
            cout << i << "\n";

    return 0;
}

void eratos(int n)
{
    if (n <= 1) return;

    for (int i = 2; i <= n; i++)
        is_prime[i] = true;
    
    for (int i = 2; i * i <= n; i++)
        if (is_prime[i])
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
}
