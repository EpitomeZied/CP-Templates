vl get_divisors(ll num) {

    vl divisors;

    ll i;
    for (i = 1; i * i < num; i++) {
        if (!(num % i)) {
            divisors.push_back(i);
            divisors.push_back(num / i);
        }
    }
    if((i * i) == num) divisors.push_back(i);

    return divisors;
}

ll count_divisors(ll num) {

    ll i, counter = 0;
    for (i = 1; i * i < num; i++) {
        if (!(num % i)) counter += 2;
    }
    if ((i * i) == num) counter++;

    return counter;
}

// get Summation of divisors for n

ll sum_of_divisors(ll n){
    ll sum_divisors = 0;
    for(int i = 1; i < sqrt(n); i++)
        if(n % i == 0) sum_divisors += ((n / i) + i);
    ll sq = sqrt(n);
    return sum_divisors + (sq * sq == n ? sq : 0);
}

// sum of divisor of number in range [1 ... n]
ll divisorSum(ll num){
    ll sum = 0;
    for (ll i = 1; i <= sqrt(num); i++) {
        ll t1 = i * (num / i - i + 1);
        ll t2 = (((num / i) * (num / i + 1)) / 2) - ((i * (i + 1)) / 2);
        sum += t1 + t2;
    }
    return sum;
}