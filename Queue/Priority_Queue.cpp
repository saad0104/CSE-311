#include <bits/stdc++.h>
using namespace std;

int main() {
    
    // Creating priority queue
    priority_queue<int, vector<int>,
                    greater<int>> pq;
    pq.push(9);
    pq.push(8);
    pq.push(6);
    
    auto temp = pq;
    while(!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    return 0;
}
