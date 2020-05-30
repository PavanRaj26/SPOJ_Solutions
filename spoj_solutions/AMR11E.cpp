#include<bits/stdc++.h>
using namespace std;
#define all(v)   v.begin(),v.end()
int _isPrime(int num);
int main()
{
   int t,s=2;
   int i=0,j=0,count=0;
   int lucky[1001]={0};
   lucky[0]=30;
   lucky[1]=42;
   vector <int> v;
   v.push_back(2);
   for(i=3;i<500;i++)
       {
       	    if(_isPrime(i))
       	        v.push_back(i);
       }
         
   for(i=43;s<1001;i++){
   	    count=0;
        for(j=2;j<=i/2;j++){
               if(i%j==0)
                 if(find(all(v),j)!=v.end())
                    count++;
               if(count==3){
		         lucky[s++]=i;
		         break;
				}
              }
   }
   cin>>t;
   while(t--){
      int n;
      cin>>n;
      cout<<lucky[n-1]<<endl;
   }
   
	return 0;
}

int _isPrime(int num)
{
    int i;
    for(i=2;i<=num/2;i++)
        {
        	if(num%i==0)
        	   return 0;
        }
   return 1;
}
