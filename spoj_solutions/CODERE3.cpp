#include<bits/stdc++.h>

using namespace std;


int CeilIndex(vector<int> &v,int high,int key);
void CalcLen(vector<int> &v,vector<int> &t,int n);
int main() {

          int t;

          cin>>t;
          while(t--) {

              int n;
              int i,x;
              cin>>n;
              vector<int> v(n,0);
              for(i=0;i<n;i++) {
                    cin>>x;
                    v[i]=x;
		    }
            vector<int> len1(n,0);
		    vector<int> len2(n,0);
		    vector<int> arr1(n,0);
		    vector<int> arr2(n,0);
		    CalcLen(v,len1,n);
		                arr1[0]=v[0];
            for(i=1;i<n;i++)   {
                if(len1[i]>len1[i-1])
                    arr1[i]=v[i];
                else
                    arr1[i]=arr1[i-1];
            }

		    reverse(v.begin(),v.end());
		    CalcLen(v,len2,n);
            arr2[0]=v[0];
            for(i=1;i<n;i++)   {
                if(len2[i]>len2[i-1])
                    arr2[i]=v[i];
                else
                    arr2[i]=arr2[i-1];
            }

		    reverse(len2.begin(),len2.end());
            reverse(arr2.begin(),arr2.end());
		    int max1=-1;
            int flag=0;

		    for(i=0;i<n-1;i++) {
		        if(len1[i]+len2[i+1]>max1&&arr1[i]!=arr2[i+1]) {
		            flag=1;
		            max1=len1[i]+len2[i+1];
		        }
		    }
            if(len1[n-1]>max1)
                max1=len1[n-1];
            if(len2[0]>max1)
                max1=len2[0];
            if(flag==0) {
               if(n==1)
                  max1=1;
               else
                  max1=2;
            }
		    cout<<max1<<endl;

		}
          return 0;
}
void CalcLen(vector<int> &v,vector<int> &t,int n) {

          if(n==0)
              return ;
          int length=1;
          vector<int> tail(n,0);
          tail[0]=v[0];
          int x=0;
          t[0]=length;
          int prev=t[0];
           for(int i=1;i<n;i++) {
			 if(v[i]<tail[0]) {
                     tail[0]=v[i];
                     if(prev>t[i])
                     t[i]=prev;
		     }
		     else if(v[i]>tail[length-1]) {
		             tail[length]=v[i];
		             length++;
		             t[i]=length;
			         if(prev>t[i])
                        t[i]=prev;

			}
			else {
				     x=CeilIndex(tail,length-1,v[i]);
			         tail[x+1]=v[i];
			         t[i]=x+2;
			         if(prev>t[i])
                        t[i]=prev;
			}
            prev=t[i];
          }

}
int CeilIndex(vector<int> &tail,int high,int key) {

		int low=0;
		int x;

		while(low<high) {
	        x=low+(high-low+1)/2;
	        if(tail[x]<=key)
	           low=x;
	        else
	           high=x-1;
		}
		if(tail[low]==key)
            low=low-1;
		return low;
}
