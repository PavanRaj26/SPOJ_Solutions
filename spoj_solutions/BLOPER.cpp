#include<bits/stdc++.h>

using namespace std;

int main() {
	int n,s;
	cin>>n;
	cin>>s;
	int ul=n*(n+1)/2;
	if(s>ul||s<(0-ul+2))
	   cout<<"Impossible"<<endl;
	else {   
	vector< char> v(n+1,'+');
	int need=ul-s,k=n;
	if(need%2==0) {
	   int temp=need-2*k;
	   while(temp>=0) {
	      v[k]='-';
	      k--;
	      temp=temp-2*k;
	     }
	     if((temp+2*k)==2) {
             if(k==2||k==n)
		     cout<<"Impossible"<<endl;
		   else {	 
		   
		   v[k+1]='+';
             v[k]='-';
             v[2]='-';
             cout<<"1";
		 for(int i=2;i<=n;i++) 
             cout<<v[i]<<i;
           cout<<endl;    
           }
          
		}
          else {
	      v[(temp+2*k)/2]='-';
	      cout<<"1";
	      for(int i=2;i<=n;i++) 
             cout<<v[i]<<i;
           cout<<endl;    
          }   
        }
         else
         cout<<"Impossible"<<endl;
       }
 	return 0;
}