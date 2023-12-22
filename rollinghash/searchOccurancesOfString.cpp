#include <vector>
#include <iostream>

using namespace std;

// Prime number that will be used in hashing
const int M1 = 1e9 + 7;
const int M2 = 1e9 + 9;

// Base for the numbers
const int P = 128;

// Powers of P
vector<int> p_powers;

int polynomialHash(string s, int len) {
    int to_return = 0;

    for (int i = len; i > 0; i--) {
        to_return += (s[len - i] * p_powers[i - 1]) % M2;
    }

    return to_return % M2;
}

struct Hash {
    const int p1 = 31, m1 = 1e9 + 7;
    const int p2 = 37, m2 = 1e9 + 9;
    int hash1 = 0, hash2 = 0;
    Hash(const string& s) {
        compute_hash1(s);
        compute_hash2(s);
    }
 
    void compute_hash1(const string& s) {
        long p_pow = 1;
        for(char ch: s) {
            hash1 = (hash1 + (ch + 1 - 'a') * p_pow) % m1;
            p_pow = (p_pow * p1) % m1;
        }
    }
 
    void compute_hash2(const string& s) {
        long p_pow = 1;
        for(char ch: s) {
            hash2 = (hash2 + (ch + 1 - 'a') * p_pow) % m2;
            p_pow = (p_pow * p2) % m2;
        }
    }
 
    // For two strings to be equal
    // they must have same hash1 and hash2
    bool operator==(const Hash& other) {
        return (hash1 == other.hash1 && hash2 == other.hash2);
    }
};

int main() {

   string s1, s2; cin >> s1 >> s2;
   int len = s1.size();

   int curr_power = 1;
   for (int i = 0; i < len; i++) {
        p_powers.push_back(curr_power % M2);
        curr_power *= P;
   }

   int s1_hash = polynomialHash(s1, len);

   // Rolling hash on s2
   int s2_hash = polynomialHash(s2, len);

   string str2_curr;
   for (int i = 0; i < len; i++) str2_curr += s2[i];

   int i = 0;
   int counter = 0;


   while(len + i < s2.size()) {

   }

   cout << counter;
   return 0;
}
