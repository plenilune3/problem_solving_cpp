#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100;

int N, M;
int cards[MAX];

int main(int argc, char const *argv[])
{
    int answer = 0;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> cards[i];
    
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            for (int k = j + 1; k < N; k++)
            {
                int result = cards[i] + cards[j] + cards[k];

                if (result <= M)
                    answer = max(answer, result);
            }
    
    cout << answer << "\n";
    
    return 0;
}
