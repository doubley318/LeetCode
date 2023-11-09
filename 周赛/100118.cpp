long long bfs(vector<vector<int>>& tree, int node, vector<int>& values, vector<bool>& visited)
{
    bool son = false;
    long long sum = 0;
    for (int i = 0; i < tree[node].size(); i++) {
        if (visited[tree[node][i]] == false) {
            son = true;
            visited[tree[node][i]] = true;
            sum += bfs(tree, tree[node][i], values, visited);
        }
    }
    if (son == false) {
        return values[node];
    }
    if (values[node] >= sum) {
        values[node] = sum;
    }
    return values[node];
}

long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values)
{
    int n = values.size();
    vector<vector<int>> tree(n);
    for (int i = 0; i < edges.size(); i++) {
        tree[edges[i][0]].push_back(edges[i][1]);
        tree[edges[i][1]].push_back(edges[i][0]);
    }
    vector<bool> visited(n, false);
    long long sum = 0;
    for (int i = 0; i < values.size(); i++) {
        sum += values[i];
    }
    visited[0] = true;
    return sum - bfs(tree, 0, values, visited);
}