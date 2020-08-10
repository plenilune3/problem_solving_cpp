#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAX = 10;

struct state
{
    int efficiency;
    int element;
};

int n, answer;
state materials[MAX][4][4];
state klin[5][5];
int visited[MAX];

void rotate(state after[4][4], state before[4][4])
{
    for (int i = 0; i < 4; i ++)
        for (int j = 0; j < 4; j++)
            after[j][4 - 1 - i] = before[i][j];
}

void putMaterials(state klin[5][5], state materials[4][4], int x, int y)
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            klin[x+i][y+j].efficiency += materials[i][j].efficiency;

            if (klin[x+i][y+j].efficiency < 0)
                klin[x+i][y+j].efficiency = 0;
            else if (klin[x+i][y+j].efficiency > 9)
                klin[x+i][y+j].efficiency = 9;
            
            if (materials[i][j].element != 0)
                klin[x+i][y+j].element = materials[i][j].element;
        }
}

void backtracking(int depth, state klin[5][5])
{
    if (depth == 3)
    {
        int s = 0;

        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                s += klin[i][j].efficiency * klin[i][j].element;
        
        answer = max(answer, s);
        return;
    }

    for (int t = 0; t < n; t++)
    {
        if (visited[t])
            continue;
        
        visited[t] = true;

        state materials_n[4][4], materials_r[4][4], klin_next[5][5];
        memcpy(materials_n, materials[t], sizeof(state) * 4 * 4);

        for (int d = 0; d < 4; d++)
        {
            rotate(materials_r, materials_n);
            memcpy(materials_n, materials_r, sizeof(state) * 4 * 4);
            
            for (int i = 0; i <= 1; i++)
                for (int j = 0; j <= 1; j++)
                {
                    memcpy(klin_next, klin, sizeof(state) * 5 * 5);
                    putMaterials(klin_next, materials_n, i, j);
                    backtracking(depth + 1, klin_next);
                }
        }
       
        visited[t] = false;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int t = 0; t < n; t++)
    {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                cin >> materials[t][i][j].efficiency;
        
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
            {
                string s;
                cin >> s;

                if (s == "R")
                    materials[t][i][j].element = 7;
                else if (s == "B")
                    materials[t][i][j].element = 5;
                else if (s == "G")
                    materials[t][i][j].element = 3;
                else if (s == "Y")
                    materials[t][i][j].element = 2;
                else
                    materials[t][i][j].element = 0;
            }
    }

    backtracking(0, klin);

    cout << answer << "\n";

    return 0;
}

// state materials [MAX][4][4][4];
// vector< vector< state > > kiln(5, vector<state>(5));

// void rotate(int type, int dir)
// {
//     for (int i = 0; i < 4; i++)
//         for (int j = 0; j < 4; j++)
//             materials[type][dir][i][j] = materials[type][dir-1][4-1-j][i];
// }

// int quality(vector< vector<state> >& v)
// {
//     int e[5] = {0, 0, 0, 0, 0};

//     for (int i = 0; i < 5; i++)
//         for (int j = 0; j < 5; j++)
//         {
//             if (v[i][j].element == 'R')
//                 e[0] += v[i][j].efficiency;
//             else if (v[i][j].element == 'B')
//                 e[1] += v[i][j].efficiency;
//             else if (v[i][j].element == 'G')
//                 e[2] += v[i][j].efficiency;
//             else if (v[i][j].element == 'Y')
//                 e[3] += v[i][j].efficiency;
//             else
//                 e[4] += v[i][j].efficiency;
//         }
    
//     return e[0] * 7 + e[1] * 5 + e[2] * 3 + e[3] * 2;
// }

// vector< vector<state> > putMaterials(vector< vector<state> > v, int type, int dir, int x, int y)
// {
//     for (int i = 0; i < 4; i++)
//         for (int j = 0; j < 4; j++)
//         {
//             v[x+i][y+j].efficiency += materials[type][dir][i][j].efficiency;

//             if (v[x+i][y+j].efficiency < 0)
//                 v[x+i][y+j].efficiency = 0;
//             else if (v[x+i][y+j].efficiency > 9)
//                 v[x+i][y+j].efficiency = 9;
            
//             if (materials[type][dir][i][j].element != 'W')
//                 v[x+i][y+j].element = materials[type][dir][i][j].element;
//         }

//     return v;
// }

// void backtracking(int depth, vector< vector<state> >& v)
// {
//     if (depth == 3)
//     {
//         answer = max(answer, quality(v));
//         return;
//     }

//     for (int t = 0; t < n; t++)
//     {
//         if (visited[t] == true)
//             continue;
        
//         visited[t] = true;

//         for (int i = 0; i <= 1; i++)
//             for (int j = 0; j <= 1; j++)
//                 for (int d = 0; d < 4; d++)
//                 {
//                     vector< vector<state> > temp = putMaterials(v, t, d, i, j);
//                     backtracking(depth + 1, temp);
//                 }
        
//         visited[t] = false;
//     }
// }

// int main(int argc, char const *argv[])
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);

//     cin >> n;

//     for (int t = 0; t < n; t++)
//     {
//         for (int i = 0; i < 4; i++)
//             for (int j = 0; j < 4; j++)
//                 cin >> materials[t][0][i][j].efficiency;
        
//         for (int i = 0; i < 4; i++)
//             for (int j = 0; j < 4; j++)
//                 cin >> materials[t][0][i][j].element;
        
//         for (int d = 1; d <= 3; d++)
//             rotate(t, d);
//     }

//     for (int i = 0; i < 5; i++)
//         for (int j = 0; j < 5; j++)
//         {
//             state init = {0, 'W'};
//             kiln[i][j] = init;
//         }

//     fill_n(&visited[0], MAX, false);
//     answer = -1;

//     backtracking(0, kiln);

//     cout << answer << "\n";

//     return 0;
// }
