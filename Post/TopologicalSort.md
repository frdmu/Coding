# 拓扑排序

## 可以用于判断有向无环图, 过程如下：。
 - 定义一个队列，并把所有入度为0的结点加入队列
 - 取队首结点，然后删除所有从他出发的边，并把他到达的结点入度减1，如果入度为0，加入队列
 - 循环执行上一步，直到队列为空。如果队列里处理过的结点数为n，则为有向无环图，否则为有环图

代码实现需要一个入度数组记录每一个结点的入度，如下：
```c++
vector<int> inDegree(MAXV);
vector<vector<int>> G(MAXV);

bool topologicalSort() {
    int num = 0;
    queue<int> q;
    
    for (int i = 0; i < MAXV; i++) {
        if (inDegree[i] == 0) 
            q.push(i);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        num++;
        for (auto v: G[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) 
                q.push(v);
        }
        G[u].clear(); // 如无必要，可不写
    }
    if (num == MAXV)
        return true;
    return false;
}
```
