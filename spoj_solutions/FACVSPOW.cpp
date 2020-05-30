#include<bits/stdc++.h>
using namespace std;
double fact(long long int x);
int main()
{
	int t;
	scanf("%d",&t);
    	vector <long long int > v;
	v.push_back(4);
	long long int curr=4;
	double fnew,fold=3.17805;
	long long int j;
	for(j=3;j<=1000000;j++)
	   {
         fnew=log(curr+1)+fold;
	      if(fnew>(curr+1)*log(j)){
	         
		     v.push_back(curr+1);
	         curr=curr+1;
	     }
	      else if(fnew+log(curr+2)>(curr+2)*log(j)){
	        fnew=fnew+log(curr+2);
		    v.push_back(curr+2);
	        curr=curr+2; 
		  }
		  else{
		  	fnew=log(curr+3)+log(curr+2)+fnew;
		    v.push_back(curr+3);
	        curr=curr+3;
	}
		 fold=fnew;   
	         
}
	while(t--){
	long long int a;
	scanf("%lld",&a);
	    cout<<v[a-2]<<endl;
  }

	return 0;
}
double fact(long long int x)
{
	double sum=0;
	while(x!=0){
	  sum=sum+log(x);
      x--;
  }
  return sum;
}