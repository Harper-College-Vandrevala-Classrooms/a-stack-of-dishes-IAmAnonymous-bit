using namespace std;

#include <iostream>
#include <array>
#include <string>

template<typename T>
class DishStack
{
    private:
        int current = 0;
        const int MAX_SIZE;
        T *dish_arr;
    public:
        DishStack(int max) : MAX_SIZE(max)
        {
            dish_arr = new T[MAX_SIZE];
        }

        void push(T value)
        {
            if(current == MAX_SIZE)
            {
                throw std::invalid_argument("Stack of Dishes is Full!");
            } else {
                dish_arr[current] = value;
                current++;
            }
        }

        T pop()
        {
            if(current == 0)
            {
                throw std::invalid_argument("Stack of Dishes is Empty!");
            }
            T popped = dish_arr[current-1];
            current--;
            return popped;
        }

        T peek()
        {
            if(current == 0)
            {
                throw std::invalid_argument("Stack of Dishes is Empty!");
            }
            T peeked = dish_arr[current-1];
            return peeked;
        }

        int size()
        {
            return current;
        }

};