#include <iostream>
#include <string>

using namespace std;

const int MAX_SINKER = 30;
const int MAX_COMPARE = 7;
const int MAX_WEIGHT = 500;

int N, M;
int sinker[MAX_SINKER];
int compare[MAX_COMPARE];
bool visited[MAX_SINKER + 1][MAX_WEIGHT * MAX_SINKER + 1];

void find_sinker(int depth, int result);
int get_difference(int a, int b);
string find_answer(int value);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> sinker[i];
    
    cin >> M;

    for (int i = 0; i < M; i++)
        cin >> compare[i];
    
    find_sinker(0, 0);

    for (int i = 0; i < M; i++)
        cout << find_answer(compare[i]) << "\n";

    return 0;
}

string find_answer(int value)
{
    if (value > MAX_WEIGHT * MAX_SINKER)
        return "N";

    if (visited[N][value])
        return "Y";
    
    return "N";
}

int get_difference(int a, int b)
{
    return a > b ? a - b : b - a;
}

void find_sinker(int depth, int result)
{
    if (depth > N)
        return;
    
    if (visited[depth][result])
        return;

    visited[depth][result] = true;

    find_sinker(depth + 1, result + sinker[depth]);
    find_sinker(depth + 1, get_difference(result, sinker[depth]));
    find_sinker(depth + 1, result);
}


