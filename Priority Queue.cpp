#include <iostream>
using namespace std;

#define MAX_SIZE 5  

class PriorityQueue {
private:
    int arr[MAX_SIZE];  
    int size;           
    bool isMinHeap;     

public:
    PriorityQueue(bool minHeap) {
        size = 0;
        isMinHeap = minHeap;
    }

    void insert(int value) {
        if (size >= MAX_SIZE) {
            cout << "Queue is full!" << endl;
            return;
        }
        arr[size++] = value;  
        cout << "Inserted " << value << endl;
    }

    void deleteMinOrMax() {
        if (size == 0) {
            cout << "Queue is empty!" << endl;
            return;
        }

        int idx = 0;  
        for (int i = 1; i < size; i++) {
            if ((isMinHeap && arr[i] < arr[idx]) || (!isMinHeap && arr[i] > arr[idx])) {
                idx = i;
            }
        }

        cout << "Deleted " << arr[idx] << endl;

        for (int i = idx; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    void display() {
        if (size == 0) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int choice;
    cout << "Choose Queue Type:\n1. Min-Heap (Ascending)\n2. Max-Heap (Descending)\nEnter choice: ";
    cin >> choice;

    PriorityQueue pq(choice == 1);

    while (true) {
        cout << "\nMenu:\n1. Insert\n2. Delete Min/Max\n3. Display\n4. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            int val;
            cout << "Enter value: ";
            cin >> val;
            pq.insert(val);
        } else if (choice == 2) {
            pq.deleteMinOrMax();
        } else if (choice == 3) {
            pq.display();
        } else if (choice == 4) {
            cout << "Exiting...\n";
            break;
        } else {
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}