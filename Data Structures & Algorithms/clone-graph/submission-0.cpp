/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // use bfs 
        if(!node){
            return nullptr;
        }
        map<Node*, Node*> visited;
        visited[node]=new Node(node->val);
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* cur=q.front();
            q.pop();
            for(Node* nei : cur->neighbors){
                if(!visited.count(nei)){
                    visited[nei]=new Node(nei->val);
                    q.push(nei);
                }
                visited[cur]->neighbors.push_back(visited[nei]);
            }
        }
        return visited[node];
    }
};
