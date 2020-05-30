#include<bits/stdc++.h>


using namespace std;
#define ff first
#define ss second
#define minimum(a,b) (a>b?b:a)
#define pb push_back
typedef long long ll;
#define vi vector<int>
#define pi pair<int,int> 
#define vl vector<ll>
#define pl pair<ll,ll>
#define vl vector<ll>
#define vpi vector<pi>
#define rep(i,n) for(i=0;i<n;i++) 
#define repr(i,n) for(i=n-1;i>=0;i--)
#define fr(i,a,b) for(i=a;i<=b;i++) 
#define fb(i,b,a) for(i=b-1;i>=a;i--)
#define M 1000000007
#define eb emplace_back
ll gcd(ll a,ll b) {
	if(a==0) return b;
	return gcd(b%a,a);
}
ll mulmod(ll a,ll b,ll c) {
	ll x=0,y=a%c;
	while(b>0) {
	     if(b&1) x=(x+y)%c;
	     y=(y*2)%c;
	     b/=2;
	}
	return x%c;
}
ll modulo(ll a,ll b,ll c) {

	ll x=1,y=a;
	while(b>0) {
	       if(b&1) x=(mulmod(x,y,c))%c;
  	       y=(mulmod(y,y,c))%c;	 		
		b/=2;
	}
	return x%c;
}
int RabiMill(ll p) {

	if(p<2) return 0;
	if(p%2==0&&p!=2) return 0;
	ll s=p-1;
	while(s%2==0) s/=2;
	for(int i=0;i<18;i++) {
		ll a=rand()%(p-1)+1,temp=s;
		ll mod=modulo(a,temp,p);
		while(temp!=p-1&&mod!=1&&mod!=p-1) {
			 mod=mulmod(mod,mod,p);
			 temp*=2;
		}
		if(mod!=p-1&&temp%2==0) return 0;
	}
	return 1;
}
int main() {

        int t;
        cin>>t;
        while(t--) {
        
        	ll n;
        	cin>>n;
        	if(RabiMill(n)) cout<<"YES"<<endl;
        	else cout<<"NO"<<endl;
        	
        }
        return 0; 			
}
