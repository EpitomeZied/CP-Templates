    auto bfs = [&](vector<pii> &srcs) {
        vvi dist(n, vector<int>(m, OO));

        queue<pii> q;

        for (auto &src: srcs) {
            auto [u,v] = src;
            dist[u][v] = 0;
            q.push(src);
        }

        while (!q.empty()) {
            auto [u,v] = q.front();
            q.pop();

            for (int kk = 0; kk < 4; kk++) {
                int nr = u + dx[kk];
                int nc = v + dy[kk];

                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;

                if (dist[nr][nc] == OO) {
                    dist[nr][nc] = dist[u][v] + 1;
                    q.push({nr, nc});
                }
            }
        }
        return dist;
    };
