ll gcd(ll a, ll b, ll& x, ll& y) {
    x = 1, y = 0;
    ll x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}
/* Si se desea encontrar un inverso multiplicativo:
  ll a = MOD, b=2, x=1,y=1;
  ll gd = gcd(a,b,x,y);
  ll inverso_de_b = (y+MOD)%MOD;
*/