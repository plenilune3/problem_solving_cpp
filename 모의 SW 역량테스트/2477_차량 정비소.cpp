#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct desk
{
    int num, time;
};

struct survey
{
    int reception_desk, repair_desk;
};

int N, M, K, A, B;
survey s[1001];
int arrive_time[1001];
int reception_time[11], repair_time[11];
queue<int> reception, repair;
desk rec[11], rep[11];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        cin >> N >> M >> K >> A >> B;

        for (int i = 1; i <= N; i++)
            cin >> reception_time[i];
        
        for (int i = 1 ; i <= M; i++)
            cin >> repair_time[i];

        for (int i = 1; i <= K; i++)
            cin >> arrive_time[i];

        int answer = 0, cnt = 0, time = 0;

        while (true)
        {
            // 접수 대기열 채우기
            for (int i = 1; i <= K; i++)
                if (arrive_time[i] == time)
                    reception.push(i);
            
            // 정비 대기열 채우기(접수완료)
            for (int i = 1; i <= N; i++)
                if (rec[i].num != 0 && rec[i].time == time)
                {
                    repair.push(rec[i].num);
                    rec[i].num = 0;
                }
            
            // 수리하기
            for (int i = 1; i <= M; i++)
                if (rep[i].num != 0 && rep[i].time == time)
                {
                    rep[i].num = 0;
                    cnt += 1;
                }
            
            // 접수로 올리기
            for (int i = 1; i <= N; i++)
            {
                if (reception.empty())
                    break;
                if (rec[i].num == 0)
                {
                    rec[i].num = reception.front();
                    rec[i].time = time + reception_time[i];
                    reception.pop();
                    s[rec[i].num].reception_desk = i;
                }
            }

            // 정비로 올리기
            for (int i = 1; i <= M; i++)
            {
                if (repair.empty())
                    break;
                if (rep[i].num == 0)
                {
                    rep[i].num = repair.front();
                    rep[i].time = time + repair_time[i];
                    repair.pop();
                    s[rep[i].num].repair_desk = i;
                }
            }

            if (cnt >= K)
                break;
            
            time++;
        }

        for (int i = 1; i <= K; i++)
            if (s[i].reception_desk == A && s[i].repair_desk == B)
                answer += i;
        
        if (answer == 0)
            answer = -1;
        
        cout << "#" << t << " " << answer << "\n";

    }
    
    return 0;
}
