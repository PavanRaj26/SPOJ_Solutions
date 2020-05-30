#include<bits/stdc++.h>
using namespace std;
unsigned long long int fact(unsigned long long int a,unsigned long long int k);
long long int Bsearch(long long int rem);
#define LYR  31622400
#define YR   31536000 
#define SIAD 86400 
#define M 4000000007
int monthsyr[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int monthslyr[12]={31,29,31,30,31,30,31,31,30,31,30,31};
char days[7][4]={
	               "Thu",
	               "Fri",
	               "Sat",
	               "Sun",
	               "Mon",
	               "Tue",
	               "Wed"
	           };
char month[12][4]={
                     "Jan",
					 "Feb",
					 "Mar",
					 "Apr",
					 "May",
					 "Jun",
					 "Jul",
					 "Aug",
					 "Sep",
					 "Oct",
					 "Nov",
					 "Dec"
				};
					 	           
	           
int main()
{
	unsigned long long int i=0;
	//CALCULATING THE NUMBER OF SECONDS
	unsigned long long int rem,x;
    unsigned long long int p,k,a;
    cin>>a;
    p=4000000007;
    k=1000000001;
    x=p-fact(a,k+1);
	//PRINTING OUT THE 26 CHARACTER FORMAT
    unsigned long long int whichyear[62]={0};
    unsigned long long int whichmonthyr[13]={0};
    unsigned long long int whichmonthlyr[13]={0};
    unsigned long long int whichday[31]={0};
    unsigned long long int storemonth,storeyear,storeday,noofdays;
    unsigned long long int storehour,storemin,storesec;
    noofdays=x/SIAD;
	for(i=1;i<=61;i++)
	   {
	   	  if((i+1970-1)%4!=0||i-1==30){
	   	        whichyear[i]=whichyear[i-1]+YR;
			 }
		  else
		     whichyear[i]=whichyear[i-1]+LYR;	 
	}
	for(i=1;i<=12;i++)
	  {
        whichmonthyr[i]=monthsyr[i-1]*SIAD +whichmonthyr[i-1];
    }
    for(i=1;i<=12;i++)
	  {
        whichmonthlyr[i]=monthslyr[i-1]*SIAD +whichmonthlyr[i-1];
    }
    for(i=1;i<=31;i++)
       whichday[i]=whichday[i-1]+SIAD;   
    for(i=0;i<=59;i++)
	    if(x>=whichyear[i]&&whichyear[i+1]>x){
		      x=x-whichyear[i];
		      storeyear=i+1970;
		  }
	if(storeyear%4!=0||storeyear==2000){
	    for(i=0;i<=11;i++)
	       if(x>=whichmonthyr[i]&&whichmonthyr[i+1]>x){
		      x=x-whichmonthyr[i];
		      storemonth=i+1;
		   }
	    for(i=0;i<=30;i++)
           if(x>=whichday[i]&&x<whichday[i+1]){
              x=x-whichday[i];
              storeday=i+1;
 	       }
 	       storehour=x/3600;
		   storemin=(x%3600)/60;
		   storesec=(x%3600)%60;	 
		   char s1[2],s2[2],s3[2],s4[2];
		      s1[0]=storeday/10+48;
		      s1[1]=storeday%10+48;
		      s2[0]=storehour/10+48;
		      s2[1]=storehour%10+48;
		      s3[0]=storemin/10+48;
		      s3[1]=storemin%10+48;
		      s4[0]=storesec/10+48;
		      s4[1]=storesec%10+48;
		      s1[2]='\0';     
		      s2[2]='\0';
		      s3[2]='\0';
		      s4[2]='\0'; 
		      
		  cout<<days[noofdays%7]<<" "<<month[storemonth-1]<<" "<<s1<<" "<<s2<<":"<<s3<<":"<<s4<<" "<<storeyear<<endl; 
	}
	else{
	    for(i=0;i<=11;i++)
	    if(x>=whichmonthlyr[i]&&whichmonthlyr[i+1]>x){
		      x=x-whichmonthlyr[i];
		      storemonth=i+1;
		  }
		  storeday=x/SIAD;
		  x=x-whichday[storeday];
 	     
		    storehour=x/3600;
		   storemin=(x%3600)/60;
		   storesec=(x%3600)%60;	 
		   char s1[2],s2[2],s3[2],s4[2];
		      s1[0]=storeday/10+48;
		      s1[1]=storeday%10+48;
		      s2[0]=storehour/10+48;
		      s2[1]=storehour%10+48;
		      s3[0]=storemin/10+48;
		      s3[1]=storemin%10+48;
		      s4[0]=storesec/10+48;
		      s4[1]=storesec%10+48;
		      s1[2]='\0';     
		      s2[2]='\0';
		      s3[2]='\0';
		      s4[2]='\0';
		  cout<<days[noofdays%7]<<" "<<month[storemonth-1]<<" "<<s1<<" "<<s2<<":"<<s3<<":"<<s4<<" "<<storeyear<<endl; 
	}
	return 0;
	
}
unsigned long long int fact(unsigned long long int a,unsigned long long int k)
{
	unsigned long long int x;
	if(k==0)
	  return 1;
	  if(k==1)
	   return a%M;
	else if(k%2==0){
                x=fact(a,k/2);
	  return   (x*x)%M;
}
	else{
                x=fact(a,(k-1)/2);
	  return   (((x*x)%M)*(a%M))%M;
}
	  
}