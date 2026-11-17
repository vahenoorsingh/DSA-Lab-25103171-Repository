#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main()
{
    string line;
    if (!getline(cin, line))
        return 0;

    stringstream ss(line);
    vector<int> tree;
    int val;
    while (ss >> val)
    {
        tree.push_back(val);
    }

    int S, K;
    cin >> S >> K;

    if (tree.empty() || tree[0] == -1)
        return 0;

    unordered_map<int, vector<int>> adj;
    queue<int> q;
    q.push(tree[0]);
    int i = 1;

    while (!q.empty() && i < tree.size())
    {
        int curr = q.front();
        q.pop();

        if (i < tree.size() && tree[i] != -1)
        {
            adj[curr].push_back(tree[i]);
            adj[tree[i]].push_back(curr);
            q.push(tree[i]);
        }
        i++;

        if (i < tree.size() && tree[i] != -1)
        {
            adj[curr].push_back(tree[i]);
            adj[tree[i]].push_back(curr);
            q.push(tree[i]);
        }
        i++;
    }

    queue<pair<int, int>> bfs;
    bfs.push({S, 0});
    unordered_set<int> visited;
    visited.insert(S);
    vector<int> res;

    while (!bfs.empty())
    {
        int node = bfs.front().first;
        int dist = bfs.front().second;
        bfs.pop();

        if (dist == K)
        {
            res.push_back(node);
        }
        else if (dist < K)
        {
            for (int neighbor : adj[node])
            {
                if (!visited.count(neighbor))
                {
                    visited.insert(neighbor);
                    bfs.push({neighbor, dist + 1});
                }
            }
        }
    }

    for (int j = 0; j < res.size(); j++)
    {
        cout << res[j] << ' ';
    }
    cout << endl;

    return 0;
}