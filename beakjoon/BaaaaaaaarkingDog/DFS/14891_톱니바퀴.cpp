#include <cstdio>
#include <deque>
#include <queue>
#include <cmath>

using namespace std;

// void move_gears(int n, int d, int gear[][8])
// {
//     bool visited[5] = { false };
//     queue< pair<int, int> > q;
//     visited[n] = true;
//     q.push(make_pair(n, d));

//     while (!q.empty())
//     {
//         pair<int, int> c = q.front();
//         q.pop();

//         int rg = c.first + 1;
//         int lg = c.first - 1;

//         if (rg <= 4 && visited[rg] == false)
//         {
//             visited[rg] = true;
//             if (gear[c.first][2] != gear[rg][6])
//             {
//                 q.push(make_pair(rg, c.second*(-1)));
//             }
//         }
        
//         if (lg >= 1 && visited[lg] == false)
//         {
//             visited[lg] = true;
//             if (gear[c.first][6] != gear[lg][2])
//             {
//                 q.push(make_pair(lg, c.second*(-1)));
//             }
//         }

//         if (c.second == 1)
//         {
//             int temp = gear[c.first][7];
//             for (int i = 7; i >= 1; i--)
//                 gear[c.first][i] = gear[c.first][i - 1];
//             gear[c.first][0] = temp;
//         }
//         else if (c.second == -1)
//         {
//             int temp = gear[c.first][0];
//             for (int i = 0; i <= 6; i++)
//                 gear[c.first][i] = gear[c.first][i + 1];
//             gear[c.first][7] = temp;
//         }
//     }
// }

void rotate(int n, int d, int gear[][8])
{
    int t[8];

    if (d == 1)
        for (int i = 0; i < 8; i++)
            t[(i + 1) % 8] = gear[n][i];
    else
        for (int i = 0; i < 8; i++)
            t[i] = gear[n][(i + 1) % 8];
    
    for (int i = 0; i < 8; i++)
        gear[n][i] = t[i];
}

int main(int argc, char const *argv[])
{
    int gear[5][8];
    int answer = 0;

    for (int i = 1; i < 5; i++)
        for (int j = 0; j < 8; j++)
            scanf("%1d", &gear[i][j]);
    
    int K;
    scanf("%d", &K);

    for (int k = 0; k < K; k++)
    {
        int n, d;
        scanf("%d %d", &n, &d);

        int direct[5] = { 0 };
        direct[n] = d;

        for (int i = n; i < 4; i++)
            if (gear[i][2] != gear[i + 1][6])
                direct[i + 1] = -direct[i];
        
        for (int i = n; i > 1; i--)
            if (gear[i][6] != gear[i - 1][2])
                direct[i - 1] = -direct[i];
        
        for (int i = 1; i < 5; i++)
            if (direct[i])
                rotate(i, direct[i], gear);

        // move_gears(n, d, gear);
    }

    // for (int i = 0; i < 4; i++)
    //     answer += gear[i+1][0] * (int)pow(2, i);

    for (int i = 0; i < 4; i++)
        if (gear[i+1][0])
            answer += (1 << i);

    printf("%d\n", answer);

    return 0;
}
