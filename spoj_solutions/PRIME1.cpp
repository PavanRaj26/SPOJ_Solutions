#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {

int t;
        cin>>t;
        while(t--) {
        	ll m,n;
        	cin>>m>>n;
        	ll arr[n-m+1];
        	ll i,j;
		for(i=0;i<n-m+1;i++) arr[i]=0;
        	for(i=2;i*i<=n;i++) {
        		
        		   for(j=max(i*i,(m+i-1)/i*i);j<=n;j+=i)  {
        		   	if(!arr[j-m]) arr[j-m]=1; 
        		   }
        			
        	}
        	if(m==1) arr[0]=1;
        	for(i=0;i<=n-m;i++)  if(arr[i]==0) cout<<i+m<<endl;	
        	cout<<endl;
        }         	
        return 0; 			
}