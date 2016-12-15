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

void createCycle(Node * head, int withNode)
{
    Node * last = head;

    while (last->next)
    {
        last = last->next;
    }

    Node * startOfCycle = head;
    for (int i = 0; i < withNode; ++i)
    {
        startOfCycle = startOfCycle->next;
    }

    last->next = startOfCycle;
}

Node * next(Node * node, int step)
{
    for (int i = 0; i < step; ++i)
    {
        if (not node) return nullptr;
        node = node->next;
    }
    return node;
}

bool hasCycle(Node * head)
{
    Node * slowPointer = next(head, 1);
    Node * fastPointer = next(head, 2);

    while(fastPointer)
    {
        if ( slowPointer == fastPointer )
        {
            return true;
        }
        slowPointer = next(slowPointer, 1);
        fastPointer = next(fastPointer, 2);
    }
    return false;
}

int main()
{
    Node * firstList = nullptr;
    createList(&firstList, {1,2,3,4,5,6,7,8,9,10});

    std::cout << hasCycle(firstList) << std::endl;

    createCycle(firstList, 3);

    std::cout << hasCycle(firstList) << std::endl;

}
