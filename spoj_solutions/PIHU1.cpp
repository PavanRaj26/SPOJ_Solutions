#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long int ii;
int main()
{
     int t;
	scanf("%d",&t);
	while(t--){
             
               int i,n;
               scanf("%d",&n);
               ii x;
               vector<ii> v(n,0);
			for(i=0;i<n;i++) {
			     scanf("%llu",&x);
			     v[i]=x;
		     }
		     ii p;
			scanf("%llu",&p);
		     sort(v.begin(),v.end());
		     int flag=0;
		     int j=0;
		     map < ii, pair<int,int > > m;
		     for(i=0;i<n;i++) {
		        
		          for(j=i+1;j<n;j++) {
		                 
		                 m[v[i]+v[j]]=make_pair(i,j);
		      	   }
				
			}
		     map < ii, pair<int,int > >::iterator it;
			for(i=0;i<n;i++) {
			        
			        it=m.find(p-v[i]);
			        if(it!=m.end()&&it->second.first!=i&&it->second.second!=i) {
			            printf("YES\n");
			            flag=1;
			            break;
				   }
		    }
               if(flag!=1)	  
		       printf("NO\n");    
	}
	return 0;
}
