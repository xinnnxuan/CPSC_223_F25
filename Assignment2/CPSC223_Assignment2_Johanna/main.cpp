#include "LinkedList.h"
#include <iostream>

int main() {
    LinkedList<int> list;
    list.insert(5);
    list.insert(10);
    list.insert(15);
    list.display();
    list.remove(10);
    list.display();
    std::cout << "Is 15 in the list? " << (list.search(15) ? "Yes" : "No") << std::endl;
    std::cout << "Is 10 in the list? " << (list.search(10) ? "Yes" : "No") << std::endl;

    return 0;
}
