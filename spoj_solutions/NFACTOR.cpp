#include<bits/stdc++.h>

using namespace std;
#define pb push_back
typedef long long ll;

const int N=1000010;
vector<vector<int> > T(11,vector<int>(N));
int ans[N+10];
int p[N+10];
int main() {

	int i,j;
	for(i=2;i<N;i++) p[i]=i;
	for(i=2;i<N;i++) {
		if(p[i]==i) {
			for(j=i+i;j<=N;j+=i) {
				if(p[j]==j) p[j]=i;
			}
		}
	}		
	for(i=2;i<N;i++) {
		int div=p[i];	
		int val=i;
		int cnt=1;
		int prev=div;
		int nw;

		while(val!=1) {
			while(val%div==0) {
				val/=div;
					
			}
			div=p[val];
			if(val!=1)cnt++;
		}
		ans[i]=cnt;			
	}
	for(i=0;i<=10;i++) {
		T[i][0]=0;
		for(j=1;j<N;j++) {
			T[i][j]=T[i][j-1]+(ans[j]==i?1:0);
		}
	}
	int t;
	cin>>t;
	while(t--) {
		 int a,b,n;
		 cin>>a>>b>>n;
		 cout<<T[n][b]-T[n][a-1]<<endl;
	}
	return 0; 			

}