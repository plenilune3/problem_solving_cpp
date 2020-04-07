#include <cstdio>
#include <list>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int N, K;
    scanf("%d %d", &N, &K);

    vector<int> v;

    for (int i = 0; i < N; i++)
        v.push_back(i+1);
    
    int position = 0;

    printf("<");
    for (int i = 0; i < N-1; i++)
    {
        position = (position + K - 1) % v.size();
        printf("%d, ", v[position]);
        v.erase(v.begin() + position);
    }
    printf("%d>", v[0]);

    return 0;
}

// #include <cstdio>
// #include <list>
// #include <vector>

// using namespace std;

// int main(int argc, char const *argv[])
// {
//     int N, K;
//     scanf("%d %d", &N, &K);
//     vector<int> answer;

//     list<int> josephus;

//     for (int i = 1; i < N+1; i++)
//         josephus.push_back(i);

//     list<int>::iterator cursor = josephus.begin();

//     while (josephus.begin() != josephus.end()) 
//     {
//         for (int i = 0; i < K-1; i++)
//         {
//             if (cursor == josephus.end())
//                 cursor = josephus.begin();
//             cursor++;
//         }

//         if (cursor != josephus.end())
//         {
//             answer.push_back(*cursor);
//             cursor = josephus.erase(cursor);
//         }
//         else
//         {
//             cursor = josephus.begin();
//             answer.push_back(*cursor);
//             cursor = josephus.erase(cursor);
//         }
//     }

//     printf("<");
//     for(int i = 0; i < answer.size()-1; i++)
//         printf("%d, ", answer[i]);
//     printf("%d>", answer[answer.size() - 1]);

//     return 0;
// }
