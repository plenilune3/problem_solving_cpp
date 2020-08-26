#include <iostream>

using namespace std;

const int MAX = 8;

int N, K, answer;
int exercise[MAX];
bool visited[MAX];

void weight_trainning(int depth, int result);

int main(int argc, char const *argv[])
{
    cin >> N >> K;

    for (int i = 0; i < N; i++)
        cin >> exercise[i];
    
    weight_trainning(0, 500);

    cout << answer << "\n";

    return 0;
}

void weight_trainning(int depth, int result)
{
    if (result < 500)
        return;
    
    if (depth == N)
    {
        answer += 1;
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (visited[i])
            continue;
        
        visited[i] = true;
        weight_trainning(depth + 1, result - K + exercise[i]);
        visited[i] = false;
    }
}

