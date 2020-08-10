#include <cstdio>
#include <queue>
#include <deque>

using namespace std;

int main(int argc, char const *argv[])
{
    deque<int> dq;
    queue<int> q;

    int n, w, l, sec = 0;
    scanf("%d %d %d", &n, &w, &l);

    for (int i = 0; i < n; i++)
    {
        int truck;
        scanf("%d", &truck);
        q.push(truck);
    }

    for (int i = 0; i < w; i++)
        dq.push_back(0);

    while (!dq.empty())
    {
        sec++;
        dq.pop_front();

        int weight = 0;
        deque<int>::iterator iter;
        for (iter = dq.begin(); iter != dq.end(); iter++)
            weight += (*iter);

        if (!q.empty())
        {
            if (weight + q.front() <= l)
            {
                dq.push_back(q.front());
                q.pop();
            }
            else
                dq.push_back(0);
        }
    }

    printf("%d\n", sec);

    return 0;
}
