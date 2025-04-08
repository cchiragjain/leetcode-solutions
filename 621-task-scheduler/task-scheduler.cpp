class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int totalTime = 0;

        // create frequency map
        unordered_map<char, int> freq;
        priority_queue<int> pq; // will store the task with the most frequency at top
        // it is best to pick the task with the most frequency first to efficiently distribute other tasks after this in the tasks cooldown perido

        for(char task: tasks){
            freq[task]++;
        }
        for(auto f: freq){
            pq.push(f.second); // dont really care about the order
        }
        
        while(!pq.empty()){
            vector<int> temp; // stores that levels uncompleted elements
            int cycle = n + 1; // in this segement say after picking A then need to complete n more tasks before we can pick A again
            // complete this cycle 
            while(cycle > 0 && !pq.empty()){
                int currentMaxFrequency = pq.top();
                pq.pop();

                currentMaxFrequency--;
                cycle--;
                totalTime++;

                if(currentMaxFrequency > 0){
                    // if this elements frequency still remains
                    temp.push_back(currentMaxFrequency);
                }
            }

            // if we had elements with remaining freq insert back into pq for use in next cycle
            for(int num: temp) pq.push(num);

            // if cycle length is remaining then that means no element present that can be used this should be used as idle time
            // also only add this if elements are present
            // since if pq is empty then that means everything was completed no need to add extra idle time
            if(!pq.empty()){
                totalTime += cycle;
            }            
        }

        return totalTime;
    }
};