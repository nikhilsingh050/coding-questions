/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/


Node* cloneGraph(Node* node) {

    if(node==nullptr)
        return nullptr;

    queue<Node*> q;
    q.push(node);

    Node* result = new Node(node->val,vector<Node*>());

    //mapping between original graph nodes and the copy graph nodes
    unordered_map<Node*,Node*> m;
    m.insert({node,result});

    while(!q.empty())
    {
        Node* node=q.front();
        q.pop();

        Node* newNode = m[node];
        for(Node* adj : node->neighbors)
        {
            //if the adj node is already created just push it to the neighbour
            if(m.find(adj)!=m.end())
            {
                newNode->neighbors.push_back(m[adj]);
                continue;
            }
            q.push(adj);
            //otherwise create new node corresponding to the adj node in hashtable and add it to the neighbor
            m[adj] = new Node(adj->val,vector<Node*>());
            newNode->neighbors.push_back(m[adj]);
        }
    }
    return result;
}
