#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int t=1;
     int *S=(int *)malloc(100010*sizeof(int));
     int *arr=(int *)malloc(1000010*sizeof(int));
     int *arr2=(int *)malloc(100010*sizeof(int));
        int i;
     for(i=0;i<=100000;i++)
        S[i]=100001;
        arr[0]=0;
        int k=0;
     for(i=0;k<=100000;){
	   arr[i]=k;
        arr2[k]=1;
        i++;
        k=i*i*i;
   }
     int q;
	for(i=1;i<=100000;i++){
           if(arr2[i]==1){
	         S[i]=1;
	         continue;
	      }
	      else{
	         for( int j=1;arr[j]<=i/2;j++){
	           q=S[arr[j]]+S[i-arr[j]];
	           if(q<S[i])
	             S[i]=q;
		   }
	          
	      }
     
     }
	while(scanf("%d",&n)!=EOF){
	int i,q;
     cout<<"Case"<<" #"<<t<<": "<<S[n]<<endl;
     t++;
}
	return 0;
}

