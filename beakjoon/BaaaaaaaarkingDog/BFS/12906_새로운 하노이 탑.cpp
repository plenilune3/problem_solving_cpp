#include <iostream>
#include <queue>
#include <set>

using namespace std;

struct hanoi
{
    string stick[3];
    int depth;
};

bool is_finished(string a, string b, string c)
{
    for (int i = 0; i < a.size(); i++)
        if (a[i] != 'A') return false;
    
    for (int i = 0; i < b.size(); i++)
        if (b[i] != 'B') return false;
    
    for (int i = 0; i < c.size(); i++)
        if (c[i] != 'C') return false;
    
    return true;
}

int bfs(hanoi &h)
{
    set<string> visited;
    queue<hanoi> q;
    visited.insert(h.stick[0] + " " + h.stick[1] + " " + h.stick[2]);
    q.push(h);
    int result = -1;

    while(!q.empty())
    {
        string a = q.front().stick[0];
        string b = q.front().stick[1];
        string c = q.front().stick[2];
        int depth = q.front().depth;
        q.pop();

        if (is_finished(a, b, c))
        {
            result = depth;
            break;
        }
         
        if (!a.empty())
        {
            string next_a = a.substr(0, a.size() - 1), v;
            char plate = a[a.size() - 1];

            hanoi nh;
            nh.stick[0] = next_a, nh.stick[1] = b + plate, nh.stick[2] = c, nh.depth = depth + 1;
            v = nh.stick[0] + " " + nh.stick[1] + " " + nh.stick[2];
            if (visited.find(v) == visited.end())
            {
                visited.insert(v);
                q.push(nh);
            }

            nh.stick[0] = next_a, nh.stick[1] = b, nh.stick[2] = c + plate, nh.depth = depth + 1;
            v = nh.stick[0] + " " + nh.stick[1] + " " + nh.stick[2];
            if (visited.find(v) == visited.end())
            {
                visited.insert(v);
                q.push(nh);
            }
        }

        if (!b.empty())
        {
            string next_b = b.substr(0, b.size() - 1), v;
            char plate = b[b.size() - 1];

            hanoi nh;
            nh.stick[0] = a + plate, nh.stick[1] = next_b, nh.stick[2] = c, nh.depth = depth + 1;
            v = nh.stick[0] + " " + nh.stick[1] + " " + nh.stick[2];
            if (visited.find(v) == visited.end())
            {
                visited.insert(v);
                q.push(nh);
            }

            nh.stick[0] = a, nh.stick[1] = next_b, nh.stick[2] = c + plate, nh.depth = depth + 1;
            v = nh.stick[0] + " " + nh.stick[1] + " " + nh.stick[2];
            if (visited.find(v) == visited.end())
            {
                visited.insert(v);
                q.push(nh);
            }
        }

        if (!c.empty())
        {
            string next_c = c.substr(0, c.size() - 1), v;
            char plate = c[c.size() - 1];

            hanoi nh;
            nh.stick[0] = a + plate, nh.stick[1] = b, nh.stick[2] = next_c, nh.depth = depth + 1;
            v = nh.stick[0] + " " + nh.stick[1] + " " + nh.stick[2];
            if (visited.find(v) == visited.end())
            {
                visited.insert(v);
                q.push(nh);
            }

            nh.stick[0] = a, nh.stick[1] = b + plate, nh.stick[2] = next_c, nh.depth = depth + 1;
            v = nh.stick[0] + " " + nh.stick[1] + " " + nh.stick[2];
            if (visited.find(v) == visited.end())
            {
                visited.insert(v);
                q.push(nh);
            }
        }
    }

    return result;
}

int main(int argc, char const *argv[])
{
    hanoi h;

    for (int i = 0; i < 3; i++)
    {
        int N;
        cin >> N;

        if (N != 0)
            cin >> h.stick[i];
    }

    h.depth = 0;

    cout << bfs(h) << "\n";

    return 0;
}
