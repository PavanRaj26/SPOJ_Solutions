#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> v(10000000,0);
	int i,j,k,x=sqrt(10000000);
	for(i=2;i<=x;i++){
	   if(v[i]==0)
	     for(j=2;j*i<=10000000;j++){
	        k=j*i;
	        if(v[k]==0)
	            v[k]=1;
		}
	}
	vector<int > a(10000000,0);
	a[2]=1;
	for(i=3;i<=10000000;i++)
	{
		  
		 if(i%2==0&&v[i/2]==0)
		   a[i]=a[i-1]-1;
		 else
		   a[i]=a[i-1]+1-v[i];
	}
	int t;
	scanf("%d",&t);
	while(t--){
	    int n;
	    scanf("%d",&n);
         printf("%d\n",a[n]);
	}
	   
	return 0;
}