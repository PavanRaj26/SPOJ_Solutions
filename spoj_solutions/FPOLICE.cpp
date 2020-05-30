#include<bits/stdc++.h>

using namespace std;

typedef vector< vector<long int > > matrix;

int main() {
  
  int t;
  cin>>t;
  while(t--) {
       int n,time;
       int l,i,j,k;
       long int q,x;
       cin>>n;
       cin>>time;
       matrix T1(n+2,vector<long int>(n+2,0));
       matrix T2(n+2,vector<long int>(n+2,0));
       for(i=1;i<=n;i++)
         for(j=1;j<=n;j++) {
            cin>>x;
            T2[i][j]=x;
	    }
       for(i=1;i<=n;i++)
         for(j=1;j<=n;j++) {
            cin>>x;
            T1[i][j]=x;
	    }
	  for(k=1;k<=n;k++) {

           for(i=1;i<=n;i++) {
            
              for(j=1;j<=n;j++) {
              	  q=T1[i][k]+T1[k][j];
                 if(q<T1[i][j]) {
                     T1[i][j]=q;
                     T2[i][j]=T2[i][k]+T2[k][j];
			  }
		    }
		 }
       }
       if(T2[1][n]<=time)
       cout<<T1[1][n]<<" "<<T2[1][n]<<endl;
       else
       cout<<"-1"<<endl;
  }
  return 0;

}