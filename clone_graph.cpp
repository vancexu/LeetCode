/* 
lone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode*> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
        if (node == NULL) return NULL;
        
        // BFS
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> visited;
        queue<UndirectedGraphNode*> q; // only push unvisited node to q
        q.push(node);
        visited[node] = new UndirectedGraphNode(node->label);

        while (!q.empty()) {
            UndirectedGraphNode* front = q.front();
            q.pop();

            for (auto neighbor : front->neighbors) {
                if (visited.count(neighbor) == 0) {
                    visited[neighbor] = new UndirectedGraphNode(neighbor->label);
                    q.push(neighbor);
                }
                visited[front]->neighbors.push_back(visited[neighbor]);
            }
        }

        return visited[node];
    }
};

int main() {
    Solution sol;
    UndirectedGraphNode* node1 = new UndirectedGraphNode(1);
    UndirectedGraphNode* node2 = new UndirectedGraphNode(2);
    UndirectedGraphNode* node3 = new UndirectedGraphNode(3);
    vector<UndirectedGraphNode*> neis1 = {node2, node3};
    vector<UndirectedGraphNode*> neis2 = {node1, node3};
    vector<UndirectedGraphNode*> neis3 = {node3};
    node1->neighbors = neis1;
    node2->neighbors = neis2;
    node3->neighbors = neis3;
    UndirectedGraphNode* res = sol.cloneGraph(node1);
    for (auto n : res->neighbors) {
        cout << n->label << " ";
    }
    cout << endl;
}
