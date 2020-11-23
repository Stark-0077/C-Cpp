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
 
