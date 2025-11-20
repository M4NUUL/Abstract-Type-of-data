#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>

#include "array/array.h"
#include "double_list/double_list.h"
#include "linked_list/list.h"
#include "queue/queue.h"
#include "stack/stack.h"
#include "tree/tree.h"

using namespace std;

// --- Global Data Structures ---
MyArr arr;
MyList slist;
DList dlist;
Queue queue;
Stack stack;
CompleteBinaryTree tree;


// --- Data Save Functions (unchanged) ---
void saveData(const MyArr& arr)
{
    ofstream file("array.txt");
    for(int i=0; i< arr.size; i++)
    {
        file << arr.data[i] << endl;
    }
    cout << "Массив сохранен в array.txt" << endl;
}

void saveData(const MyList& list)
{
    ofstream file("slist.txt");
    for(Node* curr = list.head; curr; curr = curr ->next)
    {
        file << curr ->value << endl;
    }
    cout << "Односвязный список сохранен в slist.txt" << endl;
}
void saveData(const DList& list)
{
    ofstream file("dlist.txt");
    for(DNode* curr = list.head; curr; curr = curr->next)
    {
        file << curr ->value << endl;
    }
    cout << "Двусвязный список сохранен в dlist.txt" << endl;
}

void saveData(const Queue& q)
{
    ofstream file("queue.txt");
    for(QNode* curr = q.front; curr; curr = curr->next)
    {
        file << curr->data << endl;
    }
    cout << "Очередь сохранена в queue.txt" << endl;
}

void saveData(const Stack& stack)
{
    ofstream file("stack.txt");
    for(SNode* curr = stack.top; curr; curr = curr->next)
    {
        file << curr->value << endl;
    }
    cout << "Стек сохранен в stack.txt" << endl;
}

void saveData(const CompleteBinaryTree& tree)
{
    ofstream file("tree.txt");
    for(int i=0; i < tree.size; i++)
    {
        file << tree.arr[i] << endl;
    }
    cout << "Дерево сохранено в tree.txt" << endl;
}


// --- Data Load Functions (unchanged) ---
void loadData(MyArr& arr)
{
    ifstream file("arr.txt");
    string val;
    while(file >> val)
    {
        addEnd(arr,val);
    }
}
void loadData(MyList& list)
{
    ifstream file ("slist.txt");
    string val;
    while(file >> val)
    {
        addTail(list,val);
    }
}

void loadData(DList& list)
{
    ifstream file("dlist.txt");
    string val;
    while(file >> val)
    {
        addDTail(list,val);
    }
}

void loadData(Queue& q)
{
    ifstream file("queue.txt");
    string val;
    while(file >> val)
    {
        push(q,val);
    }
}

void loadData(Stack& stack) {
    ifstream file("stack.txt");
    string val;
    string full_content;
    while(getline(file, val)) { 
        full_content = val + "\n" + full_content; 
    }
    stringstream ss(full_content);
    while(getline(ss, val)) {
        if (!val.empty()) {
           push(stack, val); 
        }
    }
}

void loadData(CompleteBinaryTree& tree)
{
    ifstream file("tree.txt");
    string val;
    while(file >> val)
    {
        insert(tree, val);
    }
}

// --- Menu Functions ---

