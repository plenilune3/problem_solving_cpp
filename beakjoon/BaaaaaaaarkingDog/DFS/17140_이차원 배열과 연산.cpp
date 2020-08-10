#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>

using namespace std;

const int MAX = 101;

int r, c, k;
int N = 3, M = 3;
int cnt[MAX], A[MAX][MAX];

void calculate_row()
{
    for (int i = 0; i < N; i++)
    {
        priority_queue< pair<int, int> > pq;
        fill_n(&cnt[0], MAX, 0);

        for (int j = 0; j < M; j++)
            if (A[i][j])
            {
                cnt[A[i][j]] += 1;
                A[i][j] = 0;
            }
        
        for (int j = 0; j < MAX; j++)
            if (cnt[j])
                pq.push(make_pair(-cnt[j], -j));
        
        int length = pq.size() * 2;
        M =  max(M, length);

        for (int j = 0; j < length; j += 2)
        {
            A[i][j] = -pq.top().second;
            A[i][j+1] = -pq.top().first;

            pq.pop();
        }
    }
}

void calculate_col()
{
    for (int j = 0; j < M; j++)
    {
        priority_queue< pair<int, int> > pq;
        fill_n(&cnt[0], MAX, 0);

        for (int i = 0; i < N; i++)
        {
            if (A[i][j])
            {
                cnt[A[i][j]] += 1;
                A[i][j] = 0;
            }
        }

        for (int i = 0; i < MAX; i++)
            if (cnt[i])
                pq.push(make_pair(-cnt[i], -i));
        
        int length = pq.size() * 2;
        N = max(N, length);

        for (int i = 0; i < length; i += 2)
        {
            A[i][j] = -pq.top().second;
            A[i+1][j] = -pq.top().first;

            pq.pop();
        }
    }
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> r >> c >> k;

    for (int i  = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];

    int answer = 0;

    while (true)
    {
        if (A[r-1][c-1] == k)
            break;
        
        if (answer > 100)
        {
            answer = -1;
            break;
        }

        if (N >= M)
            calculate_row();
        else
            calculate_col();
        
        answer += 1;
    }

    cout << answer << "\n";

    return 0;
}

// template<template <typename> class P = less>
// class compare_pair_second
// {
// public:
//     template<class T1, class T2> bool operator()(const pair<T1, T2>&left, const pair<T1, T2>&right)
//     {
//         return P<T2>()(left.second, right.second);
//     }
// };

// int r, c, k;
// int A[MAX][MAX];
// int row_cnt = 3, col_cnt = 3;

// void calculate_row()
// {
//     int cnt_max = 0;

//     for (int i = 0; i < row_cnt; i++)
//     {
//         map<int, int> num_cnt;
//         vector< pair<int, int> > v;

//         for (int j = 0; j < col_cnt; j++)
//         {
//             if (A[i][j] == 0)
//                 continue;
                
//             num_cnt[A[i][j]] += 1;
//         }

//         v.assign(num_cnt.begin(), num_cnt.end());
//         stable_sort(v.begin(), v.end(), compare_pair_second<>());

//         int length = v.size() < 50 ? v.size() : 50;
//         cnt_max = max(cnt_max, length * 2);

//         for (int j = 0; j < length; j++)
//         {
//             int temp = j * 2;

//             A[i][temp] = v[j].first;
//             A[i][temp + 1] = v[j].second;
//         }

//         if (length * 2 < col_cnt)
//             for (int j = length * 2; j < col_cnt; j++)
//                 A[i][j] = 0;
//     }

//     col_cnt = cnt_max;
// }

// void calculate_col()
// {
//     int cnt_max = 0;

//     for (int i = 0; i < col_cnt; i++)
//     {
//         map<int, int> num_cnt;
//         vector< pair<int, int> > v;

//         for (int j = 0; j < row_cnt; j++)
//         {
//             if (A[j][i] == 0)
//                 continue;

//             num_cnt[A[j][i]] += 1;
//         }
        
//         v.assign(num_cnt.begin(), num_cnt.end());
//         stable_sort(v.begin(), v.end(), compare_pair_second<>());

//         int length = v.size() < 50 ? v.size() : 50;

//         cnt_max = max(cnt_max, length * 2);

//         for (int j = 0; j < length; j++)
//         {
//             int temp = j * 2;
            
//             A[temp][i] = v[j].first;
//             A[temp + 1][i] = v[j].second;
//         }

//         if (length * 2 < row_cnt)
//             for (int j = length * 2; j < row_cnt; j++)
//                 A[j][i] = 0;
//     }

//     row_cnt = cnt_max;
// }

// int main(int argc, char const *argv[])
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);
    
//     cin >> r >> c >> k;

//     for (int i = 0; i < row_cnt; i++)
//         for (int j = 0; j < col_cnt; j++)
//             cin >> A[i][j];
    
//     int answer = 0;

//     while (true)
//     {
//         if (A[r-1][c-1] == k)
//             break;
        
//         if (answer > 100)
//         {
//             answer = -1;
//             break;
//         }
        
//         if (row_cnt >= col_cnt)
//             calculate_row();
//         else
//             calculate_col();
        
//         answer++;
//     }

//     cout << answer << "\n";

//     return 0;
// }
