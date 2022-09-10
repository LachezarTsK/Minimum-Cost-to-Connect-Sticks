
import java.util.PriorityQueue;

public class Solution {

    public int connectSticks(int[] sticks) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        for (int stick : sticks) {
            minHeap.offer(stick);
        }

        int costToConnectAllSticks = 0;
        while (minHeap.size() > 1) {
            int connectedStick = minHeap.poll() + minHeap.poll();
            costToConnectAllSticks += connectedStick;
            minHeap.offer(connectedStick);
        }
        return costToConnectAllSticks;
    }
}
