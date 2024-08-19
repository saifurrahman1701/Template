/*
* author: Saifur Rahman
*/

#include<bits/stdc++.h>
using namespace std;

#define read freopen("input.txt", "r", stdin)
#define write freopen("output.txt", "w", stdout)
#define MOD 1000000007
#define MOD1 1000000051
#define base 27
#define MAX 100000
#define ll long long

/* Double hashing */

class Hash {
    string str;
    vector<ll> prefixHashValue, prefixHashValue1, po, po1;
    ll n;
    void prefixHash() {
      prefixHashValue[0] = (str[0] - 'a' + 1);
      prefixHashValue1[0] = (str[0] - 'a' + 1);
      po[0] = 1;
      po1[0] = 1;
      for(ll i=1;i<n;i++) {
        prefixHashValue[i] = (((prefixHashValue[i-1] * base) % MOD) + (str[i] - 'a'+1)) % MOD;
        po[i] = (po[i-1] * base) % MOD;

        prefixHashValue1[i] = (((prefixHashValue1[i-1] * base) % MOD1) + (str[i] - 'a'+1)) % MOD1;
        po1[i] = (po1[i-1] * base) % MOD1;
      }
    }
  public:
    Hash(string str) {
      this->str = str;
      n = str.size();
      prefixHashValue.resize(MAX + 5);
      po.resize(MAX + 5);
      prefixHashValue1.resize(MAX + 5);
      po1.resize(MAX + 5);
      prefixHash();
    }
    ll calculateSubstringHash(ll L, ll R) {
      if(L == 0) return prefixHashValue[R];
      ll hashValue = (prefixHashValue[R] - ((prefixHashValue[L-1] * po[R-L+1])%MOD) + MOD) % MOD;
      return hashValue;
    }
    ll calculateSubstringHash1(ll L, ll R) {
      if(L == 0) return prefixHashValue1[R];
      ll hashValue = (prefixHashValue1[R] - ((prefixHashValue1[L-1] * po1[R-L+1])%MOD1) + MOD1) % MOD1;
      return hashValue;
    }
};

int main() {
  read;
  write;

  return 0;
}
