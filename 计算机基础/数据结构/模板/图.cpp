// 记录和图相关的模板

#include <vector>
#include <iostream>
using namespace std;

const int N = 1e5, M = 1e5;
// 临界矩阵
int g[N][N];

// 用数组模拟临接表

int h[N], e[N], ne[N], idx;

void init(void) {
    // 初始化临接表
    idx = 0;
    memset(h, -1, sizeof h);
}

void add(int a, int b) {
    // 添加一条边
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

// 真题中出现过的图的定义
struct MGraph {
    // 2021年, 2023年, 2024年
    int numVertices, numEdges; //图的定点数和边数
    char VerticesList[N]; //定点表 
    int Edge[N][N]; // 临接矩阵
};

// 图的遍历 - dfs

bool st[N]; // 状态记录数组

int dfs(int u) {
    st[u] = true; // 标记当前结点已经被遍历

    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) dfs(j);
    }
}

// 图的遍历 - bfs 

#include <queue>  // BFS需要使用队列

void bfs() {
    queue<int> q;
    st[1] = true; // 图中点的编号从1开始
    q.push(1); 

    while (!q.empty()) {
        int t = q.front();
        q.pop();

        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (!st[j]) {
                st[j] = true;
                q.push(j);
            }
        }
    }
}

// 拓扑排序 

int d[N], q[N];

bool topsort()
{
    int hh = 0, tt = -1;

    // d[i] 存储点i的入度
    for (int i = 1; i <= N; i ++ )
        if (!d[i])
            q[ ++ tt] = i;

    while (hh <= tt)
    {
        int t = q[hh ++ ];

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (-- d[j] == 0)
                q[ ++ tt] = j;
        }
    }

    // 如果所有点都入队了，说明存在拓扑序列；否则不存在拓扑序列。
    return tt == N - 1;
}

// 朴素Dijstra算法