void arrayMenu() {
    int choice, index;
    string value;

    while (true) {
        cout << "\n=== МЕНЮ: МАССИВ ===\n"
             << "1. Добавить в конец\n"
             << "2. Добавить по индексу\n"
             << "3. Удалить по индексу\n"
             << "4. Получить по индексу\n"
             << "5. Заменить по индексу\n"
             << "6. Узнать длину\n"
             << "7. Показать массив\n"
             << "8. Сохранить в файл\n"
             << "0. Назад\n"
             << "> ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Строка для добавления: ";
                cin >> value;
                addEnd(arr, value);
                break;
            case 2:
                cout << "Индекс: "; cin >> index;
                cout << "Строка: "; cin >> value;
                addAt(arr, index, value);
                break;
            case 3:
                cout << "Индекс: "; cin >> index;
                delAt(arr, index);
                break;
            case 4:
                cout << "Индекс: "; cin >> index;
                getAt(arr, index);
                break;
            case 5:
                cout << "Индекс: "; cin >> index;
                cout << "Новая строка: "; cin >> value;
                repArr(arr, index, value);
                break;
            case 6:
                cout << "Длина массива: " << lenArr(arr) << endl;
                break;
            case 7:
                readArray(arr);
                break;
            case 8:
                saveData(arr);
                break;
            case 0:
                return;
            default:
                cout << "Неверный выбор!\n";
        }
    }
}

void singlyListMenu() {
    int choice;
    string value;

    while (true) {
        cout << "\n=== МЕНЮ: ОДНОСВЯЗНЫЙ СПИСОК ===\n"
             << "1. Добавить в начало\n"
             << "2. Добавить в конец\n"
             << "3. Добавить после значения\n"
             << "4. Добавить до значения\n"
             << "5. Удалить первый элемент\n"
             << "6. Удалить последний элемент\n"
             << "7. Удалить по значению\n"
             << "8. Найти по значению\n"
             << "9. Показать список\n"
             << "10. Сохранить в файл\n"
             << "0. Назад\n"
             << "> ";
        cin >> choice;

        switch (choice) {
            case 1: addHead(slist); break;
            case 2:
                cout << "Строка: "; cin >> value;
                addTail(slist, value);
                break;
            case 3: addAfter(slist); break;
            case 4: addBefore(slist); break;
            case 5: delHead(slist); break;
            case 6: delTail(slist); break;
            case 7:
                cout << "Строка для удаления: "; cin >> value;
                delByValue(slist, value);
                break;
            case 8:
                cout << "Строка для поиска: "; cin >> value;
                findValue(slist, value);
                break;
            case 9: readForward(slist); break;
            case 10: saveData(slist); break;
            case 0: return;
            default: cout << "Неверный выбор!\n";
        }
    }
}

void doublyListMenu() {
    int choice;
    string value;

    while (true) {
        cout << "\n=== МЕНЮ: ДВУСВЯЗНЫЙ СПИСОК ===\n"
             << "1. Добавить в начало\n"
             << "2. Добавить в конец\n"
             << "3. Добавить после значения\n"
             << "4. Добавить до значения\n"
             << "5. Удалить первый элемент\n"
             << "6. Удалить последний элемент\n"
             << "7. Удалить по значению\n"
             << "8. Найти по значению\n"
             << "9. Показать список\n"
             << "10. Сохранить в файл\n"
             << "0. Назад\n"
             << "> ";
        cin >> choice;

        switch (choice) {
            case 1: addHead(dlist); break;
            case 2:
                cout << "Строка: "; cin >> value;
                addDTail(dlist, value);
                break;
            case 3: addAfter(dlist); break;
            case 4: addBefore(dlist); break;
            case 5: delHead(dlist); break;
            case 6: delTail(dlist); break;
            case 7:
                cout << "Строка для удаления: "; cin >> value;
                delByVal(dlist, value);
                break;
            case 8:
                cout << "Строка для поиска: "; cin >> value;
                if(findValue(dlist,value)) cout << "Элемент найден\n"; 
                else cout << "Элемент не найден\n";
                break;
            case 9: readForward(dlist); break;
            case 10: saveData(dlist); break;
            case 0: return;
            default: cout << "Неверный выбор!\n";
        }
    }
}

