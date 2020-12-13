#include <iostream>

using namespace std;

const int MAX = 1e4 + 1;

struct coordinate
{
    int x, y;
};

int N, I, M, answer;
coordinate C[101];

int count_(int x, int y, int h, int w);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> I >> M;

    for (int i = 0; i < M; i++)
        cin >> C[i].x >> C[i].y;
    
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
        {
            int x = C[i].x, y = C[i].y;

            for (int h = 1; h < I / 2; h++)
                answer = max(answer, count_(x, y, h, I / 2 - h));
        }
    
    cout << answer << "\n";

    return 0;
}

int count_(int x, int y, int h, int w)
{
    int result = 0;

    for (int i = 0; i < M; i++)
        if (C[i].x >= x && C[i].x <= x + h && C[i].y >= y && C[i].y <= y + w)
            result += 1;
    
    return result;
}