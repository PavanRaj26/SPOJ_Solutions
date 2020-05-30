#include<bits/stdc++.h>
using namespace std;
typedef vector< vector <char > > matrix;
typedef vector< vector < int > > matrix1;
int main()
{
	 int t;
	cin>>t;
	
	while(t--){
	  int n,m;
	  int i,j,x,y;
	 cin>>n;
	 cin>>m;
	 matrix M(n,vector<char >(m));
	 matrix1 D(n,vector< int >(m,10000));
	 matrix1 V(n,vector< int >(m,0));
     for(i=0;i<n;i++)
	   for(j=0;j<m;j++)
	      cin>>M[i][j];
	 for(i=0;i<n;i++)
	    for(j=0;j<m;j++)
		   if(M[i][j]=='C')
		      {
		     x=i;y=j;
		     break;
		}
     D[x][y]=0;
	 queue < pair<int,int> > Q;
	 pair <int,int > top;
	 Q.push(make_pair(x,y));
	  int p,q;
	 while(!Q.empty()){
       top=Q.front();
       Q.pop();
       p=top.first;
       q=top.second;
	   V[p][q]=1;
       if(p!=0&&M[p-1][q]!='#'&&V[p-1][q]!=1){
          D[p-1][q]=D[p][q]+1;
	      Q.push(make_pair(p-1,q));
      }
        if(p!=n-1&&M[p+1][q]!='#'&&V[p+1][q]!=1){
          D[p+1][q]=D[p][q]+1;
	      Q.push(make_pair(p+1,q));
      }
	      if(q!=0&&M[p][q-1]!='#'&&V[p][q-1]!=1){
          D[p][q-1]=D[p][q]+1;
	      Q.push(make_pair(p,q-1));
      }
        if(q!=m-1&&M[p][q+1]!='#'&&V[p][q+1]!=1){
          D[p][q+1]=D[p][q]+1;
	      Q.push(make_pair(p,q+1));
      }
      
	}
   int sum=0,max=-1;
	vector<int> v;
	  for(i=0;i<n;i++)
	    for(j=0;j<m;j++)
	         if(M[i][j]=='S'){
	            sum=60+sum+2*D[i][j];
	             if(D[i][j]>max)
				     max=D[i][j];
	         }
	 cout<<sum-max<<endl;
	            
	}
}