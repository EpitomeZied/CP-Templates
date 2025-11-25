extern struct node *const EMPTY;

struct node {
    int sum = 0;
    node *l, *r;

    node() : sum(0), l(this), r(this) {}

    node(int sum, node *l = EMPTY, node *r = EMPTY) : sum(sum), l(l), r(r) {}
};

node *const EMPTY = new node();

node *insert(int x, node *cur, int ns = -1e9, int ne = 1e9) {
    if (x < ns || x > ne) return cur;
    if (ns == ne) return new node(cur->sum + 1);
    int m = ns + (ne - ns) / 2;
    node *l = insert(x, cur->l, ns, m);
    node *r = insert(x, cur->r, m + 1, ne);
    return new node(l->sum + r->sum, l, r);
}

node *roots[N];

int BS (node *pre, node *all, int k, int ns = -1e9, int ne = 1e9) {
    if (ns == ne) return ns;
    int lfSz = all->l->sum - pre->l->sum;
    int m = ns + (ne - ns) / 2;
    if (k <= lfSz)
        return BS(pre->l, all->l, k, ns, m);
    return BS(pre->r, all->r, k - lfSz, m + 1, ne);
}