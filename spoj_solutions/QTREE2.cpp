#include<bits/stdc++.h>

using namespace std;

#define FU(i,a,b) for(int i=a;i<=b;i++)
#define REP(i,n) for(int i = 0; i < int(n); ++i)
#define FD(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vl vector< ll >
#define ss second
#define ff first
#define M 1000000007LL
#define pii pair<int,int >
#define pll pair< ll,ll >
#define pdd pair<double,double>
#define SZ(x) ((int)(x).size())
#define all(a) a.begin(),a.end()
#define inf (1000*1000*1000+5)
#define PI   3.14159265358979323846
typedef  long long ll;
int gcd(int a,int b) {
                
    if(a==0) return b;
    else return gcd(b%a,a);
}
// Modular exponentiation
template<typename T>
// m must be positive
static T mod(T a, T m)
{
        a %= m;
        if (a < 0)
            a += m;
        return a;
}
int mul(int a,int b) {
    return (ll)a * b % M;
}
int power(int base, int exponent){
    if(exponent == 0)
        return 1;
    if(exponent & 1)
        return mul(base, power(base, exponent-1));
    int root = power(base, exponent/2);
    return mul(root, root);
}
// Modular inverse
int inv(int a){
    return power(a, M-2);
}
#define root 0
#define LN 14
const int MX = 10100;
vector<int> adj[MX],costs[MX];
int baseArray[MX],subsize[MX],chainHead[MX],chainInd[MX],posInBase[MX];
int depth[MX],ptr;
ll dist[MX];
ll st[MX * 7];
int pa[LN][MX];
int chainNo;
void make_tree(int cur,int s,int e) {
        if (s == e) {
                st[cur] = baseArray[s];
                return ;
        }
        int lt = (cur << 1);
        int rt = lt | 1;
        int m = (s + e ) >> 1;
        make_tree(lt,s,m);
        make_tree(rt,m + 1,e);
        st[cur] = st[lt] + st[rt];
}
ll query_tree(int cur,int s,int e,int l,int r) {
        if (e < l || s > r) return (ll)0;
        if (s >= l && e <= r) return 1ll * st[cur];
        int m = (s + e) >> 1;
        int lt = (cur << 1);
        int rt = lt | 1;
        ll q1,q2;
        q1 = query_tree(lt,s,m,l,r);
        q2 = query_tree(rt,m + 1,e,l,r);
        return q1 + q2;
}

int LCA(int u,int v) {
        if (depth[u] < depth[v]) swap(u,v);
        int diff = depth[u] - depth[v];
        for (int i = 0; i < LN; i++) {
                if ((diff >> i) & 1) u = pa[i][u];
        }
        if (u == v) return u;
        for (int i = LN - 1; i >= 0; i--) {
                if (pa[i][u] != -1 && pa[i][u] != pa[i][v]) {
                        u = pa[i][u];
                        v = pa[i][v];
                }
        }
        return pa[0][u];
}
ll query_up(int u,int v) {
        if (u == v) return 0;
        int uchain,vchain = chainInd[v];
        ll ans = 0;
        while (1) {
                if (u == -1) break;
                uchain = chainInd[u];
                if (uchain == vchain) {
                    if (u == v) break;
                    ans += query_tree(1,0,ptr,posInBase[v] + 1,posInBase[u]);
                    break;
                }
                ans += query_tree(1,0,ptr,posInBase[chainHead[uchain]],posInBase[u]);
                u = chainHead[uchain];
                u = pa[0][u];
        }
        return ans;
}
ll queryDist(int u,int v) {
        int lca = LCA(u,v);
        ll d1 = query_up(u,lca);
        ll d2 = query_up(v,lca);
        return d1 + d2;
}
int queryNode(int u,int v,int k) {
        int lca = LCA(u,v);
        int d1 = depth[u] - depth[lca] + 1;
        int d2 = depth[v] - depth[lca] + 1;
        if (d1 == k) {
            return lca;
        }
        if (d1 > k) {
            int diff = k;
            diff--;
            for (int i = 0; i < LN; i++) {
                if ((diff >> i) & 1) u = pa[i][u];
            }
            return u;
        }
        else {
            int diff = d2 - (k - d1) - 1;
            for (int i = 0; i < LN; i++) {
                if ((diff >> i) & 1) v = pa[i][v];
            }
            return v;
        }
}

void HLD(int curNode,int cost,int prev) {
    if (chainHead[chainNo] == -1) chainHead[chainNo] = curNode;
    chainInd[curNode] = chainNo;
    posInBase[curNode] = ptr;
    baseArray[ptr++] = cost;
    int sc = -1,ncost;
    REP(i,(int)adj[curNode].size()) {
            if (adj[curNode][i] != prev) {
                    if (sc == -1 || subsize[sc] < subsize[adj[curNode][i]]) {
                            sc = adj[curNode][i];
                            ncost = costs[curNode][i];
                    }
            }
    }
    if (sc >= 0) HLD(sc,ncost,curNode);
    REP(i,(int)adj[curNode].size()) {
            if (adj[curNode][i] != prev) {
                if (sc != adj[curNode][i]) {
                    chainNo++;
                    HLD(adj[curNode][i],costs[curNode][i],curNode);
                }
            }
    }
}

void dfs(int cur,int prev,int _depth,ll _dist) {
    pa[0][cur] = prev;
    depth[cur] = _depth;
    dist[cur] = _dist;
    subsize[cur] = 1;
    REP(i,(int)adj[cur].size()) {
            if (adj[cur][i] != prev) {
                dfs(adj[cur][i],cur,_depth + 1,_dist + costs[cur][i]);
                subsize[cur] += subsize[adj[cur][i]];
            }            
    }
}
int main() {

    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);    
    cin.tie(NULL);        
    cout.tie(NULL);
    int t;
    scanf("%d",&t);
    while (t--) {
            int n;
            scanf("%d",&n);
            REP(i,n) {
                adj[i].clear();
                costs[i].clear();
                chainHead[i] = -1;
                REP(j,LN) pa[j][i] = -1;
            }
            FU(i,1,n - 1) {
                int a,b,c;
                scanf("%d%d%d",&a,&b,&c);
                a--;b--;
                adj[a].pb(b);
                costs[a].pb(c);
                adj[b].pb(a);
                costs[b].pb(c);
            }
            chainNo = 0;
            dfs(root,-1,0,0);
            HLD(root,-1,-1);
            make_tree(1,0,ptr);
            for (int i = 1; i < LN; i++) {
                REP(j,n) {
                    if (pa[i - 1][j] != -1) {
                        pa[i][j] = pa[i - 1][pa[i - 1][j]];
                    }
                }
            }
            while(1) {
                char s[100];
                scanf("%s",s);
                if (s[1] == 'O') break;
                int a,b,k;
                if (s[0] == 'D') {
                    scanf("%d%d",&a,&b);
                    a--;b--;
                    printf("%lld\n",queryDist(a,b));
                }
                else {
                    scanf("%d%d%d",&a,&b,&k);
                    a--;b--;
                    printf("%d\n",queryNode(a,b,k) + 1);
                }
                printf("\n");
            }
    }
    return 0;
}