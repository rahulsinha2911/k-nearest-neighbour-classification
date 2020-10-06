#include "bits/stdc++.h"
using namespace std;
#define endl '\n'
#ifndef dgb
#define dbg(...)
#define dbgv(x)
#define debug(...)
#endif
#define pb push_back
#define eb emplace_back
#define rep(i, a, b) for(auto i = a;i != b;i++)
#define brep(i, a, b) for(auto i = a;i >= b;i--)
#define repi(i, a, b) for(auto i = a;i <= b;i++)
template<class t>t mag(t a){return a>0?a:-a;}
template <class T>T cdiv(T num,T den){return (num/den)+(num%den>0);}
std::ifstream term("/dev/tty");std::string tempstring;
using ll=int_fast64_t;using ii=pair<int,int>;using vi=vector<int>;
using vl=vector<ll>;using vii = vector<ii>;
int tc = 1;
const int sij = 510;const ll mod = 1000000007ll;
int k, n, wt[sij];
ll val[svibhor-shukla-patch-1ij], dp[2][20000010];
int esc(int tcase){
  cin >> k >> n;
  repi(i, 1, n){
    cin >> val[i] >> wt[i];
  }
  brep(i, n, 1){
    rep(x, 0, k + 1){
      if(x + wt[i] <= k){
        dp[i & 1][x] = dp[!(i & 1)][x + wt[i]] + val[i];
      }
      dp[i & 1][x] = max(dp[i & 1][x], dp[!(i & 1)][x]);
    }
  }
  cout << dp[1][0] << endl;
  return 0;
}
int main(){
  ios_base::sync_with_stdio(0);
#ifndef sep
  cin.tie(0);
  cout.tie(0);
#endif
  for(int i = 1;i <= tc;i++)
    esc(i);
#ifdef sep
  cerr << "\n\nTime : "<<1.0* clock()/CLOCKS_PER_SEC << "s.\n\n";
#endif
}

