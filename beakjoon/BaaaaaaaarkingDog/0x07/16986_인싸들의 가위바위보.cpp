#include <iostream>
#include <deque>
#include <vector>

using namespace std;

const int MAX = 11;

int N, K;
int A[MAX][MAX];
deque<int> B[3];
vector<int> v;
bool visited[MAX];
bool answer;

void game()
{
    deque<int> C[3];
    copy(&B[0], &B[0] + 3, &C[0]);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            cout << C[i].front() << " ";
            C[i].pop_front();
        }
        cout << "\n";
    }
    // bool possible = true;
    // int winning_cnt[] = { 0, 0, 0 };
    // int winner = 0;

    // while (true)
    // {

    // }
    
}

void permutations(int depth)
{
    if (answer)
        return;

    if (depth == N)
    {
        game();
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            B[0].push_back(i);
            permutations(depth + 1);
            visited[i] = false;
            B[0].pop_back();
        }
    }
}

int main(int argc, char const *argv[])
{
    cin >> N >> K;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> A[i][j];
    
    for (int i = 1; i <= 2; i++)
        for (int j = 0; j < 20; j++)
        {
            int t;
            cin >> t;

            B[i].push_back(t);
        }
    
    // permutations(0);

    game();

    cout << answer << "\n";

    return 0;
}
