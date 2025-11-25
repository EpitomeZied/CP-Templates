struct node {
    long long sum, lzAdd, lzSet;

    void set(long long v, int ns, int ne) {
        sum = v * (ne - ns + 1);
        lzSet = v;
        lzAdd = 0;
    }

    void add(long long v, int ns, int ne) {
        sum += v * (ne - ns + 1);
        lzAdd += v;
    }
} nodes[N];

void pushDown(int ni, int ns, int ne) {
    if (ns == ne)return;
    int l = ni * 2 + 1, r = l + 1, m = ns + (ne - ns) / 2;
    if (nodes[ni].lzSet != -1) {
        nodes[l].set(nodes[ni].lzSet, ns, m);
        nodes[r].set(nodes[ni].lzSet, m + 1, ne);
        nodes[ni].lzSet = -1;
    }
    if (nodes[ni].lzAdd) {
        nodes[l].add(nodes[ni].lzAdd, ns, m);
        nodes[r].add(nodes[ni].lzAdd, m + 1, ne);
        nodes[ni].lzAdd = 0;
    }
}

int arr[N], n;

node merge(const node &a, const node &b) {
    return {a.sum + b.sum, 0, -1};
}

void build(int ni = 0, int ns = 0, int ne = n - 1) {
    if (ns == ne) {
        nodes[ni] = {arr[ns], 0, -1};
        return;
    }
    int l = ni * 2 + 1, r = l + 1, m = ns + (ne - ns) / 2;
    build(l, ns, m);
    build(r, m + 1, ne);
    nodes[ni] = merge(nodes[l], nodes[r]);
}

void update(int qs,int qe,int v,bool isAdd, int ni = 0, int ns = 0, int ne = n - 1) {
    if (qs > ne || qe < ns)return;
    if (qs <= ns && qe >= ne) {
        if (isAdd) {
            nodes[ni].add(v, ns, ne);
        } else {
            nodes[ni].set(v, ns, ne);
        }
        return;
    }
    pushDown(ni, ns, ne);
    int l = ni * 2 + 1, r = l + 1, m = ns + (ne - ns) / 2;
    update(qs,qe,v,isAdd, l, ns, m);
    update(qs,qe,v,isAdd, r, m + 1, ne);
    nodes[ni] = merge(nodes[l], nodes[r]);
}

node query(int qs, int qe, int ni = 0, int ns = 0, int ne = n - 1) {
    if (qs > ne || qe < ns)return {0,0,-1};
    if (qs <= ns && qe >= ne)return nodes[ni];
    pushDown(ni, ns, ne);
    int l = ni * 2 + 1, r = l + 1, m = ns + (ne - ns) / 2;
    return merge(query(qs, qe, l, ns, m), query(qs, qe, r, m + 1, ne));
}