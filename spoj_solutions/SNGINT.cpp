#include<bits/stdc++.h>

#define INF 1000000000

using namespace std;
typedef long long ll;

int main() {
        int t;
        cin>>t;
         
        while(t--) {
        	int n;
        	cin>>n;
        	ll i;
        	vector<int> v(10);
        	int cnt=0;
        	if(n==1||n==0) {
        		if(n==1)
        		cout<<n<<endl;
        		else
        		cout<<n+10<<endl;
        	}
        	else {
        	while(n%2==0) {n/=2;cnt++;}
        	v[2]=cnt;
        	cnt=0;
        	while(n%3==0) {n/=3;cnt++;}
        	v[3]=cnt;
        	cnt=0;
        	while(n%5==0) {n/=5;cnt++;}
        	v[5]=cnt;
        	cnt=0;
        	while(n%7==0) {n/=7;cnt++;}
		v[7]=cnt;
		if(n>1) {
			if(n!=1)
			cout<<"-1"<<endl; 
			
		}
		else  {
			
			v[8]+=v[2]/3;
			v[2]=v[2]%3;

			
			v[9]+=v[3]/2;
			v[3]=v[3]%2;
			if(v[2]>0&&v[3]==1)	{
				v[6]=1;
				v[3]=0;
				v[2]--;
			}
			if(v[2]==2) { v[4]++;
				v[2]=0;
			}
			ll rs=0;
			for(i=2;i<=9;i++)
			     while(v[i]--) {rs=rs*10+i;}
			cout<<rs<<endl;
		}
		}

        }
        //getch();
        return 0;
		
}
