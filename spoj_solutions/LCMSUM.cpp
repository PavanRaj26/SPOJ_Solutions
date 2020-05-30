#include<bits/stdc++.h>
#define INF 1000000000

using namespace std;
typedef long long ll;

const int N=1000010;
ll p[N],phi[N];
ll res[N];
int main() {

	ll i,j;
	for(i=1;i<N;i++)
	    p[i]=i;
	for(ll i=2;i*i<=N;i++) {
		if(p[i]==i)
		   for(j=i+i;j<N;j+=i)
		       if(p[j]==j) p[j]=i;
	}
	phi[1]=1;
	
	for(i=2;i<N;i++) {
	        ll rem=i;
	        ll divisor=p[i];
	        ll exp=1;
	        while(rem%divisor==0) {
	        	rem/=divisor;
	        	exp*=divisor;
	        }
		phi[i]=phi[rem]*(exp-exp/divisor);
	}
	for(i=1;i<N;i++) {
	     for(j=i;j<N;j+=i)	
		res[j]+=(phi[i]*i);	
	}                      
	int t;
	scanf("%d",&t);
	while(t--) {
		ll n;
		scanf("%lld",&n);
		ll ans=res[n]+1;
		ans*=n;
		ans/=2;
		printf("%lld\n",ans);
	}
	return 0; 			
}