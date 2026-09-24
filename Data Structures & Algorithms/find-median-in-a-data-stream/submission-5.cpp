class MedianFinder {
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.size() == right.size()){
            left.push(num);
        } else {
            right.push(num);
        }

        if(!right.empty() && right.top() < left.top()){
            int temp = right.top();
            int temp1 = left.top();
            left.pop();
            right.pop();

            left.push(temp);
            right.push(temp1);
        }
    }
    
    double findMedian() {
        if(left.size() == right.size()){
            return static_cast<double>(left.top() + right.top()) / 2;
        } else if (left.size() > right.size()){
            return left.top();
        } else {
            return right.top();
        }
    }
};
