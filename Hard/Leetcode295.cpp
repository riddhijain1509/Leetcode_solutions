class MedianFinder {
public:
    priority_queue<int> leftmaxheap;
    priority_queue<int, vector<int>, greater<int>> rightminheap; 

    MedianFinder() {
        
    }
    
    void addNum(int num) {
       
        if (leftmaxheap.empty() || num <= leftmaxheap.top()) {
            leftmaxheap.push(num);
        } else {
            rightminheap.push(num);
        }

        
        if (leftmaxheap.size() > rightminheap.size() + 1) {
            rightminheap.push(leftmaxheap.top());
            leftmaxheap.pop();
        } else if (rightminheap.size() > leftmaxheap.size()) {
            leftmaxheap.push(rightminheap.top());
            rightminheap.pop();
        }
    }
    
    double findMedian() {
        if (leftmaxheap.size() > rightminheap.size()) {
            return leftmaxheap.top();
        } else {
            return (leftmaxheap.top() + rightminheap.top()) / 2.0;
        }
    }
};
