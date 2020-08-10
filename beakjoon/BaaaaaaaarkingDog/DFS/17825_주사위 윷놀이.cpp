#include <iostream>
#include <vector>

using namespace std;

struct piece
{
    int position;
};

struct board
{
    int next, score, turn;
    bool visited;
};

board A[35];
piece p[4];
int dice[10];
int answer = -1;

void backtracking(int depth, int result)
{
    if (depth == 10)
    {
        answer = max(answer, result);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int prev = p[i].position;
        int now = prev;
        int move = dice[depth];

        A[prev].visited = true;

        if (A[now].turn != 0)
        {
            now = A[now].turn;
            move -= 1;
        }

        while (move--)
            now = A[now].next;
        
        if (now != 21 && A[now].visited == true)
            continue;
        
        A[prev].visited = false;
        A[now].visited = true;
        p[i].position = now;
        backtracking(depth + 1, result + A[now].score);
        A[prev].visited = true;
        A[now].visited = false;
        p[i].position = prev;
    }
}

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 10; i++)
        cin >> dice[i];
    
    for (int i = 0; i < 21; i++)
    {
        A[i].next = i + 1;
        A[i].score = i * 2;
    }
    
    for (int i = 22; i < 27; i++)
        A[i].next = i + 1;
    
    A[28].next = 29, A[29].next = 30, A[30].next = 25;
    A[31].next = 32, A[32].next = 25, A[27].next = 20;
    A[21].next = 21;

    A[5].turn = 22, A[10].turn = 31, A[15].turn = 28;

    A[22].score = 13, A[23].score = 16, A[24].score = 19;
    A[31].score = 22, A[32].score = 24, A[25].score = 25;
    A[28].score = 28, A[29].score = 27, A[30].score = 26;
    A[26].score = 30, A[27].score = 35;

    backtracking(0, 0);

    cout << answer << "\n";

    return 0;
}
