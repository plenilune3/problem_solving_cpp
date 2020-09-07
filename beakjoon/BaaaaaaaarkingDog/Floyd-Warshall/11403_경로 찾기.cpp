#include <iostream>

using namespace std;

const int MAX = 102;

int N;
bool adjacency[MAX][MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> adjacency[i][j];
    
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (adjacency[i][k] && adjacency[k][j])
                    adjacency[i][j] = 1;
    
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
             cout << adjacency[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
