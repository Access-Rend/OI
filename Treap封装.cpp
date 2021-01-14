#include<bits/stdc++.h>

using namespace std;
const int INF = 2147483647;
const int MAXN = 100010;
int n;
struct Treap_tree{
    struct Node{
        int v,rnd,lson,rson,siz,cnt;
        Node(){
            v = rnd = lson = rson = siz = cnt = 0;
        }
        Node(int _v,int _rnd):v(_v),rnd(_rnd){lson = rson = 0;siz = cnt = 1;}
    }node[MAXN];
    int seed;
    int sz,root;
    void init(){
		seed = 12345;
		sz = root = 0;
	}
    int rand(){
        return seed = (int)seed*482711LL%2147483647;
    }
    int newnode(int x){
        node[++sz] = Node(x,rand());
    	return sz;
	}
    void updata(int p){
        node[p].siz = node[node[p].lson].siz+node[node[p].rson].siz+node[p].cnt;
    }
    void lturn(int &k){
        int t = node[k].rson;
        node[k].rson = node[t].lson;
        node[t].lson = k;
        node[t].siz = node[k].siz;
        updata(k);
        k = t;
    }
    void rturn(int &k){
        int t = node[k].lson;
        node[k].lson = node[t].rson;
        node[t].rson = k;
        node[t].siz = node[k].siz;
        updata(k);
        k = t;
    }
    void ins(int &p,int x){
        if(p == 0){
            p=newnode(x);
            return;
        }
        node[p].siz++;
        if(node[p].v == x)node[p].cnt++;
        else if(x>node[p].v){
            ins(node[p].rson,x);
            if(node[node[p].rson].rnd<node[p].rnd)lturn(p);
        }
        else {
            ins(node[p].lson,x);
            if(node[node[p].lson].rnd<node[p].rnd)rturn(p);
        }
    }
    void del(int &p,int x){
        if(p == 0)return ;
        if(node[p].v == x){
            if(node[p].cnt>1)node[p].cnt--,node[p].siz--;
            else{
                if(!node[p].lson || !node[p].rson)p = node[p].lson+node[p].rson;
                else if(node[node[p].lson].rnd<node[node[p].rson].rnd)rturn(p),del(p,x);
                else lturn(p),del(p,x);
            }
        }
        else if(x>node[p].v)node[p].siz--,del(node[p].rson,x);
        else node[p].siz--,del(node[p].lson,x);
    }
    int query_pos(int p,int x){
        if(p == 0)return 0;
        if(node[p].v == x)return node[node[p].lson].siz+1;
        if(x>node[p].v)return node[node[p].lson].siz+node[p].cnt+query_pos(node[p].rson,x);
        else return query_pos(node[p].lson,x);
    }
    int kth(int p,int x){
        if(p == 0)return 0;
        if(x<=node[node[p].lson].siz)return kth(node[p].lson,x);
        x-=node[node[p].lson].siz;
        if(x<=node[p].cnt)return node[p].v;
        x-=node[p].cnt;
        return kth(node[p].rson,x);
    }
    int pre(int p,int x){
        if(p == 0)return -INF;
        if(node[p].v<x)return max(node[p].v,pre(node[p].rson,x));
        return pre(node[p].lson,x); 
    }
    int nxt(int p,int x){
        if(p == 0)return INF;
        if(node[p].v<=x)return nxt(node[p].rson,x);
        else return min(node[p].v,nxt(node[p].lson,x));
    }
}tree;
int main(){
    scanf("%d",&n);
    int flag,x;
    tree.init();
    while(n--){
        scanf("%d%d",&flag,&x);
        if(flag == 1)tree.ins(tree.root,x);
        if(flag == 2)tree.del(tree.root,x);
        if(flag == 3)printf("%d\n",tree.query_pos(tree.root,x));
        if(flag == 4)printf("%d\n",tree.kth(tree.root,x));
        if(flag == 5)printf("%d\n",tree.pre(tree.root,x));
        if(flag == 6)printf("%d\n",tree.nxt(tree.root,x));
    }
    return 0;
}
