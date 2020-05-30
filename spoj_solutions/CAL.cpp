#include<bits/stdc++.h>
using namespace std;
typedef long long int ii;
typedef vector< vector<ii> > matrix;
ii Calc(int i,ii &t1,ii &t2,ii &t3,matrix &T,ii head);
int main()
{
	int t;
	cin>>t;
	while(t--){
		int i=0;
       ii t1,t2,t3;
	  cin>>t1>>t2>>t3;
	  ii head=0,tail=0;
	  matrix T(5001,vector<ii>(1001,-1));
	  for(i=1;i<=5000;i++){
		 tail=Calc(i,t1,t2,t3,T,head);
           head=t2-tail;
	  }
	  ii q;
	  cin>>q;
	  while(q--){
	    int y,m;
	    cin>>y>>m;
	    if(T[y][m]==-1)
	      cout<<"0"<<endl;
	    else
	      cout<<T[y][m]<<endl;
	  }
     }
	return 0;
}
ii Calc(int i,ii &t1,ii &t2,ii &t3,matrix &T,ii head)
{
	int j=0;
	ii tr=head%t3;
	ii rem;
	T[i][j]=head/t3;
	ii temp2=t2+tr;
	ii count=(t1-head+tr)/t2;
	for(j=1;j<=count;j++){
            T[i][j]=temp2/t3;
            rem=temp2%t3;
		  temp2=temp2+rem;         	             
	}
	T[i][j]=(t1-head)%t2;
	return  T[i][j];
}
