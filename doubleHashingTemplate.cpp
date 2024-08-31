/*
* author: Saifur Rahman
*/
#include<bits/stdc++.h>
using namespace std;

#define read freopen("input.txt", "r", stdin)
#define write freopen("output.txt", "w", stdout)
#define MAX 100000
#define ll unsigned long long
#define base 263
#define base1 283
#define mod 1000000007
#define mod1 1000000009
#define fastio()                        \
    ios_base::sync_with_stdio(false);   \
    cin.tie(NULL);                      \
    cout.tie(0)

class Hash {
  string str;
  ll n;
  vector<ll> prefixHash, power, prefixHash1, power1;
  void computePrefixHash() {
    prefixHash[0] = str[0]+1;
    prefixHash1[0] = str[0]+1;
    power[0] = 1;
    power1[0] = 1;
    for(int i=1;i<n;i++) {
      prefixHash[i] = (prefixHash[i-1] * base + str[i] + 1)%mod;
      prefixHash1[i] = (prefixHash1[i-1] * base1 + str[i] + 1)%mod1;
      power[i] = (power[i-1] * base)%mod;
      power1[i] = (power1[i-1] * base1)%mod1;
    }
  }
public:
  Hash(string str) {
    this->str = str;
    n = str.size();
    prefixHash.resize(n);
    prefixHash1.resize(n);
    power.resize(n);
    power1.resize(n);
    computePrefixHash();
  }
  ll calculateHash(ll L, ll R) {
    if(L==0) return prefixHash[R];
    return (prefixHash[R] - ((prefixHash[L-1] * power[R-L+1])%mod) + mod)%mod;
  }
  ll calculateHash1(ll L, ll R) {
    if(L == 0) return prefixHash1[R];
    return (prefixHash1[R] - ((prefixHash1[L-1] * power1[R-L+1])%mod1)+mod1)%mod1;
  }
};

int main() {
  // read;
  // write;
  fastio();

  
  return 0;
} 
