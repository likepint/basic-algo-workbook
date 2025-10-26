#include "SinglyCircularLinkedList.h"

int main()
{
    SinglyCircularLinkedList<int> list;

    list.Append(1);
    list.Append(2);
    list.Prepend(0);
    list.Append(3); 
    list.Print(); // 0 -> 1 -> 2 -> 3 -> (Head)

    list.Delete(1);
    list.Print();  // 0 -> 2 -> 3 -> (Head)

    return 0;
}
