#include<bits/stdc++.h>

using namespace std;

typedef signed long long ll;
typedef vector< vector<ll > > matrix;
#define vi vector<ll >

#define MOD 1000000007
map<long long , long long > F;
long long f(long long n);
ll Bsearch(ll &n,vector< pair< ll,pair<ll,ll> > > &v);
matrix powwer(matrix A,ll p );
ll CalcExp(ll a,ll b);
matrix mul(matrix A,matrix B);
int main() {
          
          ios::sync_with_stdio(false);		
		int t;
		cin>>t; 
		int i=0;
		vector< pair< ll,pair<ll,ll> > > v(44);
	     ll a=1,b=2,c;
	     ll sum=1;
	     i=0;
		while(i<=42) {
				         
					     v[i].first=sum;
	                         v[i].second.first=a;
	                         v[i].second.second=b;
					     c=a+b;
					     a=b;
					     b=c;
					     sum=sum+c-1;
	                         i++;
		}
		/*for(i=0;i<2;i++)
		  cout<<v[i].first<<" "<<v[i].second.first<<" "<<v[i].second.second<<endl;
		  */
		while(t--) {
		
		         ll n;
		         cin>>n;		         
			    
		           
		               F[0]=1;
		               F[1]=1;
		               ll a1,b1;
				       //T1=powwer(M,n-2);
				       a1=Bsearch(n,v);
		               b1=(n==0 ? 0 : f(n-1));
					   ll result;
		               result=CalcExp(a1,b1);
		               cout<<result<<endl;
		         
		         
		         
		         
		}
          return 0;
}
long long f(long long n) {
	
	if (F.count(n)) return F[n];
	long long k=n/2;
	if (n%2==0) { 
		return F[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % MOD;
	} else { 
		return F[n] = (f(k)*f(k+1) + f(k-1)*f(k)) % MOD;
	}
}

ll CalcExp(ll a,ll b) {

     if(b==1)
         return a;
     if(b%2)
         return (a*CalcExp(a,b-1))%MOD;
     ll tmp=CalcExp(a,b/2);
	return (tmp*tmp)%MOD;
	    
}
ll Bsearch(ll &n,vector< pair< ll,pair<ll,ll> > > &v) {

          int low=0;
          int high=44;
          int x=0;
          while(low<high) {
              
                 x=low+(high-low)/2;
                 if(v[x].first>=n)
                    high=x;
                 else
                    low=x+1;
                    
		}
          return v[low].second.first+v[low].second.second+(n-(v[low].first-(v[low].second.second-1)));
}