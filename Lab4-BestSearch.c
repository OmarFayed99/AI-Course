#include <stdio.h>
#include <bitset>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string.h>
#include <string>
#include <iostream>
#include <stack>
#include <ctype.h>
#include <algorithm>
#include <deque>
#include <functional>
#include <math.h>
#include <stdlib.h>

#define ll long long
#define pii pair<int,int>
#define mp make_pair
#define npos std::string::npos

using namespace std;

const int N = 3e4 + 2;

int n, x, y;
char z, t, target;
vector<char> Adjlist[N], ans;
int vis[26];
priority_queue<pair<int,char>> pq;
map<char, int> h;


void BSList(char v)
{
	vis[v - 'a'] = 1;
	if (vis[target - 'a'])
		return;
	ans.push_back(v);
	for (auto u : Adjlist[v - 'a'])
		pq.push(mp(-h[u + 'a'], u + 'a'));
	if (!pq.empty())
	{
		pair<int, char> f = pq.top();
		pq.pop();
		if (!vis[f.second - 'a'])
			BSList(f.second);
	}
}

int main()
{
	//number of nodes
	cin >> n;
	//input each node and it's Heuristic
	for (int i = 0; i < n; i++)
	{
		cin >> z >> y;
		h[z] = y;
	}
	//number of edges
	cin >> n;
	//parent and it's child
	for (int i = 0; i < n; i++)
	{
		cin >> z >> t;
		Adjlist[z - 'a'].push_back(t - 'a');
	}
	cin >> target;
	BSList('a');
	for (auto u : ans)
		cout << u << " ";
	cout << endl;
	return 0;
}