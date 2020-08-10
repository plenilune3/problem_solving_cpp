#include <iostream>

using namespace std;

const int MAX = 101;
const int dx[] = { 0, -1, 0, 1 };
const int dy[] = { 1, 0, -1, 0,};

struct robot
{
    int x, y, dir;
};

int column, row, N, M;
robot R[MAX];
int board[MAX][MAX];

robot make_robot(int x, int y, int dir);
int make_dir(char dir);
bool OutOfRange(int x, int y);
int CrashToRobot(int x, int y);
bool MoveRobot(robot &r);
void RotateRobot(robot &r);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> column >> row;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        int x, y; char dir;
        cin >> y >> x >> dir;
        R[i] = make_robot(x - 1, y - 1, make_dir(dir));
        board[x - 1][y - 1] = i;
    }

    bool isOutOfRange = false;
    int crashedRobotNumber = 0;
    int num, count; char operation;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }

    while (M--)
    {
        cin >> num >> operation >> count;

        while (count--)
        {
            if (operation == 'F')
            {
                int x = R[num].x, y = R[num].y, dir = R[num].dir;
                int nx = x + dx[dir], ny = y + dy[dir];

                isOutOfRange = OutOfRange(nx, ny);

                if (isOutOfRange)
                    break;

                crashedRobotNumber = CrashToRobot(nx, ny);

                if (crashedRobotNumber)
                    break;

                board[x][y] = 0;
                R[num].x = nx, R[num].y = ny;
                board[nx][ny] = num;
            }
            else if (operation == 'L')
            {
                R[num].dir = (R[num].dir + 3) % 4;
            }
            else if (operation == 'R')
            {
                R[num].dir = (R[num].dir + 1) % 4;
            }
        }

        if (isOutOfRange || crashedRobotNumber)
            break;
    }

    if (isOutOfRange)
        cout << "Robot " << num << " " << "crashes into the wall" << "\n";
    else if (crashedRobotNumber)
        cout << "Robot " << num << " " << "crashes into robot " << crashedRobotNumber << "\n";
    else
        cout << "OK" << "\n";

    return 0;
}

robot make_robot(int x, int y, int dir)
{
    return { x, y, dir };
}

int make_dir(char dir)
{
    int result;

    if (dir == 'E')
        result = 0;
    else if (dir == 'W')
        result = 2;
    else if (dir == 'S')
        result = 1;
    else if (dir == 'N')
        result = 3;
    
    return result;
}

bool OutOfRange(int x, int y)
{
    if (x < 0 || x >= row || y < 0 || y >= column)
        return true;
    else
        return false;
}

int CrashToRobot(int x, int y)
{
    return board[x][y];
}
