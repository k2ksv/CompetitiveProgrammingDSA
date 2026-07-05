#include <iostream>

using namespace std;

class CustomArray {
private:
    int* data;      // Pointer to the actual array in memory (the "backing")
    int size;       // How many elements are currently in the array
    int capacity;   // How much total space is currently allocated

    // Private helper function to resize the array when it gets full
    void ensureCapacity() {
        if (size >= capacity) {
            // FIX: If capacity is 0, make it 1. Otherwise, double it!
            int new_capacity = (capacity == 0) ? 1 : capacity * 2;
            
            cout << "  [Resizing array from capacity " << capacity 
                 << " to " << new_capacity << "]\n";

            // 1. Ask the OS for a new, bigger array
            int* new_data = new int[new_capacity];

            // 2. Copy the old elements over
            for (int i = 0; i < size; i++) {
                new_data[i] = data[i];
            }

            // 3. Destroy the old array to prevent memory leaks!
            delete[] data;

            // 4. Point our class to the new array and update capacity
            data = new_data;
            capacity = new_capacity;
        }
    }

public:
    // Constructor: Called when you create a new CustomArray
    CustomArray() {
        capacity = 2; // Let's start with a small capacity of 2
        size = 0;
        data = new int[capacity];
    }

    // Destructor: Called automatically when the object is destroyed
    ~CustomArray() {
        delete[] data; // Cleans up the memory!
    }

    // Add an element to the end of the array
    void push_back(int value) {
        ensureCapacity(); // Make sure we have room first!
        data[size] = value;
        size++;
    }

    // Get an element at a specific index
    int get(int index) {
        if (index < 0 || index >= size) {
            cout << "Error: Index out of bounds!\n";
            return -1; 
        }
        return data[index];
    }

    // Get current size
    int getSize() {
        return size;
    }

    // Get current capacity
    int getCapacity() {
        return capacity;
    }

    // Print all elements
    void print() {
        cout << "Array contents: [ ";
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << "]\n";
    }
};

int main() {
    CustomArray arr;

    cout << "Initial state: Size=" << arr.getSize() << ", Capacity=" << arr.getCapacity() << "\n\n";

    cout << "Adding 10...\n";
    arr.push_back(10);
    
    cout << "Adding 20...\n";
    arr.push_back(20);
    
    cout << "Adding 30... (This will trigger a resize!)\n";
    arr.push_back(30); 
    
    cout << "Adding 40...\n";
    arr.push_back(40);
    
    cout << "Adding 50... (This will trigger another resize!)\n";
    arr.push_back(50);

    cout << "\nFinal state: Size=" << arr.getSize() << ", Capacity=" << arr.getCapacity() << "\n";
    arr.print();

    // Accessing an element
    cout << "\nElement at index 2 is: " << arr.get(2) << "\n";

    return 0; // When main finishes, arr's Destructor (~CustomArray) automatically runs!
}