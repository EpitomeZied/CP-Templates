struct DSU {
    int n;
    int cnt;
    vector<int> parent, size, mn;

    DSU(int sz) {
        n = sz;
        cnt = 0;
        parent.resize(n + 1);
        size.resize(n + 1);
        mn.resize(n + 1);
        init();
    }

    void init() {
        for (int u = 1; u <= n; ++u)
            makeSet(u);
    }

    void makeSet(int u) {
        if (!size[u]) cnt++;
        parent[u] = u;
        size[u] = 1;
        mn[u] = u;
    }


    int find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]); // Path Compression
    }

    bool merge(int u, int v) {
        int uP = find(u), vP = find(v);
        if (vP == uP) return false ; // Cycle Detection
        if (size[vP] > size[uP]) swap(uP, vP);
        size[uP] += size[vP];
        mn[uP] = min(mn[uP], mn[vP]);
        parent[vP] = uP;
        cnt--;
        return true;
    }
};