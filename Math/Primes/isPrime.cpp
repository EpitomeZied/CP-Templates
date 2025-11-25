bool isPrime(ll n) {
    if(n == 2) return true;
    if(n % 2 == 0 || n < 2) return false;
    bool res = true;
    for(ll i = 3; i * i <= n; i += 2) if(!(n % i)) res = false;
    return res;
}