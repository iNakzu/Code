#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <set>
#include <algorithm>

int main()
{
    std::array<int, 11> my_array;
    std::vector<int> my_vector;
    std::queue<int> my_queue;
    std::stack<int> my_stack;
    std::map<int, int> my_map;
    std::list<int> my_list;
    std::set<int> my_set;

    for (int i = 0; i < 11; i++)
    {
        my_array[i] = i;
        my_vector.push_back(i);
        my_queue.push(i);
        my_stack.push(i);
        my_map[i] = i;
        my_list.push_back(i);
        my_set.insert(i);
    }

    // Actualización
    my_array[5] = 50;
    my_vector[5] = 50;
    my_map[5] = 50;
    auto it_list = my_list.begin();
    std::advance(it_list, 5);
    *it_list = 50;
    my_set.erase(5);
    my_set.insert(50);

    // Inserción
    my_vector.push_back(100);
    my_queue.push(100);
    my_stack.push(100);
    my_map[100] = 100;
    my_list.push_back(100);
    my_set.insert(100);

    // Borrado
    my_vector.pop_back();
    my_queue.pop();
    my_stack.pop();
    my_map.erase(100);
    my_list.pop_back();
    my_set.erase(100);

    // Ordenación (solo para vector y list, los demás ya están ordenados o no soportan ordenación)
    std::sort(my_vector.begin(), my_vector.end());
    my_list.sort();

    std::cout << "Array: ";
    for (int i = 0; i < my_array.size(); i++)
    {
        std::cout << my_array[i] << " ";
    }
    std::cout << "\nVector: ";
    for (int i = 0; i < my_vector.size(); i++)
    {
        std::cout << my_vector[i] << " ";
    }
    std::cout << "\nQueue: ";
    while (!my_queue.empty())
    {
        std::cout << my_queue.front() << " ";
        my_queue.pop();
    }
    std::cout << "\nStack: ";
    while (!my_stack.empty())
    {
        std::cout << my_stack.top() << " ";
        my_stack.pop();
    }
    std::cout << "\nMap: ";
    for (int i = 0; i < my_map.size(); i++)
    {
        std::cout << my_map[i] << " ";
    }
    std::cout << "\nList: ";
    for (std::list<int>::iterator it = my_list.begin(); it != my_list.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\nSet: ";
    for (std::set<int>::iterator it = my_set.begin(); it != my_set.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}