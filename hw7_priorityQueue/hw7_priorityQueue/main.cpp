#include <iostream>
#include <vector>

using namespace std;

int n;

struct prior{
    // things to do
    string to_do;
    // priority level
    int level;
};

prior h[1100000];

vector<string> ans;

int left(int i){
    return (2*i + 1);
}

int right(int i){
    return (2*i + 2);
}

int parent(int i){
    return ((i-1) / 2);
}

void maxHeapify(int i, int n){
    int l = left(i);
    int r = right(i);
    int largest;
    if(l < n && h[l].level > h[i].level){
        largest = l;
    }
    else{
        largest = i;
    }
    if(r < n && h[r].level > h[largest].level){
        largest = r;
    }
    if(largest != i){
        swap(h[i], h[largest]);
        maxHeapify(largest, n);
    }
    return;
}

void buildMaxHeap(int n){
    for(int i = n/2-1; i >= 0; i--){
        maxHeapify(i, n);
    }
}

void heapSort(int n){
    buildMaxHeap(n);
    ans.push_back(h[0].to_do);
    for(int i = n-1; i >= 0; i--){
        swap(h[0], h[i]);
        maxHeapify(0, i);
        ans.push_back(h[0].to_do);
        if(i == n-3){
            break;
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        // things to do
        cin >> h[i].to_do;
        // priority level
        cin >> h[i].level;
    }
    heapSort(n);
    cout << "First three things to do:" << endl;
    for(int i = 0; i < ans.size(); i++){
        // only need to print out first three things
        if(i >= 3){
            break;
        }
        cout << ans[i] << endl;
    }
}
