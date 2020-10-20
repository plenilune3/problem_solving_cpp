#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100;

struct sticker
{
    int r, c;
};

int H, W, N, answer;
bool board[MAX][MAX];
sticker s[MAX];
bool visited[MAX];
vector<sticker> v;

void combinations(int depth);

int main(int argc, char const *argv[])
{
    cin >> H >> W;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> s[i].r >> s[i].c;
    
    combinations(0);
    cout << answer << "\n";

    return 0;
}

void combinations(int depth)
{
    if (depth == 2)
    {
        sticker ss[4];
        ss[0].r = v[0].r, ss[0].c = v[0].c;
        ss[1].r = v[0].c, ss[1].c = v[0].r;
        ss[2].r = v[1].r, ss[2].c = v[1].c;
        ss[3].r = v[1].c, ss[3].c = v[1].r;

        int area = v[0].r * v[0].c + v[1].r * v[1].c;

        for (int i = 0; i <= 1; i++)
            for (int j = 2; j <= 3; j++)
            {
                if (ss[i].r + ss[j].r <= H)
                    if (max(ss[i].c, ss[j].c) <= W)
                        answer = max(answer, area);
                
                if (ss[i].c + ss[j].c <= W)
                    if (max(ss[i].r, ss[j].r) <= H)
                        answer = max(answer, area);
            }

        return;
    }

    for (int i = depth; i < N; i++)
    {
        if (visited[i]) continue;

        visited[i] = true;
        v.push_back(s[i]);
        combinations(depth + 1);
        visited[i] = false;
        v.pop_back();
    }
}