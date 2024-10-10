#include <iostream>

using namespace std;

class linkedList{
    struct node{
        int value;
        node* next;
        node* previous;

        node(){
            value = 0;
            next = nullptr;
            previous = nullptr;
        }

    };

    node* head;
    node* tail;

    static int number_of_nodes;

public:

    linkedList(){
        head = nullptr;
        tail = nullptr;
        number_of_nodes++;
    }

    void appendNode(int);
    void displayList() const;
    void deleteNode(int);
    void insertNode(int, int);

    ~linkedList(){
        while (head){
            node* temp = head;
            head = head->next;
            delete temp;
        }
    }

};

int linkedList::number_of_nodes = 0;

int main() {
    linkedList list;
    list.appendNode(10);
    list.appendNode(20);
    list.appendNode(30);
    list.displayList();

    cout<<"\n10, 20, and 30 have been appended." << endl << endl;

    list.insertNode(11,1);  
    list.displayList();

    cout<<"\n11 has been inserted to the first position" << endl << endl;

    list.insertNode(7,3);
    list.displayList();

    cout<<"\n11 has been inserted to the third position" << endl << endl;

    list.deleteNode(2); 
    list.displayList();
    
    cout << "\nThe 2nd element has been deleted." << endl;

    return 0;
}


void linkedList::appendNode(int value){
    node *newNode = new node;
    newNode->value = value;

    if (!head){ head = newNode;}
    else{
        node* temp = head;
        while(temp->next){temp = temp->next;}
        temp->next = newNode;
        newNode->previous = temp;
        tail = newNode->next;
    }
    number_of_nodes++;
}

void linkedList::displayList() const{
    if (!head){cout << "Empty list.\n";}
    node* temp = head;
    while(temp){
        cout << temp->value << endl;
        temp = temp->next;
    }
}

void linkedList::insertNode(int number, int position){

    if (!head || position >= number_of_nodes){appendNode(number);}
    else if(position==1){
        node *newNode = new node;
        newNode->value = number;
        newNode->next = head;
        head->previous = newNode;
        head = newNode;
    }
    else{
        node *newNode = new node;
        newNode->value = number;
    
        node *temp = head;

        for (int i =1; i < position-1; i++){temp = temp->next;}
        newNode->next = temp->next;
        temp->next->previous = newNode;
        newNode->previous = temp;
        temp->next = newNode;
    }
}



void linkedList::deleteNode(int position){
    if (!head || position < 1 || position > number_of_nodes) {
        cout << "Nothing to delete" << endl;
        return;
    }

    node* temp = head;

    if (position == 1) { 
        head = temp->next;
        if (head) { head->previous = nullptr; } 
        else {tail = nullptr; }
        delete temp;
    } 
    else {
        node* pre = nullptr;
        for (int i = 1; i < position; i++) {
            pre = temp;
            temp = temp->next;
        }
        pre->next = temp->next;
        if (temp->next) { temp->next->previous = pre;}
         else {tail = pre;}
        delete temp;
    }
    number_of_nodes--;
}

