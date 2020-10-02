#include <iostream>
#include <bitset>
#include <vector>
#include <map>

using namespace std;

const int MAX_N = 101;
const int MAX_M = 21;

int N, M;
bool visited[MAX_M];
bitset<MAX_N> door;
bitset<MAX_N> change[MAX_M];
map< int, vector<int> > answer;

void combinations(int depth, int cnt, bitset<MAX_N> d);

int main(int argc, char const *argv[])
{
    cin >> N >> M;

    cin >> door;

    for (int i = 0; i < M; i++)
        cin >> change[i];
    
    for (int i = -N; i <= N; i++)
        answer[i] = vector<int> (1, -1);
    
    combinations(0, 0, door);

    for (map< int, vector<int> >::iterator i = answer.begin(); i != answer.end(); i++)
    {
        for (vector<int>::iterator j = (*i).second.begin(); j != (*i).second.end(); j++)
            cout << (*j) << " ";
        cout << "\n";
    }

    return 0;
}

void combinations(int depth, int cnt, bitset<MAX_N> d)
{
    if (depth == M)
    {
        int result = -N + d.count() * 2;
        vector<int> v;

        v.push_back(cnt);

        for (int i = 0; i < M; i++)
            if (visited[i])
                v.push_back(i + 1);
        
        answer[result] = v;

        return;
    }

    visited[depth] = true;
    combinations(depth + 1, cnt + 1, d ^ change[depth]);

    visited[depth] = false;
    combinations(depth + 1, cnt, d);
}
