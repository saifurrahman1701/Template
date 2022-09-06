/*
  Call init() before doing anything for gob's sake.
  Change query return type to ll or pii or piii depending on number of hashes.
  Vector is really slow.
  String ->abcde, base 10, a is 1
  hash array will be-> [1, 12, 123, 1234, 12345]
  hash value will be ->12345
  query(2,3)->34
  update will only work for hash value. Array will not be modified and will be inconsistent.
  update(2, 'e') -> new hash value is 12545
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INFI 1e18
#define pii pair<ll, ll>
#define piii pair<ll, pii>
#define endl "\n"

const ll MAX = 1e5+10;
const ll N = 1;

ll base[N], mod[N], power[N][MAX + 10];

void init() {
  if(N == 3) mod[2] = 1000004023, base[2] = 4729;
  if(N >= 2) mod[1] = 1000003999, base[1] = 4721; 
  mod[0] = 1000000861, base[0] = 3407;
  for(ll i = 0;i<N;i++) {
    power[i][0] = 1;
    for(ll j = 1;j<MAX;j++) {
      power[i][j] = (power[i][j-1] * base[i]) % mod[i];
    }
  }
}

struct HashDate {
  ll pre[N][MAX + 10];
  char str[MAX + 10];
  ll len;
  HashDate(string &s) {
    string str = s;
    len = str.length();
    for(ll i=0;i<N;i++) {
      pre[i][0] = str[0];
      for(ll j = 1;j<len;j++) {
        pre[i][j] = (pre[i][j-1] * base[i]) % mod[i];
        pre[i][j] = (pre[i][j] + str[j]) % mod[i];
      }
    }
  }

  inline ll query(ll st, ll ed) {
    ll ret[N];
    for(ll i=0;i<N;i++) {
      ll nw = pre[i][ed];
      if(st>0) {
        nw = ((nw - (pre[i][st-1] * power[i][ed-st+1]) % mod[i]) + mod[i]) % mod[i];
      } 
      ret[i] = nw;
    }
    return ret[0];
  }



};

int main() {
  ios_base:: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  init();

  string s = "abbaababbab";
  HashDate hd(s);

  cout << hd.query(0, s.size() - 1) << "\n";
  cout << hd.query(0, 3) << "\n";
  cout << hd.query(6, 9) << "\n";

  return 0;
}
