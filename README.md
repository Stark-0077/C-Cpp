# cpp
Here is my cpp learning content.
Some knowledge will be recorded.  

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


 ## 4. 构造函数和析构函数
 
 对象的动态内存分配
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
  

