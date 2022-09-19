#include <iostream>
#include <functional>
#include <algorithm>
#include <list>



int main(int argc, const char* argv[]) {


    // Declare a simple lambda
    auto lambda = [](int x, int y) {
        return x + y;
    };

    std::cout << "result: " << lambda(3, 4) << std::endl;

    // We can also assign lambda to function object
    std::function<int(int, int)> f = lambda;


    // Use lambda with std::sort
    auto absSort = [](int a, int b){
        return std::abs(a) < std::abs(b);
    };
    int arr[10];
    for (int i = 0; i < 10; ++i) {
        arr[i] = rand() % 10;
    }

    std::sort(arr, arr + 10, absSort);

    // Use lambda with std::find_if
    std::list<int> list;
    list.push_back(1);
    list.push_back(3);
    list.push_back(4);
    list.push_back(10);
    list.push_back(5);


    auto it = std::find_if(list.begin(), list.end(), [](int n){return n % 2 == 0;});
    std::cout << "First even number: " << *it << std::endl;

}