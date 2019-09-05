#include <iostream>
#include <stdexcept>
template<typename T>
struct DoubleList{

};

template<typename T>
struct SingleList{
    T value;
    SingleList<T>* nextList;
};

template<typename T>
class LinkedList{
public:
    LinkedList(T element){
        head = new SingleList<T>;
        head->value = element;
        head->nextList = nullptr;
        previousList = head;
        n++;
    }
    ~LinkedList(){

    }

    void append(T element){
        SingleList<T>* item = new SingleList<T>;
        item->value = element;
        item->nextList = nullptr;
        previousList->nextList = item;
        previousList = item;
        n++;
    }
    void insert(int index, T element){
        SingleList<T>* item = head;
        for(int i = 0; i < index; ++i){
            item = item->nextList;
        }
        delete item;
    }
    void remove(int index){

        SingleList<T>* item = head;
        for(int i = 0; i < index; ++i){
            item = item->nextList;
        }
        delete item;

    }
    void replace(int index, T element){
         SingleList<T>* item = head;
        for(int i = 0; i < index; ++i){
            item = item->nextList;
        }
        item->value = element;
    }

    T at(int index){
        if(index < 0 || index > n){
            throw std::out_of_range ("blah");
        }
        SingleList<T>* item = head;
        for(int i = 0; i < index; ++i){
            item = item->nextList;
        }
        return item->value;
    }

    int count(){
        return n;
    }
    // int contains(T element){

    // }
    // T operator [](int i) const {

    // }
    // T & operator [](int i) {

    // }
private:
    SingleList<T>* previousList;
    SingleList<T>* head;
    int n = 0;
};

int main(){
    auto bla = LinkedList<int>(5);
    bla.append(3);
    bla.append(9);
    bla.append(102);
    
    for(int i = 0; i < bla.count(); ++i){
        
        std::cout << bla.at(i) << std::endl;
    }


}
