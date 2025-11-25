struct node {
    int sm, mx;
};

node nodes[N];
int arr[N], n;

node merge(const node &a, const node &b) {
    return {a.sm + b.sm, max(a.mx, b.mx)};
}

void build(int ni = 0, int ns = 0, int ne = n - 1) {
    if (ns == ne) {
        nodes[ni] = {arr[ns], arr[ns]};
        return;
    }
    int l = 2 * ni + 1, r = l + 1, m = ns + (ne - ns) / 2;
    build(l, ns, m);
    build(r, m + 1, ne);
    nodes[ni] = merge(nodes[l], nodes[r]);
}

void update(int p, int v, int ni = 0, int ns = 0, int ne = n - 1) {
    if (p < ns || p > ne) return;
    if (ns == ne) {
        nodes[ni] = {v, v};
        return;
    }
    int l = 2 * ni + 1, r = l + 1, m = ns + (ne - ns) / 2;
    update(p, v, l, ns, m);
    update(p, v, r, m + 1, ne);
    nodes[ni] = merge(nodes[l], nodes[r]);
}

void mod(int qs, int qe, int v, int ni = 0, int ns = 0, int ne = n - 1) {
    if (ne < qs || ns > qe || v > nodes[ni].mx) return;
    if (ns == ne) {
        nodes[ni] = {nodes[ni].sm % v, nodes[ni].sm % v};
        return;
    }
    int l = 2 * ni + 1, r = l + 1, m = ns + (ne - ns) / 2;
    mod(qs, qe, v, l, ns, m);
    mod(qs, qe, v, r, m + 1, ne);
    nodes[ni] = merge(nodes[l], nodes[r]);
}

node query(int qs, int qe, int ni = 0, int ns = 0, int ne = n - 1) {
    if (ne < qs || ns > qe) return {0, 0};
    if (qs <= ns && ne <= qe) return nodes[ni];
    int l = 2 * ni + 1, r = l + 1, m = ns + (ne - ns) / 2;
    return merge(query(qs, qe, l, ns, m), query(qs, qe, r, m + 1, ne));
}