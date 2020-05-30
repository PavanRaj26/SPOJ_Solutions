#include<bits/stdc++.h>
using namespace std;
typedef vector <vector <int > > matrix;
void _ApplyDFS(matrix &A,matrix &V,int n,int m,int &p,int i,int j);
int main()
{
	int n,m;
	cin>>n;
	cin>>m;
	while(n!=0&&m!=0){
	   matrix A(n,vector<int >(m));
	   matrix V(n,vector<int >(m,0));
	   int i,j,count=0;
	   for(i=0;i<n;i++)
	     for(j=0;j<m;j++)
		    cin>>A[i][j];
	   int arr[62501]={0};	 
	   int nofslicks=0;
	   for(i=0;i<n;i++)
	     for(j=0;j<m;j++)
	       {
	       	  if(V[i][j]==0&&A[i][j]==1){
	             count=1;
		   	      nofslicks++;
				    _ApplyDFS(A,V,n,m,count,i,j);
	       	 
	       	     arr[count]++;
	       	 }
	       }
	    cout<<nofslicks<<endl;   
	    for(i=1;i<62501;i++)
		   if(arr[i]!=0)
		     cout<<i<<" "<<arr[i]<<endl;   
	   cin>>n;
	   cin>>m;
	}
	return 0;
}
void _ApplyDFS(matrix &A,matrix &V,int n,int m,int &p,int i,int j)
{
	V[i][j]=1;
	    if(i!=0&&V[i-1][j]!=1&&A[i-1][j]==1){
	          p++;
		      _ApplyDFS(A,V,n,m,p,i-1,j);
	      }
	
    	if(i!=n-1&&V[i+1][j]!=1&&A[i+1][j]==1){
	          p++;
		      _ApplyDFS(A,V,n,m,p,i+1,j);
	      }
	
    	if(j!=0&&V[i][j-1]!=1&&A[i][j-1]==1){
	           p++;
		      _ApplyDFS(A,V,n,m,p,i,j-1);
	      }
	
    	if(j!=m-1&&V[i][j+1]!=1&&A[i][j+1]==1){
	           p++;
		      _ApplyDFS(A,V,n,m,p,i,j+1);
	      }
	
   return ;
}