void queueMenu() {
    int choice;
    string value;

    while (true) {
        cout << "\n=== МЕНЮ: ОЧЕРЕДЬ ===\n"
             << "1. Добавить в очередь\n"
             << "2. Извлечь из очереди\n"
             << "3. Прочитать первый элемент\n"
             << "4. Показать очередь\n"
             << "5. Сохранить в файл\n"
             << "0. Назад\n"
             << "> ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Строка: "; cin >> value;
                push(queue, value);
                break;
            case 2:
                cout << "Удален элемент: " << pop(queue) << endl;
                break;
            case 3:
                if(!isEmpty(queue)) cout << "Первый элемент: \"" << peek(queue) << "\"" << endl; 
                else cout << "Очередь пуста\n";
                break;
            case 4: print(queue); break;
            case 5: saveData(queue); break;
            case 0: return;
            default: cout << "Неверный выбор!\n";
        }
    }
}

void stackMenu() {
    int choice;
    string value;
    
    while (true) {
        cout << "\n=== МЕНЮ: СТЕК ===\n"
             << "1. Добавить в стек\n"
             << "2. Извлечь из стека\n"
             << "3. Прочитать верхний элемент\n"
             << "4. Показать стек\n"
             << "5. Сохранить в файл\n"
             << "0. Назад\n"
             << "> ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Строка: "; cin >> value;
                push(stack, value);
                break;
            case 2:
                cout << "Удален элемент: \"" << pop(stack) << "\"" << endl;
                break;
            case 3:
                if(stack.top) cout << "Верхний элемент: \"" << peek(stack) << "\"" << endl; 
                else cout << "Стек пуст\n";
                break;
            case 4: readStack(stack); break;
            case 5: saveData(stack); break;
            case 0: return;
            default: cout << "Неверный выбор!\n";
        }
    }
}

void treeMenu() {
    int choice;
    string value;

    while (true) {
        cout << "\nМЕНЮ: ДЕРЕВО\n"
             << "1. Вставить в дерево\n"
             << "2. Найти в дереве по значению\n"
             << "3. Проверить, является ли дерево полным\n"
             << "4. Показать дерево\n"
             << "5. Сохранить в файл\n"
             << "0. Назад\n"
             << "> ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Строка: "; cin >> value;
                insert(tree, value);
                break;
            case 2:
                cout << "Строка для поиска: "; cin >> value;
                {
                    int result = search(tree, value);
                    if (result != -1) cout << "Индекс элемента: " << result << endl;
                    else cout << "Элемент не найден." << endl;
                }
                break;
            case 3:
                cout << "Проверка: дерево " << (isComplete(tree) ? "является" : "не является") << " полным.\n";
                break;
            case 4: prettyPrint(tree); break;
            case 5: saveData(tree); break;
            case 0: return;
            default: cout << "Неверный выбор!\n";
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    

    initArray(arr);
    initList(slist);
    initList(dlist);
    init(queue);
    initStack(stack);
    init(tree, 8);

    loadData(arr);
    loadData(slist);
    loadData(dlist);
    loadData(queue);
    loadData(stack);
    loadData(tree);
    cout << "Данные из файлов загружены." << endl;

    int mainChoice;
    while (true) {
        cout << "\n=== ГЛАВНОЕ МЕНЮ ===\n"
             << "1. Массив\n"
             << "2. Односвязный список\n"
             << "3. Двусвязный список\n"
             << "4. Стек\n"
             << "5. Очередь\n"
             << "6. Полное бинарное дерево\n"
             << "0. Выход\n"
             << "Выберите структуру данных: ";
        cin >> mainChoice;

        switch (mainChoice) {
            case 1: arrayMenu(); break;
            case 2: singlyListMenu(); break;
            case 3: doublyListMenu(); break;
            case 4: stackMenu(); break;
            case 5: queueMenu(); break;
            case 6: treeMenu(); break;
            case 0:
                cout << "Очистка памяти и выход..." << endl;
                goto cleanup;
            default:
                cout << "Неверный выбор!" << endl;
        }
    }

cleanup:
    freeArr(arr);
    freeList(slist);
    clearList(dlist);
    clear(queue);
    clearStack(stack);
    destroy(tree);

    return 0;
}