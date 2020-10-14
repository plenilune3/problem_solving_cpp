#include <iostream>

using namespace std;

struct plate
{
    int score, red, blue;
};

const int MAX = 10;

int dice[MAX], answer;
plate plates[33];
int piece[4];
bool visited[33];

void init_plate();
void backtracking(int depth, int result);
int get_next(int location, int count);
plate make_plate(int score, int red, int blue);

int main(int argc, char const *argv[])
{
    for (int i = 0; i < MAX; i++)
        cin >> dice[i];
    
    init_plate();

    for (int i = 0; i < 4; i++)
        piece[i] = 0;

    backtracking(0, 0);

    cout << answer << "\n";
    
    return 0;
}

void backtracking(int depth, int result)
{
    if (depth == MAX)
    {
        answer = max(answer, result);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (piece[i] == 32) continue;

        int now = piece[i];
        int next = get_next(piece[i], dice[depth]);

        if (next != 32 && visited[next]) continue;

        visited[now] = false;
        visited[next] = true;
        piece[i] = next;
        backtracking(depth + 1, result + plates[next].score);
        visited[now] = true;
        visited[next] = false;
        piece[i] = now;
    }
}

int get_next(int location, int count)
{
    location = plates[location].blue;
    count -= 1;

    while (count--)
        location = plates[location].red;
    
    return location;
}

void init_plate()
{
    for (int i = 0; i <= 18; i++)
        plates[i] = make_plate(i * 2, i + 1, i + 1);
    plates[19] = make_plate(38, 31, 31);

    plates[5].blue = 20;
    plates[10].blue = 23; 
    plates[15].blue = 25;

    plates[20] = make_plate(13, 21, 21);
    plates[21] = make_plate(16, 22, 22);
    plates[22] = make_plate(19, 28, 28);
    
    plates[23] = make_plate(22, 24, 24);
    plates[24] = make_plate(24, 28, 28);

    plates[25] = make_plate(28, 26, 26);
    plates[26] = make_plate(27, 27, 27);
    plates[27] = make_plate(26, 28, 28);

    for (int i = 28; i <= 31; i++)
        plates[i] = make_plate(25 + (i - 28) * 5, i + 1, i + 1);
    
    plates[32] = make_plate(0, 32, 32);
}

plate make_plate(int score, int red, int blue)
{
    plate p = { score, red, blue };
    return p;
}
