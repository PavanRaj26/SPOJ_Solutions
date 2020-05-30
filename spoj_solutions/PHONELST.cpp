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
const int N = 200005;
int gcd(int a,int b) {
    		
    if(a==0) return b;
    else return gcd(b%a,a);
}
#define INT_SIZE 32
struct TrieNode {
		int val;
		TrieNode *let[26];
		TrieNode *arr[10];
	};
typedef TrieNode TN;
int f;
TN *newNode() {
		TN *tmp = new TN;
		tmp->val = -1;
		for (int i = 0; i < 26; i++) tmp->let[i] = NULL;
		for (int i = 0; i < 10; i++) tmp->arr[i] = NULL;
		return tmp;
	}
void insert(TN *root,string s) {
			
		int sz = s.size();
		TN *tmp = root;
		for (int i = 0; i < sz; i++) {
				
				char c = s[i];
				int val = c - '0';
				if (tmp->arr[val] == NULL) {
						tmp->arr[val] = newNode();	
					}
				if (tmp->val == -1) tmp->val = 0;
				if (tmp->val == 1) f = 1;	
				tmp = tmp->arr[val];	
						
			}			
		if (tmp->val == 0 || tmp->val == 1) {
				 f = 1;				 
			}	
		tmp->val = 1;	
				
	}	
int main() {
    			   
    		   
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    	cout.tie(NULL); 
    	
    	int t;
    	cin >> t;
    	while (t--) {
				int n;
				cin >> n;
				TN *root = newNode();
				f = 0;
				for (int i = 1; i <= n; i++) {
						string s;
						cin >> s;
						insert(root,s);						
					}
				if (!f) {
						cout << "YES" << endl;
					}	
				else
						cout << "NO" << endl;
				free(root);		
			}
    	return 0;						
}
