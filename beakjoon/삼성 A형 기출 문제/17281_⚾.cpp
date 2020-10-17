#include <iostream>
#include <vector>

using namespace std;

const int MAX = 50;

int N, answer;
int board[MAX][9];
bool selected[9];
vector<int> v;

void permutations(int depth);
int play();

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < 9; j++)
            cin >> board[i][j];
    
    permutations(0);
    
    cout << answer << "\n";

    return 0;
}

void permutations(int depth)
{
    if (depth == 4)
        if (v[3] != 0)
            return;

    if (depth == 9)
    {
        answer = max(answer, play());
        return;
    }

    for (int i = 0; i < 9; i++)
    {
        if (selected[i])
            continue;
        
        selected[i] = true;
        v.push_back(i);
        permutations(depth + 1);
        selected[i] = false;
        v.pop_back();
    }
}

int play()
{
    int score = 0, hitter = 0;

    for (int i = 0; i < N; i++)
    {
        int out = 0, base = 0;

        while (out < 3)
        {
            int type = board[i][v[hitter]];

            if (type == 0) out += 1;
            else
            {
                base = (base + 1) << type;
                score += ((base >> 4) & 1) + ((base >> 5) & 1) + ((base >> 6) & 1) + ((base >> 7) & 1);
                base &= 0b1111;
            }

            hitter = (hitter + 1) % 9;
        }
    }

    return score;
}
