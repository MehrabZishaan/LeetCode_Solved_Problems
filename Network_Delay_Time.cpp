class Solution
{
public:
    const long long INF = 1e18;
    vector<vector<pair<int, int>>> adj_list;
    vector<long long> d;
    vector<int> visited;

    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        adj_list.resize(n + 1);
        d.resize(n + 1, INF);
        visited.resize(n + 1, 0);

        for (const auto& time : times)
        {
            int u = time[0];
            int v = time[1];
            int w = time[2];
            adj_list[u].push_back({v, w});
        }

        dijkstra(k, n);

        long long maxTime = 0;
        for (int i = 1; i <= n; i++)
        {
            if (d[i] == INF)
            {
                return -1;
            }
            maxTime = max(maxTime, d[i]);
        }

        return maxTime;
    }

    void dijkstra(int src, int n)
    {
        d[src] = 0;
        priority_queue<pair<long long, int>> pq;
        pq.push({0, src});

        while (!pq.empty())
        {
            pair<long long, int> head = pq.top();
            pq.pop();
            int selected_node = head.second;

            if (visited[selected_node])
            {
                continue;
            }

            visited[selected_node] = 1;

            for (auto adj_entry : adj_list[selected_node])
            {
                int adj_node = adj_entry.first;
                int edge_cst = adj_entry.second;

                if (d[selected_node] + edge_cst < d[adj_node])
                {
                    d[adj_node] = d[selected_node] + edge_cst;
                    pq.push({-d[adj_node], adj_node});
                }
            }
        }
    }
};
