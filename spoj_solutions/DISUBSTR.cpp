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
const int N = 10005;
int gcd(int a,int b) {
    		
    if(a==0) return b;
    else return gcd(b%a,a);
}
typedef pair< pair<int,int> ,int > PII ;
int sto[40];
void compute() {
		sto[0] = 1;
		for (int i = 1; i < 31; i++) sto[i] =  2* sto[i - 1];
		
	}
vector<int> buildSuffix(string txt,int P[][1003],PII L[],int &step) {
		
	int n = txt.size();
	vector<int> sufarr(n,0);	
	step = 1;
	for (int i = 0; i < n; i++) {
			P[0][i] = txt[i];
		}	
	for (int i = 1; sto[i] < n; i++,step++) {
			for (int j = 0; j < n; j++) {
				
					L[j].ss = j;
					L[j].ff.ff = P[i - 1][j];
					L[j].ff.ss = (j + sto[i - 1] < n?P[i - 1][j + sto[i - 1]]:-1);
				}
			sort(L,L + n);
			for (int j = 0; j < n; j++) {
					P[i][L[j].ss] = ((j > 0 && L[j - 1].ff.ff == L[j].ff.ff and L[j - 1].ff.ss == L[j].ff.ss)?P[i][L[j - 1].ss]:j);
				}	
		}
	step--;
	for (int i = 0; i < n; i++) {
			sufarr[P[step][i]] = i;
		}		
		return sufarr;
}
int LCP(int i,int j,int P[][1003],int n,int step) {
		if (i == j) {
				return n - i + 1;
			}	
		int ret = 0;
		for (int x = step; x >=0 ; x--) {
				if (P[x][i] == P[x][j] && i + sto[x] <= n && j + sto[x] <= n) {
						ret = ret + sto[x];
						i = i + sto[x];
						j = j + sto[x];
					}
			}
		return ret;		
}
vector<int> kasai(string txt,vector<int> sufarr) {
		
		int n = txt.size();
		vector<int> lcp(n,0);
		vector<int> invSuf(n,0);
		for (int i = 0; i < n; i++) invSuf[sufarr[i]] = i;
		int k = 0;
		for (int i = 0; i < n; i++) {
				if (invSuf[i] == n - 1) {
						k = 0;
						continue;
					}
				int j = sufarr[invSuf[i] + 1];
				while (i + k < n && j + k < n && txt[i + k] == txt[j + k]) k++;
				lcp[invSuf[i]] = k;
				if (k > 0) k--;	
			}
		return lcp;	
	}
	
int main() {
    			   
    		   
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    	cout.tie(NULL);    	
    	compute();
    	int t;
    	cin >> t;
    	while (t--) {
			
			string s;
			cin >> s;
			int P[32][1003];
			PII L[1003];
			int n = s.size();
			int step;
			vector<int> sufarr = buildSuffix(s,P,L,step);
			vector<int> lcp = kasai(s,sufarr);
			int res = n - sufarr[0];
			for (int i = 1 ; i < n; i++) {
				res += (n - sufarr[i]) - lcp[i - 1];
			}
			cout << res << endl;	
		}
    	return 0;						
}
