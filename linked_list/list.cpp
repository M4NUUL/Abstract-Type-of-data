#include <iostream>
#include "list.h"

using namespace std;

void initList(MyList &list)
{
    list.head = nullptr;
}

void freeList(MyList &list)
{
    Node* cur = list.head;
    while(cur != nullptr)
    {
        Node* tmp = cur;
        cur = cur->next;
        delete tmp;
    }
    list.head = nullptr;
}

void addHead(MyList &list)
{
    cout << "Введите значение: ";
    string val;
    cin >> val;

    Node* node = new Node{val, list.head};
    list.head = node;
}

//добавление в конец
void addTail(MyList &list, const string& val)
{

    Node* node = new Node{val, nullptr};
    if(!list.head)
    {
        list.head = node;
        return;
    }
    
    Node* cur = list.head; //указатель на узел
//проверка на узел, если есть (не нулевой указатель), то сдвигаем вперед
//идем пока не достигнем нулевого укзаателя(т.е конца)
    while(cur->next)
        cur = cur->next;
    cur->next=node;
}

void addBefore(MyList &list)
{
    if(!list.head)
    {
        cout << "Список пуст!" << endl;
        return;
    }

    string target, val;
    cout << "Введите значение, перед которым добавить: ";
    cin >> target;
    cout << "Введите новое значение: ";
    cin >> val;

    if(list.head -> value == target)
    {
        addHead(list);
        return;
    }

    Node* cur = list.head;
    while (cur->next && cur->next->value != target)
    {
        cur=cur->next;
    }

    if(!cur->next)
    {
        cout << "Элемент не найден"<< endl;
        return;
    }

    Node* node = new Node{val, cur->next};
    cur->next = node;
}

void addAfter(MyList &list)
{
    if(!list.head)
    {
        cout << "Список пуст" << endl;
        return;
    }
    string target, val;
    cout << "Введите значение, после которого добавить: ";
    cin >> target;
    cout << "Введите новое значение: ";
    cin >> val;

    Node* cur = list.head;
    while(cur && cur->value != target)
    {
        cur = cur->next;
    }
    if(!cur)
    {
        cout << "Элемент не найден" << endl;
        return;
    }

    Node* node = new Node{val, cur->next};
    cur->next = node;
}

void delTail(MyList &list)
{
    if(!list.head)
    {
        cout << "Список пуст" << endl;
        return;
    }
    if(!list.head->next)
    {
        delete list.head;
        list.head = nullptr;
        return;
    }

    Node* cur = list.head;
    while(cur->next->next)
        cur = cur->next;
    
    delete cur->next;
    cur->next = nullptr;
}

void delByValue(MyList &list, const string& val) {
    if(!list.head) {
        cout << "Список пуст." << endl;
        return;
    }
    if(list.head->value == val) {
        delHead(list);
        cout << "Элемент " << val << " удален." << endl;
        return;
    }
    Node* cur = list.head;
    while(cur->next && cur->next->value != val) {
        cur = cur->next;
    }
    if(!cur->next) {
        cout << "Элемент " << val << " не найден." << endl;
        return;
    }
    Node* tmp = cur->next;
    cur->next = tmp->next;
    delete tmp;
    cout << "Элемент " << val << " удален." << endl;
}

void findValue(const MyList &list, const string& val) {
    Node* curr = list.head;
    int p = 0;
    while(curr) {
        if(curr->value == val) {
            cout << "Элемент \"" << val << "\" найден на позиции: " << p << endl;
            return;
        }
        curr = curr->next;
        p++;
    }
    cout << "Элемент \"" << val << "\" не найден." << endl;
}
void readForward(const MyList &list)
{
    if(!list.head)
    {
        cout << "Список пуст" << endl;
        return;
    }
    cout << "Список вперёд";
    for(Node* curr = list.head; curr; curr= curr->next)
    {
        cout << curr->value << " ";
    }
    cout << endl;
}

void printBack(Node* node)
{
    if(!node)
        return;
    printBack(node->next);
    cout << node -> value << " ";
}

void readBack(const MyList &list)
{
    if(!list.head)
    {
        cout << "Список пуст" << endl;
        return;
    }
    cout << "Список (назад)";
    printBack(list.head);
    cout << endl;
}

void delHead(MyList &list) {
    if (!list.head) return;
    Node* tmp = list.head;
    list.head = list.head->next;
    delete tmp;
}

void delAfterValue(MyList &list, const string& val) {
    if (!list.head || !list.head->next) {
        cout << "Нечего удалять после элемента." << endl;
        return;
    }
    Node* cur = list.head;
    while(cur && cur->value != val) {
        cur = cur->next;
    }
    if (!cur || !cur->next) {
        cout << "Элемент '" << val << "' не найден или он последний." << endl;
        return;
    }
    Node* tmp = cur->next;
    cur->next = tmp->next;
    delete tmp;
    cout << "Элемент после '" << val << "' удален." << endl;
}


void delBeforeValue(MyList &list, const string& val) {
    if (!list.head || !list.head->next) {
        cout << "Нечего удалять перед элементом." << endl;
        return;
    }
    if (list.head->next->value == val) {
        delHead(list);
        cout << "Элемент перед '" << val << "' удален." << endl;
        return;
    }
    Node* cur = list.head;
    while(cur->next && cur->next->next && cur->next->next->value != val) {
        cur = cur->next;
    }
    if (!cur->next || !cur->next->next) {
        cout << "Элемент '" << val << "' не найден или перед ним нечего удалять." << endl;
        return;
    }
    Node* tmp = cur->next;
    cur->next = tmp->next;
    delete tmp;
    cout << "Элемент перед '" << val << "' удален." << endl;
}