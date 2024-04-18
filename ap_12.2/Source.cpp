#include <iostream>

struct Elem
{
    Elem* link;
    int info;
};

typedef int Info;

void enqueue(Elem*& first, Elem*& last, Info value)
{
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->link = NULL;
    if (last != NULL)
        last->link = tmp;
    last = tmp;
    if (first == NULL)
        first = tmp;
}

Info dequeue(Elem*& first, Elem*& last)
{
    Elem* tmp = first->link;
    Info value = first->info;
    delete first;
    first = tmp;
    if (first == NULL)
        last = NULL;
    return value;
}

int count(Elem* L, Info value)
{
    int cnt = 0;
    while (L != NULL)
    {
        if (L->info == value)
        {
            cnt++;
        }
        L = L->link;
    }
    return cnt;
}

void removeValue(Elem*& first, Elem*& last, Info value)
{
    Elem* current = first;
    Elem* previous = NULL;

    while (current != NULL)
    {
        if (current->info == value)
        {
            if (previous == NULL)
            {
                first = current->link;
                delete current;
                current = first;
                if (first == NULL)
                    last = NULL;
            }
            else
            {
                previous->link = current->link;
                if (current == last)
                    last = previous;
                delete current;
                current = previous->link;
            }
        }
        else
        {
            previous = current;
            current = current->link;
        }
    }
}

void printList(Elem* L)
{
    while (L != NULL)
    {
        std::cout << L->info << " ";
        L = L->link;
    }
    std::cout << std::endl;
}

int main()
{
    Elem* first = NULL;
    Elem* last = NULL;

    for (int i = 1; i <= 10; i++)
        enqueue(first, last, i);

    std::cout << "List: ";
    printList(first);

    Info x;
    std::cout << "Element to delete: ";
    std::cin >> x;

    removeValue(first, last, x);

    std::cout << "List 2: ";
    printList(first);

    return 0;
}
