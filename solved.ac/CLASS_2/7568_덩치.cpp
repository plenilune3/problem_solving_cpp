#include <iostream>

using namespace std;

const int MAX = 50;

int N;
int ranking[MAX];
pair<int, int> person[MAX];

int main(int argc, char const *argv[])
{
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> person[i].first >> person[i].second;
    
    for (int i = 0; i < N; i++)
    {
        int result = 0;

        for (int j = 0; j < N; j++)
            if (person[i].first < person[j].first && person[i].second < person[j].second)
                result += 1;
        
        ranking[i] = result + 1;
    }

    for (int i = 0; i < N; i++)
        cout << ranking[i] << " ";
    cout << "\n";

    return 0;
}
