# cpp
Here is my cpp learning content.
Some knowledge will be recorded.  
https://zh.cppreference.com/  
https://interview.huihut.com/#/
## 1.基本常识  
Source Files文件夹：放源程序，如 **.cpp**。  
Resource Files文件夹：放程序里需要的资源文件，如 **图标，对话框，图片等**。  
Header Files文件夹：放程序的头文件，变量和成员函数的声明,如 **.h**。  

**代码规范**  
- 头文件保护  
#progma once  



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

**使用类的成员变量和成员函数**  

* 方法一： **对象名.成员名**  
```
CRectangle r1,r2; 
r1.w = 5;
r2.Init(5,5);  
```
* 方法二： **指针->成员名** 
```
CRectangle *p1 = &r1; 
p1->w = 5;  
p1->Init(5,5);
```
* 方法三：**引用名.成员名**  
```
CRectangle r2;  
CRectangle &rr = r2;  
rr.w = 5;  
rr.Init(5,5);
// example  
void PrintRectangle(CRectangle &r)  
{ cout<< r.Area()<<endl;}
CRectangle r3;
r3.Init(5,5);
PrintRectangle(r3);  
```
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


 ## 4. 构造函数Constructor和析构函数Destructor & this  
 
 - 目的：执行初始化工作，避免再写初始化函数。有时没对象被初始化就使用，会导致程序出错。  
 - 实例  
 ```
 class Box
{
   public:
      Box() { 
         cout << "调用构造函数！" <<endl; 
	 //构造函数可以提醒程序员进行初始化
      }
      ~Box() { 
         cout << "调用析构函数！" <<endl; 
      }
};
 ```  
- 可以有多个构造函数（函数重载） 
- 构造函数在数组中的使用  
```
class Complex
{
    int x;
	public:  
	Complex()  
	{
	cout<< "Constructor 1 is called"<<endl
	};
	Complex(int n)  
	{
	x = n;
	cout<<"Constructor 2 is called"<<endl
	};
};  
//constructor for array  
Complex array0[2]; 
// Constructor 1 is called 
// Constructor 1 is called  

Complex array1[2] = {4,5};
// Constructor 2 is called  
// Constructor 2 is called  

Complex array2[2] = {3};
//Constructor 2 is called
//Constructor 1 is called  

Complex*arrary4 = new Complex[2];
delete []array4;
//Constructor 1 is called
//Constructor 1 is called
```
 
 
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
   Box* myBoxArray = new Box[4];  //指针数组
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
**复制构造函数**  
http://c.biancheng.net/view/151.html   
- Def:复制构造函数是构造函数的一种，也称拷贝构造函数，它只有一个参数，参数类型是本类的引用。  
- 如果编写了复制构造函数，则默认复制构造函数就不存在了。  

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

Header files:
```
#pragma once
#include<iostream>
#include<string>
using namespace std;

class Student
{
public:
	void setname(string name);
	void setage(int age);
	void setscore(float score);
	void show();
private:
	string name;
	int age;
	float score;
};

```  
Cpp files For function implementation:  
```
#include "../header/This.h"

void Student::setname(string name) {
	this->name = name;
}
void Student::setage(int age) {
	this->age = age;
}
void Student::setscore(float score) {
	this->score = score;
}
void Student::show() {
	cout << this->name << " 's age is" << this->age << ", grade is " << this->score << endl;
}
```
Main Cpp file For using Class:
```
#include "header/This.h"

int main()
{
	// 
	Student *pstu = new Student;
	pstu->setname("qwer");
	pstu->setage(16);
	pstu->setscore(96.5);
	pstu->show();
	return 0;

}
```



## 5. 命名空间  
```
namespace namespace_name {
   // 代码声明
}
```  
存在意义：namespace通常用来给类或者函数做个区间定义，以使编译器能准确定位到适合的类或者函数。  
譬如说，自行实现了一个函数test(void)，而在该项目的库函数内也定义了一个函数test(void);当你调用test();函数的时候，编译器就困惑了，该调用哪个呢？这个时候namespace的作用就显现出来了。  
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

int a[5] = {1,2,3,4,5};
vector<int>test(a,a+5);// 把数组赋值给vector
 ``` 
  
- 输入输出可以像普通数组那样： cin >> a[3]; cout <<a[i]<<endl;  
- 也可以用迭代器：
```
 vector<int>::iterator iter ;

for(t=a.begin(); iter !=a.end(); t++)

cout<<*iter <<" " ;

// vector<int>::const_iterator iter_read_only;
// Read Only Iterator
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

