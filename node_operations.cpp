#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* next;
};

template <typename T>
void insert(Node<T>** root, const T item){
    Node<T>* temp = new Node<T>;
    temp->data = item;
    temp->next = *root;
    *root = temp;
}

template <typename T>
Node<T>* arrayToList(const T arr[], size_t size) {
    Node<T>* head = nullptr;
    for (int i = size-1; i >= 0; i--) {
        insert(&head, arr[i]);
    }

    return head;
}

template <typename T, typename Pred>
void removeBad(Node<T>*& head, Pred p) {
    if (head == nullptr) {
        return;
    }
    Node<T>* prev = nullptr;
    Node<T>* oldhead = head;
    prev = head;
    while (head != nullptr) {
        T gr = head->data;
        if (p(gr)) {
            if (oldhead == head) {
                oldhead = oldhead->next;
            }
            Node<T>* t = head;
            head = t->next;
            std::cout << "DEL " << t->data << "; ";
            delete (t);
            t = nullptr;
            if (prev != nullptr) {
                prev->next = head;
            }

            if (head != nullptr && head->next != nullptr) {
                prev = head;
            }
        } 
        else {
            prev = head;
            head = head->next;
        }
    }
    head = oldhead;
    std::cout << std::endl;
    
}

template <typename T>
void showList(const Node<T>* head) {
    
    if (head == nullptr) {
        std::cout << "Empty list";
    }

    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
        
    }
    std::cout << std::endl;
}

template <typename T>
void deleteList(Node<T>*& head) {
    while (head != nullptr) {
            std::cout << "deleting " << head->data << "; ";
            Node<T>* t = head->next;
            delete head;
            head = t;
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    size_t size = std::size(arr);
    Node<int>* head = arrayToList(arr, size);
    showList(head);
    removeBad(head, [](int n) {return n % 2 != 0;});
    showList(head);
    removeBad(head, [](int n) {return n < 5;});
    showList(head);
    removeBad(head, [](int n) {return n > 9;});
    showList(head);
    deleteList(head);
    showList(head);
}
