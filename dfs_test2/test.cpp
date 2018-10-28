// Copyright 2018.刘珅珅
// author：刘珅珅
// 深度优先搜索-迷宫
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

#define N 10  // 迷宫大小
#define ENTER_X 0  // 入口位置
#define ENTER_Y 0
#define EXIT_X N-1  // 出口位置
#define EXIT_Y N-1

int maze[N][N];  // 定义迷宫
int paths;  // 路径条数

vector<Point> current_path;  // 当前路径
vector<Point> best_path;  // 最短路径

void InitMaze()
{
    //定义一个迷宫，0表示通道，1表示墙(或不可走)
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

    //复制到迷宫
    memcpy(maze, mz, sizeof(mz));

    paths = 0;
}

// 深度搜索算法
// 从(x, y)开始走，初始为(0, 0)
void DFS(int x, int y)
{
    Point point = { x, y };
    current_path.push_back(point);
    maze[x][y] = 1;  // 已走，标记为不可走

    if (x == EXIT_X && y == EXIT_Y)  // 这里不能直接返回，因为这只是找到一条路径
    {
        ++paths;

        // 输出路径
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
        cout << "路径长度：" << current_path.size() << endl;
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

    if (x - 1 >= 0 && maze[x - 1][y] == 0)  // 向上走
    {
        DFS(x - 1, y);
    }

    if (x + 1 < N && maze[x + 1][y] == 0)  // 向下走
    {
        DFS(x + 1, y);
    }

    if (y - 1 >= 0 && maze[x][y - 1] == 0)  // 向后走
    {
        DFS(x, y - 1);
    }

    if (y + 1 < N && maze[x][y + 1] == 0)  // 向前走
    {
        DFS(x, y + 1);
    }

    current_path.pop_back();  // 不走(x, y)点
    maze[x][y] = 0;  // 设置为未走
}

int main(int argc, char* argv[])
{
    InitMaze();
    DFS(ENTER_X, ENTER_Y);
    cout << "路径数：" << paths << endl;
    cout << "最短路径为：" << endl;
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
    cout << "最短路径长度为：" << best_path.size() << endl;
    return 0;
}
