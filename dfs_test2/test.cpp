// Copyright 2018.���|�|
// author�����|�|
// �����������-�Թ�
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

typedef struct Point
{
    int x;
    int y;
};

#define N 10  // �Թ���С
#define ENTER_X 0  // ���λ��
#define ENTER_Y 0
#define EXIT_X N-1  // ����λ��
#define EXIT_Y N-1

int maze[N][N];  // �����Թ�
int paths;  // ·������

vector<Point> current_path;  // ��ǰ·��
vector<Point> best_path;  // ���·��

void InitMaze()
{
    //����һ���Թ���0��ʾͨ����1��ʾǽ(�򲻿���)
    int mz[10][10] = {
        { 0,0,1,1,1,1,1,1,1,1 }, //0
        { 1,0,0,1,1,0,0,1,0,1 }, //1
        { 1,0,0,1,0,0,0,1,0,1 }, //2
        { 1,0,0,0,0,1,1,0,0,1 }, //3
        { 1,0,1,1,1,0,0,0,0,1 }, //4
        { 1,0,0,0,1,0,0,0,0,1 }, //5
        { 1,0,1,0,0,0,1,0,0,1 }, //6
        { 1,0,1,1,1,0,1,1,0,1 }, //7
        { 1,1,0,0,0,0,0,0,0,0 }, //8
        { 1,1,1,1,1,1,1,1,1,0 }  //9
     //   0 1 2 3 4 5 6 7 8 9
    };

    //���Ƶ��Թ�
    memcpy(maze, mz, sizeof(mz));

    paths = 0;
}

// ��������㷨
// ��(x, y)��ʼ�ߣ���ʼΪ(0, 0)
void DFS(int x, int y)
{
    Point point = { x, y };
    current_path.push_back(point);
    maze[x][y] = 1;  // ���ߣ����Ϊ������

    if (x == EXIT_X && y == EXIT_Y)  // ���ﲻ��ֱ�ӷ��أ���Ϊ��ֻ���ҵ�һ��·��
    {
        ++paths;

        // ���·��
        for (int i = 0; i < current_path.size(); ++i)
        {
            if (i < current_path.size() - 1)
            {
                cout << "(" << current_path[i].x << "," << current_path[i].y
                    << ")" << "->";
            }
            else
            {
                cout << "(" << current_path[i].x << "," << current_path[i].y
                    << ")";
            }
        }
        cout << endl;
        cout << "·�����ȣ�" << current_path.size() << endl;
        if (best_path.size() == 0)
        {
            for (int i = 0; i < current_path.size(); ++i)
            {
                best_path.push_back(current_path[i]);
            }
        }
        else
        {
            if (current_path.size() < best_path.size())
            {
                best_path.clear();
                for (int i = 0; i < current_path.size(); ++i)
                {
                    best_path.push_back(current_path[i]);
                }
            }
        }
    }

    if (x - 1 >= 0 && maze[x - 1][y] == 0)  // ������
    {
        DFS(x - 1, y);
    }

    if (x + 1 < N && maze[x + 1][y] == 0)  // ������
    {
        DFS(x + 1, y);
    }

    if (y - 1 >= 0 && maze[x][y - 1] == 0)  // �����
    {
        DFS(x, y - 1);
    }

    if (y + 1 < N && maze[x][y + 1] == 0)  // ��ǰ��
    {
        DFS(x, y + 1);
    }

    current_path.pop_back();  // ����(x, y)��
    maze[x][y] = 0;  // ����Ϊδ��
}

int main(int argc, char* argv[])
{
    InitMaze();
    DFS(ENTER_X, ENTER_Y);
    cout << "·������" << paths << endl;
    cout << "���·��Ϊ��" << endl;
    for (int i = 0; i < best_path.size(); ++i)
    {
        if (i < best_path.size() - 1)
        {
            cout << "(" << best_path[i].x << "," << best_path[i].y
                << ")" << "->";
        }
        else
        {
            cout << "(" << best_path[i].x << "," << best_path[i].y
                << ")";
        }
    }
    cout << endl;
    cout << "���·������Ϊ��" << best_path.size() << endl;
    return 0;
}
