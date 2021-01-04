#include <iostream>

using namespace std;

const int MAX = 2e5 + 2;

int N, M, S, K;
char fruits[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    cin >> fruits;

    M = N / 2;
    S = K = N / 4;

    int k = 0, left = 0, right = 0;
    int counter_s = 0, counter_k = 0;

    for (right = 0; right < M; right++)
        if (fruits[right] == 's') counter_s += 1;
        else counter_k += 1;
    
    if (counter_s == S && counter_k == K)
        k = 1;
   
    while (right != N)
    {
        if (counter_s == S && counter_k == K)
            break;
        
        if (fruits[left++] == 's') counter_s -= 1;
        else counter_k -= 1;

        if (fruits[right++] == 's') counter_s += 1;
        else counter_k += 1;
    }

    if (k == 1)
    {
        cout << 1 << "\n";
        cout << right << "\n";
    }
    else
    {
        cout << 2 << "\n";
        cout << left << " " << right << "\n";
    }

    return 0;
}
