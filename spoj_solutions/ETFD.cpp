#include<bits/stdc++.h>

using namespace std;
typedef vector< vector<int > > matrix;
const int N=1000010;
int phi[N],p[N],depth[N];
matrix T(21,vector<int>(N,0));
int main() {

	int i,j;
	for(i=1;i<N;i++)
	   p[i]=i;
        for(i=2;i<N;i++)  {
        	if(p[i]==i) {
        		for(j=i+i;j<N;j+=i) {
        			if(p[j]==j) p[j]=i;
        		}
        	}
        }
        phi[1]=1;
        for(i=2;i<N;i++) {
        	int rem=i;
        	int divisor=p[i];
        	int exp=1;
        	while(rem%divisor==0) {
        		rem/=divisor;
        		exp*=divisor;
        	}
        	phi[i]=phi[rem]*(exp-exp/divisor);
        }
        depth[1]=0;
        for(i=2;i<N;i++) {
        
        	depth[i]=depth[phi[i]]+1;
        }
        int t;
        for(i=0;i<21;i++) {
        	T[i][0]=0;
        	for(j=1;j<N;j++) {
        		T[i][j]=T[i][j-1]+(depth[j]==i?1:0);
        	}
        }
       cin>>t;
        
        while(t--) {
        	int m,n,k;
        	cin>>m>>n>>k;
        	int cnt=0;
		cout<<T[k][n]-T[k][m-1]<<endl;        	
        }
           
	return 0; 			
}