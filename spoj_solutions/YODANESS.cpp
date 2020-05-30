#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int getSum(int tree[],int ind) {
	int sum=0;
	while(ind>0) {
		sum+=tree[ind];
		ind-=ind &(-ind);
	}	
	return sum;
}
void updateTree(int tree[],int maxElem,int ind,int val) { 
	 
	 while(ind<=maxElem) {
	 	tree[ind]+=val;
	 	ind+=ind&(-ind);
	 }
}
int main() {

  	 int t;
   	 cin>>t;
	 while(t--) {	
		int n;
		cin>>n;
		map<string,int> m;
		int i;
		for(i=0;i<n;i++) {
			string s;
			cin>>s;
			m[s]=i+1;
		}
		vector<string> v(n);
		for(i=0;i<n;i++) {
		         cin>>v[i];
		}	     
		int ans=0;
		int tree[n+1];
		for(i=0;i<=n;i++)
		   tree[i]=0;
		for(i=n-1;i>=0;i--) {
		
		        ans+=getSum(tree,m[v[i]]-1);
		        updateTree(tree,n,m[v[i]],1);
		}	
		cout<<ans<<endl;
	}
	return 0; 			
}
