#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
vector<int> sub;

void dfs(int u)
{
    sub[u] = 1;

    for(int v : tree[u])
    {
        dfs(v);
        sub[u] += sub[v];
    }
}

int main()
{
    int n;
    cin >> n;

    tree.resize(n + 1);
    sub.resize(n + 1);

    for(int i = 2; i <= n; i++)
    {
        int boss;
        cin >> boss;

        tree[boss].push_back(i);
    }

    dfs(1);

    for(int i = 1; i <= n; i++)
        cout << sub[i] - 1 << " ";

    return 0;
}