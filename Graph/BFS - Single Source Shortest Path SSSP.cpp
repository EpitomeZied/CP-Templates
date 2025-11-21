    auto bfs = [&](int src) {
        vi dist(n , OO);

        dist[src] = 0;

        queue<int> q;
        q.push(src);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto v: grid[u]) {
                if (dist[v] == OO) {
                    dist[v] = dist[u] + 1;
                     q.push(v);
                }
            }
        }
        return dist;
    };
