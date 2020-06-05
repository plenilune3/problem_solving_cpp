#include <iostream>
#include <vector>

using namespace std;

const int MAX = 20;

bool house[MAX][MAX];
int N, M;

int get_distance(int a, int b, int c, int d)
{
    int result = 0;

    if (a > c)
        result += a - c;
    else
        result += c - a;
    
    if (b > d)
        result += b - d;
    else
        result += d - b;

    return result;
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        vector< pair<int, int> > v;
        int answer = 0;
        cin >> N >> M;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
            {
                cin >> house[i][j];

                if (house[i][j])
                    v.push_back(make_pair(i, j));
            }
        
        for (int k = 1; k <= N + 1; k++)
        {
            int cost = k * k + (k - 1) * (k - 1);

            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                {
                    int range = k - 1;
                    int cnt = 0;

                    for (vector< pair<int, int> >::iterator iter = v.begin(); iter != v.end(); iter++)
                    {
                        int distance = get_distance(i, j, (*iter).first, (*iter).second);
                        if (distance <= range)
                            cnt += 1;
                    }

                    int benefit = cnt * M - cost;

                    if (benefit >= 0)
                        answer = max(answer, cnt);
                }
        }

        cout << "#" << t << " " << answer << "\n";
    }

    return 0;
}
