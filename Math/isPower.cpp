
bool is_power(ll number, int base = 2){
    return (get_log(number, base) - (ll) get_log(number, base) <= EPS);
}