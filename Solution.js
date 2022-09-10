
/**
 * @param {number[]} sticks
 * @return {number}
 */
var connectSticks = function (sticks) {
    const {PriorityQueue} = require('@datastructures-js/priority-queue');
    const minHeap = new MinPriorityQueue({compare: (x, y) => x - y});//MinPriorityQueue<Number>
    for (let stick of sticks) {
        minHeap.enqueue(stick);
    }

    let costToConnectAllSticks = 0;
    while (minHeap.size() > 1) {
        let connectedStick = minHeap.dequeue() + minHeap.dequeue();
        costToConnectAllSticks += connectedStick;
        minHeap.enqueue(connectedStick);
    }
    return costToConnectAllSticks;
};
