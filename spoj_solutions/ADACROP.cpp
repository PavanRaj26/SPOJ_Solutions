#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int MAX = 200005;
int N, Q;
int data[MAX];
int position[MAX],value[MAX];

struct node {
		
		int sum;
		node *l;
		node *r;
		node () {
			
			}
};
typedef node *pnode;

int getValue(pnode p) {
		
		return p ? p->sum: 0;
}
// INTILIAZATION OF PNODE
pnode initialize(int value) {
		
		pnode p = pnode(malloc(sizeof(node)));
		p->sum = value;
		p->l = NULL;
		p->r = NULL;
		return p;
}
void updatePosition(pnode &root,int st,int end,int pos,int value) {
		if (!root) {
				root = initialize(0);
			}
		if (st == end) {
			
				root->sum += value;
				return ;
			}	
		int mid = (st + end) / 2;
		if (pos <= mid) {
				updatePosition(root->l,st,mid,pos,value);				
			}	
		else {
				updatePosition(root->r,mid + 1, end,pos,value);
			}	
		root->sum = getValue(root->l) + getValue(root->r);				
}
int getInRange(pnode &root,int st,int end,int l,int r) {
		if (!root) return 0;
		if (st > r or end < l) {
				return 0;
			}
		if (l <= st and end <= r) {
				return root->sum;
			}	
		int mid = (st + end) / 2;
		return getInRange(root->l,st,mid,l,r) + getInRange(root->r,mid + 1,end,l,r);	
}
pnode pool[MAX << 1];
int main() {
		
		cin >> N >> Q;
		for (int i = 1; i <= N; i++) {
				cin >> data[i];
			}
		for (int i = 1; i <= Q; i++) {
				int x;				
				cin >> x >> value[i];				
				position[i] = x + 1;
			}	
		vector<int> items = vector<int> (data + 1,data + N + 1);
		items.insert(items.end(),value + 1,value + Q + 1);
		sort(items.begin(),items.end());
		items.erase(unique(items.begin(),items.end()),items.end());
		for (int i = 1; i <= N; i++) {
				data[i] = (int) (lower_bound(items.begin(),items.end(),data[i]) - items.begin());				
			}
		for (int i = 1; i <= Q; i++) {
				value[i] = (int) (lower_bound(items.begin(),items.end(),value[i]) - items.begin());
			}		
		for (int i = 1; i <= N; i++) {
				updatePosition(pool[data[i]],1,N,i,1);
			}			
		for (int i = 1; i <= Q; i++) {
				cout << getInRange(pool[value[i]],1,N,1,position[i] - 1) << endl;
				if (data[position[i]] != value[i]) {
						updatePosition(pool[data[position[i]]],1,N,position[i],-1);
						data[position[i]] = value[i];
						updatePosition(pool[data[position[i]]],1,N,position[i], 1);
					}
			}	
}

