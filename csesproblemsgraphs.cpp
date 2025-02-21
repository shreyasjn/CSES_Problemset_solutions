#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"
 
int n, m;
vector<set<pair<int,int>>> g;
vector<int> dist;
vector<int> par;
 
void dij()
{
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0,1});
	dist[1] = 0;
	par[1] = -1;
 
	while(!pq.empty())
	{
		int u = pq.top().second;
		int d = pq.top().first;
		pq.pop();
		
		if(dist[u] < d) continue;
		
		for(auto e: g[u])
		{
			int v = e.first;
			int c = e.second;
			if(dist[v] > dist[u]+c)
			{
				dist[v] = dist[u]+c;
				pq.push({dist[v],v});
				par[v] = u;
			}
		}
 
 
	}
 
}
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	dist.resize(n+1);
	par.resize(n+1);
	
	for(int i = 1; i <= n; ++i)
	{
		par[i] = -1;
	}
 
	g.resize(n+1);
	for(int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		g[u].insert({v,-1});
	}
	dij();
	if(dist[n] == 0)
	{
		cout << "IMPOSSIBLE";
		return 0;
	}
	
	cout << 1 + dist[n]*(-1) << endl;
	vector<int> ans;
	int temp = n;
	while(temp != -1)
	{
		ans.push_back(temp);
		temp = par[temp];
	}
	reverse(ans.begin(), ans.end());
	for(auto u: ans)
	{
		cout << u << " ";
	}
 
}