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
typedef long long ll;

ll gcd(ll a,ll b) {
	if(a==0) return b;
	return gcd(b%a,a);
}
string longDiv(string num,int &rem) {

	 string ans;
	 int idx=0;
	 int div=9;
	 int tmp=num[idx]-'0';
	 while(tmp<div) tmp=tmp*10+(num[++idx]-'0');
	 while(num.size()>idx) {
	 
	 	ans+=(tmp/div)+'0';
	 	tmp=(tmp%div)*10+(num[++idx]-'0');
	 	
	 }
	 rem=tmp-(num[idx]-'0');
	 rem/=10;
	 if(ans.length()==0) return 0;
	 return ans;
}
int main() {

	string s;
	cin>>s;
	while(s[0]!='-'){
        int rem;
        if(s.size()<=1) {
                if(s[0]!='0')
        	cout<<1<<endl; 
        	else cout<<0<<endl;
        } 
        else {
    		 string r=longDiv(s,rem);

    	    if(rem==0) cout<<r<<endl;
        	else {
        	int n=r.size();
        	int cry=0;
        	for(int i=n-1;i>=0;i--) {
        		int x=r[i]-'0';
        		int sum=x+(i==n-1?1:0)+cry;
        		r[i]=sum%10+'0';
        		cry=sum/10;
        		if(!cry) break;		
        	}
        	if(cry==1) {
        		string nn="1";
        		nn+=r;
        		cout<<nn<<endl;
        		
        	}
        	else cout<<r<<endl;
        	}
        }
        cin>>s;
}    
        return 0; 			
}
