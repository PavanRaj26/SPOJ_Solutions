#include<bits/stdc++.h>
using namespace std;
typedef  vector< vector < int > > matrix;
int max(int i,int j,matrix &A,int n);
#define maximum(a,b) (a>b?a:b)
int main(){
   int t;
   cin>>t;
   while(t--){
     int h,w,i,j;
     cin>>h>>w;
     matrix A(h,vector<int >(w,0));
     for(i=0;i<h;i++)
       for(j=0;j<w;j++)
           cin>>A[i][j];
           
     for(i=1;i<h;i++){
        for(j=0;j<w;j++){
            A[i][j]=A[i][j]+max(i,j,A,w);
	   }
	  
	}
	i=h-1;
	int max1=-1;
	
	for(j=0;j<w;j++){
	   if(A[i][j]>max1)
	      max1=A[i][j];         
	 }
     cout<<max1<<endl;
   } 
   
   return 0;
}
int max(int i,int j,matrix &A,int n)
{
	  if(j!=0&&j!=n-1)
	     return  maximum(maximum(A[i-1][j-1],A[i-1][j]),A[i-1][j+1]);
	  else if(j==0)
	    return  maximum(A[i-1][j],A[i-1][j+1]);
	  return maximum(A[i-1][j],A[i-1][j-1]);   
}