#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
		int n;
		int i=0,sum=0;
		cin>>n;
		int arr1[n];
		int ar2[n];
		for(i=0;i<n;i++)
		  cin>>arr1[i];
		for(i=0;i<n;i++)
		  cin>>ar2[i];
		sort(arr1,arr1+n);
		sort(ar2,ar2+n);
		for(i=0;i<n;i++)
		 sum=sum+arr1[i]*ar2[i];
		 cout<<sum<<endl;
	}
	return 0;
}