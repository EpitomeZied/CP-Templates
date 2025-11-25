vector<bool> prime;
vector<int> primes;

vector<int> Sieve(int n) {
    prime.assign(n + 1, true);
    prime[0] = prime[1] = false;

    for(int i = 2; i * i <= n; ++i) {
        if(!prime[i]) continue;
        for(int j = 2; j * i <= n; ++j) prime[i * j] = false;
    }

    // If needed
    for(int i = 2; i <= n; ++i) if(prime[i]) primes.push_back(i);
    return primes;
}