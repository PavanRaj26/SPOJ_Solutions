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
const int MX = 101000;
vector<int> g[MX];
int subsize[MX],chainNo,chainInd[MX],chainHead[MX],chainPos[MX],chainLength[MX];
vector<int> sto[MX];
set<int> H[MX][2];
int col[MX];
int pa[LN][MX];
int query_up(int u) {
    if (u == 0) {
        if (col[u] == 1) return u;
        return -1;
    }
    int uchain;
    int v = 0;
    int vchain = chainInd[0];
    int ans = -2;
    uchain = chainInd[u];
    while (1) {
        uchain = chainInd[u];
        if (uchain == vchain) {
             if (u == v) {
                if (col[u] == 1) return u + 1;
                return ans + 1;
             }   
             if ((int)H[uchain][1].size() > 0) {
                set<int>::iterator it = H[uchain][1].begin();
                if ((*it) <= chainPos[u])
                ans = sto[uchain][(*it)];
             }
             break;
        }
        if ((int)H[uchain][1].size() > 0) {
            set<int>::iterator it = H[uchain][1].begin();
            if ((*it) <= chainPos[u])
            ans = sto[uchain][(*it)];
        }
        u = chainHead[uchain];
        u = pa[0][u];
    }
    return ans + 1;
}
void change(int v) {
        
        int cNo = chainInd[v];
        int pos = chainPos[v];
        if (col[v] == 0) {
            set<int>::iterator it = H[cNo][0].find(pos);
            H[cNo][0].erase(it);
            H[cNo][1].insert(pos);
            col[v] = 1;
        }
        else {
            set<int>::iterator it = H[cNo][1].find(pos);
            H[cNo][1].erase(it);
            H[cNo][0].insert(pos);
            col[v] = 0;
        }
}
void HLD(int cur,int prev) {
    
    if (chainHead[chainNo] == -1) {
        chainHead[chainNo] = cur;
    }
    chainInd[cur] = chainNo;
    chainPos[cur] = chainLength[chainNo];
    chainLength[chainNo]++;
    H[chainNo][0].insert(chainPos[cur]);
    sto[chainNo].pb(cur);
    int sc = -1;
    REP(i,(int)g[cur].size())  {
            int x = g[cur][i];
            if (x != prev) {
                if (sc == -1 || subsize[sc] < subsize[x]) {
                        sc = x;
                }
            }
    }
    if (sc != -1) HLD(sc,cur);
    REP(i,(int)g[cur].size()) {
            int x = g[cur][i];
            if (x != prev) {
                    if (sc != x) {
                        chainNo++;
                        HLD(x,cur);
                    }
            }
    }
}
void dfs(int cur,int prev) {
    pa[0][cur] = prev;
    subsize[cur] = 1;
    REP(i,(int)g[cur].size()) {
            int x = g[cur][i];
            if (x != prev) {
                dfs(x,cur);
                subsize[cur] += subsize[x];
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
    int n,q;
    scanf("%d%d",&n,&q);
    FU(i,0,n) {
        chainHead[i] = -1;
        REP(j,LN) pa[j][i] = -1;
    }
    FU(i,1,n - 1) {
          int a,b;
          scanf("%d%d",&a,&b);
          a--;b--;
          g[a].pb(b);
          g[b].pb(a);
    }
    dfs(0,-1);
    HLD(root,-1);
    for (int i = 1; i < LN; i++) {
            REP(j,n) {
                if (pa[i - 1][j] != -1) {
                    pa[i][j] = pa[i - 1][pa[i - 1][j]];
                }
            }
    }
    while(q--) {
            int t,v;
            scanf("%d%d",&t,&v);
            if (t == 0) {
                v--;
                change(v);
            }
            else {
                v--;
                printf("%d\n",query_up(v));
            }
    }
    return 0;
}