#include<bits/stdc++.h>
using namespace std;
#define max(a,b) (a>b?a:b)
long long int _Blast(vector<long long int > &v,long long int i,long long int n,long long int a[]);
int main()
{
  int t;
  cin>>t;
  while(t--){
  long int i,n;
  cin>>n;
  long long int arr[n+10];
  for(i=0;i<n;i++)
      cin>>arr[i];
    vector <long long int> v(arr,arr+n);
  if(n<=3){
     long long int sum=0;
	for(i=0;i<n;i++)
        sum=sum+v[i];
        cout<<sum<<endl;
  }
  else{
     v[n-2]=v[n-2]+v[n-1];
     v[n-3]=v[n-3]+v[n-2];
     
     for(i=n-4;i>=0;i--)
       v[i]=_Blast(v,i,n,arr);
    cout<<v[0]<<endl;
  }
  
}
  return 0;	
}
long long int _Blast(vector<long long int > &v,long long int i,long long int n,long long int a[])
{
	long long int s1=a[i]+a[i+1]+a[i+2];
	if(i+6<n){
	  return max(max(a[i]+v[i+2],a[i]+a[i+1]+v[i+4]),s1+v[i+6]);
	}
	else{
       if(i+4<n)
	  return max(max(a[i]+v[i+2],a[i]+a[i+1]+v[i+4]),s1); 
	  else
   	  return max(max(a[i]+v[i+2],a[i]+a[i+1]),s1); 
	  
}
}