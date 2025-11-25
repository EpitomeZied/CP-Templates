vector<int> nodes[N];
int arr[N], n;

void build(int ni = 0,int ns = 0,int ne = n - 1) {
    nodes[ni].clear();
    if (ns == ne) return void(nodes[ni].push_back(arr[ns]));
    int l = ni * 2 + 1, r = l + 1, m = ns + (ne - ns) / 2;
    build(l, ns, m);
    build(r, m + 1, ne);
    merge(nodes[l].begin(), nodes[l].end(), nodes[r].begin(), nodes[r].end(), back_inserter(nodes[ni]));
}

int query(int qs,int qe,int x,int ni = 0,int ns = 0,int ne = n - 1) {
    if (qs > ne or qe < ns) return 0;
    if (qs <= ns and qe >= ne) return upper_bound(nodes[ni].begin(), nodes[ni].end(), x) - nodes[ni].begin();
    int l = ni * 2 + 1, r = l + 1, m = ns + (ne - ns) / 2;
    return query(qs, qe, x, l, ns, m) + query(qs, qe, x, r, m + 1, ne);
}

int BS (int qs,int qe,int k) {
    int s = -1e9 - 1, e = 1e9 + 1;
    while (e - s > 1) {
        int m = s + (e - s) / 2;
        if (query(qs, qe, m) < k) s = m;
        else e = m;
    }
    return e;
}