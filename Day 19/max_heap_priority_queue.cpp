#include <iostream>
#include <queue> // Include the <queue> header for priority_queue

int main() {
    // Declaration of a max-heap priority queue of integers
    std::priority_queue<int> maxHeapPQ;

    // Push elements into the max-heap priority queue
    maxHeapPQ.push(3);
    maxHeapPQ.push(1);
    maxHeapPQ.push(4);
    maxHeapPQ.push(1);
    maxHeapPQ.push(5);

    // Access the top element of the max-heap priority queue
    std::cout << "Top element: " << maxHeapPQ.top() << std::endl; // Output: 5

    // Pop the top element
    maxHeapPQ.pop();

    // Access the new top element
    std::cout << "Top element after pop: " << maxHeapPQ.top() << std::endl; // Output: 4

    return 0;
}
