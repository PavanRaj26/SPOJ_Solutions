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
const int N = 305;
int gcd(int a,int b) {
    		
    if(a==0) return b;
    else return gcd(b%a,a);
}
double ext = 1.23343747814;
typedef vector< vector<char> > matrix1;
typedef vector< vector<ll> > matrix;
matrix T(4,vector<ll>(4,0));
matrix multiply(matrix A,matrix B) {
		matrix C(4,vector<ll>(4,0));
		for (int i = 1; i <= 2; i++) {
			for (int j = 1; j <= 2; j++) {
					for (int k = 1; k <= 2; k++) {
						C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % M;
					}
				}
			}
		return C;	
	}
matrix power(matrix A,int n) {
				
		if (n == 1) return A;
		if (n % 2) 
			return multiply(A,power(A,n - 1));
		matrix X = power(A,n / 2);
		return multiply(X,X);
	}
double cal(pair<int,int> a,pair<int,int> b) {
		
		if (a.ff != b.ff) {
				return (a.ss * 1.0 - b.ss * 1.0) / (a.ff*1.0 - b.ff * 1.0);
			}	
		return inf*1.0;	
	}	
int main() {
    			   
    		   
    	ios_base::sync_with_stdio(false);	
    	cin.tie(NULL);
    	cout.tie(NULL);    	
    	int n;
    	cin >> n;
    	while (n) {
			pair<int,int> a[N];
			map<double,int> m;
			for (int i = 1; i <= n; i++) {
				cin >> a[i].ff;
				cin >> a[i].ss;
			}
			for (int i = 1; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) {
						double val = cal(a[i],a[j]);
						m[val]++;
					}
			}
			cout << m.size() << endl;		
			
			cin >> n;
		}
    	return 0;								
}
