    vi path;
    vvi allCycles;
    vi onPath(n);
    function<void(int, int, int)> dfs = [&](int u, int p, int startNode) {
        path.pb(u);
        onPath[u] = true;

        if (path.size() > 3) {
            path.pop_back();
            onPath[u] = false;
            return;
        }

        for (auto v: grid[u]) {
            if (v == p) {
                continue;
            }

            if (v == startNode) {
                if (path.size() == 3) {
                    allCycles.pb(path);
                }
            } else if (v > startNode && !onPath[v]) {
                if (path.size() < 3) {
                    dfs(v, u, startNode);
                }
            }
        }
        path.pop_back();
        onPath[u] = false;
    };

    for (int i = 0; i < n; ++i) {
        path.clear();
        fill(all(onPath), false);
        dfs(i, -1, i);
    }
