#include <iostream>
#include <queue>

using namespace std;

int main() {
  int n, shout[100000];
  priority_queue<int> maxHeap, minHeap;

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> n;

  for (int i = 0; i < n; i++) cin >> shout[i];

  for (int i = 0; i < n; i++) {
    if(maxHeap.size() == minHeap.size()) maxHeap.push(shout[i]);
    else minHeap.push(-shout[i]);

    if(!minHeap.empty() && !maxHeap.empty() && minHeap.top() > -maxHeap.top()) {
      int a = maxHeap.top(), b = -minHeap.top();
      maxHeap.pop();
      minHeap.pop();
      maxHeap.push(b);
      minHeap.push(-a);
    }

    cout << maxHeap.top() << endl;
  }


  return 0;
}
