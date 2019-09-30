class Solution {
public:
    /*
     * @param start: a string
     * @param end: a string
     * @param dict: a set of string
     * @return: An integer
     */
    int ladderLength(string &start, string &end, unordered_set<string> &dict) {
        // write your code here
        if(start == end) return 1;
    
        queue<string> q;
        q.push(start);
        int length = 1;
        
        while(!q.empty()){
            int size = q.size();
            length++;
            for(int i = 0; i < size; i++){  // for each word
                auto now = q.front(); 
                q.pop();
                for(int j = 0; j < now.size(); j++){ // for each char of each word
                    char lastChar = now[j];
                    for(int ch = 'a'; ch <= 'z'; ch++){ // substitue each char for each char of each word
                        if(ch == lastChar) continue;
                        now[j] = ch;
                        if(now == end) return length;  // can reach end
                        if(dict.find(now) != dict.end()){
                            q.push(now);
                            dict.erase(now);
                        }
                    }
                    now[j] = lastChar;
                }
                
            }
        }
        return 0;
    }
};