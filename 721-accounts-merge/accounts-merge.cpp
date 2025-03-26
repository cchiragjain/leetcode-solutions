class DisjointSet{
    public:
        vector<int> rank;
        vector<int> parent;

    DisjointSet(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }

    int find(int node){
        if(parent[node] != node) parent[node] = find(parent[node]);
        return parent[node];
    }

    void unionByRank(int u, int v){
        int upu = find(u);
        int upv = find(v);
        if(upu == upv) return;
        if(rank[upu] < rank[upv]){
            parent[upu] = upv;
        } else if(rank[upv] < rank[upu]){
            parent[upv] = upu;
        } else{
            parent[upv] = upu;
            rank[upu]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);

        unordered_map<string, int> userIndexMailMap;
        vector<vector<string>> mergedMails(n);
        vector<vector<string>> result;

        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                int user = i;// the user position is referd to using its index in account
                string mail = accounts[i][j];

                if(userIndexMailMap.find(mail) == userIndexMailMap.end()){
                    // if not able to find in map then insert it
                    userIndexMailMap[mail] = i; // ex. johnsmith@mail.com is of user that is at index 0 in accounts array
                    // or mary@mail.com is of user which has index 2 in accounts array
                } else {
                    // if we are able to find then that means user with same mail already exists
                    // merge these 2 users together using dsu
                    ds.unionByRank(userIndexMailMap[mail], i);
                }
            }
        }

        for(auto it: userIndexMailMap){
            string mail = it.first;
            int userIndex = it.second;
            // store mails to the top user
            // ex. if john was found first then parent is 0 for both 0 and 1. they should be in the same list
            int userParent = ds.find(userIndex);
            mergedMails[userParent].push_back(mail);
        }

        for(int i = 0; i < mergedMails.size(); i++){
            if(mergedMails[i].size() == 0) continue; // this user was already covered through its paretn
            string user = accounts[i][0]; // this users name is stored here
            sort(mergedMails[i].begin(), mergedMails[i].end()); // sort this users mails
            vector<string> temp;
            temp.push_back(user);
            for(auto mail: mergedMails[i]){
                temp.push_back(mail);
            }
            result.push_back(temp);
        }

        return result;
    }
};