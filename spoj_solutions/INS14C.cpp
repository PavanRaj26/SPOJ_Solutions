#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx


using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+9)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
using namespace std;

int main() {

		int t;
		cin>>t;
		while(t--) {
				
				int n,k;
				cin>>n>>k;
				string s;
				cin>>s;
				int pos0=0,pos1=0;
				vector<int> counter(n,0);
				int i=0,j=0;
				i=0;
				while(i<n&&s[i]!='0')
				  i++;
				pos0=i;
				if(i==n) {
					rep(i,k) 
					  cout<<s[i];
					  cout<<endl;	
				}
				else {
					i=0;
					while(i<n&&s[i]!='1')
				  	i++;
					pos1=i;  
					if(i==n) {
						rep(i,k) 
					  	cout<<s[i];
					  	cout<<endl;	
					}
					else {
						rep(i,n-k) {
						
								if(i%2==0) {
									counter[pos1]=1; 
									int j=i;
									while(j<n&&(s[j]!='1'||counter[j]!=0)) {
										j++;
									}
									if(j==n) {
		
										j--;
										while(j>i&&(s[j]!='0'||counter[j]!=0)) {
											j--;
										}
											
									}
									pos1=j;
								}	
								else {
									counter[pos0]=1;
									int j=i;
									while(j<n&&(s[j]!='0'||counter[j]!=0)) {
										j++;
									}
									if(j==n) {

										j--;	
										while(j>i&&(s[j]!='1'||counter[j]!=0)) {
											j--;
										}
								
									}
									pos0=j;							
								}
						
						}
							rep(i,n)
					  		if(counter[i]!=1)
					    		 cout<<s[i];
					    	cout<<endl;	 
						}
					}
		}
		
		return 0;			
}