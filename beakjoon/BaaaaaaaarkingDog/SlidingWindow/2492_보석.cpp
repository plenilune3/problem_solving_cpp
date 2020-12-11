#include <iostream>
#include <vector>

using namespace std;

int N, M, T, K, X, Y, answer;
vector< pair<int, int> > v;

int count_(int x, int y);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> T >> K;

    for (int i = 0; i < T; i++)
    {
        int x, y; cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

    for (int i = 0; i < T; i++)
        for (int j = 0; j < T; j++)
        {
            int x = (v[i].first + K > N) ? N - K : v[i].first;
            int y = (v[j].second + K > M) ? M - K : v[j].second;

            int temp = count_(x, y);

            if (answer < temp)
            {
                answer = temp;
                X = x, Y = y + K;
            }
        }
    
    cout << X << " " << Y << "\n";
    cout << answer << "\n";

    return 0;
}

int count_(int x, int y)
{
    int result = 0;

    for (vector< pair<int, int> >::iterator i = v.begin(); i != v.end(); i++)
        if (x <= (*i).first && (*i).first <= x + K && y <= (*i).second && (*i).second <= y + K)
            result += 1;
    
    return result;
}