#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

bool arr[10000];
int dist[10000];

template<typename T>
string to_string(const T& value)
{
    stringstream ss;
    ss << value;
    return ss.str();
}

int to_int(string value)
{
    int ret = 0;

    for (int i = 0; i < 4; i++)
        ret = ret * 10 + (value[i] - '0');
    
    return ret;
}

void set_prime()
{
    arr[1] = true;

    for (int i = 2; i <= sqrt(9999); i++)
    {
        if (arr[i] == true)
            continue;
        
        for (int j = i + i; j <= 9999; j += i)
            arr[j] = true;
    }
}

int bfs(int s, int t)
{
    fill_n(&dist[0], 10000, -1);
    queue<int> q;
    dist[s] = 0;
    q.push(s);

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        if (x == t)
            return dist[x];

        for (int i = 0; i < 4; i++)
        {
            string s = to_string(x);

            for (int j = 0; j < 10; j++)
            {
                s[i] = j + '0';

                int next = to_int(s);

                if (next >= 1000 && arr[next] == false && dist[next] == -1)
                {
                    dist[next] = dist[x] + 1;
                    q.push(next);
                }
            }
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    set_prime();

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        int A, B;
        cin >> A >> B;

        int result = bfs(A, B);

        if (result == -1)
            cout << "Impossible\n";
        else
            cout << result << "\n";
    }

    return 0;
}
