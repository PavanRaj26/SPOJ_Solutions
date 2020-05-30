#include<bits/stdc++.h>
using namespace std;
typedef long long int ii;
int main()
{
	vector < ii > v(10000000,0);
	
	for(ii i=2;i<=sqrt(10000000);i++) {
	   	
		   if(v[i]==0)
              for(ii j=1,k=i;k<=10000000;) {
		      
			 if (v[k]==0)
                  v[k]=i;
                  j++;
                  k=i*j; 
             }
      }
     v[0]=v[1]=0;
     
       for(ii i=2;i<=10000000;i++) 
           v[i]=v[i-1]+v[i];      
	 
     ii t;
     cin>>t;
     while(t--) {
        
	   ii n;
	   cin>>n;
	   cout <<v[n]<<endl;
	   	
     }
     cin.clear();
	return 0;
}