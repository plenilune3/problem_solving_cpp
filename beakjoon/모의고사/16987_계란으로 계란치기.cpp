#include <iostream>

using namespace std;

struct egg
{
    int d, w;
};

const int MAX = 8;

int N, answer;
egg eggs[MAX];

egg make_egg(int d, int w);
void backtracking(int depth);

int main(int argc, char const *argv[])
{
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> eggs[i].d >> eggs[i].w;
    
    backtracking(0);

    cout << answer << "\n";
    
    return 0;
}

void backtracking(int depth)
{
    if (depth == N)
    {
        int result = 0;

        for (int i = 0; i < N; i++)
            if (eggs[i].d <= 0)
                result += 1;
        
        answer = max(answer, result);
        
        return;
    }

    if (eggs[depth].d <= 0)
    {
        backtracking(depth + 1);
        return;
    }

    bool possible = false;

    for (int i = 0; i < N; i++)
    {
        if (depth == i) continue;

        if (eggs[i].d <= 0) continue;

        possible = true;
        eggs[i].d -= eggs[depth].w;
        eggs[depth].d -= eggs[i].w;
        backtracking(depth + 1);
        eggs[i].d += eggs[depth].w;
        eggs[depth].d += eggs[i].w;
    }

    if (possible == false)
        backtracking(depth + 1);
}

egg make_egg(int d, int w)
{
    egg e = { d, w };
    return e;
}
