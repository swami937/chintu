#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    int prn;
    char name[50];
    Node* next;
};

class PinnacleClub {
private:
    Node* head;
    
public:
    PinnacleClub() {
        head = NULL;
    }
    
    void addPresident() {
        Node* newNode = new Node;
        cout << "Enter PRN: ";
        cin >> newNode->prn;
        cout << "Enter Name: ";
        cin >> newNode->name;
        
        newNode->next = head;
        head = newNode;
        cout << "President added successfully!\n";
    }
    
    void addMember() {
        Node* newNode = new Node;
        cout << "Enter PRN: ";
        cin >> newNode->prn;
        cout << "Enter Name: ";
        cin >> newNode->name;
        newNode->next = NULL;
        
        if (head == NULL) {
            head = newNode;
            cout << "Member added successfully!\n";
            return;
        }
        
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        
        Node* prev = temp;
        prev->next = newNode;
        newNode->next = NULL;
        
        cout << "Member added successfully!\n";
    }
    
    void addSecretary() {
        Node* newNode = new Node;
        cout << "Enter PRN: ";
        cin >> newNode->prn;
        cout << "Enter Name: ";
        cin >> newNode->name;
        newNode->next = NULL;
        
        if (head == NULL) {
            head = newNode;
            cout << "Secretary added successfully!\n";
            return;
        }
        
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        cout << "Secretary added successfully!\n";
    }
    
    void deletePresident() {
        if (head == NULL) {
            cout << "Club is empty!\n";
            return;
        }
        
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "President deleted successfully!\n";
    }
    
    void deleteMember() {
        if (head == NULL) {
            cout << "Club is empty!\n";
            return;
        }
        
        int prn;
        cout << "Enter PRN of member to delete: ";
        cin >> prn;
        
        if (head->prn == prn) {
            cout << "Cannot delete president using this option!\n";
            return;
        }
        
        Node* temp = head;
        Node* prev = NULL;
        
        while (temp != NULL && temp->next != NULL && temp->prn != prn) {
            prev = temp;
            temp = temp->next;
        }
        
        if (temp == NULL || temp->prn != prn) {
            cout << "Member not found!\n";
            return;
        }
        
        if (temp->next == NULL) {
            cout << "Cannot delete secretary using this option!\n";
            return;
        }
        
        prev->next = temp->next;
        delete temp;
        cout << "Member deleted successfully!\n";
    }
    
    void deleteSecretary() {
        if (head == NULL) {
            cout << "Club is empty!\n";
            return;
        }
        
        if (head->next == NULL) {
            delete head;
            head = NULL;
            cout << "Secretary deleted successfully!\n";
            return;
        }
        
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        
        delete temp->next;
        temp->next = NULL;
        cout << "Secretary deleted successfully!\n";
    }
    
    int countMembers() {
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    
    void display() {
        if (head == NULL) {
            cout << "Club is empty!\n";
            return;
        }
        
        cout << "\n--- Pinnacle Club Members ---\n";
        cout << "PRN\tName\t\tPosition\n";
        cout << "------------------------------------\n";
        
        Node* temp = head;
        int pos = 1;
        int total = countMembers();
        
        while (temp != NULL) {
            cout << temp->prn << "\t" << temp->name << "\t\t";
            
            if (pos == 1)
                cout << "President";
            else if (pos == total)
                cout << "Secretary";
            else
                cout << "Member";
            
            cout << endl;
            temp = temp->next;
            pos++;
        }
    }
};

int main() {
    PinnacleClub club;
    int choice;
    
    do {
        cout << "\n=== Pinnacle Club Menu ===\n";
        cout << "1. Add President\n";
        cout << "2. Add Member\n";
        cout << "3. Add Secretary\n";
        cout << "4. Delete President\n";
        cout << "5. Delete Member\n";
        cout << "6. Delete Secretary\n";
        cout << "7. Display Members\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                club.addPresident();
                break;
            case 2:
                club.addMember();
                break;
            case 3:
                club.addSecretary();
                break;
            case 4:
                club.deletePresident();
                break;
            case 5:
                club.deleteMember();
                break;
            case 6:
                club.deleteSecretary();
                break;
            case 7:
                club.display();
                break;
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 8);
    
    return 0;
}
