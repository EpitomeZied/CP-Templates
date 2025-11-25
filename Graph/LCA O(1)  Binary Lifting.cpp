int st[20][N], lg2[N], dpth[N], nti[N], itn[N], cnt;

void build() {
    lg2[0] = -1;
    for (int i = 0; i < cnt; ++i) {
        lg2[i + 1] = lg2[i] + !(i & (i + 1));
        st[0][i] = i;
    }

    for (int j = 1; 1 << j <= cnt; ++j)
        for (int i = 0; i + (1 << j) <= cnt; ++i) {
            int a = st[j - 1][i], b = st[j - 1][i + (1 << (j - 1))];
            st[j][i] = dpth[a] < dpth[b] ? a : b;
        }
}

int rmq(int s, int e) {
    int sz = e - s + 1;
    int l = lg2[sz];
    int a = st[l][s], b = st[l][e - (1 << l) + 1];
    return dpth[a] < dpth[b] ? a : b;
}

vector<vector<int> > adj;

void dfs(int u,int p,int d) {
    itn[cnt] = u;
    nti[u] = cnt;
    dpth[cnt++] = d;
    for (auto v: adj[u]) {
        if (v == p)continue;
        dfs(v, u, d + 1);
        itn[cnt] = u;
        dpth[cnt++] = d;
    }
}

int lca(int a,int b) {
    a = nti[a];
    b = nti[b];
    if (a > b)swap(a, b);
    return itn[rmq(a, b)];
}


auto Solve(int &n) {
    adj = vector<vector<int>>(n + 1);
    int q;
    cin >> q;
    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    dfs(0,-1,0);
    build();
    vi ans;
    while (q--) {
        int u, v;
        cin >> u >> v;
        ans.pb(lca(u, v));
    }
    return ans  ;
}
