# cpp
Here is my cpp learning content.
Some knowledge will be recorded.  
https://zh.cppreference.com/  
## 1.基本常识  
Source Files文件夹：放源程序，如 **.cpp**。  
Resource Files文件夹：放程序里需要的资源文件，如 **图标，对话框，图片等**。  
Header Files文件夹：放程序的头文件，变量和成员函数的声明,如 **.h**。  

## 2. 什么是面向对象  
objects = attributes + services  
**An example**:
class Piont3d{  
public:  
  Point3d(float x, float y, float z);  
  print();  
private:  
  float x;
  float y;  
  float z;
};

Point3d a(1,2,3);  
a.print();  

**Object-oriented(Focus on things,not operations)**  
A way to organize(design, implementations)  
Objects, not control or data flow, are primary focus of the design and implemetation  

## 3.面向对象基本原理  
- Object send and receive messages(ojects do things)  
Object send messages:  
Messages may cause receiver to change state or return results  

- OOP 
(1). 一切都是对象    

(2). 程序是一堆对象，这一堆对象发送消息，互相告知别人what to do.  
     C源代码: 函数的集合  
     C++程序运行的时候: 对象之间发送消息, what to do.  

(3). 每一个对象有它自己的内存，内存里又是由其它对象组成的.  
     eg:Point3d a;  
     a是一个对象,对象a里面又有对象float x,float y,float z;  

(4). 每个对象都有类型  

(5). 一个特定类型的所有的对象，可以接收相同的消息.  
     eg: 所有的水果都可以被你咬一口.  
     所有可以接受相同消息的对象，可以被认为是相同的类型.  


 ## 4. 构造函数和析构函数 & this  
 
 **对象的动态内存分配**  
```
#include <iostream>
using namespace std;
 
class Box
{
   public:
      Box() { 
         cout << "调用构造函数！" <<endl; 
      }
      ~Box() { 
         cout << "调用析构函数！" <<endl; 
      }
};
 
int main( )
{
   Box* myBoxArray = new Box[4];
    // 调用四次
   delete [] myBoxArray; // 删除数组
   return 0;
}
/* 
int main( )
{
   Box* myBoxArray = new Box;
    // 调用一次
   delete  myBoxArray; // 删除数组
   return 0;
*/
```
**this**  
http://c.biancheng.net/cpp/biancheng/view/201.html  
- this 是 C++ 中的一个关键字，也是一个 const 指针，它指向当前对象，通过它可以访问当前对象的所有成员。  
- C++只能用在类的内部，通过this可以访问类的所有成员，包括private，protected，public属性的。  
- this 是一个指针，要用->来访问成员变量或成员函数。  
- this 虽然用在类的内部，但是只有在对象被创建以后才会给 this 赋值，并且这个赋值的过程是编译器自动完成的，不需要用户干预，用户也不能显式地给 this 赋值。  
- 只有当对象被创建后 this 才有意义，因此不能在 static 成员函数中使用。  
-  this 实际上是成员函数的一个形参，在调用成员函数时将对象的地址作为实参传递给 this。不过 this 这个形参是隐式的，它并不出现在代码中，而是在编译阶段由编译器默默地将它添加到参数列表中。  
- **this是 成员函数 和 成员变量 关联的桥梁。**  
-  this 作为隐式形参，本质上是成员函数的局部变量，所以只能用在成员函数的内部，并且只有在通过对象调用成员函数时才给 this 赋值。  




## 5. 命名空间  
```
namespace namespace_name {
   // 代码声明
}
```  
[Click this Link to learn more](https://www.runoob.com/cplusplus/cpp-namespaces.html)  

## 6. C++模板  
函数模板&类模板
### 6.1 函数模板  

### 6.2 类模板  


## 7. vector容器  
- 属于标准模板库（STL:standard template library）的一种（另外还有string等）。  
- 使用时要包含头文件 #include<vector>  
- vector vs. array  
  vector 容器与数组相比其优点在于它能够根据需要随时自动调整自身的大小以便容下所要放入的元素  
- vector 常用的声明及初始化  
  
 ```
vector<int> a ; //声明一个int型向量a

vector<int> a(10) ; //声明一个初始大小为10的向量

vector<int> a(10, 1) ; //声明一个初始大小为10且初始值都为1的向量

vector<int> b(a) ; //声明并用向量a初始化向量b

vector<int> b(a.begin(), a.begin()+3) ; //将a向量中从第0个到第2个(共3个)作为向量b的初始值  
 ``` 
  
- 输入输出可以像普通数组那样： cin >> a[3]; cout <<a[i]<<endl;  
- 也可以用迭代器：
```
 vector<int>::iterator t ;

for(t=a.begin(); t!=a.end(); t++)

cout<<*t<<" " ;
```
- 向量基本操作  
```
a.size()   // get the # of elements
a.empty()  // Judge if vector is empty  
a.clear()  // clear vector  
a = b // copy b to a  
a==b  a!=b   // logic comparsion between two vector  
a.insert(a.begin(),1000)  // insert 1000 to the start of a  
a.insert(a.begin(),3,1000)  // insert 1000 to position 0-2  
vector<int> a(5,1); vector<int> b(10); b.insert(b.begin(),a.begin,a.end());  
b.erase(b.begin())  // delete the start position of vector  
b.erase(b.begin(),b.begin()+3);  
b.swap(a);  // swap vector a and b  
```

