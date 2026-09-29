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
        if(!node) return node;
        
        queue<pair<Node*, Node*>> q;
        unordered_map<int, Node*> created;
        Node *new_node = new Node();
        new_node->val = node->val;
        q.push({node, new_node});
        created[node->val] = new_node;

        while(!q.empty()){
            auto p = q.front(); q.pop();
            Node* original = p.first;
            Node* copy = p.second;

            for(int i = 0; i < original->neighbors.size(); i++){
                Node* n = original->neighbors[i];
                if(created.find(n->val) == created.end()){
                    Node* n_copy = new Node(n->val);
                    created[n->val] = n_copy;
                    copy->neighbors.push_back(n_copy);
                    q.push({n, n_copy});
                } else {
                    copy->neighbors.push_back(created[n->val]);
                }
            }
        }

        return new_node;
    }
};
