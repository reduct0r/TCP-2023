#include <iostream>
using namespace std;

#ifndef MyStack_h           // защита от повторной компиляции
#define MyStack_h           // модуль подключен

// Шаблонный класс ListNode (узел односвязного списка)
template<class INF, class FRIEND>
class ListNode              // узел списка
{
private:
    INF d;                  // информационная часть узла
    ListNode* next;         // указатель на следующий узел списка
public:
    ListNode()              // конструктор
    {
        d = INF();
        next = nullptr;
    }

    friend FRIEND;
};
// Шаблонный класс MyStack на основе односвязного списка.
template<class INF>
class MyStack 
{
    typedef class ListNode<INF, MyStack<INF>> Node;
    Node* top;

public:
    MyStack() // конструктор
    {
        this->top = nullptr;
    } 

    MyStack(MyStack<INF>& currStack)
    {
        this->top = new Node;

        Node* head = this->top;
        Node* head2 = currStack.top;

        while (head2 != nullptr)
        {
            if (head2->next != nullptr)
            {
                head->next = new Node;
            }

            head->d = head2->d;

            head = head->next;
            head2 = head2->next;
        }
    }

    ~MyStack() // освободить динамическую память
    {
        while (!empty())
        {
            this->pop();
        }
    }

    bool empty() // стек пустой?
    {
        if (this->top == nullptr)
        {
            return true;
        }
        return false;
    }

    void push(INF n) // добавить узел в вершину стека
    {
        Node* newNode = new Node;
        newNode->d = n;
        newNode->next = this->top;
        this->top = newNode;
    }

    void pop()       // удалить узел из вершины стека
    {

        Node* tempNode = this->top->next;
        delete this->top;
        this->top = tempNode;
    }

    INF top_inf() // считать информацию из вершины стека
    {
        return this->top->d;
    }

    void PrintStack()
    {
        Node* tempNode = this->top;

        while (tempNode != nullptr)
        {
            //tempNode = this->top;
            cout << tempNode->d;
            if (tempNode->next != nullptr)
            {
                cout <<  " ";
            }
            tempNode = tempNode->next;
        }
        cout << endl;
    }

    void PrintStackM(int n)
    {
        Node* tempNode = this->top;
        std::cout << n << " = ";
        while (tempNode != nullptr)
        {
            //tempNode = this->top;
            cout << tempNode->d;
            if (tempNode->next != nullptr)
            {
                cout << " * ";
            }
            tempNode = tempNode->next;
        }
        cout << endl;
    }

    void PrintStackReverse()
    {
        if (this->empty())
        {
            return;                         //если стек пуст
        }

        auto bottomElement = this->top->d;   // Сохраняем верхний элемент стека
        this->pop();                        // Удаляем верхний элемент стека
        PrintStackReverse();                // Рекурсивно обрабатываем оставшийся стек
        cout << bottomElement << " ";       // Выводим сохраненный элемент
        this->push(bottomElement);          // Возвращаем удаленный элемент обратно в стек
    }

    void PrintStackReverseM(int n)
    {
        static bool flag = 1;
        if (flag) 
        {
            cout << n << " = ";
            flag = 0;
        }

        if (this->empty())
        {
            return;                         // если стек пуст
        }

        int bottomElement = this->top->d;   // Сохраняем верхний элемент стека
        this->pop();                        // Удаляем верхний элемент стека

        if (!this->empty())
        {
            PrintStackReverseM(n);            // Рекурсивно обрабатываем оставшийся стек
            cout << " * ";                  
        }

        cout << bottomElement;              // Выводим сохраненный элемент
        this->push(bottomElement);          // Возвращаем удаленный элемент обратно в стек
    }

    MyStack& operator=(MyStack& currStack)
    {
        if (this == &currStack) 
        {
            return *this;
        }

        // Освобождаем память, занимаемую текущим стеком
        while (!empty())
        {
            this->pop();
        }

        Node* head = this->top;
        Node* head2 = currStack.top;

        while (head2 != nullptr)
        {
            Node* newNode = new Node;
            newNode->d = head2->d;

            if (head == nullptr) 
            {
                this->top = newNode;
            }
            else 
            {
                head->next = newNode;
            }

            head = newNode;

            head2 = head2->next;
        }

        return *this;
    }
};

#endif

