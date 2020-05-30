#include<bits/stdc++.h>

using namespace std;

#define FU(i,a,b) for(int i=a;i<=b;i++)
#define REP(i,n) for(int i = 0; i < int(n); ++i)
#define FD(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vl vector< ll >
#define ss second
#define ff first
#define M 1000000007LL
#define pii pair<int,int >
#define pll pair< ll,ll >
#define SZ(x) ((int)(x).size())
#define all(a) a.begin(),a.end()
#define inf (1000*1000*1000+5)
#define PI   3.14159265358979323846
typedef  long long ll;
int gcd(int a,int b) {
				
	if(a==0) return b;
	else return gcd(b%a,a);
}
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % M;
			ans = (ans * a) % M, --b;
		} return ans;
}
template<typename T>
// m must be positive
static T mod(T a, T m)
{
		a %= m;
		if (a < 0)
			a += m;
		return a;
}

	// a must be relatively prime to m
template<typename T>
static T inverse(T a, T m)
{
	a = mod(a, m);
	if (a == 1)
		return a;
		return mod((1 - inverse(m, a) * m) / a, m);
}
const int MX = 1000005;
ll dp[20][2];
ll sum[20][2];
vector<int> num;
ll l,r;
ll call(int pos,int f) {
        if(pos == num.size()) {
            sum[pos][f] = 0;
            return dp[pos][f] = 1;
        }
        if (dp[pos][f] != -1) return dp[pos][f];
        int lt = 9;
        ll res = 0,amt = 0;
        if (f == 0) lt = num[pos];
        for (int i = 0; i <= lt; i++) {
            int nf = f;
            if (f == 0 && i < lt) nf = 1;
            amt += call(pos + 1,nf);
            res = res + i * dp[pos + 1][nf] + sum[pos + 1][nf];
        }
        dp[pos][f] = amt;
        sum[pos][f] = res;
        return amt;
}
ll solve(ll b) {
        num.clear();
        while (b) {
            num.pb(b % 10);
            b /= 10;
        }
        reverse(num.begin(),num.end());
        memset(dp,-1,sizeof(dp));
        memset(sum,0,sizeof(sum));
        if ((int)num.size() > 0) call(0,0);
        return sum[0][0];
}
int main() {

    #ifndef ONLINE_JUDGE 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);	
    cin.tie(NULL);    	
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        cin >>  l >> r;
        cout<< solve(r) - solve(l - 1) << endl;
    }
    return 0;
}