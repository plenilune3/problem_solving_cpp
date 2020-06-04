#include <iostream>
#include <vector>

using namespace std;

const int dx[] = { 0, -1, 0, 1, 0 };
const int dy[] = { 0, 0, 1, 0, -1 };

struct bc
{
    int x, y, c, p;
};

int T, M, A;
int user_a[101];
int user_b[101];
bc b[8];

int get_distance(int ux, int uy, int x, int y)
{
    int result = 0;

    if (ux > x)
        result += ux - x;
    else
        result += x - ux;
    
    if (uy > y)
        result += uy - y;
    else
        result += y - uy;
    
    return result;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        int sum_bc = 0;
        cin >> M >> A;

        for (int i = 1; i <= M; i++)
            cin >> user_a[i];
        
        for (int i = 1; i <= M; i++)
            cin >> user_b[i];
        
        for (int i = 0; i < A; i++)
        {
            int x, y, c, p;
            cin >> x >> y >> c >> p;
            bc t = { y, x, c, p };
            b[i] = t;
        }

        int ax = 1, ay = 1, bx = 10, by = 10;

        for (int i = 0; i <= M; i++)
        {
            ax += dx[user_a[i]], ay += dy[user_a[i]];
            bx += dx[user_b[i]], by += dy[user_b[i]];

            vector<bc> bc_a, bc_b;

            for (int j = 0; j < A; j++)
            {
                if (get_distance(ax, ay, b[j].x, b[j].y) <= b[j].c)
                    bc_a.push_back(b[j]);
                if (get_distance(bx, by, b[j].x, b[j].y) <= b[j].c)
                    bc_b.push_back(b[j]);
            }
                
            if (bc_a.empty() && bc_b.empty())
                continue;
            else if (bc_a.empty() && bc_b.empty() == false)
            {
                int temp = 0;
                for (int k = 0; k < bc_b.size(); k++)
                    temp = max(temp, bc_b[k].p);
                sum_bc += temp;
            }
            else if (bc_b.empty() && bc_a.empty() == false)
            {

                int temp = 0;
                for (int k = 0; k < bc_a.size(); k++)
                    temp = max(temp, bc_a[k].p);
                sum_bc += temp;
            }
            else if (bc_a.empty() == false && bc_b.empty() == false)
            {
                int temp = 0;
                for (int a = 0; a < bc_a.size(); a++)
                    for (int b = 0; b < bc_b.size(); b++)
                    {
                        if (bc_a[a].x == bc_b[b].x && bc_a[a].y == bc_b[b].y)
                            temp = max(temp, (bc_a[a].p + bc_b[b].p) / 2);
                        else
                            temp = max(temp, (bc_a[a].p + bc_b[b].p));
                    }
                sum_bc += temp;
            }
        }

        cout << "#" << t << " " << sum_bc << "\n";
    }

    return 0;
}
