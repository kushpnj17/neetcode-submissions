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
        if(!node) return nullptr;
        queue<pair<Node*, Node*>> q;
        unordered_map<int, Node*> visited;
        Node* clone = new Node(node->val);
        q.push({node, clone});
        visited[node->val] = clone;

        while(!q.empty()){
            auto p = q.front(); q.pop();
            Node* first = p.first;
            Node* second = p.second;

            for(auto n : first->neighbors){
                if(!visited.count(n->val)){
                    Node* c = new Node(n->val);
                    second->neighbors.push_back(c);
                    visited[n->val] = c;
                    q.push({n, c});
                } else {
                    second->neighbors.push_back(visited[n->val]);
                }
            }
        }

        return clone;
    }
};
