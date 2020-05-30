#include<bits/stdc++.h>

using namespace std;

typedef long long int ii;
const int N=1000010;
ii phi[N];
ii q[N];
ii ans[N];
int main() {
	
	for(int i=1;i<=N;i++) {
	     
	     phi[i]=i;
	}
	for(int i=2;i<N;i++) {
	
	    if(phi[i]==i)
	    for(int j=i+i;j<N;j+=i) {
	     
	           if(phi[j]==j)
	              phi[j]=i;
	    }
	}
	q[1]=1;
	for(int i=2;i<N;i++) {
	
	           int divisor=phi[i];
	           int exponent=0;
	           int remainder =i;
	           while(remainder%divisor==0) {
		
		            remainder/=divisor;
		            exponent++;
			 }
			 q[i]=q[remainder]*(i/remainder/divisor)*((divisor-1)*exponent+divisor);
			 ans[i]=ans[i-1]+q[i]-i; 
	       
	}
     ii n;
     cin>>n;
     while(n) {
     
         cout<<ans[n]<<endl;
         cin>>n;
      
	}
}