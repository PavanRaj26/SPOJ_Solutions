#include<bits/stdc++.h>
using namespace std;
int main()
{
    int p;
    cin>>p;
    while(p--){
       long long int n,k,m;
       cin>>n;
       cin>>k;
       cin>>m;
       long long int x=1;
       while(pow(k,x)*n<=m)
          x++;
       cout<<x-1<<endl;
	      
	}
	return 0;
}