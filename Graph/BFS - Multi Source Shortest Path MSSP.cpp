    auto bfs = [&](vector<int> &srcs) {
        vi dist(n , OO );
        queue<int> q;
        
        for (auto &src: srcs) {
            dist[src] = 0;
            q.push(src);
        }

        while (!q.empty()) {
            auto u = q.front();
            q.pop();

            for (auto v: grid[u]) {
                if (dist[v] == OO) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
    };
