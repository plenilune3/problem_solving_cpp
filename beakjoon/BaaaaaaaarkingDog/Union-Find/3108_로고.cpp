#include <iostream>

using namespace std;

const int MAX = 1e3 + 1;

struct rectangle
{
   int x1, y1, x2, y2;
};

int N;
int parent[MAX];
rectangle rectangles[MAX];

int find_(int u);
void union_(int u, int v);
bool is_connected(rectangle a, rectangle b);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i <= N; i++)
        parent[i] = i;
    
    for (int i = 1; i <= N; i++)
        cin >> rectangles[i].x1 >> rectangles[i].y1 >> rectangles[i].x2 >> rectangles[i].y2;
    
    for (int i = 0; i <= N; i++)
        for (int j = i + 1; j <= N; j++)
            if (is_connected(rectangles[i], rectangles[j]))
                union_(i, j);
    
    int answer = 0;

    for (int i = 0; i <= N; i++)
        if (find_(i) == i)
            answer += 1;
    
    cout << answer - 1 << "\n";

    return 0;
}

int find_(int u)
{
    if (parent[u] == u)
        return u;
    else
    {
        int v = find_(parent[u]);
        return parent[u] = v;
    }
}

void union_(int u, int v)
{
    u = find_(u), v = find_(v);

    if (u == v) return;

    parent[u] = v;
}

bool is_connected(rectangle a, rectangle b)
{
    if (a.x1 < b.x1 && b.x2 < a.x2 && a.y1 < b.y1 && a.y2 > b.y2)
        return false;
    if (b.x1 < a.x1 && a.x2 < b.x2 && b.y1 < a.y1 && b.y2 > a.y2)
        return false;
    if (b.x1 > a.x2 || b.x2 < a.x1 || b.y1 > a.y2 || b.y2 < a.y1)
        return false;

    return true;
}