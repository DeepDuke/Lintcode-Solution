/*
用一个unordered_map来记录原图中被copy的node对应的新node,
对于copy的每个node，需要copy它的label和邻居关系，在进入队列之前，
先复制该node的label,进入队列之后，出队时复制邻居关系。代码中copied这个unordered_map里出现的，
说明已经复制了label,还需要进队出队复制邻居关系。
*/
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */


class Solution {
public:
    /*
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
        // write your code here
        if(!node) return nullptr;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> copied;
        copied[node] = new UndirectedGraphNode(node->label);
        queue<UndirectedGraphNode*> q;
        q.push(node);
        while(!q.empty()){
            auto now = q.front();
            q.pop();
            for(const auto& n: now->neighbors){
                if(copied.find(n) == copied.end()){
                    copied[n] = new UndirectedGraphNode(n->label);  // copy label
                    q.push(n); // all graph nodes enter queue for only once
                }
                copied[now]->neighbors.push_back(copied[n]); // copy relations
            }
        }
        return copied[node];
    }
};