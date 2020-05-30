#include<bits/stdc++.h>
using namespace std;
typedef  vector< vector < char> > matrix;
typedef vector < vector< int> > matrix1;
int _ApplyDFS(matrix &A,matrix1 &V,int n,int m,int i,int j,int flag);
int main()
{
	int t;
	cin>>t;
	while(t--){
	int n,m,i,j;
	cin>>n;
	cin>>m;
	matrix A(n,vector <char >(m));
	matrix1 V(n,vector<int >(m,0));
	int count=0,flag=1;
	for(i=0;i<n;i++)
	   for(j=0;j<m;j++)
	      cin>>A[i][j];
	    int x=0,y=0;  
    	for(i=0,j=0;j<m;j++)
	   if(A[i][j]=='.'&&V[i][j]!=1){
	     x=i,y=j;
	     V[i][j]=1;
	      count++;      
	  }
    	for(i=n-1,j=0;j<m;j++)
	   if(A[i][j]=='.'&&V[i][j]!=1){
	      count++; 
		  V[i][j]=1;     
	      	     x=i,y=j;
	  }
     	for(i=1,j=0;i<n-1;i++)
	   if(A[i][j]=='.'&&V[i][j]!=1){
	      count++;
		  V[i][j]=1;	     
		  x=i,y=j;
}      
     	for(i=1,j=m-1;i<n-1;i++)
	   if(A[i][j]=='.'&&V[i][j]!=1){
	      count++;  
		   V[i][j]=1;
		   x=i,y=j;		   
}
    for(i=0;i<n;i++)
      for(j=0;j<m;j++)
        V[i][j]=0;
	    if(count>2)
		  cout<<"invalid\n";
		else{
	       if(_ApplyDFS(A,V,n,m,x,y,flag))
	          cout<<"valid"<<endl;
	       else
	          cout<<"invalid"<<endl;
	}

    
}
	return 0;
}
int _ApplyDFS(matrix &A,matrix1 &V,int n,int m,int i,int j,int flag){
   	 
   	  if(flag!=1&&(i==0||j==0||i==n-1||j==m-1))
   	     return 1;
   	    flag=0; 
	   V[i][j]=1;
	    if(i!=0&&V[i-1][j]!=1&&A[i-1][j]=='.'&&_ApplyDFS(A,V,n,m,i-1,j,flag))
	          return 1;
	
    	if(i!=n-1&&V[i+1][j]!=1&&A[i+1][j]=='.'&&_ApplyDFS(A,V,n,m,i+1,j,flag))
	          return 1;
	
    	if(j!=0&&V[i][j-1]!=1&&A[i][j-1]=='.'&&_ApplyDFS(A,V,n,m,i,j-1,flag))
	          return 1;
	
    	if(j!=m-1&&V[i][j+1]!=1&&A[i][j+1]=='.'&&_ApplyDFS(A,V,n,m,i,j+1,flag))
	          return 1;
	   return 0;
}