/*
遍历节点，计算所有节点入度，用BFS进行拓扑排序。
*/
/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {
public:
    /*
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
        // write your code here
        vector<DirectedGraphNode*> result;
       unordered_map<DirectedGraphNode*, int> inDegree;
       for(const auto& node: graph){
           for(const auto& n: node->neighbors){
               inDegree[n]++;
           }
       }
       queue<DirectedGraphNode*> q;
       for(const auto& node: graph){
           if(inDegree[node] == 0) q.push(node);
       }
       while(!q.empty()){
           auto node = q.front();
           q.pop();
           result.push_back(node); // store the result
           for(const auto& n: node->neighbors){
               --inDegree[n];
               if(inDegree[n] == 0) q.push(n);
           }
       }
       return result;
    }
};