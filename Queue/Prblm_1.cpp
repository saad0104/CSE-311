// // // // **** Using Queue + Stack STL

// #include <iostream>
// #include <queue>
// #include <stack>
// #include <sstream>
// using namespace std;

// // void reverseTextUsingQueue(string sentence) {
// //     queue<string> q;
// //     stack<string> s;
// //     stringstream ss(sentence);
// //     string word;

// //     // Enqueue q into the queue
// //     while (ss >> word) {
// //         q.push(word);
// //     }

// //     // Move q from queue to stack to reverse order
// //     while (!q.empty()) {
// //         s.push(q.front()); // Push front of queue into stack
// //         q.pop(); // Remove from queue
// //     }

// //     // Print q from stack (LIFO order gives reversed q)
// //     while (!s.empty()) {
// //         cout << s.top() << " ";
// //         s.pop();
// //     }
// //     cout << endl;
// // }


// // //  *** Using only Queue STL + string

// string reverseOnlyQueue(string str)
// {
//     string ans;
//     queue<string> q;
//     stringstream ss(str);
//     string s;

//     while (ss >> s)
//     {
//         // q.push(s);
//         q.push(s);
//     }
//     while (!q.empty())
//     {
//         ans = q.front() + " " + ans;
//         q.pop();
//     }
//     return ans;
// }

// int main()
// {
//     string sentence = "Technical Interview Preparation";
//     // reverseTextUsingQueue(sentence);
//     cout << reverseOnlyQueue(sentence);
//     return 0;
// }





//    ******* Using Array Implementation

#include <iostream>
#include <sstream>
using namespace std;

class Queue {
private:
    string* arr;
    int front;
    int rear;
    int capacity;
    int count;

public:
    Queue(int size) {
        capacity = size;
        arr = new string[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    Queue() {
        delete[] arr;
    }

    void enqueue(string value) {
        if (isFull()) {
            cout << "Queue Overflow" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        count++;
    }

    string dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return ""; 
        }
        string value = arr[front];
        front = (front + 1) % capacity;
        count--;
        return value;
    }

    string peek() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return "";
        }
        return arr[front];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }
};

string reverseWords(string input) {
    stringstream ss(input);
    string word;
    int wordCount = 0;

    // Count words to determine queue size
    stringstream ss_count(input);
    while (ss_count >> word) {
        wordCount++;
    }

    Queue words(wordCount);

    // Enqueue words
    stringstream ss_enqueue(input);
    while (ss_enqueue >> word) {
        words.enqueue(word);
    }

    // Build reversed string
    string reversedString = "";
    while (!words.isEmpty()) {
        reversedString = words.dequeue() + (reversedString.empty() ? "" : " ") + reversedString;
    }

    return reversedString;
}

int main() {
    string input = "Technical Interview Preparation";
    string output = reverseWords(input);
    cout << "Input: " << input << endl;
    cout << "Output: " << output << endl;
    return 0;
}