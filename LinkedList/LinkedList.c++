#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
class LinkedList {
    public:
    Node* head;
    Node* tail;
    LinkedList() {
        this->head = NULL;
        this->tail = NULL;
    }
    
    void insertAtHead(int data) {
        Node* newNode = new Node(data);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;       
            head = newNode;
        }
    }

    void insertAtTail(int data) {
        Node* newNode = new Node(data);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void Print() {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data;
            if(temp->next != NULL) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    LinkedList list;
    int n;
    int data;
    int choice;
    cout << "Enter choice: \n 1. Insert at Head \n 2. Insert at Tail \n 3. Print \n 4. Exit";
    while(choice != 4) {
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter the number of nodes: ";
                cin >> n;
                for(int i = 0; i < n; i++) {
                    cout << "Enter the data: ";
                    cin >> data;
                    list.insertAtHead(data);
                }
                break;
            case 2:
                cout << "Enter the number of nodes: ";
                cin >> n;
                for(int i = 0; i < n; i++) {
                    cout << "Enter the data: ";
                    cin >> data;
                    list.insertAtTail(data);
                }
                break;
            case 3:
                list.Print();
                break;
            case 4:
                exit(0);
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }
    list.Print();
    return 0;
}