#include<bits/stdc++.h>

using namespace std;

typedef long long int ii;
typedef vector< vector< ii > > matrix;
#define min(a,b) (a>b?b:a)
#define pos(a,b) (a>b?a-b:b-a)
int main() {
        
        
        int n,m;
	   cin>>n;
	   cin>>m;
	   vector< ii> v1,v2;
	   v1.push_back(0);
	   v2.push_back(0);
	   int i,j,x;
        for(i=0;i<n;i++)  {
           cin>>x;
           v1.push_back(x);
	   }
        for(i=0;i<m;i++)  {
           cin>>x;
           v2.push_back(x);
	   }
	   sort(v1.begin(),v1.end());
	   sort(v2.begin(),v2.end());
        matrix T(n+2,vector<ii>(m+2,0));
	   for(i=1;i<=n;i++) {
           
		 T[i][i]=T[i-1][i-1]+pos(v1[i],v2[i]);
		 for(j=i+1;j<=m;j++) {
	         
	          T[i][j]=min(T[i][j-1],T[i-1][j-1]+pos(v1[i],v2[j]));
			 
	          
		 }
        }
        cout<<T[n][m]<<endl;
	   return 0;

}