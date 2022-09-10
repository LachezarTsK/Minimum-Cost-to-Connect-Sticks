
#include <queue>
#include <vector>
using namespace std;

class Solution {
    
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<>> minHeap;
        for (const auto& stick : sticks) {
            minHeap.push(stick);
        }

        int costToConnectAllSticks = 0;
        while (minHeap.size() > 1) {
            int connectedStick = removeAndReturnTop(minHeap) + removeAndReturnTop(minHeap);
            costToConnectAllSticks += connectedStick;
            minHeap.push(connectedStick);
        }
        return costToConnectAllSticks;
    }

private:
    int removeAndReturnTop(priority_queue<int, vector<int>, greater<>>& minHeap) {
        int top = minHeap.top();
        minHeap.pop();
        return top;
    }
};
