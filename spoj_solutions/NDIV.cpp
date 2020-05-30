#include<bits/stdc++.h>

using namespace std;
#define pb push_back
const int N=31678;
int p[N];
int main() {

        vector<int> primes;
        int i,j;
        for(i=1;i<N;i++)
           p[i]=i;
        for(i=2;i<N;i++)
           if(p[i]=i)
                for(j=i+i;j<=N;j+=i)
                    if(p[j]==j) p[j]=i;
        for(i=2;i<=N;i++)
	    if(p[i]==i) primes.pb(i);
	int a,b,n;
	cin>>a>>b>>n;
	vector<vector<int> > v(b-a+1);
	for(i=0;i<primes.size();i++) {
		    int first=a;
		    if(first%primes[i]==0) v[0].pb(primes[i]);
		    first=first+primes[i]-first%primes[i];
		    if(first>b) continue;
		    while(first<=b) {
		    	v[first-a].pb(primes[i]);
		    	first=first+primes[i];	
		    }	    	
		    	
	}
	vector<int>::iterator it;
	vector<int> ans(b-a+1);
	int cnt=0;
	
	for(i=0;i<=b-a;i++) {
		
		int val=i+a;
		 cnt=1;
			 
		for(it=v[i].begin();it!=v[i].end();it++) {
		          int exp=0;
		          int div=(*it);
		          while(val%div==0) {
		          	val/=div;
		          	exp++;
		          }
		          cnt=cnt*(exp+1);		
		}
		if(val!=1) cnt=cnt*2;
		ans[i]=cnt;
	}
	cnt=0;
	for(i=0;i<=b-a;i++)
	   if(ans[i]==n)
	      cnt++;
	cout<<cnt<<endl;
	return 0; 			
}