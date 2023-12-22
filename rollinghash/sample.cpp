
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

    ll p = 29;
    ll size_x = x.size();
    ll size_y = y.size();

    ll m = 1e9 + 7;

    // Precompute powers of p = 29
    //precompute_pow(size);

    ll hash_x = 0;
    ll curr_pow = 1;
    for (ll i = size_x - 1; i >= 0; i--) {
        hash_x += (x[i] * curr_pow) % m;
        curr_pow = (curr_pow * p) % m;
    }
    cout << "HASH FOR X:\n" << hash_x << '\n';

    // size_y > size_x
    cout << "HASHES IN Y:\n";
    ll hash_y = 0;
    curr_pow = 1;
    for (int i = size_x - 1; i >= 0; i--) {
        hash_y += (y[i] * curr_pow) % m;
        curr_pow = (curr_pow * p) % m;
    }
    cout << hash_y << '\n';

    ll max_pow = curr_pow / p;
    for (int i = size_x; i < size_y; i++) {
        hash_y -= (y[i - size_x] * max_pow) % m;
        hash_y %= m;
        if (hash_y < 0) hash_y += m;
        hash_y *= p;
        hash_y %= m;
        hash_y += y[i];
        hash_y %= m;
        cout << hash_y << '\n';
    }

    return 0;

}
