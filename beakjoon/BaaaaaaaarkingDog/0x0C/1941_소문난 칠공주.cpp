#include <cstdio>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

char student[5][5];
bool visited[1 << 25];
int answer = 0;

void princesses(int depth, int dasom, int visit)
{
    visited[visit] = true;

    if (depth == 7)
    {
        if (dasom >= 4)
            answer++;
        return;
    }

    for (int i = 0; i < 25; i++)
    {
        if ((visit & (1 << i)) == false)
            continue;

        int x = i / 5;
        int y = i % 5;

        for (int j = 0; j < 4; j++)
        {
            int nx = x + dx[j];
            int ny = y + dy[j];
            int num = nx * 5 + ny;

            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
                continue;
            
            if (visited[visit | (1 << num)])
                continue;

            princesses(depth + 1, dasom + (student[nx][ny] == 'S'), visit | (1 << num));
        }
    }
}

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            scanf("%1s", &student[i][j]);
    
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            princesses(1, student[i][j] == 'S', 1 << (i * 5 + j));
    
    printf("%d\n", answer);

    return 0;
}
