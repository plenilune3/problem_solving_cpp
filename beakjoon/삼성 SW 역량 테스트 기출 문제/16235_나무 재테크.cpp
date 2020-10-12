#include <iostream>
#include <queue>

using namespace std;

struct tree
{
    int age;
    bool is_alive;
};

const int MAX = 11;
const int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int N, M, K;
int board[MAX][MAX];
int A[MAX][MAX];
deque<tree> trees[MAX][MAX];

int count_alive();
void spring();
void summer();
void fall();
void winter();
void older(int x, int y);
void die(int x, int y);
void breed(int x, int y);
tree make_tree(int age, bool is_alive);

int main(int argc, char const *argv[])
{
    fill_n(&board[0][0], MAX * MAX, 5);

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];

    while (M--)
    {
        int x, y, age; cin >> x >> y >> age;
        trees[x - 1][y - 1].push_back(make_tree(age, true));
    }

    while (K--)
    {
        spring();
        summer();
        fall();
        winter();
    }

    int answer = count_alive();

    cout << answer << "\n";

    return 0;
}

int count_alive()
{
    int alive = 0;

    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            alive += trees[x][y].size();
    
    return alive;
}

void spring()
{
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            if (!trees[x][y].empty())
                older(x, y);

}

void summer()
{
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            if (!trees[x][y].empty())
                die(x, y);
}

void fall()
{
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            for (deque<tree>::iterator iter = trees[x][y].begin(); iter != trees[x][y].end(); iter++)
                if ((*iter).age % 5 == 0)
                    breed(x, y);
}

void winter()
{
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            board[x][y] += A[x][y];
}

void older(int x, int y)
{
    for (deque<tree>::iterator iter = trees[x][y].begin(); iter != trees[x][y].end(); iter++)
        if ((*iter).age <= board[x][y])
        {
            board[x][y] -= (*iter).age;
            (*iter).age += 1;
        }
        else
            (*iter).is_alive = false;   
}

void die(int x, int y)
{
    deque<tree> dq;
    int nutrient = 0;

    while (!trees[x][y].empty())
    {
        tree t = trees[x][y].front();
        trees[x][y].pop_front();

        if (t.is_alive) dq.push_back(t);
        else nutrient += (t.age) / 2;
    }

    trees[x][y] = dq;
    board[x][y] += nutrient;
}

void breed(int x, int y)
{
    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
            continue;
        
        trees[nx][ny].push_front(make_tree(1, true));
    }
}

tree make_tree(int age, bool is_alive)
{
    tree t = { age, is_alive };
    return t;
}