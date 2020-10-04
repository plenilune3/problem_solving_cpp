#include <iostream>
#include <vector>

using namespace std;

struct process
{
    int sort, index, k;
};

int answer = 8;
int standard[4][4], board[4][4];
vector<process> c, v;

void backtracking(int depth);
int get_difference();
void rotate(int sort, int index, int cnt);
process make_process(int s, int index, int k);

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> board[i][j];
    
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            standard[i][j] = (i * 4 + j) + 1;
    
    backtracking(0);

    cout << answer << "\n";

    for (vector<process>::iterator i = c.begin(); i != c.end(); i++)
        cout << (*i).sort << " " << (*i).index << " " << (*i).k << "\n";
    
    return 0;
}

void backtracking(int depth)
{
    int difference = get_difference();

    if (difference == 0)
    {
        if (depth < answer)
        {
            answer = depth;
            c.assign(v.begin(), v.end());
        }

        return;
    }

    int change = (difference / 4);
    
    if (difference % 4 != 0)
        change += 1;

    if (change + depth >= answer)
        return;

    for (int s = 1; s <= 2; s++)
        for (int i = 0; i < 4; i++)
            for (int k = 1; k <= 3; k++)
            {
                v.push_back(make_process(s, i + 1, k));
                rotate(s, i, k);
                backtracking(depth + 1);
                rotate(s, i, 4 - k);
                v.pop_back();
            }
}

process make_process(int sort, int index, int k)
{
    process p = { sort, index, k };
    return p;
}

void rotate(int sort, int index, int cnt)
{
    int arr[4];

    if (sort == 1)
    {
        for (int i = 0; i < 4; i++)
            arr[(i + cnt) % 4] = board[index][i];

        for (int i = 0; i < 4; i++)
            board[index][i] = arr[i];
    }
    else
    {
        for (int i = 0; i < 4; i++)
            arr[(i + cnt) % 4] = board[i][index];
        
        for (int i = 0; i < 4; i++)
            board[i][index] = arr[i];
    }
}

int get_difference()
{
    int cnt = 0;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (board[i][j] != standard[i][j])
                cnt += 1;
    
    return cnt;
}
