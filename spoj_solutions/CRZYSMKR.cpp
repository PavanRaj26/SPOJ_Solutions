#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		  long long int n;
		  cin>>n;
		  int i;
		  int m[11]={0};
		  m[0]=0;
		  for(i=1;i<11;i++)
		     m[i]=(36+34*m[i-1])%11;
		  
		     cout<<m[n%11]<<endl;   
		  
	}
	return 0;
}