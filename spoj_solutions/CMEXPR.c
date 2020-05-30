#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct node
{
  struct node *left;
  char data;
  struct node *right;
  int container;
  char data1;
};
struct node *construct_tre(int low,int high,char *s,int *count,int x,struct node *parent);
struct node *create_node();
void print_tree(struct node *root,struct node *parent,int counter);
int main() {

         int t;
         scanf("%d",&t);
         while(t--) {
              char *s=(char *)malloc(260*sizeof(char));
		    scanf("%s",s);
		    struct node *root=NULL;
		    int len=strlen(s);
		    int count=1;
		    root=construct_tre(0,len-1,s,&count,-1,root);
		    print_tree(root->left,root,0);
	         printf("%c",root->data);
		    print_tree(root->right,root,1);
		    printf("\n");
	    }
         return 0;
}
struct node *construct_tre(int low,int high,char *s,int *count,int x,struct node *parent) {


	if(high<low)
	    return NULL;
     int flag=0;
	struct node *nn=create_node();
	if(x==0)
	   nn->data1=parent->data1;
	else if(x==1)
	   nn->data1=parent->data;
     if(high==low) {

	    nn->data=s[low];
	    nn->container=*count;
	    return nn;
	}
	int count1=0,count2=0;
	while(flag!=1) {

		count1=0;
		count2=0;
		for(int i=low;i<=high;i++) {
			    if(s[i]=='(')
			    	     count1++;
			    else if(s[i]==')')
			          count2++;
			    else if(count1==count2&&(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')) {
		               flag=1;
					if(s[i]=='-') {

		                  nn->data='-';
		                  nn->container=*count;
					   nn->left=construct_tre(low,i-1,s,count,0,nn);
					   *count=nn->container;
					   nn->right=construct_tre(i+1,high,s,count,1,nn);
					   return nn;
				     }
		               else if(s[i]=='+') {

                            nn->data='+';
		                  nn->container=*count;
					   nn->left=construct_tre(low,i-1,s,count,0,nn);
					   *count=nn->container;
					   nn->right=construct_tre(i+1,high,s,count,1,nn);
		                  return nn;
					}
					else if(s[i]=='*') {

		                  nn->data='*';
		                  nn->container=*count;
					   nn->left=construct_tre(low,i-1,s,count,0,nn);
					   *count=nn->container;
					   nn->right=construct_tre(i+1,high,s,count,1,nn);
					   return nn;
					}
					else {

		                  nn->data='/';
		                  nn->container=*count;
					   nn->left=construct_tre(low,i-1,s,count,0,nn);
					   *count=nn->container;
					   nn->right=construct_tre(i+1,high,s,count,1,nn);
					   return nn;
					}
		         }
		}
		(*count)++;
		low=low+1;
		high=high-1;
		if(low==high) {

     	    nn->data=s[low];
		    nn->container=*count;
	         return nn;

		}

	}
	     return nn;

}
struct node *create_node(){
   struct node *nn=(struct node *)malloc(sizeof(struct node));
   nn->left=NULL;
   nn->right=NULL;
   nn->container=0;
   nn->data1='+';
   return nn;
}
void print_tree(struct node *root,struct node *parent,int counter) {

        if(root==NULL)
     	   return ;
        char c=parent->data;
        char t=root->data;
        char check=root->data1;
        int c1=parent->container;
        int c2=root->container;
        int flag=0;
        if(c1!=c2) {
          if(counter==1) {
      	    if((c=='/'&&(t=='+'||t=='-'||t=='*'||t=='/'))||((c=='-'||c=='*')&&(t=='+'||t=='-'))) {
		    flag=1;
		    printf("(");
             }
          }
              else {
                 if((c=='/'&&(t=='-'||t=='+'))||(check=='/'&&(t=='+'||t=='-'||t=='*'||t=='/'))) {
                    flag=1;
                    printf("(");
		       }

	             else if((check=='-'||check=='*')&&(t=='+'||t=='-')) {
		          flag=1;
		          printf("(");
                 }
             }
        }

        print_tree(root->left,root,0);
        printf("%c",root->data);
	   print_tree(root->right,root,1);
	   if(flag==1)
	       printf(")");
}
