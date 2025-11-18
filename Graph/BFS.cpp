    auto bfs = [&](int s) -> void {
        queue<int> q;
        q.push(s);
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            if (vis[v])
                continue;
            vis[v] = true;
            for (auto const &u : grid[v])
                if (!vis[u])
                    q.push(u);
        }
    };
