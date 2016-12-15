#include <iostream>
#include <vector>

struct Node
{
    Node(Node *_next, int _value) : value(_value), next(_next) {}
    int value;
    Node* next;
};

void destroy(Node* head)
{
    while (head)
    {
        Node * next = head->next;
        delete head;
        head = next;
    }
}

void addToEnd(Node **head, int value)
{
    if (*head == nullptr)
    {
        *head = new Node(nullptr, value);
        return;
    }

    Node * tmp = *head;
    while (tmp->next)
    {
        tmp = tmp->next;
    }
    tmp->next = new Node(nullptr, value);
}

void createList(Node **head, std::initializer_list<int> list)
{
    for (int value : list)
    {
        addToEnd(head, value);
    }
}

void print(Node* head)
{
    while (head)
    {
        std::cout << head->value << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

void zip (Node **firstList, Node **secondList, Node **zippedList)
{
    Node * firstListPointer  = *firstList;
    Node * secondListPointer = *secondList;

    while (firstListPointer && secondListPointer)
    {
        Node * tmpFirst = firstListPointer->next;
        Node * tmpSecond = secondListPointer->next;

        firstListPointer->next = secondListPointer;
        secondListPointer->next = tmpFirst;

        firstListPointer = tmpFirst;
        secondListPointer = tmpSecond;
    }

    *zippedList = *firstList;
    *firstList = nullptr;
    *secondList = nullptr;
}

int main()
{
    Node * firstList = nullptr;
    createList(&firstList, {1,2,3,4,5});
    Node * secondList = nullptr;
    createList(&secondList, {6,7,8,9,10});
    Node * zipped = nullptr;
    zip(&firstList, &secondList, &zipped);
    print(zipped);
}
