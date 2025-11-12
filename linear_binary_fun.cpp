#include <iostream>
#include <algorithm> 
using namespace std;

const int MAX = 100;


bool linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return true;
    }
    return false;
}


bool binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1,mid;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return true;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

int main() {
    int rollNumbers[MAX], n, choice, searchKey;

    cout << "Enter number of students: ";
    cin >> n;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Linear Search (Random Order)\n";
        cout << "2. Binary Search (Sorted Order)\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
        	int i;
            cout << "\nEnter roll numbers in random order:\n";
            for (int i = 0; i < n; i++)
                cin >> rollNumbers[i];
            cout << "Enter roll number to search: ";
            cin >> searchKey;
            if (linearSearch(rollNumbers, n, searchKey))
                cout << "Student attended the training program.["<<i<<"]\n";
            else
                cout << "Student did NOT attend the training program.\n";
            break;

        case 2:
        	int mid;
            cout << "\nEnter roll numbers (they will be sorted automatically):\n";
            for (int i = 0; i < n; i++)
                cin >> rollNumbers[i];
            sort(rollNumbers, rollNumbers + n); // Correct usage of sort

            cout << "Enter roll number to search: ";
            cin >> searchKey;
            if (binarySearch(rollNumbers, n, searchKey))
                cout << "Student attended the training program.["<<mid<<"]\n";
            else
                cout << "Student did NOT attend the training program.\n";
            break;

        case 3:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 3);

    return 0;
}

