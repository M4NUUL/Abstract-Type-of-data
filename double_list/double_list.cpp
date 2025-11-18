#include "double_list.h"

void initList(DList &list)
{
    list.head = nullptr;
    list.tail = nullptr;
}


void addHead(DList &list)
{
    cout << "Введите значение";
    string val;
    cin >> val;

    DNode* node = new DNode{val, list.head, nullptr};

    if(list.head)
    {
        list.head->prev = node;
    }
    else
        list.tail = node;
    
    list.head = node;
}


void addDTail(DList &list, string val)
{

    DNode* node = new DNode{val, nullptr, list.tail};

    if(list.tail)
        list.tail->next = node;
    else
        list.head = node;
    
    list.tail = node;
}

void addBefore(DList &list)
{
    if(!list.head)
    {
        cout << "Список пуст" << endl;
        return;
    }

    cout << "Введите значение перед которым вставить: ";
    string target, val;
    cin >> target;

    cout <<"Введите новое значение";
    cin >> val;

    for(DNode* curr = list.head; curr; curr=curr->next)
    {
        if(curr->value == target)
        {
            DNode* node = new DNode{val, curr, curr->prev};
            if(curr->prev)
            {
                curr->prev->next = node;
            }
            else
                list.head = node;
            curr->prev = node;
            cout << "Элемент добавлен перед " << target << " не найден" << endl;
        }
    }
}


void addAfter(DList &list)
{
    if(!list.head)
    {
        cout << "Список пуст" << endl;
        return;
    }

    cout << "Введите значение после которого вставить: ";
    string target, val;
    cin >> target;
    cout << "Введите новое значение: ";
    cin >> val;

    for(DNode* curr = list.head; curr; curr=curr->next)
    {
        if(curr->value == target)
        {
            DNode* node = new DNode{val, curr->next, curr};
            if(curr->next)
            {
                curr->next->prev = node;
            }
            else
                list.tail = node;
            curr->next = node;
            cout << "Элемент добавлен после " << target << endl;
            return;
        }
    }
    cout << "Элемент " << target << " не найден" << endl;
}


void delHead(DList &list)
{
    if(!list.head)
    {
        cout << "Список пуст" << endl;
        return;
    }
    DNode* tmp = list.head;
    list.head = list.head->next;

    if(list.head)
        list.head->prev = nullptr;
    else
        list.tail = nullptr;
    
    delete tmp;
    cout << "Первый элемент удалён" << endl;
}

void delTail(DList &list)
{
    if(!list.tail)
    {
        cout << "Список пуст" << endl;
        return;
    }

    DNode* tmp = list.head;
    list.tail = list.tail->prev;

    if(list.tail)
        list.tail->next = nullptr;
    else
        list.head = nullptr;

    delete tmp;
    cout << "Первый элемент удалён";
}

void delByVal(DList &list, const string& val) {
    if(!list.head) {
        cout << "Список пуст." << endl;
        return;
    }
    DNode* curr = list.head;
    while(curr && curr->value != val) {
        curr = curr->next;
    }

    if (!curr) {
        cout << "Элемент " << val << " не найден." << endl;
        return;
    }

    if (curr->prev)
        curr->prev->next = curr->next;
    else
        list.head = curr->next;

    if (curr->next)
        curr->next->prev = curr->prev;
    else
        list.tail = curr->prev;

    delete curr;
    cout << "Элемент \"" << val << "\" удален." << endl;
}

DNode* findValue(const DList &list, const string& val) {
    for(DNode* curr = list.head; curr; curr = curr->next) {
        if(curr->value == val) {
            return curr;
        }
    }
    return nullptr;
}


void readForward(const DList &list)
{
    if(!list.head)
    {
        cout << "Список пуст" << endl;
        return;
    }

    cout << "Список вперед: ";
    for(DNode* curr = list.head; curr; curr = curr->next)
        cout << curr->value << " ";
    cout << endl;
}

void readBackward(const DList &list)
{
    if(!list.tail)
    {
        cout << "Список пуст" << endl;
        return;
    }

    cout << "Список назад: ";
    for(DNode* curr = list.tail; curr; curr= curr->prev)
    {
        cout << curr->value << " ";
    }
    cout << endl;
}

void clearList(DList &list)
{
    while(list.head)
    {
        DNode* tmp = list.head;
        list.head = list.head ->next;
        delete tmp;
    }
    list.tail = nullptr;
}

void delAfterValue(DList &list, const string& val) {
    DNode* targetNode = findValue(list, val);
    if (!targetNode || !targetNode->next) {
        cout << "Элемент '" << val << "' не найден или он последний." << endl;
        return;
    }
    DNode* nodeToDelete = targetNode->next;
    // Если удаляемый узел - хвост, обновляем хвост
    if (nodeToDelete == list.tail) {
        delTail(list);
    } else {
        targetNode->next = nodeToDelete->next;
        nodeToDelete->next->prev = targetNode;
        delete nodeToDelete;
    }
    cout << "Элемент после '" << val << "' удален." << endl;
}

void delBeforeValue(DList &list, const string& val) {
    DNode* targetNode = findValue(list, val);
    if (!targetNode || !targetNode->prev) {
        cout << "Элемент '" << val << "' не найден или он первый." << endl;
        return;
    }
    DNode* nodeToDelete = targetNode->prev;
    // Если удаляемый узел - голова, обновляем голову
    if (nodeToDelete == list.head) {
        delHead(list);
    } else {
        targetNode->prev = nodeToDelete->prev;
        nodeToDelete->prev->next = targetNode;
        delete nodeToDelete;
    }
     cout << "Элемент перед '" << val << "' удален." << endl;
}