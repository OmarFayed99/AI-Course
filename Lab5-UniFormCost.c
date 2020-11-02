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

using namespace std;

const int N = 3e4 + 2;

int n, x;
char z, t;
vector<char> Adjlist[N], targets;
int vis[N], ans[N];
priority_queue<pair<int, char>> pq;
map<pair<char, char>, int> cost;


void UniCostSearch(char st)
{
	pq.push(mp(0, st));
	int cnt = 0;
	while (pq.size() > 0)
	{
		pair<int, char> top = pq.top();
		pq.pop();
		vis[top.second] = 1;
		top.first *= -1;
		if (find(targets.begin(), targets.end(), top.second) != targets.end()) {

			// if a new goal is reached 
			if (ans[top.second] == INT_MAX)
				cnt++;

			// if the cost is less 
			if (ans[top.second] > top.first)
				ans[top.second] = top.first;

			// if all goals are reached 
			if (cnt == targets.size())
				return;
		}
		for each (auto it in Adjlist[top.second])
			pq.push(mp((top.first + cost[mp(top.second, it)]) * -1, it));

	}
	return;
}

int main()
{
	//number of edges
	cin >> n;
	//parent, child and cost from p -> c
	for (int i = 0; i < n; i++)
	{
		cin >> z >> t >> x;
		cost[mp(z, t)] = x;
		Adjlist[z].push_back(t);
	}
	//number of targets
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		targets.push_back(t);
		ans[t] = INT_MAX;
	}
	UniCostSearch('a');
	for (auto u : targets)
		printf("Path to %c = %d\n", u, ans[u]);
	cout << endl;
	return 0;
}