#include<bits/stdc++.h>

using namespace std;
typedef  long long int ii;
int addOvf(ii a, ii b);
ii _Bsearch(ii a,int k);
ii Ep(ii x,int k);
int main() {

    
       ii i,a,b;
       cin>>a;
       cin>>b;
       while(a!=0&&b!=0) {
              ii sum=0;
       for(i=a;i<=b;i++) {
       	      for(int k=64;k>=1;k--) {
				 double r=pow(i,1.0/k);
				 ii m=r;
				 
				 if(Ep(m,k)==i) {
				     
				    sum=sum+k;
			          break;
				 }
			 }
       }
  
       cout<<sum<<endl;
       cin>>a;
       cin>>b;
  }
}

ii Ep(ii x,int k) {
    
    if(k==1||x==1)
       return x;
    if(!(k%2)) {
       ii m=Ep(x,k/2);
       if(addOvf(m,m)==-1)
          return 0;
       return m*m;   
    }
    ii m=Ep(x,(k-1)/2);
    
    if(addOvf(m,m)==-1||addOvf(m*m,x)==-1)
      return 0;
    return m*m*x;  
       
      
}
int addOvf(ii a, ii b)
 {
 	ii* result=(ii *)malloc(sizeof(ii));
     *result = a * b;
     if(a > 0 && b > 0 && *result < 0)
         return -1;
     return 0;
 }