#include<bits/stdc++.h>

using namespace std;

typedef vector< vector <pair<int,int> > >  matrix;
typedef vector< vector <char > >  matrix1;
int main() {
	
          int k;
          scanf("%d",&k);
          while(k--) {
                  
			   int m,n;
			   int i,j;
			   scanf("%d%d",&m,&n);
                  matrix T1(m+1,vector<pair <int,int> >(n+1));
                  matrix T2(m+1,vector<pair <int,int> >(n+1));
                  matrix1 D(m+1,vector<char>(n+1));
                  char c;
                  for(i=1;i<=m;i++) {
                             
				   for(j=1;j<=n;j++)
				       scanf(" %c",&D[i][j]);
			  }
		        stack<int> S,S1;
		        //FOR THE ROW*COLUMN
                  for(j=1;j<=n;j++) {
		            
		            while(!S.empty())
		                S.pop();
		            while(!S1.empty())
				      S1.pop();    
				  for(i=1;i<=m;i++) {
			       
			               //Front
			               while(!S.empty()&&D[S.top()][j]=='F')
			                   S.pop();
			               if(S.empty())
			                   T1[i][j].first=0;
						else
						    T1[i][j].first=S.top(); 
						S.push(i);    
			               //Back          
			               while(!S1.empty()&&D[S1.top()][j]=='F')
			                   S1.pop();
			               if(S1.empty())
			                   T1[m-i+1][j].second=m+1;
						else
						    T1[m-i+1][j].second=S1.top(); 
						S1.push(m-i+1); 
						   
				  }
		        }
                  //FOR THE ROW*COLUMN
			   for(i=1;i<=m;i++) {
		            
		            while(!S.empty())
		                S.pop();
		            while(!S1.empty())
				      S1.pop();    
				  for(j=1;j<=n;j++) {
			       
			               //Front
			               while(!S.empty()&&D[i][S.top()]=='F')
			                   S.pop();
			               if(S.empty())
			                   T2[i][j].first=0;
						else
						    T2[i][j].first=S.top(); 
						S.push(j);    
			               //Back          
			               while(!S1.empty()&&D[i][S1.top()]=='F')
			                   S1.pop();
			               if(S1.empty())
			                   T2[i][n-j+1].second=n+1;
						else
						    T2[i][n-j+1].second=S1.top(); 
						S1.push(n-j+1); 
						   
				  }
		        }
		        int k=0; 
		        int area=0;
		        int max1=-1;
		        for(i=1;i<=m;i++) {
		        
			        for(j=1;j<=n;) {
			                 int min1=1002;
			                  k=j;
				            if(D[i][j]=='R') {
						    j++;
						    continue;
					       }
					       while(j<T2[i][k].second) {
							 
					           if(T1[i][j].second<min1) {
							    min1=T1[i][j].second;
					            }
					           j++; 
					       }
					       if(min1>=1002)
					         min1=0;
					       area=(j-k)*(min1-i);
						  if(area>max1)
						    max1=area;
						    j=k+1;   	     
  				    }
			   }
			   if(max1>-1)
		        printf("%d\n",3*max1);   
		        else
		        printf("0\n");
         }
		return 0;   
}