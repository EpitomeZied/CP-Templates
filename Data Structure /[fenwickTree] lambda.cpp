    vector<int> v(n), bit(n + 1);
    auto get = [&](int i) {
        int res = 0;
        for (++i; i; i -= (i & -i)) {
            res += bit[i - 1];
        }
        return res;
    };

    auto set = [&](int i, int val) {
        for (++i; i <= n; i += (i & -i)) {
            bit[i - 1] = val;
        }
    };
    

    auto add = [&](int i, int val) {
        for (++i; i <= n; i += (i & -i)) {
            bit[i - 1] += val;
        }
    };

    auto getRange = [&](int s, int e) {
        return get(e) - get(s - 1);
    };

    auto getVal = [&](int i) {
        return getRange(i , i);
    };

    auto lb= [&] (int t) {
        int s = 0;
        for (int sz = n >> 1; sz; sz >>= 1)
            if (bit[s + sz - 1] < t)
                t -= bit[(s += sz) - 1];
        return s;
    };