
vb prime_range_sieve(ll num) {

    vb primes(num + 1, true);
    primes[0] = primes[1] = false;

    for (ll i = 2; i * i <= num; i++) {
        for (ll j = i * 2; primes[i] && j <= num; j += i) {
            primes[j] = false;
        }
    }

    return primes;
}

ll count_primes(ll num) {

    vb primes(num + 1);
    primes = prime_range_sieve(num);

    ll counter = 0;
    for (bool i : primes) counter += i;

    return counter;
}

vl get_primes(ll num) {

    vb primes_check(num + 1);
    primes_check = prime_range_sieve(num);

    vl primes;
    for (ll i = 2; i < sz(primes_check); i++) {
        if (primes_check[i]) primes.push_back(i);
    }

    return primes;
}
