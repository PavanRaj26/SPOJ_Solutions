#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
	string s;
	cin>>s;
    int len=s.size();
    int i,change=-1;
    int count=0;
    int flag=0;
    for(i=len/2-1;i>=0;i--){
    	 int j;
    	    //STATEMENT TO COUNT THE NUMBER OF NINES TO USE IT FOR LATER FOR THE CASES LIKE 999 99999 9999
    	    if(s[i]==s[len-i-1]&&s[i]=='9')
    	         count++;
    	         
    	    //STATEMENT FOR ALL NINES CASE 999 AND 9999  FOR BOTH EVEN AND ODD  
    	    if(count==(len-1)/2&&len%2!=0){
		         if(s[len/2]=='9')
		            {
		            	flag=1;
		            	cout<<"1";
		            	for(j=1;j<len;j++)
		            	    cout<<"0";
		            	cout<<"1"<<endl;
		            }
		    }
		    else if(count==len/2&&len%2==0){
		    	        flag=1;
		            	cout<<"1";
		            	for(j=1;j<len;j++)
		            	    cout<<"0";
		            	cout<<"1"<<endl;
		            }
			
		    //EXAMPLE FOR 7997->8008 FOR BOTH EVEN AND ODD
		    
    	    if(i==0&&count>0&&change==-1&&len%2==0&&count<len/2&&s[0]==s[len-1]){
		       int x=s[len/2-1];
		    //IF THE MIDDLE NO.. ARE NOT 9 THEN JUST ADD 1 TO IT AND CHANGE=1
			   if(s[len/2-1]!='9'){
				x=x+1;
				s[len-(len/2-1)-1]=x; 
				s[len/2-1]=x;
				change=1;
			}
			//IF EQUAL TO 9 THE TURN IT ITNTO ZEROES AND 
			   else if(s[len/2-1]=='9'){
			     s[len/2-1]='0';
			     s[len-(len/2-1)-1]='0';
			     int j=len/2-2;
			     while(s[j]=='9'){
			        s[j]='0';
			        s[len-j-1]='0';
			        j--;
				 }
			     int x=s[j];
			     x=x+1;
			     s[j]=x;
			     s[len-j-1]=x;
			     change=1;
			   }
		    }
		    //EXAMPLE FOR 797->808
               	    if(i==0&&count>0&&change==-1&&len%2!=0&&count<(len-1)/2&&s[0]==s[len-1]){
		         int x=s[len/2];
		         if(s[len/2]!='9'){
		              x=x+1;
		              s[len/2]=x;
		              change=1;
				 }
				else if(s[len/2]=='9')
				   {
			         s[len/2]='0';
			         int j=len/2-1;
			     while(s[j]=='9'){
			        s[j]='0';
			        s[len-j-1]='0';
			        j--;
				 }
			     int x=s[j];
			     x=x+1;
			     s[j]=x;
			     s[len-j-1]=x;
			         change=1;
			}
		}
            //CONDITION FOR A>B  
	        if(s[i]>s[len-i-1]){
	             s[len-i-1]=s[i];
	             change=1;
			}
			//CASE 1229 1339 143349
			if(s[i]<s[len-i-1]&&change==-1){
				
				s[len-i-1]=s[i]; 
			   if(len%2==0){	 
			       int x=s[len/2-1];
		           if(s[len/2-1]!='9'){
				   x=x+1;
				   s[len-(len/2-1)-1]=x; 
				   s[len/2-1]=x;
				   change=1;
			   }
			       else if(s[len/2-1]=='9'){
			       s[len/2-1]='0';
			       s[len-(len/2-1)-1]='0';
			       int j=len/2-2;
			       while(s[j]=='9'){
			           s[j]='0';
			           s[len-j-1]='0';
					   j--;
			       }
				   int x=s[j];
			       x=x+1;
			       s[j]=x;
			       s[len-j-1]=x;
			       change=1;
			      }
		    }
		       else if(len%2!=0){
		         int x=s[len/2];
		         if(s[len/2]!='9'){
		              x=x+1;
		              s[len/2]=x;
		              change=1;
		              int x=s[len/2-1];
			         
			         
			         s[len-(len/2-1)-1]=s[len/2-1];
				 }
				else if(s[len/2]=='9')
				   {
			         s[len/2]='0';
			         int j=len/2-1;
			         
			       while(s[j]=='9'){
			           s[j]='0';
			           s[len-j-1]='0';
				       j--;
			       
				   }
				   int x=s[j];
			       x=x+1;
			       s[j]=x;
			       s[len-j-1]=x;   
			         change=1;
			}
			 }
			}
			else  if(s[i]<s[len-i-1])
			   {
			   	   s[len-i-1]=s[i];
			   	   change=1;
			   }
			 //CASES 1221 121 191 131  
			if(i==0&&change==-1&&len%2==0)
			   {
			   	int x=s[len/2-1];
				x=x+1;
				
				s[len-(len/2-1)-1]=x; 
				s[len/2-1]=x;
				change=1;
			   }
			 else if(i==0&&change==-1&&len%2!=0){
		        int x=s[len/2];
		           if(s[len/2]!='9'){
				   x=x+1;
				   s[len/2]=x;
			}
		          else if(s[len/2]=='9')
		              {
		              	s[len/2]='0';
			         int x=s[len/2-1];
			         x=x+1;
			         s[len/2-1]=x;
			         s[len-(len/2-1)-1]=x;
			         change=1;
		              }
			 }
	   }
	   if(len==1)
	     cout<<"11"<<endl;
	   else if(flag!=1)
	   cout<<s<<endl;
    }
	return 0;
}
