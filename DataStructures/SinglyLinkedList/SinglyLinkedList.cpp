#include "SinglyLinkedList.h"

int main()
{
    cout << "Singly Linked List:" << endl;

    SinglyLinkedList<int> list;

    list.Append(1);
    list.Append(2);
    list.Prepend(0);
    list.Print(); // 0 -> 1 -> 2 -> nullptr

    list.Delete(1);
    list.Print(); // 0 -> 2 -> nullptr

    return 0;
}
