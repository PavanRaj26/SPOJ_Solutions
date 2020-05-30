#include<bits/stdc++.h>
using namespace std;
typedef char ii;
typedef vector < vector<ii> > matrix;
typedef int ij;
typedef vector < vector<ij> > matrix1;
#define modul(a) (a>=0?a:0-a)
int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
	     int m,n;
	     int i=0,j=0,k=0;
	     cin>>m;
	     cin>>n;
	     matrix T(m,vector <ii >(n));
	     vector < pair <int ,int > > v;
         //taking input into a matrix in the form of char
	     for(i=0;i<m;i++)
	        for(j=0;j<n;j++)
	            cin>>T[i][j];
	    matrix1 A(m,vector< int >(n));    
		for(i=0;i<m;i++)
		    for(j=0;j<n;j++){
	             if(T[i][j]=='1')
	                v.push_back(make_pair(i,j));
	             A[i][j]=365;
				}
		 int x=0;
	    int max=v.end()-v.begin();
		for(k=0;k<max;k++) 
		 for(i=0;i<m;i++)
		    for(j=0;j<n;j++){
		    	if(v[k].first-i>=0)
		    	   x=v[k].first-i;
		    	else
				   x=i-v[k].first;
				if(v[k].second-j>=0)
				   x=x+v[k].second-j;
				else
				  x=x-v[k].second+j;         
		    	
				   if(x<A[i][j])
				       A[i][j]=x;	
				   }
         for(i=0;i<m;i++){
           for(j=0;j<n;j++)
              cout<<A[i][j]<<" ";
            cout<<endl;  
		   }
	
	
	}
	
	
			return 0;
		
	}
         