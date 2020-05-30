#include<bits/stdc++.h>
using namespace std;
void _Satisfied(vector<long long int> &v,long long int i,vector<long long int> &arr);
int main()
{
	
  long long int n,i;
  cin>>n;
  long long int arr[n+5];
  for(i=0;i<n;i++)
      cin>>arr[i];
  vector<long long int > v(arr,arr+n),v1;    
  v1.push_back(1);
  for(i=1;i<n;i++)
      _Satisfied(v,i,v1);
      
   cout<<*max_element(v1.begin(),v1.end())<<endl;        

 return 0;  
}
void _Satisfied(vector<long long int> &v,long long int i,vector<long long int> &arr)
{
	long long int j;
     arr.push_back(1);
	for(j=0;j<i;j++)
     if(v[j]*(v[i]+v[j])<0&&(arr[i]<arr[j]+1)){
	   arr[i]=arr[j]+1;
   }
    
  }