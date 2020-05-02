#include <iostream>
#include <vector>

using namespace std;

const int MAX = 50;

int N, answer;
int player[MAX][9];
bool visited[9];
vector<int> v;

int score_count()
{
    int score = 0;
    int hitter = 0;

    for (int x = 0; x < N; x++)
    {
        int out = 0;
        int base = 0;

        while (out < 3)
        {
            int result = player[x][v[hitter]];

            if (result == 0)
                out += 1;
            else
            {
                base = (base + 1) << player[x][v[hitter]];
                score += ((base >> 4) & 1) + ((base >> 5) & 1) + ((base >> 6) & 1) + ((base >> 7) & 1);
                base &= 0b1111;
            }

            hitter = (hitter + 1) % 9;
        }
    }

    return score;
}


void permutations(int depth)
{
    if (depth == 9)
    {
        int score = score_count();
        answer = max(answer, score);
        return;
    }

    if (depth == 4)
        if (v[3] != 0)
            return;

    for (int i = 0; i < 9; i++)
        if (visited[i] == false)
        {
            visited[i] = true;
            v.push_back(i);
            permutations(depth + 1);
            visited[i] = false;
            v.pop_back();
        }

}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < 9; j++)
            cin >> player[i][j];
    
    permutations(0);

    cout << answer << "\n";
    
    return 0;
}

