#include <iostream>
#include <queue>

using namespace std;

const int MAX = 10;

int N, K;
int h[MAX];
int c[MAX];
bool visited[360];
queue<int> q;

int get_differnce(int a, int b)
{
    if (a > b)
        return a - b;
    else
        return b - a;
}

void bfs()
{
    while(!q.empty())
    {
        int c = q.front();
        q.pop();

        bool visited_copy[360];
        copy(&visited[0], &visited[0] + 360, &visited_copy[0]);

        for (int i = 0; i < 360; i++)
        {
            if (visited[i] == false)
                continue;
            
            int a = (c + i) % 360;
            int b = (get_differnce(c, i)) % 360;

            if (visited[a] == false)
            {
                visited_copy[a] = true;
                q.push(a);
            }

            if (visited[b] == false)
            {
                visited_copy[b] = true;
                q.push(b);
            }
        }

        copy(&visited_copy[0], &visited_copy[0] + 360, &visited[0]);
    }
}




int main(int argc, char const *argv[])
{
    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> c[i];
        q.push(c[i]);
        visited[c[i]] = true;
    }
    
    for (int i = 0; i < K; i++)
        cin >> h[i];
    
    bfs();

    // for (int i = 0; i < 360; i++)
    // {
    //     cout << i << ": " << visited[i] << "\n";
    // }

    for (int i = 0; i < K; i++)
    {
        if (visited[h[i]])
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
