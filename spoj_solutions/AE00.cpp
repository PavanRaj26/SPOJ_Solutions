#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
    cin>>n;
    int i=0,j=0;
    int sum=0;
    for(i=1;i<=n;i++)
        {
        	 for(j=1;j<=sqrt(i);j++)
        	      if(i%j==0)
        	         sum++;
        }
     cout<<sum<<endl;   
	return 0;
}