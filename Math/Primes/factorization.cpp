vl prime_factorization(ll num) {

    vl factors;

    if (num < 2) return factors;

    while (!(num % 2)) {
        factors.push_back(2);
        num /= 2;
    }

    for (ll i = 3; i * i <= num; i += 2) {
        while (!(num % i)) {
            factors.push_back(i);
            num /= i;
        }
    }

    if (num > 1) factors.push_back(num);

    return factors;
}
