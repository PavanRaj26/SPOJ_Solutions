#include<bits/stdc++.h>
using namespace std;
typedef vector<vector<int> > matrix;
void CallRecur(int depth,vector<int > &v2,long long int &count1,int n,vector<int > &mask);
int  main()
{

	int t;
	cin>>t;
	while(t--){
	int i,n,j;
	cin>>n;
	vector<int> v1,v2;
	matrix T(21,vector<int>(21));
	for(i=0;i<n;i++)
	 for(j=0;j<n;j++)
	   cin>>T[i][j];
	   int x;
         long long int count1=0;

 	for(i=0;i<n;i++){
	   v2.push_back(0);
	     x=0;
	    for(j=0;j<n;j++){
             if(T[i][j]==1){
               x=x+1;

           }
		 if(j!=n-1)
		   x=(x<<1);
         }
	    v2[i]=x;
	}
	int depth=1;
     vector<int > mask;
     for(i=0;i<n;i++){
         mask.push_back(1);
	}
   for(i=0;i<n;i++)
       if(v2[0]&(1<<i)) {
      	//To set all the corresponding bits to zero
             mask[i]=0;
		   CallRecur(depth+1,v2,count1,n,mask);
		   mask[i]=1;
		 

     }
       cout<<count1<<endl;
      }
	return 0;
}
void CallRecur(int depth,vector<int > &v2,long long int &count1,int n,vector<int > &mask) {
     int i=0;
     vector<int> v3;
	if(depth==n) {
	   for(i=0;i<n;i++)
           if(v2[n-1]&(1<<i)&&mask[i])
             count1++;
             return ;
	}
	for(i=0;i<n;i++) {
           if(v2[depth-1]&(1<<i)&&mask[i]) {
         	  mask[i]=0;
		   CallRecur(depth+1,v2,count1,n,mask);
		   mask[i]=1;
           }
     }
return ;
}
