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
#include <numeric>
#include <functional>
#include <math.h>
#include <stdlib.h>

using namespace std;

const int N = 1e3 + 5;
int n, m, visD[N], visB[N], x, y;
vector<int> AdjList[N], ansD, ansB;
queue<int> q;

void DFSList(int v)
{
	visD[v] = 1;
	if (visD[n] == 1)
		return;
	ansD.push_back(v);
	for (auto u : AdjList[v])
		if (!visD[u])
			DFSList(u);
}

void BFSList(int v)
{
	visB[v] = 1;
	if (visB[n] == 1)
		return;
	ansB.push_back(v);
	for (auto u : AdjList[v])
		q.push(u);
	int f = q.front();
	q.pop();
	if(!visB[f])
		BFSList(f);
}
int main()
{
	printf("Target: ");
	cin >> n;
	printf("Number of Edges: ");
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		//inputer each edge as parent - child
		cin >> x >> y;
		AdjList[x].push_back(y);
		//if non-directed graph remove the comment from the next line
		//AdjList[y].push_back(x);
	}
	DFSList(1);
	BFSList(1);
	cout << "DFS Path: ";
	for (auto u : ansD)
		cout << u << " ";
	cout << endl;
	cout << "BFS Path: ";
	for (auto u : ansB)
		cout << u << " ";
	cout << endl;
	return 0;
}
