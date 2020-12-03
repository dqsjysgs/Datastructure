#include <iostream>
using namespace std;

class Exception {};

template<typename T>
class MyVector {
public:
    //默认构造函数，把数据指针指向NULL，size和capacity设为0
    MyVector() : p(NULL), capacity(0), size(0) {}

    //用_size个data构造对象，预留两倍空间
    MyVector(int _size, T data) {
        p = new T[2 * _size];
        for (int i = 0; i < _size; ++i) {
            p[i] = data;
        }
        capacity = 2 * _size;
        size = _size;
    }

    ~MyVector() { delete[] p; }

    MyVector(const MyVector& v) : capacity(v.capacity), size(v.size) {
        p = new T[capacity];
        for (int i = 0; i < size; ++i) {
            p[i] = v.p[i];
        }
    }

    MyVector& operator=(const MyVector& v) {
        if (this != &v) {
            delete[] p;
            capacity = v.capacity;
            size = v.size;
            p = new T[capacity];
            for (int i = 0; i < size; ++i) {
                p[i] = v.p[i];
            }
        }
        return *this;
    }

    friend ostream& operator<<(ostream& out, MyVector& v) {
        //重载<<使得该类的对象可以用cout输出
        cout << '{';
        for (int i = 0; i < v.size - 1; ++i) {
            out << v.p[i] << ", ";
        }
        if (v.size > 0) {
            out << v.p[v.size - 1];
        }
        out << '}';
        return out;
    }

    void insert(int pos, T data) {
        //将data插入到pos下标位置
        try {
            if (pos < 0 || pos > size) throw Exception();
            if (size + 1 > capacity) {
                doubleCapacity();
            }
            for (int i = size - 1; i >= pos; --i) {
                p[i + 1] = p[i];
            }
            p[pos] = data; size++;
        } catch (Exception& e) {
            cout << "Index " << pos << "is not valid!\n";
        }
    }

    void remove(int pos) {
        //删除pos下标的元素
        try {
            if (pos < 0 || pos >= size) throw Exception();
            for (int i = pos; i <= size - 2; ++i) {
                p[i] = p[i + 1];
            }
            size--;
        } catch (Exception& e) {
            cout << "Index " << pos << " is not valid!\n";
        }
    }

    void pushBack(T data) {
        //在对象的末尾添加元素
        insert(size, data);
    }

    void popBack() {
        //删除对象最后的元素
        remove(size - 1);
    }

    T& operator[](int pos) const {
        //重载[]使得该类对象可以用数组的方式访问元素
        return p[pos];
    }
    
    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }

    //调试用，后期删掉
    //void printp() {
    //    printf("p = %p\n", p);
    //}

private:
    T *p;//指向数据的指针，下标从0开始用
    int capacity;//当前总共可以容纳的数据个数，合法下标为[0, capacity - 1]
    int size;//当前已经使用了多少数据

    void doubleCapacity() {
        capacity = (capacity == 0) ? 1 : 2 * capacity;
        T *tp = new T[capacity];
        for (int i = 0; i < size; ++i) {
            tp[i] = p[i];
        }
        delete[] p;
        p = tp;
    }
};

int main() {
    //一些测试代码
    MyVector<double> test;
    for (int i = 1; i < 10; ++i) test.pushBack(i);
    test.insert(0, 666);
    test.remove(2);
    cout << test << endl;
    return 0;
}