## const & voliatle 关键字  
```
int main()
{   
    // cosnt 定义常量
    const int a = 6;
    a = 7;    // error; variable a is read-only
    
    // 指针使用 const 
    //  (1) 指针本身是常量
    int* const b;
    
    // （2）指针指向的内容不可变
    const int* c;
    
    //  (3) 指针是常量，指向的内容也不可变
    const int* const d;
 
    return 0;
}
```
## inline 内联函数  
- 设计目的：为了减少函数调用的开销。  
- 机制：不调用，直接用函数体。（类似是macro）  
- 实例  
```
inline int MAX(int a,int b)
{
	if(a>b) return a;
	return b;
}
```  
## 函数重载  
- 含义：函数名字相同，参数个数/类型不同。  
- 机制：编译器通过参数个数/类型来判断调用哪个函数。  
- 实例  
```
int max(double f1,doublef2){}
int max(int i,int j){}
int max(int a, int b, int c){}
```
- 意义：使得函数命名变得简单。  

## 静态（static）成员  
- 目的： 将和某些类紧密相关的全局变量和函数写到类里面，看上去更像一个整体，易于维护，理解。  
- 普通成员变量 vs 静态成员变量  
静态成员变量被所有的对象共享。  
- sizeof不会计算静态成员变量，静态成员不是被放在对象内部的。  
- 静态成员不需要通过对象就可以访问。  
- 静态成员变量/函数，本质上是全局变量/函数。  

- 如何访问静态成员？  
类名::成员名 rectangle::PrintTotal();  
对象名::成员名 rectangle r; r.PrintTotal();  
指针->成员名 rectangle* p = &r; p->PrintTotal();  
引用.成员名 rectangle&ref = r; int n = ref.Num;  

- 使用：  
在定义类的文件中对静态成员变量进行一次说明/初始化。  
在静态成员函数中，不能访问非静态成员变量/函数。  
```
class rectangle
{
private:
	int w,h;
	static int Area;	//静态成员变量，如总面积，总数量etc.
	static int Num;
public:
	rectangle(int w_,int h_);
	~rectangle();
	static void PrintTotal();	//静态成员函数
};
```
## 智能指针(shared_ptr,unique_ptr,weak_ptr)  
- 目的：因为C++没有自动回收内存的机制，因此每一次new出来的动态内存必须手动delete回去。而智能指针可以解决这个问题。  
 内存泄漏的危害是巨大的，它导致可用内存越来越少，甚至拖慢系统，最终进程可能被OOM（out of memory）机制杀死。  
- 智能指针：自动负责释放所指向的对象，实际上它利用了栈的机制，每一个智能指针都是一个模板类，  
调用智能指针实际上是创建了一个智能指针的对象，  
对象生命周期到达尽头的时候，会自动调用智能指针的析构函数，在析构函数里，释放掉它管理的内存，从而避免手动delete。  
- 三种智能指针：*shared_ptr* 允许多个指针指向同一个对象 *unique_ptr* 独占所指向的对象 *weak_ptr* shared_ptr的弱引用  
- [click here to learn more](https://zhuanlan.zhihu.com/p/29628938)  
- [implementation](https://zhuanlan.zhihu.com/p/344953368)
- [more](https://mp.weixin.qq.com/s?__biz=MzI2OTA3NTk3Ng==&mid=2649285218&idx=1&sn=dc8fc5f25ce59729101067651c650325&chksm=f2f99105c58e181366dcd1ce1865e97ace103b17f7f25c2ce24cb8151ea6af84596160713cca&scene=21#wechat_redirect)  
- 


## ++i和i++  
```
#include <iostream>
using namespace std;
int main()
{
    cout << "Hello, world!" << endl;
	int i = 0;
	int a = i++;
	cout<< a <<endl;
	i = 0;
	int b = ++i;
	cout<< b <<endl;
    return 0;
}
```  
output  
```
Hello, world!
0
1
```  
说明：  
a = i++; 先赋值i给a，再自加  
b = ++i; 先自加，再赋值给b  


## auto在for循环的用法  
Auto的意义:优势在于拥有初始化表达式的复杂类型变量声明时简化代码  
尤其是随着STL模板的使用，提高了程序的可读性。  

- for(auto a:b)中b为一个容器，效果是利用a遍历并获得b容器中的每一个值，但是a无法影响到b容器中的元素。  
```
#include <iostream>
using namespace std;
int main()
{
    int a[5] = {1,2,3,4,2};
    for(auto idx:a)
    {
        std::cout<< idx << endl;
        
    }
    return 0;
}
```
- for(auto &a:b)中加了引用符号，可以对容器中的内容进行赋值，即可通过对a赋值来做到容器b的内容填充。  
```
#include <iostream>
using namespace std;
int main()
{
    int a[5] = {1,2,3,4,2};
    for(auto &idx:a)
    {   idx = 1;
        std::cout<< idx << endl;
        
    }
    return 0;
}	

```
