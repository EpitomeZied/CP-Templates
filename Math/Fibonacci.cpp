///////////////////////////////////
// Count Fibonacci numbers ..?
    vi dp(N, -1);
    dp[0] = 0 ; dp[1] = 1;
    for (int i = 2; i < N; ++i) {
        dp[i] = add_mod(dp[i - 1] , dp[i - 2]);
    }

///////////////////////////////////
// isFibonacci ..?
bool isPerfectSquare(long long x) {
    long long s = sqrtl(x);
    return s * s == x;
}

bool isFibonacci(long long n) {
    return isPerfectSquare(5 * n * n + 4) || isPerfectSquare(5 * n * n - 4);
}


///////////////////////////////////
// idx Fib ..?
map<int, int> F;

int f(int n) {
    //  in Main ->     if (n == 0) return 0LL ; F[0] = 1, F[1] = 1;
    if (F.count(n)) return F[n];
    int k = n / 2;
    if (n % 2 == 0) {
        // n=2*k
        return F[n] = (f(k) * f(k) + f(k - 1) * f(k - 1)) % M;
    } else {
        // n=2*k+1
        return F[n] = (f(k) * f(k + 1) + f(k - 1) * f(k)) % M;
    }
}

///////////////////////////////////
// Fibonacci Sum ..?

map<int, int> F;

int f(int n) {
    //  in Main ->     if (n == 0) return 0LL ; F[0] = 1, F[1] = 1;
    if (F.count(n)) return F[n];
    int k = n / 2;
    if (n % 2 == 0) {
        // n=2*k
        return F[n] = (f(k) * f(k) + f(k - 1) * f(k - 1)) % M;
    } else {
        // n=2*k+1
        return F[n] = (f(k) * f(k + 1) + f(k - 1) * f(k)) % M;
    }
}

auto Solve(const int &n) {
    F[0] = F[1] = 1;
    int m;cin >> m;
    return (f(m + 1) - f(n) + M) % M;
}

