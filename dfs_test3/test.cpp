// Copyright 2018.刘珅珅
// author：刘珅珅
// 深度优先搜索-啊哈磊算法-拯救小哈
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int maze[5][9];  // 定义迷宫
int paths;  // 路径条数
int n = 5;
int m = 9;
int p = 1;  // 终点x
int q = 1;  // 终点y
int book[51][51];
int min_step = 99999;

void dfs(int x, int y, int step)
{
	int next[4][2] = { {0, 1},  // 向右走
	                            {1, 0},  // 向下走
	                            {0, -1},  // 向左走
	                            {-1, 0}  // 向上走
	};

	if (x == p && y == q)
	{
		++paths;
		if (step < min_step)
			min_step = step;
		return;
	}

	for (int k = 0; k < 3; ++k)
	{
		int tx = x + next[k][0];
		int ty = y + next[k][1];
		if (tx < 0 || tx > (n - 1) || ty < 0 || ty > (m - 1))
			continue;
		if (maze[tx][ty] == 0 && book[tx][ty] == 0)
		{
			book[tx][ty] = 1;  // 标记已走
			dfs(tx, ty, step + 1);  // 尝试下一个
			book[tx][ty] = 0;  // 尝试结束，取消这个点的标记
		}
	}
	return;
}

void InitMaze()
{
    //定义一个迷宫，0表示通道，1表示墙(或不可走)
    int mz[5][9] = {
        { 0,0,0,0,0,0,0,0,0 }, //0
        { 0,0,1,1,1,1,1,1,0 }, //1
        { 1,0,0,1,1,1,0,0,1 }, //2
        { 1,1,0,0,1,0,0,1,1 }, //3
        { 1,1,1,0,0,0,1,1,1 }  //4
        //   0 1 2 3 4 5 6 7 8
    };

    //复制到迷宫
    memcpy(maze, mz, sizeof(mz));

    paths = 0;
}

int main(int argc, char* argv[])
{
	int startx = 0;
	int starty = 8;
	book[startx][starty] = 1;
	dfs(startx, starty, 0);
	cout << "min step: " << min_step << endl;
	cout << "total path: " << paths << endl;
    return 0;
}
