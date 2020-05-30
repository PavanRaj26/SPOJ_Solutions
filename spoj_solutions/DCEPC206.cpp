#include<bits/stdc++.h>
void merge_sort(long long int *,long long int);
void merge(long long int *,long long int *,long long int *,long long int);
long long int sum=0;
int main()
{
     long long int t;
     scanf("%lld",&t);
     while(t--){
     	sum=0;
      long long int i;
	long long int n;
	scanf("%lld",&n);
	long long int a[n];
	for(i=0;i<n;i++)
	  scanf("%lld",&a[i]);
	merge_sort(a,n);
	 printf("%lld\n",sum); 
}
return 0;
}
void merge_sort(long long int *a,long long int n)
{   if(n<2)
    return;
    long long int i;
	long long int mid=n/2;
	long long int l[mid];
	long long int r[n-mid];
	for(i=0;i<mid;i++)
	   l[i]=a[i];
	for(i=0;i<n-mid;i++)
	   r[i]=a[i+mid];
	   merge_sort(l,mid);
	   merge_sort(r,n-mid);
       merge(l,r,a,n);
   }
void merge(long long int *l,long long int *r,long long int *a,long long int n)
{   long long  int low,high,mid=n/2;
    long long int i,j,k;
	i=0;
	j=0;
	k=0;
	while(i<mid&&j<n-mid){
     if(l[i]<=r[j]){
        a[k]=l[i];
        long long int x=0;
	   low=0;
        high=n-mid;
        while(low<high){
            x=low+(high-low)/2;
		  if(r[x]>l[i])
		    high=x;
		  else
		    low=x+1;     
	   }
	   sum=sum+l[i]*(n-mid-low);
	   i++;
	 }
	 else {
	    a[k]=r[j];
	    j++;
	 }
	 k++;
}
while(i<mid){
   a[k]=l[i];
   k++;
   i++;
}
while(j<n-mid){
   a[k]=r[j];
   k++;
   j++;
}
}