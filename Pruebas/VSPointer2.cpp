
#include <iostream>
using namespace std;

// Class representing a reference counter class
class Counter {
public:
    // Constructor
    Counter() : m_counter(0){};

    Counter(const Counter&) = delete;
    Counter& operator=(const Counter&) = delete;

    // Destructor
    ~Counter(){}

    void reset(){
        m_counter = 0;
    }

    unsigned int get(){
        return m_counter;
    }

    // Overload post/pre increment
    void operator++(){
        m_counter++;
    }
    void operator++(int){
        m_counter++;
    }

    // Overload post/pre decrement
    void operator--(){
        m_counter--;
    }
    void operator--(int){
        m_counter--;
    }

    // Overloading << operator
    friend ostream& operator<<(ostream& os, const Counter& counter){
        os << "Counter Value : "
           << counter.m_counter << endl;
    }

private:
    unsigned int m_counter{};
};

// Class representing a shared pointer
template <typename T>
class VSPtr {
public:
    // Constructor
    explicit VSPtr(T* ptr = nullptr){
        m_ptr = ptr;
        m_counter = new Counter();
        if (ptr) {
            (*m_counter)++;
        }
    }

    // Copy constructor
    VSPtr(VSPtr<T>& sp){
        m_ptr = sp.m_ptr;
        m_counter = sp.m_counter;
        (*m_counter)++;
    }

    // Reference count
    unsigned int use_count(){
        return m_counter->get();
    }

    // Get the pointer
    T* get(){
        return m_ptr;
    }

    T &operator *(){
        return *m_ptr;
    }

    // Destructor
    ~VSPtr(){
        (*m_counter)--;
        if (m_counter->get() == 0) {
            delete m_counter;
            delete m_ptr;
        }
    }

    friend ostream& operator<<(ostream& os, VSPtr<T>& sp){
        os << "Address pointed : "
           << sp.get() << endl;
        cout << *(sp.m_counter) << endl;
    }

private:
    // Reference counter
    Counter* m_counter;

    // Shared pointer
    T* m_ptr;
};