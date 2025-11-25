 vector<int> v(n), m(n + 1), c(n + 1);

    auto get = [&](int pos) {
        int res = 0;
        int i = pos;
        for (++i; i; i -= (i & -i))
            res += pos * m[i - 1] + c[i - 1];
        return res;
    };
    auto add = [&](int i, int ma , int ca) {
        for (++i; i <= n; i += (i & -i))
            m[i - 1] += ma,c[i-1]+=ca;
    };
    auto getRange = [&](int s, int e) {
        return get(e) - get(s - 1);
    };
    auto getVal = [&](int i) {
        return getRange(i, i);
    };
    auto addRange = [&](int s, int e,int v) {
        add(s,v,v*(1-s));
        add(e+1,-v,v*e);
    };
