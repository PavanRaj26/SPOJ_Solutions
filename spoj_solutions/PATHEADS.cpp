#include <bits/stdc++.h>

using namespace std;

int main() {

ios::sync_with_stdio(false);
    
        int i=0;
        int n;
        cin>>n;
        vector<int> count(1000001,0);
        vector< pair< int,int > > v(n);
        int x;
        for(i=0;i<n;i++) {
             
	          cin>>x;
	          v[i].first=x;
	          v[i].second=i;
	   }
	   map<int,int> m;    
        for(i=0;i<n;i++)
             count[v[i].first]++;
        sort(v.begin(),v.end());
        int noof=0;
	   
	   
	   for(i=0;i<n;i++)
	      m[v[i].first]=count[1];
	   m[1]=count[1]-1;
	   int j=1,k;
	   for(i=2;i<=1000000;i++) {
          
              if(count[i]>=1) {
              
                     m[i]=m[i]+count[i]-1; 
		           for(j=2,k=i*j;k<=1000000;) {
		           
				    if(count[k]>=1) {
				        
				        m[k]=m[k]+count[i];
				    }
				    j++;
				    k=i*j;
				 }
		    }
	            
	  }
	  vector<int> v2(n,0);
	  for(i=0;i<n;i++) {
	  
	       v2[v[i].second]=m[v[i].first];
	  
	  }
	  for(i=0;i<n;i++)
	     cout<<v2[i]<<endl;
	 
      return 0; 
  }

