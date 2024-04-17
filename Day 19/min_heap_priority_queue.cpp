#include <iostream>
#include <queue> // Include the <queue> header for priority_queue

int main() {
    // Declaration of a min-heap priority queue of integers
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeapPQ;

    // Push elements into the min-heap priority queue
    minHeapPQ.push(3);
    minHeapPQ.push(1);
    minHeapPQ.push(4);
    minHeapPQ.push(1);
    minHeapPQ.push(5);

    // Access the top element of the min-heap priority queue
    std::cout << "Top element: " << minHeapPQ.top() << std::endl; // Output: 1

    // Pop the top element
    minHeapPQ.pop();

    // Access the new top element
    std::cout << "Top element after pop: " << minHeapPQ.top() << std::endl; // Output: 1

    return 0;
}
