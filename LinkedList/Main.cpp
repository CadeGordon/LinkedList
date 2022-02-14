#include "List.h"


int main()
{
    List<int> list = List<int>();
    list.pushBack(2);
    list.pushFront(1);
    list.pushFront(12);
    list.pushBack(15);
    list.pushBack(14);
    list.insert(200, 5);
    list.insert(149, 0);
    list.remove(200);
    list.remove(149);
    list.sort();

    list.print();

    std::cout << " " << std::endl;

    list.destroy();
    list.destroy();
    list.insert(10, 0);
    list.insert(45, 1);
    list.pushBack(47);
    list.print();

    std::cout << " " << std::endl;

    List<int> listTwo = List<int>();

    listTwo = list;

    list.destroy();

    listTwo.pushFront(88);

    listTwo.print();
}