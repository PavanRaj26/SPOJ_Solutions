#include<bits/stdc++.h>
using namespace std;
class FenwickTree{
public:
void updatebit(vector<int> &bit,int val,int index){
	    while(index<bit.size()){
	     bit[index]+=val;
	     index=getNext(index);
	    }
	    
}
	 //CREATING A TREE IS LIKE UPDATING FOR EVERY VALUE
public:
vector<int> createTree(vector<int> &input){
	   vector<int> bit(input.size()+1,0);
	   for(int i=1;i<input.size();i++)
	      updatebit(bit,input[i-1],i);
	    return bit;
}
	  //TO GET SUM JUST GO TO INDEX +1 THEN DECREMENT TO 0 AND ADD THE VALUES INT THE INDEX
public:	  
int getSum(vector<int> &bit,int index){
          int sum=0;
		index=index+1;
          while(index>0){
             sum=sum+bit[index];
             index=getParent(index);
		}
          return sum;
}
	  //TO GET PARENT 2'S COMPLEMENT AND AND THEN SUBTRACT
private:
int getParent(int index){
             return index-(index & -index);
         }
        //TO GET NEXT INDEX 2'S COMPLEMENT AND THEN ADD
private:
int getNext(int index){
             return index+(index & -index);
 }
};
int main(){
   int n,q;
   scanf("%d%d",&n,&q);
     vector<int> v(n+1,0);
     FenwickTree ft;
     vector<int> bit=ft.createTree(v);
   while(q--){
     char s[4];
     int a,b;
     scanf("%s%d%d",s,&a,&b);
	if(s[0]=='a'){
		v[a]=v[a]+b;
          ft.updatebit(bit,b,a);
	}
	else{
	 printf("%d\n",ft.getSum(bit,b-1)-ft.getSum(bit,a-2));
	}
     
     
   }
   return 0;
}
