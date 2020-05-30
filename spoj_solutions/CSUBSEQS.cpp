#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ii;
typedef vector< vector<int > > matrix;
typedef vector< vector<char > > matrix1;
void ConLCS(matrix &lcs,matrix1 &b,string &s1,string &s2);
void Satisfy(matrix &T,string &s);
void BackAndAssign(vector<char> &s,string &s1,int i,int j,matrix1 &b,int len);
int Search(matrix &T,vector<char> &s,int len);
int Bsearch(matrix &T,int index,int &key);
int main() {

           
          int i,j;
          multimap<int,string > m1;   
          string s;
		for(i=0;i<4;i++) {
		    cin>>s;
		    m1.insert(pair<int,string>(s.size(),s));
		}
		multimap<int,string >::iterator it=m1.begin();
		multimap<int,string >::iterator it1,it2,it3,it4;
		it1=it;
		it++;
		it2=it;
		it++;
		it3=it;
		it++;
		it4=it;
		string s1,s2,s3,s4;
		s1=it1->second;
		s2=it2->second;
		s3=it3->second;
		s4=it4->second;
          int m=it1->first;
          int n=it2->first;
          matrix lcs(m+1,vector<int>(n+1,0));
          matrix1 b(m+1,vector<char>(n+1,'1'));
          ConLCS(lcs,b,s1,s2);
          matrix T3(26,vector<int>(51,51));
          matrix T4(26,vector<int>(51,51));
          Satisfy(T3,s3);
          Satisfy(T4,s4);
          ii count=0;
          
          for(int key=1;key<=it1->first;key++) {
		      map< vector<char> ,int> m2;
		      map< vector<char> ,int>::iterator itmp;
			 for(i=1;i<=m;i++) {
                       		
		             for(j=1;j<=n;j++) {
		             
				          if(lcs[i][j]==key&&b[i][j]=='d') {
					          vector<char> s(lcs[i][j]);
							BackAndAssign(s,s1,i,j,b,key);
							itmp=m2.find(s);
							if(itmp==m2.end())
					          if(Search(T3,s,key)&&Search(T4,s,key)) {
                                     m2[s]=1;
							  count++;
						     }
					     }
					     else if(lcs[i][j]>key) {
					       
					        break;
						}
				   }
			 }
       
		}
		cout<<count<<endl;
          return 0;
}
void ConLCS(matrix &lcs,matrix1 &b,string &s1,string &s2) {

     int i=1,j=1;
     int m=s1.size();
     int n=s2.size();
     for(i=1;i<=m;i++)
         for(j=1;j<=n;j++) {
             if(s1[i-1]==s2[j-1]) {
                 lcs[i][j]=1+lcs[i-1][j-1];
                 b[i][j]='d';
		   }
		   else if(lcs[i-1][j]>=lcs[i][j-1]){
		   
		       lcs[i][j]=lcs[i-1][j];
		       b[i][j]='u';
		   }
		   else {
		       lcs[i][j]=lcs[i][j-1];
		       b[i][j]='l';
		   }
	    }
}
void Satisfy(matrix &T,string &s){
      
      int i=0;
      for(i=0;i<26;i++)
          T[i][50]=0;
      int len=s.size();
      int arr[len];
      for(i=0;i<len;i++)
         arr[i]=s[i]-'a';
      int index=0;
	 for(i=0;i<len;i++) {
            
            index=arr[i];  
            T[index][T[index][51]]=i;
            T[index][51]++;
      }
	   
}
void BackAndAssign(vector<char> &s,string &s1,int i,int j,matrix1 &b,int len){
          
          
          while(i>=1&&j>=1) {
               if(b[i][j]=='d') {
                   s[len-1]=s1[i-1];
                   len--;
                   i=i-1;
                   j=j-1;
			}
			else if(b[i][j]=='l')
			    j=j-1;
			else
			    i=i-1;
		}
}
int Search(matrix &T,vector<char> &s,int len) {

     int index;
     int key=0;
     int i;
     for(i=0;i<len;i++) {
       
	    index=s[i]-'a';
	    if(!Bsearch(T,index,key)) 
	     return 0;
	}
	return 1;
}
int Bsearch(matrix &T,int index,int &key) {
   
     int low=0;
     int high=T[index][51];
     int x=0;
     while(low<high) {
       x=low+(high-low)/2;
       if(T[index][x]<key)
          low=x+1;
       else
          high=x;
	}
	if(T[index][low]==51)
	   return 0;
	else {
        key=T[index][low];
        return 1;
	}
}