
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;

#define mod 1000000007
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define pii pair<int, int>
#define vi vector<int>
#define fi first
#define se second
#define inf 1e18
#define sp(ans, pre) fixed << setprecision(pre) << y
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define all(x) x.begin(),x.end()
#define pb push_back
#define srt(v) sort(v.begin(), v.end())

struct Node
{
	string name, email;
	vector<Node*> children;
	Node(string name, string email)
	{
		this->name = name;
		this->email = email;
	}
};

unordered_map<string, bool> visited;
vector<pair<string, vector<string>>> ans;

void traverse(unordered_map<string, Node*> &graph, string curEmail)
{
	queue<Node *> q;
	Node *node = graph[curEmail];
	string name = node->name;
	vector<string> res;
	q.push(node);

	while (!q.empty())
	{
		Node *curNode = q.front();
		string email = curNode->email;
		visited[email] = true;
		res.push_back(email);
		q.pop();

		for (Node* child : curNode->children)
		{
			if (!visited[child->email])
				q.push(child);
		}
	}
	sort(res.begin(), res.end());
	ans.push_back(make_pair(name, res));

}

void solve()
{
	int n, k = 0;
	cin >> n;
	unordered_map<string, Node*> graph;
	for (int i = 0; i < n; i++)
	{
		string name, email1, email2;
		cin >> name;
		int cnt;
		cin >> cnt;
		cin >> email1;
		if (graph.find(email1) == graph.end())
		{
			graph[email1] = new Node(name, email1);
			visited[email1] = false;
		}
		cnt--;
		while (cnt--)
		{
			cin >> email2;
			if (graph.find(email2) == graph.end())
			{
				graph[email2] = new Node(name, email2);
				visited[email2] = false;
			}
			Node *node1 = graph[email1];
			Node *node2 = graph[email2];
			node1->children.push_back(node2);
			node2->children.push_back(node1);
			email1 = email2;
			k++;
		}
	}

	/*for(auto it:graph)
	{
	    cout<<it.first<<": ";
	    for(auto el:(it.second)->children)
	        cout<<el->email<<" ";
	    cout<<"\n";
	}*/

	for (auto el : graph)
	{
		if (!visited[el.first])
			traverse(graph, el.first);
	}


	sort(ans.begin(), ans.end());

	for (auto el : ans)
	{
		cout << el.first << " ";
		for (auto it : el.second)
			cout << it << " ";
		cout << "\n";
	}

}

int main()
{
	//for time calculation
#ifndef ONLINE_JUDGE
	auto start = chrono::steady_clock::now();
#endif

	send help
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// int t;
	// cin >> t;
	// while (t--)
	// {
	solve();
	// }

#ifndef ONLINE_JUDGE
	auto end = chrono::steady_clock::now();

	auto diff = end - start;

	cout << "\nTime taken: ";
	cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
#endif
}