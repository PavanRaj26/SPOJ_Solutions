#include<bits/stdc++.h>
using namespace std;
typedef char  ch;
typedef vector < vector <char > > matrix;
typedef vector < vector <int > > matrix1;
void _ApplyDFS(matrix A,matrix1 &V,int n,int m,int &p,int &q,int i,int j);
int main()
{
   int n,m,i,j,p,q;
   cin>>n;
   cin>>m;
   matrix F(n,vector <char >(m));
   matrix1 V(n,vector <int >(m,0));
   for(i=0;i<n;i++)
      for(j=0;j<m;j++)
         cin>>F[i][j];
   int countsheep=0,countwolves=0;      
  for(i=0;i<n;i++)
    for(j=0;j<m;j++)
	   {
       if(V[i][j]==1||F[i][j]=='.'||F[i][j]=='#')
          continue;
       else{
       	p=0;q=0;
	     if(F[i][j]=='k')
	        p++;
	     else 
	        q++;
          V[i][j]=1;
		  _ApplyDFS(F,V,n,m,p,q,i,j);
		  if(p>q)
          countsheep=countsheep+p;
	   		  else
		  countwolves=countwolves+q;
          
	   }
}
cout<<countsheep<<" "<<countwolves<<endl;
   return 0;
}
void _ApplyDFS(matrix A,matrix1 &V,int n,int m,int &p,int &q,int i,int j)
{
	V[i][j]=1;
	    if(i!=0&&V[i-1][j]!=1&&A[i-1][j]!='#'){
	       if(A[i-1][j]=='k')
	        	p++;
	       else if(A[i-1][j]=='v')
	            q++;
	          _ApplyDFS(A,V,n,m,p,q,i-1,j);
	}
    	if(i!=n-1&&V[i+1][j]!=1&&A[i+1][j]!='#'){
	    if(A[i+1][j]=='k')
	        	p++;
	    else if(A[i+1][j]=='v')
	          q++;
	          _ApplyDFS(A,V,n,m,p,q,i+1,j);
	}
    	if(j!=0&&V[i][j-1]!=1&&A[i][j-1]!='#'){
	    if(A[i][j-1]=='k')
	        	p++;
	    else if(A[i][j-1]=='v')
	          q++;
	          _ApplyDFS(A,V,n,m,p,q,i,j-1);
	}
    	if(j!=m-1&&V[i][j+1]!=1&&A[i][j+1]!='#'){
	    if(A[i][j+1]=='k')
	        	p++;
	    else if(A[i][j+1]=='v')
	          q++;
	          _ApplyDFS(A,V,n,m,p,q,i,j+1);
	}

}
