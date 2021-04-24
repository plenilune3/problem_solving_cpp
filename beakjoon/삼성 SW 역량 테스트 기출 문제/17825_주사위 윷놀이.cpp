#include <iostream>

using namespace std;

const int MAX = 10;

struct plate 
{
    int score, red, blue;

    plate() : score(0), red(0), blue(0) {}
    plate(int _score, int _red, int _blue) : score(_score), red(_red), blue(_blue) {}
};

int answer;
int dice[MAX], pieces[4];
plate plates[33];
bool visited[33];

void init_plate(plate plates[33]);
void play(int depth, int result, plate plates[33]);
int calculate_next(int p, int d, plate plates[MAX]);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    for (int i = 0; i < MAX; i++)
        cin >> dice[i];
    
    init_plate(plates);

    play(0, 0, plates);

    cout << answer << "\n";

    return 0;
}

void play(int depth, int result, plate plates[33])
{
    if (depth == MAX)
    {
        answer = max(answer, result);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (pieces[i] == 32)
            continue;
        
        int now = pieces[i];
        int next = calculate_next(now, dice[depth], plates);

        if (next != 32 && visited[next]) continue;

        visited[now] = false;
        visited[next] = true;
        pieces[i] = next;
        play(depth + 1, result + plates[next].score, plates);
        visited[now] = true;
        visited[next] = false;
        pieces[i] = now;
    }
}

int calculate_next(int p, int d, plate plates[33])
{
    int next = plates[p].blue;
    d -= 1;

    while (d--)
        next = plates[next].red;

    return next;
}

void init_plate(plate plates[33])
{
    for (int i = 0; i < 21; i++)
        plates[i] = plate(i * 2, i + 1, i + 1);
    
    plates[20].score = 40, plates[20].red = 32; plates[20].blue = 32;
    plates[32].score = 0; plates[32].red = 32; plates[32].blue = 32;
    plates[5].blue = 21; plates[10].blue = 24; plates[15].blue = 26;

    plates[21].score = 13; plates[21].red = 22; plates[21].blue = 22;
    plates[22].score = 16; plates[22].red = 23; plates[22].blue = 23;
    plates[23].score = 19; plates[23].red = 29; plates[23].blue = 29;

    plates[24].score = 22; plates[24].red = 25; plates[24].blue = 25;
    plates[25].score = 24; plates[25].red = 29; plates[25].blue = 29;

    plates[26].score = 28; plates[26].red = 27; plates[26].blue = 27;
    plates[27].score = 27; plates[27].red = 28; plates[27].blue = 28;
    plates[28].score = 26; plates[28].red = 29; plates[28].blue = 29;

    plates[29].score = 25; plates[29].red = 30; plates[29].blue = 30;
    plates[30].score = 30; plates[30].red = 31; plates[30].blue = 31;
    plates[31].score = 35; plates[31].red = 20; plates[31].blue = 20;
}
