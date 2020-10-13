#include <iostream>
using namespace std;

//struct or class? 不限制访问属性的时候，default type is different.

class Student{
private://as default
    int i;
    int *p;
public:
    Student(): i(0){
        p= 0;
        cout<<"Student::Student()"<<endl;
    }
    ~Student(){
        if(p) delete p; // to avoid 内存泄漏
        cout<<"Student::~Student()"<<endl;
    }

    void f(){
        p= new int;
    }
protected: // this means inside the main function, you cannot call this func.
    void set(int i){
        this->i = i;
    }
};

class BadStudent : public Student{
public:
    BadStudent() : Student(){
        //使用初始化列表对于父类构造函数进行调用
    }
    void f1(){
        set(20);// this shows how to call the function inside the Class
        //i=30; //! invalid!
        Student::f(); // C++无override
    }
    void f(int ha){

    };
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    //利用new进行动态内存分配
    int *p = new int;
    int * a = new int[10];

    Student *q= new Student();
    Student *r= new Student[10];
    //调用析构再回收空间
    delete p;
    delete[] a;

    delete q;
//    delete r;
    delete[] r;

    return 0;
}