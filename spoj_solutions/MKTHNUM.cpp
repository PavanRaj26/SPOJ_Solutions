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
const int N = 100005;
int gcd(int a,int b) {
    		
    if(a==0) return b;
    else return gcd(b%a,a);
}
vector <int> tree[2060964];
vector< pair<int,int > > a;
int n, q,mem[N];
void build(int node,int st,int end) {
			
		if (st == end) {
				tree[node].pb(a[st].ss);
				return ;
			}	
		int mid = (st + end) / 2;
		build(2 * node , st , mid);
		build(2 * node + 1, mid + 1, end);
		merge(all(tree[2 * node]),all(tree[2 *node + 1]),back_inserter(tree[node]));	
}
int query(int node,int st,int end,int l,int r,int k) {
		
		
		if (st == end) {
				return tree[node][0];
			}
		int mid = (st + end) / 2;
		int ult = (upper_bound(all(tree[2*node]),r) - tree[2*node].begin());
		int llt	= (lower_bound(all(tree[2*node]),l) - tree[2*node].begin());
		int diff = ult - llt;
		if (diff >= k) {
				return query(2*node,st,mid,l,r,k);
			}
		else {
				return query(2*node+1,mid + 1,end,l,r,k - diff);
			}	
}
int main() {
    			   
    		   
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    	cout.tie(NULL);    	
		int n, q;
		cin >> n >> q;
		a.pb(mp(-inf,0));
		fu(i,1,n) {
				cin >> mem[i];
				a.pb(mp(mem[i],i));				
			}
		sort(all(a));
		build(1,1,n);
		while (q--) {			
				int l, r, k;
				cin >> l >> r >> k;
				cout << mem[query(1,1,n,l,r,k)] << endl;
			}	
		return 0;						
}
