#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 16;

int L, C;
char alpha[MAX];

bool possible(string pwd)
{
    int vowel = 0;
    int consonant = 0;
    string::iterator iter;

    for (iter = pwd.begin(); iter != pwd.end(); iter++)
        if ((*iter) == 'a' || (*iter) == 'e' || (*iter) == 'i' || (*iter) == 'o' || (*iter) == 'u')
            vowel++;
        else
            consonant++;
    
    return (vowel >= 1 && consonant >= 2);
}

void dfs(int depth, string pwd)
{
    if (depth > C)
        return;

    if ((int)pwd.length() == L && possible(pwd))
        cout << pwd << "\n";
    else
    {
        dfs(depth + 1, pwd + alpha[depth]);
        dfs(depth + 1, pwd);
    }
}


int main(int argc, char const *argv[])
{
    cin >> L >> C;

    for (int i = 0; i < C; i ++)
        cin >> alpha[i];
    
    sort(alpha, alpha + C);

    dfs(0, "");

    return 0;
}

// int L, C;
// char alpha[MAX];
// bool visited[MAX];
// vector<char> result;

// bool possible(vector<char>& result)
// {
//     int vowel = 0;
//     int consonant = 0;
//     vector<char>::iterator iter;

//     for (iter = result.begin(); iter != result.end(); iter++)
//     {
//         if ((*iter) == 'a' || (*iter) == 'e' || (*iter) == 'i' || (*iter) == 'o' || (*iter) == 'u')
//             vowel++;
//         else
//             consonant++;
//     }

//     if (vowel >= 1 && consonant >= 2)
//         return true;
//     else
//         return false;
// }

// void backtracking(int depth, int index)
// {
//     if (depth == L && possible(result))
//     {
//         vector<char>::iterator iter;
//         for (iter = result.begin(); iter != result.end(); iter++)
//             cout << (*iter);
//         cout << "\n";
//     }
//     else
//     {
//         for (int i = index; i < C; i++)
//             if (visited[i] == false)
//             {
//                 visited[i] = true;
//                 result.push_back(alpha[i]);
//                 backtracking(depth + 1, i);
//                 visited[i] = false;
//                 result.pop_back();
//             }
//     }
// }

// int main(int argc, char const *argv[])
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     cin >> L >> C;
    
//     for (int i  = 0; i < C; i++)
//         cin >> alpha[i];
    
//     sort(alpha, alpha + C);

//     backtracking(0, 0);

//     return 0;
// }

