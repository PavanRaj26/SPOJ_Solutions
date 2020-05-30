#include<bits/stdc++.h>

using namespace std;
const int N=1e8+10;
int LIM=10000;
int p[N>>6];
#define pb push_back
#define ifc(x) (p[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (p[x>>6]|=(1<<((x>>1)&31)))
typedef long long ll;

int main() {

        int i,j,k;                        
	for(i=3;i<LIM;i+=2)
	   if(!(ifc(i))) 
	      for(j=i*i,k=i<<1;j<=N;j+=k)
	         isc(j);
	vector<int> v;
	v.pb(2);
	
	for(i=3;i<N;i+=2)  
	    if(!(ifc(i))) v.pb(i);
	int x;
		cin>>x;
	while(x) {
	
		
		vector<int>::iterator it;
		it=upper_bound(v.begin(),v.end(),x);
		int num=distance(v.begin(),it);
		//if(!(ifc(x))) num=num+1;
		double ans=(num*1.0-(1.0*x)/log(x))/(1.0*num);
		if(ans<0) ans=0.0-ans;
		ans=ans*(100.0);
		cout<<setprecision(1)<<fixed<<ans<<endl;
		cin>>x;
	}
	return 0; 			

}
