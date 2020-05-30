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
const int N = 1005;
int gcd(int a,int b) {
    		
    if(a==0) return b;
    else return gcd(b%a,a);
}
typedef vector< vector<char> > matrix1;
typedef vector< vector<int> > matrix;
int main() {
    			   
    		   
    	ios_base::sync_with_stdio(false);	
    	cin.tie(NULL);
    	cout.tie(NULL);    	
    	int t;
    	cin >> t;
    	while (t--) {
		 int m, n;
		cin >> m >> n;
		int x = 0, y = 0;
		int a[N];
		int b[N];
		fu(i,1,m - 1) cin >> a[i];
		fu(i,1,n - 1) cin >> b[i];
		sort(a + 1, a + m,greater<int>());
		sort(b + 1, b + n,greater<int>());
		int i = 1,j = 1;
		int res = 0;
		while (i <= m - 1 && j <= n - 1) {
			if (a[i] >= b[j]) {
					res += a[i] * (y + 1);
					x++;
					i++;
				}	
			else {
					res += b[j] * (x + 1);
					y++;
					j++;
				}	
		}
		while (i <= m - 1) {
				res += a[i] * (y + 1);
				x++;
				i++;
			}		
		while (j <= n - 1) {
				res += b[j] * (x + 1);
				y++;
				j++;
			}	
		cout << res << endl;
	}
		return 0;								
}
