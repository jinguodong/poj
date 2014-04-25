#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct Edge
{
	int from, to;
	int weight;
	Edge():from(0), to(0), weight(0){}
};

class Solution
{
public:
	const static int maxn = 30;
	const static int inf = 0x3f3f3f3f;
	int prim(vector<vector<int> > &graph, int n)
	{
		int vis[maxn];
		int lowc[maxn];
		memset(vis, 0, sizeof(vis));
		for(int i=0; i<n; ++i)
		{
			lowc[i] = graph[0][i];
		}
		vis[0] = 1;
		int res = 0;
		for(int i=1; i<n; ++i)
		{
			int p;
			int minc = inf;

			for(int j=0; j<n; ++j)
			{
				if((0 == vis[j]) && (minc > lowc[j]))
				{
					p = j;
					minc = lowc[j];
				}
			}
			if(minc == inf) // no answer
				return -1;
			res += minc;
			vis[p] = 1;
			for(int j=0; j<n; ++j) if(0 == vis[j] && lowc[j] > graph[p][j])
			{
				lowc[j] = graph[p][j];
			}
		}
		return res;
	}


};

int main()
{
	vector<vector<int> > inp(Solution::maxn, vector<int>(Solution::maxn, Solution::inf));
	int n;
	while(scanf("%d", &n) && n)
	{
		int m;
		int w;
		char a[2], b[2];
		Edge tmp;
		for(int j=0; j<n; j++)
		{
			for(int k=0; k<n; k++)
			{
				inp[j][k] = Solution::inf;
			}
		}
		for(int i=1; i<n; ++i)
		{
			scanf("%s%d", a, &m);
			
			for(int j=0; j<m; ++j)
			{
				scanf("%s%d", b, &w);
				tmp.from = a[0]-'A';
				tmp.to = b[0] -'A';
				tmp.weight = w;
				inp[tmp.from][tmp.to] = tmp.weight;
				inp[tmp.to][tmp.from] = tmp.weight;
			}
		}
		Solution sol;
		cout << sol.prim(inp, n) << endl;
	}
	return 0;
}
