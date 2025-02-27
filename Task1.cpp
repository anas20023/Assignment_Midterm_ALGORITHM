#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<int>max_heap;
priority_queue<int,vector<int>,greater<int>>min_heap;

void InsertToHeap(int n) {

    if (max_heap.empty() || n <= max_heap.top()) max_heap.push(n);
    else  min_heap.push(n);

    if (max_heap.size() > min_heap.size() + 1) {
        min_heap.push(max_heap.top());
        max_heap.pop();
    } else if (min_heap.size() > max_heap.size()) {
        max_heap.push(min_heap.top());
        min_heap.pop();
    }
}

void show_Median_Value() {
    if (max_heap.empty()) return;
    cout<<max_heap.top()<<" ";
    max_heap.pop();

    if (max_heap.size() < min_heap.size()) {
        max_heap.push(min_heap.top());
        min_heap.pop();
    }
}

int main() {

    while (cin >> n && n!=0) {
        if (n == -1) {
            show_Median_Value();
        } else {
            InsertToHeap(n);
        }
    }
    return 0;
}
