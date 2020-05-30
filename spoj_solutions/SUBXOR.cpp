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
#define IS 32
struct Node {
	Node *ch[2];
	int cnt;
};
typedef Node *pNode;
pNode root;
int a[111000];
pNode alloc() {
		pNode p = new Node();
		p->ch[0] = p->ch[1] = NULL;
		p->cnt = 0;
		return p;
	}
void add(const int x) {
		
	pNode at = root;
	for (int b = 19; b >= 0; b--) {
			const int nx = (x >> b & 1);
			if (!at->ch[nx]) 
				at->ch[nx] = alloc();
			at->cnt++;
			at = at->ch[nx];					
				
		}	
	at->cnt++;	
}	
int go(const int x,const int k) {
		pNode at = root;
		int res = 0;
		for (int b = 19; b >= 0 && at; b--) {
				if (k >> b & 1) {
						const int need = x >> b & 1;
						res +=  (at->ch[need]?at->ch[need]->cnt:0);
					}
				at = at->ch[(k >> b & 1) ^ (x >> b & 1)];	
			}
		return res;	
	}
int main() {
    			   
    		   
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    	cout.tie(NULL);     	
    	int t;
    	cin >> t;
    	while (t--) {
    	int n,k;
    	cin >> n >> k;
    	root = alloc();
    	add(0);
    	ll res = 0;
    	int pre_xor = 0;
    	fu(i,1,n) {
				cin >> a[i];		
			}    			
		fu(i,1,n) {
				pre_xor ^= a[i];
				res += go(pre_xor,k);
				add(pre_xor);
			}	
		cout << res << endl;	
	}
    	return 0;						
}
