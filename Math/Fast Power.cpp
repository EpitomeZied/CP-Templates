int binpow(int a,int b, int m) {
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

// b power e in O(log(n))

ll Bin_Pow(ll b, ll e){
    ll power = 1;
    while(e){
        if(e & 1) power *= b;
        e >>= 1;
        b *= b;
    }
    return power;
}

//=========================================================
// b power e % mod in O(log(e))

ll Bin_Pow(ll b, ll e, ll mod){
    ll power = 1;
    while(e){
        if(e & 1) mul(power, b, mod);
        e >>= 1;
        mul(b, b, mod);
    }
    return power % mod;
}

//=========================================================

ll fastPower(ll a , ll b){
	if(b==0)
		return 1;
	ll res = fastPower(a,b/2);
	if(b%2 == 1)
		return ((res * res)%mod * a)%mod;
	return (res*res)%mod;
}
