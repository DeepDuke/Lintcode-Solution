/*
seqs表示了一个有向图（树），如果该有向图是个单链图，层序遍历每层都只有一个元素，而且与org的元素一对一相等，则可以重建成功。
用BFS遍历有向图做拓扑排序，即可得到一条重建的序列，要求重建结果唯一的话，则 重建过程中BFS层序遍历的时候每层只能有一个元素。
*/
class Solution {
public:
    /**
     * @param org: a permutation of the integers from 1 to n
     * @param seqs: a list of sequences
     * @return: true if it can be reconstructed only one or false
     */
    bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
        // write your code here
        if(seqs.size() == 0) return false;
        if(org.size() == 0 && seqs.size() == 1 && seqs[0].size() == 0) return true;
        if(org.size() != 0 && seqs.size() != 0 && seqs[0].size() == 0) return false;
        
        vector<vector<int> > graph(org.size()+1);
        vector<int> inDegree(org.size()+1, 0);
        vector<int> ans;
        // build graph
        for(int i = 0; i < seqs.size(); i++){
            vector<int> seq = seqs[i];
            for(int j = 0; j < seq.size()-1; j++){
                graph[seq[j]].push_back(seq[j+1]); 
                if(seq[j] > org.size() || seq[j+1] > org.size()) return false; // 越界
                inDegree[seq[j+1]]++;
            }
        }
        // bfs
        queue<int> q;
        for(int i = 1; i < inDegree.size(); i++){
            if(inDegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int levelSize = q.size();
            if(levelSize > 1) return false;
            int now = q.front();
            ans.push_back(now);
            q.pop();
            for(int i = 0; i < graph[now].size(); i++){
                if(--inDegree[graph[now][i]] == 0) q.push(graph[now][i]);
            }
        }
        if(ans.size() != org.size()) return false;
        for(int i = 0; i < org.size(); i++){
            if(ans[i] != org[i]) return false;
        }
        return true;
    }
};