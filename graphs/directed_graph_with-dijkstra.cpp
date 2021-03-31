/*
 * Implementation of directed graph with Dijkstra algorithm (lazy)
 * for finding the shortest path.
 * 
 * Example input:
 *   4 4
 *   1 2 1
 *   2 3 4
 *   2 1 2
 *   3 4 2
 *   1 4
 *   1 2 3 4 
 *   Summed Weights: 7
 */

#include <iostream>
#include <vector>
#include <queue> // For std::priority_queue
#include <limits> // For std::numeric_limits<double>::max()
#include <tuple>
using namespace std;

// Directed Edge Implementation
class Edge {
public:
	Edge(int v, int w, double weight): v(v), w(w), weight(weight) {}
	int from() { return v; }
	int to() { return w; }
	double getWeight() { return weight; }
private:
	int v, w;
	double weight;
};

// Directed Graph Implementation
class DirectedGraph {
public:
	DirectedGraph(int n): edges(n), numberOfNodes(n) {}
	void addEdge(Edge e) {
		int v = e.from();
		edges[v].push_back(e);
	}

	vector<Edge> adj(int v) {
		return edges[v];
	}
	int getNumberOfNodes() { return numberOfNodes; }
private:
	vector<vector<Edge>> edges;
	int numberOfNodes;
};


using int_double_pair_t = std::pair<int,double>;
struct pair_compar{
	bool operator()(int_double_pair_t a, int_double_pair_t b) {
		return a.second > b.second;
	}
};

tuple<vector<int>, vector<double>> dijkstra(DirectedGraph g, int s) {
	int n = g.getNumberOfNodes();
	vector<int> edgeTo(n, -1);
	vector<double> distTo(n, std::numeric_limits<double>::max() );
	distTo[s] = 0;
	priority_queue<int_double_pair_t, vector<int_double_pair_t>, pair_compar> pq;
	pq.push(make_pair(s, 0));

	while(!pq.empty()) {
		// Get the best pair (with the smallest second element)
		auto top = pq.top();
		pq.pop();
		int index = top.first;
		double minValue = top.second;
		if(distTo[index] < minValue) continue;
		for(auto edge: g.adj(index)) {
			// Relax: [-
			double newDist = distTo[index] + edge.getWeight();
			if(newDist < distTo[edge.to()]) {
				distTo[edge.to()] = newDist;
				edgeTo[edge.to()] = index;
				pq.push(make_pair(edge.to(), newDist));
			}
			// -]
		}
	}
	return make_tuple(edgeTo, distTo);
}

tuple<vector<int>, vector<double>> findShortestPath(DirectedGraph dg, int s, int e) {
	vector<int> edgeTo;
	vector<double> distTo;
	tie(edgeTo, distTo) = dijkstra(dg, s);

	vector<int> path, invertedPath;
	if(edgeTo[e] == -1) { return make_tuple(vector<int>(), vector<double>()); }

	// Getting the path (from destination to source)
	for(int i = e; i != s; i = edgeTo[i]) {
		path.push_back(i);
	}
	path.push_back(s);

	// Inverting the path (changing to it from source to destination)
	for(size_t i = 0; i < path.size(); i++) {
		invertedPath.push_back(path[path.size() - 1 - i]);
	}
	return make_tuple(invertedPath, distTo);
}

int main() {
	int n, m;
	cin >> n >> m;
	DirectedGraph dg(n);
	for (int i = 0; i < m; i++) {
		int x, y, w;
		std::cin >> x >> y >> w;
		dg.addEdge(Edge(x-1,y-1,w));
	}
	int s, e;
	cin >> s >> e;
	s--, e--;

	vector<int> edgeTo;
	vector<double> distTo;
	tie(edgeTo, distTo) = findShortestPath(dg, s, e);

	if(edgeTo.size() == 0 || distTo.size() == 0) {
		cout << "-1\n";
		return 0;
	}

	for(auto node: edgeTo) {
		cout << node+1 << " ";
	}
	cout << "\n";
	cout << "Summed Weight: " << distTo[e] << "\n";
}
