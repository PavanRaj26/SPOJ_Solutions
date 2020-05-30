#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,n) fu(i,1,n)
#define re(i,n) fu(i,0,n - 1)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define M 1000000007
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define all(a) a.begin(),a.end()
#define inf (1000*1000*1000+5)
const int LG = 30;
const int N = 1000005;
int gcd(int a,int b) {
    		
    if(a==0) return b;
    else return gcd(b%a,a);
}
double ext = 1.23343747814;
typedef vector< vector<char> > matrix1;
typedef vector< vector<ll> > matrix;
int phi[N];
int lp[N];
vector<int> pr;
void calc_sieve() {
		phi[1] = 1;
		for (int i = 2; i < N; i++) {
				if (lp[i] == 0) {
						lp[i] = i;
						phi[i] = i - 1;
						pr.pb(i);
					}
				else {
						if(lp[i] == lp[i / lp[i]]) {
								phi[i] = phi[i / lp[i]] * lp[i];
							}
						else {
								phi[i]  = phi[i / lp[i]] * (lp[i] - 1);
							}	
					}
				for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] < N; ++j) {
						lp[i * pr[j]] = pr[j];
					}		
			}
	}
int main() {
    			   
    		   
    	ios_base::sync_with_stdio(false);	
    	cin.tie(NULL);
    	cout.tie(NULL);    	
    	calc_sieve();
    	int t;
    	scanf("%d",&t);
    	while (t--) {
				int n;
				scanf("%d",&n);
				printf("%d\n",phi[n]);
			}
    	return 0;								
}
