#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>

#define N 80
#define INF 10000000

using namespace std;

int dist[N][N];

struct node {
	int x,y;
};

bool operator<(const node& a,const node& b)
{
	return dist[a.x][a.y]<dist[b.x][b.y]?0:1;
}

priority_queue<node> q;
int graph[N][N];

void consider(int x,int y,int depth)
{
	if(x>=N || y>=N || x<0 || y<0 || dist[x][y]<depth+graph[x][y])
		return;
	dist[x][y]=depth+graph[x][y];
	q.push((node) { x,y } );
}

void initdist()
{
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			dist[i][j]=INF;
}

void dijkstra(int x,int y)
{
	dist[x][y]=graph[x][y];
	q.push((node) { x,y } );
	while(!q.empty()) {
		node a=q.top();
		q.pop();
		consider(a.x+1,a.y,dist[a.x][a.y]);
		consider(a.x-1,a.y,dist[a.x][a.y]);
		consider(a.x,a.y+1,dist[a.x][a.y]);
	}
}

int main(void)
{
	ifstream pfin("input.txt");
	int min=INF;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			pfin >> graph[i][j];
	for(int i=0; i<N; i++) {
		initdist();
		dijkstra(i,0);
		for(int j=0; j<N; j++) {
			if(dist[j][N-1]<min)
				min=dist[j][N-1];
		}
	}
	cout << min << endl;
	return 0;
}
