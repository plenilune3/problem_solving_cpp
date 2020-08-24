#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

const int MAX = 51;

int N, max_num;
string p;
vector<int> v;
bool visited[MAX];
bool is_finished;

void recover_blank(int depth);
int string_to_int(string num);
bool is_possible();

int main(int argc, char const *argv[])
{
    cin >> p;

    N = p.size();

    recover_blank(0);

    return 0;
}

bool is_possible()
{
    for (int i = 1; i < v.size() + 1; i++)
        if (!visited[i])
            return false;
    
    return true;
}

int string_to_int(string num)
{
    int result = 0, length = num.size();

    for (int i = 0; i < length; i++)
        result = (result * 10) + (num[i] - '0');
    
    return result;
}

void recover_blank(int depth)
{
    if (is_finished)
        return;

    if (depth >= N)
    {
        if (is_possible())
        {
            is_finished = true;
            for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
                cout << (*iter) << " ";
            cout << "\n";
        }

        return;
    }

    for (int i = 1; i <= 2; i++)
    {
        string num = p.substr(depth, i);
        int n = string_to_int(num);

        if (n > 50 || visited[n])
            continue;
        
        visited[n] = true;
        v.push_back(n);
        recover_blank(depth + i);
        visited[n] = false;
        v.pop_back();
    }
}
