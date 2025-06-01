class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        vector<int> waitingTimes;

        //handle first customer
        waitingTimes.push_back(customers[0][1]);
        int currTime = customers[0][0] + customers[0][1];

        for(int i = 1; i < customers.size(); i++) {
            vector<int>& customer = customers[i];

            //Calculate time for customer
            int customerWaitTime;
            //if customer arrived when their order can be prepared immediately
            if(currTime < customer[0]) {
                customerWaitTime = customer[1]; //they only wait for their order
                currTime = customer[0] + customer[1]; //current time is their arrival plus prep time
            } else { //if customer waits for previous order before theirs
                customerWaitTime = (currTime + customer[1]) - customer[0];
                currTime += customer[1]; 
            }
            waitingTimes.push_back(customerWaitTime);
        }

        //Calculate average waiting time
        double avgWaitingTime = 0;
        for(int waitTime: waitingTimes) {
            avgWaitingTime += (double) waitTime / (double) waitingTimes.size();
        }

        return avgWaitingTime;
    }
};