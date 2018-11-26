#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
#include <functional>
#include <set>
#include <map>

using namespace std;

struct edges
{
	int x;
	int weight;
};

bool operator<(const edges& a,const edges& b)
{
	return a.weight<b.weight?0:1;
}
int main(void)
{
	freopen("large_case4.in","rt",stdin);
	int V,E,u,v,w,min_weight=0;
	E=40; V=40;
	long sum=0;
	vector<edges> graph[V+1];
	priority_queue<edges> q;
	edges p;
	bool visited[V+1];
	for(int i=1; i<=V; i++)
	{
		visited[i]=false;
	}
	for(int i=1; i<=E; i++)
	{
		for(int j=1; j<=E; j++)
		{
			scanf("%d",&w);
			if(w==0)
				continue;
			p.x=j;
			p.weight=w;
			sum+=p.weight;
			graph[i].push_back(p);
		}
	}
	p.x=1;
	p.weight=0;
	q.push(p);
	while(!q.empty())
	{
		p=q.top();
		q.pop();
		if(!visited[p.x])
		{
			min_weight+=p.weight;
			visited[p.x]=true;
		}
		for(int i=0; i<graph[p.x].size(); i++)
		{
			if(!visited[graph[p.x].at(i).x])
			{
				printf("weight =%d starting edge = %d ending edge=%d\n",graph[p.x].at(i).weight,p.x,graph[p.x].at(i).x);
				q.push(graph[p.x].at(i));
			}
		}
	}
	printf("%d\n",sum/2-min_weight);
	return 0;
}
