#include<bits/stdc++.h>

using namespace std;

typedef long long int ii;
ii Money(ii x,vector<pair< ii,ii> > &v,int n);
ii addOvf(ii a,ii b) ;
int main() {

          int t;
          cin>>t;
          while(t--) {
          
		         int n,i;
		         scanf("%d",&n);
		         ii m;
		         ii x,y;
		         scanf("%lld",&m);
		         vector< pair< ii,ii > > v(n);
		         for(i=0;i<n;i++) {
		               
		               scanf("%lld%lld",&x,&y);
		               v[i]=make_pair(x,y);
		               
			    }
			    sort(v.begin(),v.end());
			    ii min1=v[0].first;
			    ii hi=min1+m/(v[0].second);
			    ii lo=0;
			    ii tmp=0;
			    while(lo<hi) {
			          
			          x=lo+(hi-lo+1)/2;
			          tmp=Money(x,v,n);
			          if(tmp>m||(tmp==-1&&hi>1)) 
			                hi=x-1;
			          else
			                lo=x;
			    }
			    
			    printf("%lld\n",lo);
		}
          return 0;
}
ii addOvf(ii a,ii b) {

     ii *result=(ii *)malloc(sizeof(ii));
     *result= a * b;
     if(a > 0 && b < 0 &&*result < 0)
        return -1;
     if(a < 0 && b < 0 &&*result < 0)
        return -1;
     return *result;   
        
}
ii Money(ii x,vector<pair< ii,ii> > &v,int n) {

     ii sum=0;
     int i;
     ii *result=(ii *)malloc(sizeof(ii));
     ii tmp=0;
     for(i=0;i<n;i++) {
         
           if(v[i].first>=x)
             continue;
           tmp=addOvf(x-v[i].first,v[i].second);             
           if(tmp==-1)
           return -1;
           *result=sum+tmp;
           if(*result<0)
              return -1;
           sum=*result;   
	}
	return sum;
}
