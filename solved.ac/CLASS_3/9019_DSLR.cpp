#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 10001;

int visited[MAX];
string temp[MAX];

string bfs(int S, int E);
string get_route(string temp[MAX], int visited[MAX], int S, int E);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T; cin >> T;

    while (T--)
    {
        int S, E; cin >> S >> E;
        cout << bfs(S, E) << "\n";
    }

    return 0;
}

string bfs(int S, int E)
{
    queue<int> q;

    fill_n(&visited[0], MAX, -1);

    visited[S] = S;
    temp[S] = "";
    q.push(S);

    while (!q.empty())
    {
        int x = q.front(); q.pop();

        if (x == E) break;

        int nx = (x * 2) % 10000;

        if (visited[nx] == -1)
        {
            visited[nx] = x;
            temp[nx] = "D";
            q.push(nx);
        }

        nx = (x - 1) >= 0 ? x - 1 : 9999;

        if (visited[nx] == -1)
        {
            visited[nx] = x;
            temp[nx] = "S";
            q.push(nx);
        }

        int d = x / 1000, r = x % 1000;
        nx = r * 10 + d;

        if (visited[nx] == -1)
        {
            visited[nx] = x;
            temp[nx] = "L";
            q.push(nx);
        }

        d = x / 10, r = x % 10;
        nx = r * 1000 + d;

        if (visited[nx] == -1)
        {
            visited[nx] = x;
            temp[nx] = "R";
            q.push(nx);
        }
    }

    return get_route(temp, visited, S, E);
}

string get_route(string temp[MAX], int visited[MAX], int S, int E)
{
    string route = "";

    while (E != S)
    {
        route.append(temp[E]);
        E = visited[E];
    }

    reverse(route.begin(), route.end());

    return route;
}
