template<class T>
struct SparseTable {
    // change mxLog
    static const int mxLog = 20;
    vector<array<T, mxLog> > table;
    vector<int> lg;
    int n;
 
    SparseTable(int sz) {
        n = sz;
        table.resize(n + 1);
        lg.resize(n + 1);
        for (int i = 0; i <= n; ++i) lg[i] = __lg(i);
    }
 
    void build(vector<T> &v) {
        for (int i = 0; i < n; ++i) table[i][0] = v[i];
        for (int j = 1; j < mxLog; ++j)
            for (int i = 0; i + (1 << j) - 1 < n; ++i)
                table[i][j] = merge(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
    }
 
    T merge(T &l, T &r) {
        // X op X = X
        return gcd(l, r);
    }
 
    T query(int l, int r) {
        int j = lg[r - l + 1];
        return merge(table[l][j], table[r - (1 << j) + 1][j]);
    }
    T query2(int l , int r){
        int xr = 0;
        for (int i = 0; i < mxLog; ++i) {
            if ((r - l + 1) & (1 << i)){
                xr ^= table[l][i];
                l += (1 << i);
            }
        }
        return xr;
    }
};
