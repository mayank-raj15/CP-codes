//Name :- Mayank Raj
//Roll No :- 190001035
//Assignment :- 8 (Connecting the cities with roads)
//Date :- 07/05/2021

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//this graph will find and print the minimum cost roads to be built
vector<pair<int, int>> findMinimumCostGraph(vector<pair<int, int>> graph[], int vertices)
{
    //since we want to find roads with minimum cost, we use a minimum priority queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    //we start from the vertex 1
    int start = 1;

    //key will note the minimum distance of each node from a parent node with the key array
    vector<int> key(vertices + 1, INT_MAX);

    //this is where we store our final pairs of roads that we will construct
    //we use a pair to store the pairing index, as well as the cost
    vector<pair<int, int>> conPair(vertices + 1);

    //this boolean array will basically stop us from updating the already selected roads with minimum cost
    //since we are using priority queue, if we have picked a pair of cities with min cost road
    //then if again we will have to deal with same vertex, which was already included
    //we skip it
    vector<bool> inc(vertices + 1, false);

    //since we are starting from start(1) vertex, key(distance) = 0
    //we push the cost as 0 and vertex as start
    pq.push(make_pair(0, start));
    key[start] = 0;

    //we will continue to iterate through the queue, until it becomes empty
    while (!pq.empty())
    {
        //here we are picking the road with minimum cost and its one vertex
        int u = pq.top().second;

        //removing that element from queue, as we have stored it now
        pq.pop();

        //since, we have reached this vertex, we will include it in the tree
        inc[u] = true;

        //no we iterate through all adjacent cities of the current city
        for (auto i : graph[u])
        {
            //we select the vertex and cost of the road
            int v = i.first;
            int wt = i.second;

            //and if the vertex is not already selected,
            // and it's key value is greater than the current cost of road
            if (!inc[v] && key[v] > wt)
            {
                //we update the key value to current cost
                key[v] = wt;

                //now we insert this city in the queue
                pq.push(make_pair(key[v], v));

                //we store this pair, as it could possibly be a answer pair
                conPair[v] = {u, wt};
            }
        }
    }

    //finally we return the pairs of cities as an array
    return conPair;
}

int main()
{
    //taking the input
    int x, p, a, b, c;
    cin >> x >> p;

    //creating an array of vectors which will store the graph nodes and cost
    vector<pair<int, int>> graph[x + 1];

    //taking the p lines of possibly connected citites and creating a graph
    for (int i = 0; i < p; i++)
    {
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }

    //storing the answer pairs return from the function
    vector<pair<int, int>> conPair = findMinimumCostGraph(graph, x);

    //printing the vertices and minimum no. of roads
    cout << x << " " << x - 1 << "\n";

    //printing the city pairs and road cost
    for (int i = 2; i <= x; i++)
    {
        cout << conPair[i].first << " " << i << " " << conPair[i].second << "\n";
    }

    return 0;
}
