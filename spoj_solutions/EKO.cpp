#include<bits/stdc++.h>
using namespace std;
int main()
{

   long long int n,m;
   long long int i=0,x;
   scanf("%lld%lld",&n,&m);
   vector <long long int > v;
   for(i=0;i<n;i++)
       {    
	   scanf("%lld",&x);           
	   v.push_back(x);
                  
	}
   long long int low,high;
   low=0;
   high=*max_element(v.begin(),v.end());
   while(low<high){
	   long long int sum=0;
   	 x=low+(high-low+1)/2;
   	   for(i=0;i<n;i++){
   	   	if(sum>=m)
   	   	   break;
   	      if(v[i]>x)
		     sum=sum+v[i]-x;
   	  }
       if(sum>=m)
         low=x;
      else
         high=x-1;
   }
    printf("%lld\n",low);
    return 0;	
}