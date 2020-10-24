#include <iostream>

using namespace std;

const int MAX = 11;

int N;
int energy[MAX];
bool visited[MAX];

int get_energy();

int main(int argc, char const *argv[])
{
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> energy[i];

    cout << get_energy() << "\n";

    return 0;
}

int get_energy()
{
    int ret = 0;

    for (int i = 1; i < N - 1; i++)
    {
        if (visited[i]) continue;

        int left = i - 1, right = i + 1;

        while (visited[left]) left--;
        while (visited[right]) right++;

        visited[i] = true;
        ret = max(ret, get_energy() + energy[left] * energy[right]);
        visited[i] = false;
    }

    return ret;
}
