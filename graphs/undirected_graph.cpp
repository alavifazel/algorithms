/* Graph implementation with Adjacent list (including connected compnents ranking)
 * Example input:
	6 6
	1 2
	2 3
	3 4
	4 5
	5 6
	2 3
	1 6
	s
	1	2	3	4	5	6	
 */

#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <queue>

using std::vector;
using std::queue;

class Graph {
private:
	std::vector<std::vector<int>> list;
	int numOfNodes, numOfEdges;

	// DFS
	void connections(int node, std::vector<bool> &visited, std::vector<int> &connectionsVector, int count) {
		visited[node] = true;
		connectionsVector[node] = count;
		for(int nextNode: list[node]) {
			if(!visited[nextNode]) {
				connections(nextNode, visited, connectionsVector, count);
			}
		}
	}

public:
    Graph(int n):
        list(n, std::vector<int>()),
		numOfNodes(n),
		numOfEdges(0) {}

	Graph(std::vector<std::vector<int>> list):
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

    // Uses DFS
	std::vector<int> connections() {
		std::vector<bool> visited(numOfNodes, false);
		std::vector<int> connectionsVector(numOfNodes);
		int count = 0;
		for(int i = 0; i < numOfNodes; i++) {
			if(!visited[i]){
				connections(i, visited, connectionsVector, count);
				count++;
			}
		}
		return connectionsVector;
	}

	// Uses BFS
	vector<int> shortestPath(int srcNode, int destNode) {
		srcNode -= 1;
		destNode -= 1;
		vector<bool> visited(numOfNodes, false);

		// The following vector keeps track of the parent of each node
		vector<int> parents(numOfNodes, -1);
		queue<int> q;
		visited[srcNode] = true;
		q.push(srcNode);
		while(!q.empty()) {
		    int tmpNode = q.front();
		    q.pop();
		    for(int neighboringNode: list[tmpNode]) {
		        if(!visited[neighboringNode]) {
		            q.push(neighboringNode);
		            visited[neighboringNode] = true;
		            parents[neighboringNode] = tmpNode;

		            if(neighboringNode == destNode) {
		                std::cout << "s\n";

				// Shortest Path Vector
		                vector<int> SPVec(0);
		                for(int i = neighboringNode; i != -1; i = parents[i]){

		                    SPVec.push_back(i + 1);
		                }

				// Inverting vector elements
				vector<int> invertedSPVec;
				for(int i = 0; i < SPVec.size(); i++) {
					invertedSPVec.push_back(SPVec[SPVec.size() - 1 - i]);
				}
		                return invertedSPVec;
		            }
		        }
		    }
		}
	}

    void addEdge(int v, int w) {
        if(v <= list.size() && w <= list.size()) {
            list[v - 1].push_back(w - 1);
            list[w - 1].push_back(v - 1);

        }
        else
            throw std::runtime_error("Invalid edge value");
    }

	int degree(int v) {
        int degreeCount = 0;
        for(int i = 0; i < list[v].size(); i++) {
            degreeCount++;
        }
        return degreeCount;
	}
};

int main() {
  size_t n, m, sNode, dNode;
  std::cin >> n >> m;
  Graph G(n);

  for (size_t i = 0; i < m + 1; i++) {
    int x, y;
    std::cin >> x >> y;
    if(i == m) {
        sNode = x;
        dNode = y;
    } else {
        G.addEdge(x, y);
    }
  }
    auto shortestPath = G.shortestPath(sNode, dNode);
    for(int i = 0; i < shortestPath.size(); i++) {
        std::cout << shortestPath[i] << "\t";
    }
    std::cout << "\n";

}
