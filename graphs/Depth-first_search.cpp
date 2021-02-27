/* Graph implementation with Adjacent list (including connected compnents ranking)
 * Example input:
 *  5 3
 *  3 2
 *  1 2
 *  4 1
 *  # of connections: 2
 */

#include <iostream>
#include <vector>
#include <tuple>

using std::vector;
using std::pair;

class GraphAdjacentList {
private:
	std::vector<std::vector<int>> list;
	int numOfNodes, numOfEdges;
	void explore(int node, std::vector<bool> &visited, std::vector<int> &connections, int count) {
		visited[node] = true;
		connections[node] = count;
		for(int nextNode: list[node]) {
			if(!visited[nextNode]) {
				explore(nextNode, visited, connections, count);
			}
		}
	}

public:
	GraphAdjacentList(std::vector<std::vector<int>> list):
		list(list),
		numOfNodes(list.size()),
		numOfEdges(0)
	{
		size_t tmp;
		for(size_t i = 0; i < list.size(); i++) {
			tmp += list[i].size();
		}
		numOfEdges = tmp;
	}

	std::tuple<std::vector<bool>, std::vector<int>> explore() {
		std::vector<bool> visited(numOfNodes, false);
		std::vector<int> connections(numOfNodes);
		int count = 0;
		for(int i = 0; i < numOfNodes; i++) {
			if(!visited[i]){
				explore(i, visited, connections, count);
				count++;
			}
		}
		return std::make_tuple(visited, connections);
	}

};

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adjVec(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adjVec[x - 1].push_back(y - 1);
    adjVec[y - 1].push_back(x - 1);
  }

  GraphAdjacentList a(adjVec);
  auto tmp = a.explore();
  auto connections = std::get<1>(tmp);
  int numOfConnections = 0;
  for(size_t i = 0; i < connections.size(); i++) {
	  if(numOfConnections < connections[i])
		  numOfConnections = connections[i];

  }
  std::cout << "# of connections: " << numOfConnections + 1 << '\n';
}
