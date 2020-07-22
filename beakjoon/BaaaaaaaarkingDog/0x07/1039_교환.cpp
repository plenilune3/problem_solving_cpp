#include <iostream>
#include <string>

using namespace std;

int K, length, answer = -1;
bool visited[1000001][11];

int to_int(string value)
{
    int result = 0;

    for (int i = 0; i < length; i++)
        result = result * 10 + (value[i] - '0');
    
    return result;
}

void dfs(int depth, string num)
{
    visited[to_int(num)][depth] = true;
    
    if (depth == K)
    {
        answer = max(answer, to_int(num));
        return;
    }

    for (int i = 0; i < length - 1; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            swap(num[i], num[j]);

            if (num[0] != '0' && visited[to_int(num)][depth + 1] == false)
                dfs(depth + 1, num);
            
            swap(num[i], num[j]);
        }
    }

}


int main(int argc, char const *argv[])
{
    string N;
    cin >> N >> K;

    length = N.length();
    dfs(0, N);

    cout << answer << "\n";
    return 0;
}
