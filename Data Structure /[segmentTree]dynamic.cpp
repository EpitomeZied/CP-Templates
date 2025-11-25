int arr[N];
extern struct node *const EMPTY;

struct node {
    int v;
    node *l, *r;

    node(): v(0), l(this), r(this) {
    }

    node(int v): v(v), l(EMPTY), r(EMPTY) {
    }
};

node *const EMPTY = new node();

void add(int p,int v, node *&cur,int ns = 1,int ne = 1e9) {
    // update
    if (p < ns or p > ne)return;
    if (cur == EMPTY)cur = new node(0);
    if (ns == ne) {
        cur->v += v;
        return;
    }
    int m = ns + (ne - ns) / 2;
    add(p, v, cur->l, ns, m);
    add(p, v, cur->r, m + 1, ne);
    cur->v = cur->l->v + cur->r->v;
}

int query(int qs,int qe, node *&cur,int ns = 1,int ne = 1e9) {
    if (qs > ne or qe < ns)return 0;
    if (qs <= ns and qe >= ne)return cur->v;
    if (cur == EMPTY) return 0;
    int m = ns + (ne - ns) / 2;
    return query(qs, qe, cur->l, ns, m) + query(qs, qe, cur->r, m + 1, ne);
}