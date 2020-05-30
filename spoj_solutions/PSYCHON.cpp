#include<bits/stdc++.h>


using namespace std;
typedef long long ll;

ll gcd(ll a,ll b) {
	if(a==0) return b;
	return gcd(b%a,a);
}
const int N=10000002;
int v[N];
vector<vector<int> > kn(N,vector<int>(2));
int main() {

	int i,j;
	for(i=2;i<N;i++) v[i]=i;
        for(i=2;i*i<N;i++) 
            if(v[i]==i)
               for(j=i*i;j<N;j+=i) 
                  if(v[j]==j) v[j]=i;
        
        
        //for(i=2;i<N;i++)if(v[i]==0) p.pb(i);
	kn[1][0]=0;kn[1][0]=0;
	for(i=2;i<N;i++) {
	         int rem=i;
	         int div=v[i];
	         int exp=0;
	         while(rem%div==0) {
	         	rem/=div;
	         	exp++;
	         }
		 kn[i][exp&1]=kn[i][exp&1]+1;
	}        
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);
		if(kn[n][0]>kn[n][1]) {
			printf("Psycho Number\n");

		}
		else 
		printf("Ordinary Number\n");
	}

        return 0; 			
}
