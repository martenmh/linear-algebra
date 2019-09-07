#include <iostream>
#include <stdexcept>
#include <iterator>

template<typename T>
struct DoubleList{

};

template<typename T>
struct SingleList{
    T value;
    SingleList<T>* nextList;
};

template<typename T>
class Vector{
public:
    Vector(T element){
        head = new SingleList<T>{element, nullptr};
        
        previousList = head;
        n++;
    }

    Vector(){
        head = nullptr;
        previousList = nullptr;
    }
    ~Vector(){

    }

    void append(T element){
        SingleList<T>* item = new SingleList<T>{element, nullptr};
        previousList->nextList = item;
        previousList = item;
        n++;
    }

    void insert(int index, T element){
        SingleList<T>* item = head;
        for(int i = 0; i < index; ++i){
            item = item->nextList;
        }
        SingleList<T>* newItem = new SingleList<T>;
    }

    /*
       Removes list at the given index
     */
    void remove(int index){

        SingleList<T>* item = head;
        for(int i = 0; i < index; ++i){
            item = item->nextList;
        }
        delete item;
        n--;
    }

    /*
       Replaces value of the list at the given index
     */
    void replace(int index, T element){
        SingleList<T>* item = head;
        for(int i = 0; i < index; ++i){
            item = item->nextList;
        }
        item->value = element;
    }

    /*
       Returns value at index with out of range checking
     */
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

    /*
       Returns count
     */
    int count(){
        return n;
    }

    /*
       Returns the index of the list where the value is the same as the value in the parameter
     */
    int contains(T element){
        SingleList<T>* item = head;
        for(int i = 0; i < n; ++i){
            if(item->value == element)
                return i;
            item = item->nextList;
        }
        return 0;
    }

    double dotProduct(Vector<T> &v){
        double dotProduct = 0;
        // Vectors have to be the same size
        if(v.count() != n){
            return dotProduct;   //Error
        }

        for(int i = 0; i<n; ++i){
            dotProduct += this->at(i) * v[i];
        }
        return dotProduct;
    }


    void reset(){
        SingleList<T>* item = head;
        SingleList<T>* nextAddress;

        for(int i = 0; i < n; ++i){
            nextAddress = item->nextList;   // Store address of next item 
            delete item;   
            item = nextAddress;
        }
        // Finally reset all properties
        delete head;
        delete previousList;
        head = nullptr; 
        previousList = nullptr;
        n = 0;
    }

    /*
       Returns value at index without out of range checking
     */
    T operator [](int index) const {
        SingleList<T>* item = head;
        for(int i = 0; i < index; ++i){
            item = item->nextList;
        }
        return item->value;
    }

    T & operator [](int index) {
        SingleList<T>* item = head;
        for(int i = 0; i < index; ++i)
            item = item->nextList;
        
        return item->value;
    }

    // Using a reference to know the size of the array
    template <size_t N>
    void operator=(T (&elements)[N]) {

        if(n > 0)
            reset();

        head = new SingleList<T>{*elements, nullptr};
        previousList = head;
        n++;

        for(int i = 1; i != N; ++i)
            append(elements[i]);

        
    }

    Vector<T> operator+(Vector<T> &v){
        auto value = *this;

        // Vectors have to be the same size
        if(v.count() != n){
            return value;   //Error
        }

        for(int i = 0; i<n; ++i)
            value.replace(i, value[i] + v[i]);
        
        return value;
    }
    T operator-(Vector<T> &v){
        auto value = *this;
        // Vectors have to be the same size
        if(v.count() != n){
            return value;   //Error
        }

        for(int i = 0; i<n; ++i)
            value.replace(i, value[i] - v[i]);
        
        return value;
    }
    T operator*(Vector<T> &v){
        double dotProduct = 0;
        // Vectors have to be the same size
        if(v.count() != n){
            return dotProduct;   //Error
        }

        for(int i = 0; i<n; ++i)
            dotProduct += this->at(i) * v[i];
        
        return dotProduct;
    }

    /*
    * Multiplying the vector with a scalar
    */
    Vector<T> operator*(T scalar){
        auto value = *this;

        for(int i =0; i<n; ++i)
            value.replace(i, value[i]*scalar);
        
        return value;
    }

private:
    SingleList<T>* previousList;
    SingleList<T>* head;
    int n = 0;
};

int main(){
    Vector<int> bla = Vector<int>();
    int b[5] = {1,0,2,5,-2};
    bla = b;
    
    std::cout << "--------" << std::endl;
    Vector<int> v = Vector<int>();
    int c[5] = {2,8,-6,1,0};
    v = c;
    
    auto d = bla + v;
    std::cout << "new values" << std::endl;
    for(int i = 0; i < d.count(); i++){
        std::cout << d[i] << std::endl;    
    }
    
    d = bla * 3;
    std::cout << "newer values" << std::endl;
    for(int i = 0; i < d.count(); i++){
        std::cout << d[i] << std::endl;    
    }
    
}
