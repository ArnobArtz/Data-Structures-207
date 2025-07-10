#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int d) {
        data = d;
        next = NULL;
    }
};

class SLL {
    node* head;

public:
    SLL() {
        head = NULL;
    }

    void push_front(int d) {
        node* newnode = new node(d);
        newnode->next = head;
        head = newnode;
    }

    void push_back(int d) {
        node* newnode = new node(d);
        if (head == NULL) {
            head = newnode;
            return;
        }
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    void pop_front() {
        if (head == NULL) {
            cout << "No data\n";
            return;
        }
        node* temp = head;
        head = temp->next;
        delete temp;
    }

    void pop_back() {
        if (head == NULL) {
            cout << "No data.\n";
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    void insert_anypos(int d, int pos) {
        if (pos <= 0) {
            cout << "Invalid Position\n";
            return;
        }
        if (pos == 1) {
            push_front(d);
            return;
        }
        node* temp = head;
        for (int i = 1; temp != NULL && i < pos - 1; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            push_back(d);
            return;
        }
        node* newnode = new node(d);
        newnode->next = temp->next;
        temp->next = newnode;
    }

    void display() {
        node* temp = head;
        if (head == NULL) {
            cout << "No data\n";
            return;
        }
        cout << "The items in the list are:\n";
        while (temp != NULL) {
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << endl;
    }

    void search(int d) {
        node* temp = head;
        while (temp != NULL) {
            if (temp->data == d) {
                cout << "Searched item found\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Item not found\n";
    }

    int size() {
        int size = 0;
        node* temp = head;
        while (temp != NULL) {
            size++;
            temp = temp->next;
        }
        return size;
    }

    bool contains(int data) {
        node* temp = head;
        while (temp != NULL) {
            if (temp->data == data)
                return true;
            temp = temp->next;
        }
        return false;
    }

    bool isEmpty() {
        return head == NULL;
    }

    void remove_any_node(int pos) {
        if (head == NULL) {
            cout << "No Data\n";
            return;
        }
        if (pos <= 0) {
            cout << "Invalid Position\n";
            return;
        }
        if (pos == 1) {
            pop_front();
            return;
        }
        node *temp1 = head, *temp = head->next;
        int i = 2;
        while (temp != NULL && i < pos) {
            temp1 = temp;
            temp = temp->next;
            i++;
        }
        if (temp == NULL) {
            cout << "Invalid Position\n";
            return;
        }
        temp1->next = temp->next;
        delete temp;
    }

    int get(int pos) {
        if (pos <= 0) {
            cout << "Invalid Position\n";
            return -1;
        }
        node* temp = head;
        int i = 1;
        while (temp != NULL && i < pos) {
            temp = temp->next;
            i++;
        }
        if (temp == NULL) {
            cout << "Position is not there\n";
            return -1;
        }
        return temp->data;
    }

    void reverse() {
        node* prev = NULL, *curr = head, *next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void sortList() {
        if (head == NULL) return;

        bool swapped;
        node* ptr1;
        node* lptr = NULL;

        do {
            swapped = false;
            ptr1 = head;

            while (ptr1->next != lptr) {
                if (ptr1->data > ptr1->next->data) {
                    int temp = ptr1->data;
                    ptr1->data = ptr1->next->data;
                    ptr1->next->data = temp;
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }
};

int main() {
    SLL ll;
    int choice, val;

    do {
        cout << "\n MENU \n";
        cout << "0. Exit\n";
        cout << "1. Push front\n";
        cout << "2. Push Back\n";
        cout << "3. Size of Linked List\n";
        cout << "4. Pop front\n";
        cout << "5. Pop Back\n";
        cout << "6. Display the linked list\n";
        cout << "7. Insert data at any position\n";
        cout << "8. Remove data from any position\n";
        cout << "9. See if the data is in the list\n";
        cout << "10. Check a particular position\n";
        cout << "11. Check if the list is Empty\n";
        cout << "12. Reverse the list\n";
        cout << "13. Sort the list (ascending)\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 0:
            cout << "Exiting from the Program\n";
            break;
        case 1:
            cout << "Enter the value: ";
            cin >> val;
            ll.push_front(val);
            break;
        case 2:
            cout << "Enter the value: ";
            cin >> val;
            ll.push_back(val);
            break;
        case 3:
            cout << "The size of the linked list is: " << ll.size() << endl;
            break;
        case 4:
            ll.pop_front();
            break;
        case 5:
            ll.pop_back();
            break;
        case 6:
            ll.display();
            break;
        case 7: {
            cout << "Enter the value: ";
            cin >> val;
            int pos;
            cout << "Enter the position: ";
            cin >> pos;
            ll.insert_anypos(val, pos);
            break;
        }
        case 8: {
            int position;
            cout << "Enter the position to delete: ";
            cin >> position;
            ll.remove_any_node(position);
            break;
        }
        case 9: {
            int item;
            cout << "Enter the item to check: ";
            cin >> item;
            cout << (ll.contains(item) ? "Found\n" : "Not Found\n");
            break;
        }
        case 10: {
            int position;
            cout << "Enter the position: ";
            cin >> position;
            int value = ll.get(position);
            if (value != -1) cout << "Value: " << value << endl;
            break;
        }
        case 11:
            cout << (ll.isEmpty() ? "List is empty\n" : "List is not empty\n");
            break;
        case 12:
            ll.reverse();
            ll.display();
            break;
        case 13:
            ll.sortList();
            cout << "Sorted List: ";
            ll.display();
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
