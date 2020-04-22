#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int M;
    int cup[4] = {0, 1, 0, 0};

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int x, y, temp;
        cin >> x >> y;

        temp = cup[x]; cup[x] = cup[y]; cup[y] = temp;
    }

    for (int i = 1; i <= 3; i++)
        if (cup[i] == 1)
            cout << i << "\n";

    return 0;
}
