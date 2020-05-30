#include<bits/stdc++.h>
using namespace std;
typedef long long int ii;
typedef vector < vector<ii> > matrix;
matrix powwer(matrix A,int p);
matrix mul(matrix A,matrix B);
long long int k,n;
long long int M=1000000000;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    long long int i,j;
	    cin>>k;
	    long long int b[k],c[k];
	    long long int a[k];
	      for(i=1;i<=k;i++)
	         cin>>b[i];
	      for(i=1;i<=k;i++)
	        cin>>c[i];
	      long long int sum=0;
	      cin>>n;
		   vector<ii> A1(k+1);
	       for(i=1;i<=k;i++)
		     A1[i]=b[i];  
	       matrix T(k+1,vector<ii>(k+1));
	       for(i=1;i<=k;i++)
	           T[k][i]=c[k-i+1];
	       for(i=1;i<k;i++)
	           T[i][i+1]=1;
		   if(n<=k)
	           cout<<b[n]%M<<endl;
	       else{
	       	   sum=0;
	           T=powwer(T,n-k);
	           for(i=1;i<=k;i++)
	                sum=(sum+T[k][i]*A1[i])%M;
	           cout<<sum<<endl;
	       }
	}
	return 0;
}
matrix mul(matrix A,matrix B)
{
	
	int i=1,j=1,l=1;
	matrix C(k+1,vector<ii>(k+1));
	   for(i=1;i<=k;i++)
	       for(j=1;j<=k;j++)
	          for(l=1;l<=k;l++)
	             C[i][j]=(C[i][j]+A[i][l]*B[l][j])%M;
	           return C;  
}
matrix powwer(matrix A,int p)
{
	 if(p==1)
	    return A;
	 if(p%2)
	   return mul(A,powwer(A,p-1));
	 matrix X=powwer(A,p/2);
	 return mul(X,X);   
}