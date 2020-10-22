#include <iostream>
#include <queue>

using namespace std;

int N, target;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T; cin >> T;

    while (T--)
    {
        int counter = 0;

        cin >> N >> target;

        queue< pair<int, int> > q;
        priority_queue<int> pq;

        for (int i = 0; i < N; i++)
        {
            int priority; cin >> priority;
            q.push(make_pair(i, priority));
            pq.push(priority);
        }

        while (!q.empty())
        {
            int i = q.front().first, p = q.front().second;
            q.pop();

            if (pq.top() == p)
            {
                pq.pop();
                counter += 1;

                if (i == target)
                    break;
            }
            else
                q.push(make_pair(i, p));
        }

        cout << counter << "\n";
    }

    return 0;
}
