#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Edge
{
	int from, to;
	int weight;
	Edge():from(0), to(0), weight(0){}
};

bool comfunc(const Edge& src, const Edge& dst)
{
	return src.weight < dst.weight;
}

struct mycompare
{
	bool operator() (const Edge& src, const Edge& dst)
	{
		return src.weight < dst.weight;
	}
}mycompare;

class Solution
{
private:
	const static int maxn = 30;
	int my_find(vector<int> &nodes, int i)
	{
		if(nodes[i] == i)
			return i;
		else
			return nodes[i] = my_find(nodes, nodes[i]);
	}

	bool my_union(vector<int> &nodes, int i, int j)
	{
		int i1 = my_find(nodes, i);
		int j1 = my_find(nodes, j);
		if(i1 == j1)
			return false;
		else{
			nodes[i1] = nodes[j1];
			return true;
		}
	}
public:
	int kruskal(vector<Edge>& graph)
	{
		vector<int> nodes(maxn, 0);
		for(int i=0; i<maxn; i++)
		{
			nodes[i] = i;
		}
		int ans = 0;
		vector<Edge> res;
		for(int i=0; i<graph.size(); ++i)
		{
			if(my_union(nodes, graph[i].from, graph[i].to))
			{
				ans += graph[i].weight;
				res.push_back(graph[i]);
			}
		}
		return ans;
	}


};

int main()
{
	vector<Edge> inp;
	int n;
	while(scanf("%d", &n) && n)
	{
		int m;
		int w;
		char a[2], b[2];
		Edge tmp;
		for(int i=1; i<n; ++i)
		{
			scanf("%s%d", a, &m);
			for(int j=0; j<m; ++j)
			{
				scanf("%s%d", b, &w);
				tmp.from = a[0]-'A';
				tmp.to = b[0] -'A';
				tmp.weight = w;
				inp.push_back(tmp);
			}
		}
		sort(inp.begin(), inp.end(), mycompare);
		// sort(inp.begin(), inp.end(), comfunc);
		Solution sol;
		cout << sol.kruskal(inp) << endl;

		inp.clear();
	}
	return 0;
}
