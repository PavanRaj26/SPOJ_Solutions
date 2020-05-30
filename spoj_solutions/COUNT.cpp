#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ii;
typedef vector< vector<ii > > matrix;
int main() {
          
          
          int t;
          matrix T(5002,vector<ii>(5002,0));
	             int i=0,j=0;
	             T[0][0]=1;
	             for(i=1;i<=5000;i++) {
	         
	                  for(j=1;j<=i;j++) {
	               
	                      T[i][j]=(T[i-1][j-1]+T[i-j][j])%1988;
	                      
		             }
	           
		        }
		  
                 int n;
		        int k;
	             cin>>n;
		        cin>>k;

		 while(n!=0&&k!=0) {
		     
		        cout<<T[n][k]<<endl;
		        cin>>n;
		        cin>>k;
		}
          return 0;
}