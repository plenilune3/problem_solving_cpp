#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

const int MAX = 52;

int city[MAX][MAX];
bool visited[13];
int N, M, answer = INT_MAX;
vector< pair<int, int> > house;
vector< pair<int, int> > chicken;
vector<int> v;

int chicken_distance()
{
    int distance = 0;

    vector< pair<int, int> >::iterator iter_house;
    for (iter_house = house.begin(); iter_house != house.end(); iter_house++)
    {
        vector<int>::iterator iter;
        int d = INT_MAX;

        for (iter = v.begin(); iter != v.end(); iter++)
            d =  min(d, abs((*iter_house).first - chicken[(*iter)].first) + abs((*iter_house).second - chicken[(*iter)].second));

        distance += d;
    }

    return distance;
}

void backtracking(int depth, int length, int index)
{
    if (depth == M)
    {
        answer = min(answer, chicken_distance());
        return;
    }

    for (int i = index; i < length; i++)
        if (visited[i] == false)
        {   
            visited[i] = true;
            v.push_back(i);
            backtracking(depth + 1, length, i);
            visited[i] = false;
            v.pop_back();
        }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N + 2; i++)
        for (int j = 0; j < N + 2; j++)
        {
            if (i == 0 || j == 0 || i == N + 1 || j == N + 1)
                city[i][j] = 0;
            else
            {
                cin >> city[i][j];

                if (city[i][j] == 1)
                    house.push_back(make_pair(i, j));
                else if (city[i][j] == 2)
                    chicken.push_back(make_pair(i, j));
            }
        }
    
    int length = chicken.size();

    backtracking(0, length, 0);

    cout << answer << "\n";

    return 0;
}


// int city[MAX][MAX];
// int N, M, answer = INT_MAX;
// vector< pair<int, int> > house;
// // vector< pair<int, int> > chicken;

// int chicken_distance()
// {
//     vector< pair<int ,int> > chicken;

//     for (int i = 1; i <= N; i++)
//         for (int j = 1; j <= N; j++)
//             if (city[i][j] == 2)
//                 chicken.push_back(make_pair(i, j));
    
//     int distance = 0;

//     for (pair<int, int> h : house)
//     {
//         int d = INT_MAX;
//         for (pair<int, int> c : chicken)
//             d =  min(d, abs(h.first - c.first) + abs(h.second - c.second));
//         distance += d;
//     }

//     return distance;
// }

// void backtracking(int depth, int x)
// {
//     if (depth == M)
//     {
//         answer = min(answer, chicken_distance());
//         return;
//     }

//     for (int i = x; i <= N; i++)
//         for (int j = 1; j <= N; j++)
//             if (city[i][j] == 2)
//             {
//                 city[i][j] = 0;
//                 backtracking(depth + 1, i);
//                 city[i][j] = 2;
//             }
// }

// int main(int argc, char const *argv[])
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);
    
//     int chicken = 0;
//     cin >> N >> M;

//     for (int i = 0; i < N + 2; i++)
//         for (int j = 0; j < N + 2; j++)
//         {
//             if (i == 0 || j == 0 || i == N + 1 || j == N + 1)
//                 city[i][j] = 0;
//             else
//             {
//                 cin >> city[i][j];

//                 if (city[i][j] == 1)
//                     house.push_back(make_pair(i, j));
//                 else if (city[i][j] == 2)
//                     chicken++;
//                     // chicken.push_back(make_pair(i, j));
//             }
//         }
    
//     M = chicken - M;

//     backtracking(0, 1);

//     cout << answer << "\n";

//     return 0;
// }


