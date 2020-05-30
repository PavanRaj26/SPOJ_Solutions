#include <bits/stdc++.h>

using namespace std;

typedef long long int ii;
int main() {


           ii a,b;
           cin>>a;
           cin>>b;
           ii temp;
           if(a>b) {
              temp=b;
              b=a;
              a=temp;
		 }
           ii x=1;
           ii a1=1;
		 ii b1=1;
		 ii flag=0;
		 ii start=0;
		 if(a!=b)
           while(1) {
           
		         a1=(a1*x)%a;
		         b1=(b1*x)%b;
		         if(a1==0) {
		                   
					   x++;
		                  start=0;
		                  while(1) {
		                        
						    start++;
					         b1=(b1*x)%b;
					         if(b1==0) {
					        
						       flag=1;
						       break;
						       
					         }
					         x++;
					   }
			    }
		         if(b1==0||flag==1) { 
					break;
			    }
		         x++;
		 }
		 cout<<start<<endl;
           return 0;
}