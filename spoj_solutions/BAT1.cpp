#include<bits/stdc++.h>

using namespace std;

typedef vector< vector <int > > matrix;
int CalculateRow(matrix &T,matrix &T1,matrix &S,int n,int m,int k,vector<int> &p);
int main() {

             int t;
             cin>>t;
             while(t--) {
                   
                      int n,m,k;
                      cin>>n;
                      cin>>m;
                      cin>>k;
                      int i,j,row=0;
                      matrix T(n+1,vector<int>(m+1,0));
                      matrix T1(n+1,vector<int>(m+1,0));
                      matrix S(n+1,vector<int>(k+1,0));
                      vector<int> p(n+1,0);
                      matrix dp(n+1,vector<int>(k+1,0));
                      int x,q;
		            for(i=1;i<=n;i++) {
		                   cin>>x;
					    p[i]=x;    
		            }
		            for(i=1;i<=n;i++) 
		                   for(j=1;j<=m;j++) {
		                        cin>>x;
		                        T[i][j]=x;
					    }
				  for(i=1;i<=n;i++) 
		                   for(j=1;j<=m;j++) {
		                        cin>>x;
		                        T1[i][j]=x;
					    }
				  CalculateRow(T,T1,S,n,m,k,p);	    
				  i=1;
				  for(j=0;j<=k-p[1];j++) 
				       dp[i][j+p[1]]=S[1][j];
                            
 				  int price=k;
				  int max1=-1;     
				  for(row=2;row<=n;row++) {
 
                             for(k=1;k<=price;k++) {
                                  
						    max1=dp[row-1][k];				  
				              for(j=1;j<=k-p[row];j++) {
				              
					               q=S[row][j]+dp[row-1][k-p[row]-j];
					               if(q>max1)
					                 max1=q;
					         }
				              dp[row][k]=max1;
				         }
			       }
			       cout<<dp[n][price]<<endl; 
		   }
             return 0;
}

int CalculateRow(matrix &T,matrix &T1,matrix &S,int n,int m,int k,vector<int> &p) {

    int i,j;
    int q;
    int max1=-1;
    int row=0;
     for(row=1;row<=n;row++) { 
               
			for(i=1;i<=k-p[row];i++) {
              
                    max1=0;
                    for(j=1;j<=m;j++) {
                          
					   if(T[row][j]>i)
		                     continue;
		                  q=T1[row][j]+S[row][i-T[row][j]]; 
		                  if(q>max1)
		                      max1=q;
		          
		         }
                   S[row][i]=max1; 
	          }
     }
	
}