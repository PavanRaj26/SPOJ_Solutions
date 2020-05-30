#include<bits/stdc++.h>

using namespace std;

typedef  long long int ii;
int main() {


           int n;
		 scanf("%d",&n);
		 while(n) {
	          
	             int i;
	             ii x;
		        vector<ii> v(n+1,0);
		        
		        for(i=1;i<=n;i++) {
                        
		                scanf("%lld",&x);
				    	 v[i]=x;	        
			   }
		        stack<int> S;
		        vector< pair<int,int> > v1(n+1);
		        int k=0;
			   for(i=1;i<=n;i++) {
			        k=i;
			            while(!S.empty()&&v[S.top()]>=v[i]) {
					      S.pop();
			           }
			            if(S.empty()){
					      v1[i].first=0;
					  }
			            else {
					      v1[i].first=S.top();
					  }
					  S.push(i);    
			   }
			   while(!S.empty())
			      S.pop();
			   
			   for(i=n;i>=1;i--) {
			        k=i;
			            while(!S.empty()&&v[S.top()]>=v[i]) {
						 S.pop();
			            }
			            if(S.empty()) 
					      v1[i].second=n+1;
			            else {
					      v1[i].second=S.top();
					  }
					 S.push(i);    
			   }
			   ii tmp=0;
			   ii max1=-1;
			   for(i=1;i<=n;i++) {
			            
			           tmp=(v1[i].second-v1[i].first-1)*v[i];
			           if(tmp>max1)
			               max1=tmp;
			   }
			   printf("%lld\n",max1);
		      scanf("%d",&n);
		 }
           return 0;
}
