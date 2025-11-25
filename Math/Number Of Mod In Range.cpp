// count number of y such that y%n = x (0 -> l)
int f(int l, int n, int x = 0 ) {
    int cnt = (l / n) + (l % n >= x);
    return cnt;
}

ll how_many_divisors(ll a, ll b, ll c){
    return (b / c) - ((a - 1) / c);
}

    ll Summation_of_Devisors(ll a, ll b, ll c){
        ll right = Summation(b / c);
        ll left = Summation((a - 1) / c);
        return (right - left) * c;
    }