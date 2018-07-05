// https://www.hackerrank.com/challenges/ctci-bfs-shortest-reach/problem


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node {
  int val;
  node* left;
  node* right;
};

class Graph {
    node** listNodes;
    int lenNodes;
    const unsigned short COST = 6;

    public:
        Graph(int n) {
            this->listNodes = (node**) malloc(sizeof(node*) * n);
            this->lenNodes = n;

            // Fill the val value in the listNodes array
            for (int iterNode = 0; iterNode < n; ++iterNode) {
                this->listNodes[iterNode] = (node*) malloc(sizeof(node));
                // Node values start at one.
                this->listNodes[iterNode]->val = iterNode + 1;
                this->listNodes[iterNode]->right = NULL;
                this->listNodes[iterNode]->left = NULL;
            }
        }
    
        ~Graph() {
            for (int iterNode = 0; iterNode < this->lenNodes; ++iterNode) {
                free(this->listNodes[iterNode]);
            }
            free(this->listNodes);
        }
    
        void add_edge(int u, int v) {
            if (listNodes[u]->right == NULL) {
                listNodes[u]->right = listNodes[v];
            } else {
                listNodes[u]->left = listNodes[v];                
            }
        }

        vector<int> shortest_reach(int start) {
            vector<int> costs(this->lenNodes);

            if (start == -1)
                start = 0;

            node *head = this->listNodes[start];
            
            recursiveBFS(head, &costs, -6);

            // Remove the head from the costs array.
            for (int iterCost = 0; iterCost < this->lenNodes; ++iterCost) {
                if (costs[iterCost] == 0) {
                    costs[iterCost] = -1;   
                }
            }

            return costs;
        }
    
        void recursiveBFS(
            const node* currentNode, vector<int> *costs, const int previousCost
        ) {
            // Node value start at one but indexes start at 0.
            int costIndex = currentNode->val - 1;

            // Insert the cost in the cost array for the node value.
            (*costs)[costIndex] = previousCost + COST;

            // BFS right first
            if (currentNode->right != NULL) {
                recursiveBFS(currentNode->right, costs, costs->at(costIndex));
            }
            if (currentNode->left != NULL) {
                recursiveBFS(currentNode->left, costs, costs->at(costIndex));
            }
        }
    
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
		int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
		int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}

