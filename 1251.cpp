/*
kruskal
Memory 172K
Time    0MS
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define MAXM 900
#define MAXV 30

typedef struct{
	int s,t,w;
}Edge;

int n,esum,set[MAXV];
Edge edge[MAXM];

int find(int x){
	int rt;
	if(set[x]!=x){
		rt=find(set[x]);
		set[x]=rt;
		return set[x];
	}else return x;
}

bool Union(int a,int b){
	int fa,fb;
	fa=find(a);		//这里用并查集来判断是否有环
	fb=find(b);
	if(fa==fb) return 0;		//构成环了，这条边不能加进来
	set[fa]=fb;
	return 1;
}

void kruskal(){
	int i,ans=0;
	for(i=0;i<esum;i++){
		if(Union(edge[i].s,edge[i].t)){		
			//如果将这条边加进来构成不了环就加进来
			//还可以加一个计数，加到n-1就退出循环，如果不足n-1就构成不了生成树
			ans+=edge[i].w;
		}
	}
	printf("%d\n",ans);
}

int cmp(const void * a,const void *b){
	return (*(Edge*)a).w-(*(Edge*)b).w;
}

int main(){
	int i,j,m,c;
	char a[2],b[2];
	while(scanf("%d",&n) && n){
		esum=0;
		for(i=0;i<=n;i++) set[i]=i;
		for(i=1;i<n;i++){
			scanf("%s%d ",&a,&m);
			for(j=0;j<m;j++){
				scanf("%s%d ",&b,&c);
				edge[esum].s=a[0]-'A';
				edge[esum].t=b[0]-'A';
				edge[esum++].w=c;
			}
		}
		qsort(edge,esum,sizeof(edge[0]),cmp);		//首先对所有边的权值从小到大排序
		kruskal();
	}
	return 0;
}