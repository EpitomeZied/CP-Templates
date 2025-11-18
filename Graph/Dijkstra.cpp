auto dijkstra = [&]() {
        vector<int> dist(n, OO);
        vector<bool> vis(n);
        vector<int> par(n);
        priority_queue<pii, vector<pii>, greater<>> q;

        dist[0] = 0;
        q.emplace(0, 0);

        while (!q.empty()) {
            auto [d, u] = q.top();
            q.pop();
            if (vis[u]) continue;
            vis[u] = true;
            for (auto &v : grid[u]) {
                if (dist[u] + v.second < dist[v.first]) {
                    dist[v.first] = dist[u] + v.second;
                    q.emplace(dist[v.first], v.first);
                    par[v.first] = u;
                }
            }
        }
        return dist;
    };