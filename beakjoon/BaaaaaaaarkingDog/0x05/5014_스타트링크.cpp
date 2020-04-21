#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
const int MAX = 1000001;
bool visited[MAX];

int F, S, G, U, D;

int bfs()
{
    queue< pair<int, int> > q;
    visited[S] = true;
    q.push(make_pair(S, 0));

    while (!q.empty())
    {
        pair<int, int> c = q.front();
        q.pop();

        if (c.first == G)
            return c.second;

        if (c.first + U <= F && visited[c.first + U] == false)
        {
            visited[c.first + U] = true;
            q.push(make_pair(c.first + U, c.second + 1));
        }

        if (c.first - D >= 1 && visited[c.first - D] == false)
        {
            visited[c.first - D] = true;
            q.push(make_pair(c.first - D, c.second + 1));
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    cin >> F >> S >> G >> U >> D;

    fill_n(&visited[0], MAX, false);

    int answer = bfs();

    if (answer == -1)
        cout << "use the stairs" << "\n";
    else
        cout << answer << "\n";

    return 0;
}
