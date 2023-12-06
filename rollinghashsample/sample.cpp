#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#define ll long long
vector<ll> pow;

void precompute_pow(int max) {
    ll curr_pow = 1;
    while(max--) {
        pow.push_back(curr_pow);
        curr_pow *= curr_pow;
    }
}

int main() {

    string x, y;
    cin >> x >> y;

    ll p = 137;
    ll size_x = x.size();
    ll size_y = y.size();

    ll m = 1e9 + 7;
    ll m_ = 1e9 + 9;

    // Precompute powers of p = 29
    //precompute_pow(size);

    ll ans = 0;

    ll hash_x_1 = 0;
    ll curr_pow = 1;
    for (ll i = size_x - 1; i >= 0; i--) {
        hash_x_1 += (x[i] * curr_pow) % m;
        if (i != 0) curr_pow = (curr_pow * p) % m;
        hash_x_1 %= m;
    }
    cout << "HASH FOR X:\n" << hash_x_1 << '\n'; 

    // size_y > size_x
    ll hash_y_1 = 0;
    curr_pow = 1;
    cout << "HASHES FOR Y:\n";
    for (int i = size_x - 1; i >= 0; i--) {
        hash_y_1 += (y[i] * curr_pow) % m;
        if (i != 0) curr_pow = (curr_pow * p) % m;
        hash_y_1 %= m;
    }
    cout << hash_y_1 << '\n';
    if (hash_y_1 == hash_x_1) ans++;

    ll max_pow = curr_pow;
    for (int i = size_x; i < size_y; i++) {
        hash_y_1 -= (y[i - size_x] * max_pow) % m;
        if (hash_y_1 < 0) hash_y_1 += m;
        hash_y_1 *= p;
        hash_y_1 %= m;
        hash_y_1 += y[i];
        hash_y_1 %= m;
        cout << hash_y_1 << '\n';
        if (hash_x_1 == hash_y_1) ans++;
    }
    cout << ans;

    return 0;
}
