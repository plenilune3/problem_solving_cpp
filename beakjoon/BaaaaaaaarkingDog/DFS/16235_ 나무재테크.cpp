#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

const int MAX = 11;
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1 ,1, -1, 0, 1};

// class tree 
// {
// public:
//     int age;
//     bool alive;

//     tree(int a, bool b)
//     {
//         age = a;
//         alive = b;
//     }

//     bool operator<(const tree &t) const
//     {
//         return (age < t.age);
//     }
// };

struct tree
{
    int age;
    bool alive;
};

int land_food[MAX][MAX];
int A[MAX][MAX];
deque<tree> land_tree[MAX][MAX];
int N, M, K;

void spring()
{
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            if (land_tree[i][j].empty())
                continue;

            deque<tree>::iterator iter;
            for (iter = land_tree[i][j].begin(); iter != land_tree[i][j].end(); iter++)
            {
                int food = land_food[i][j];
                int age = (*iter).age;

                if (food >= age)
                {
                    land_food[i][j] -= age;
                    (*iter).age += 1;
                }
                else
                    (*iter).alive = false;
            }
        }
}

void summer()
{
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            if (land_tree[i][j].empty())
                continue;

            while (!land_tree[i][j].empty())
            {
                if (land_tree[i][j].back().alive)
                    break;
                land_food[i][j] += land_tree[i][j].back().age / 2;
                land_tree[i][j].pop_back();
            }
        }
}

void fall()
{
    for (int x = 1; x <= N; x++)
        for (int y = 1; y <= N; y++)
        {
            if (land_tree[x][y].empty())
                continue;
            
            deque<tree>::iterator iter;
            for (iter = land_tree[x][y].begin(); iter != land_tree[x][y].end(); iter++)
                if ((*iter).age % 5 == 0)
                    for (int i = 0; i < 8; i++)
                    {
                        int nx = x + dx[i];
                        int ny = y + dy[i];

                        if (nx < 1 || nx > N || ny < 1 || ny > N)
                            continue;
                        
                        tree t = {1, true};
                        land_tree[nx][ny].push_front(t);
                    }
        }
}

void winter()
{
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            land_food[i][j] += A[i][j];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> A[i][j];
    
    fill_n(&land_food[0][0], MAX*MAX, 5);
    
    for (int i = 0; i < M; i++)
    {
        int x, y, z;
        
        cin >> x >> y >> z;

        tree t = {z, true};
        land_tree[x][y].push_back(t);
    }
    
    int year = 0;

    while (year < K)
    {
        spring();
        summer();
        fall();
        winter();

        year++;
    }

    int answer = 0;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            answer += land_tree[i][j].size();
    
    cout << answer << "\n";

    return 0;
}
