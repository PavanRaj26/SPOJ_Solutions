#include<bits/stdc++.h>
using namespace std;
int main()
{
	int num,i,s=0,j;
    
	int arr[34002];
	int counter[34002]={0};
	for(i=3;s<34002;i++)
	     if(i%2!=0&&i%6!=3)
	          arr[s++]=i;
	int lucky[3001];
	lucky[0]=2;
	lucky[1]=3;
	j=2;
	i=0;
	int k;
	int dec=0;
	while(j<3001){
        if(counter[i]!=1)
          lucky[j]=arr[i];
        else{
	     i++;
	     continue;
	   }
	   
          k=i+1;
         while(k<34002)
            { 
                                                
			   for(dec=lucky[j];dec>0;)
			     {
			               
				     if(counter[k]!=1){
			            k++;
						dec--;
					 }
					 else
					 k++;
			    if(k>34002)
			       break;
			   }
               counter[k-1]=1;
               
			}
         i++;
		 j++;   
   }
   cin>>num;
	do{
		cout<<lucky[num-1]<<endl;
		cin>>num;
	}while(num!=0);
	return 0;
}