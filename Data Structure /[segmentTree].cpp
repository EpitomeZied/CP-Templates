int nodes[N], n = 200001;
vi arr;
int merge(const int &a, const int &b) {
    return a + b;
}
 
void build(int ni = 0,int ns = 0,int ne = n - 1) {
    // (idx , start , end)
    if (ns == ne) {
        // Leaf Node
        nodes[ni] = 0;
        return;
    }
    // internal Node
    int l = ni * 2 + 1, r = l + 1, m = ns + (ne - ns) / 2;
    build(l, ns, m);
    build(r, m + 1, ne);
    nodes[ni] = merge(nodes[l], nodes[r]);
}
 
void update(int p,int v,int ni = 0,int ns = 0,int ne = n - 1) {
    if (p < ns || p > ne)return; // (out of range) No Change
    if (ns == ne) {
        nodes[ni] += v;
        return;
    }
    int l = ni * 2 + 1, r = l + 1, m = ns + (ne - ns) / 2;
    update(p, v, l, ns, m);
    update(p, v, r, m + 1, ne);
    nodes[ni] = merge(nodes[l], nodes[r]);
}
 
int query(int qs,int qe,int ni = 0,int ns = 0,int ne = n - 1) {
    if (qs > ne || qe < ns) return 0; // All Out ( Put thing Doesn't Change)
    if (qs <= ns && qe >= ne)return nodes[ni];
    int l = ni * 2 + 1, r = l + 1, m = ns + (ne - ns) / 2;
    return merge(query(qs, qe, l, ns, m), query(qs, qe, r, m + 1, ne));
}