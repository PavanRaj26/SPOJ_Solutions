#include<bits/stdc++.h>

using namespace std;
#define pb push_back
typedef long long ll;
const int N=1000010;
int phi[N],p[N],depth[N];

int main() {

	vector<ll> primes;
	int i,j,n;
	for(i=1;i<N;i++)
	    p[i]=i;
	for(i=2;i<N;i++)
	      if(p[i]==i)
	          for(j=i+i;j<=N;j+=i)
	             if(p[j]==j) p[j]=i;
	for(i=2;i<100;i++)  {
	      if(p[i]==i) {primes.pb(i);}
	}
	cin>>n;
	ll k=1;
	for(i=0;k<n;i++) {
	      k=k*primes[i];
	}
	k=k/primes[i-1];
	cout<<k<<endl;
	return 0; 			
}