## 1.含义
定义值不可修改变量的限定符
## 2.使用场景
**(1)定义常量**
```c++
const int i = 100; 		//编译时初始化
const int j = get_input();	//运行时初始化
```
**(2)对const的引用(reference to const)**

即不可修改所绑定对象的引用

情况1：被引用对象为常量
```c++
const int ci = 100;
const int &ri = ci;
```
情况2：被引用对象非常量：
```c++
double val = 3.14;
const int &v = val;
```
等价于：
```c++
const int temp = val;
const int &v = temp;
```
此处v相当于绑定了一个临时对象，故无法通过v改变val的值

**(3)指针与const**

*在const前则指针为常量，即定义了常量指针，*在const后则指针指向常量，即指向常量的指针
```c++
int i = 0;
int *const p1 = &i; //常量指针
const int *p2;      //指向常量的指针
int const *p3;
```
- 常量指针（**顶层const**）
	->常量指针本身是常量，定义时必须初始化
	->常量指针可以对指向的非常量进行修改
	```c++
	*p1 = 1;
	```
- 指向常量的指针（**底层const**）
	->指向常量的指针本身不是常量，定义时可以不进行初始化
	->不能通过指向常量的指针修改所指变量的值，但是若所指变量为非常量，可通过其他方式修改其值
	```c++
	p2 = &i;
	int p4 = &i;
	*p4 = 3;
	```
**(4)const修饰函数参数**
- 常量参数
	```c++
	void fun(const int a);
	void fun(int *const a);
	```
	->没有实际意义，因为a是通过“值传递”拷贝的而来的形参，对实参本就没有影响
- 指向常量的指针
	```c++
	void fun(int const *a);
	```
	->防止函数对a所指对象的值进行修改
- 对常量的引用
	```c++
	void fun(int const &a);
	void fun(A const &a);
	```
	->防止函数对a所引用的对象进行修改
	->提升效率，当a的类型非基本数据类型时，通过“值传递”直接复制对象存在构造和析构的开销
	
**(5)替代#define**
宏定义在编译时把所有用到宏定义值的地方用宏定义常量替换，结束于编译期。const常量可以看作是一个只读变量，需要指定类型，需要分配内存，有自己的作用域。

**(6)类中的常量成员函数**
任何不会修改数据成员的函数都应该声明为const类型。
->提升健壮性：如果在编写const成员函数时，不慎修改数据成员，或者调用了其它非const成员函数，编译器将指出错误
->使成员函数的意义更加清楚，将成员函数分修改对象和不修改对象两类
->const对象只能访问const成员函数
```c++
class A {
public:
	int getAge() {
		return age;
	}
	int getAge() const{
		return age;
	}
private:
	int age = 0;
};
void main() {
	
	const A a;
	A a1;

	cout << a.getAge()<< endl;
	cout << a1.getAge() << endl;
```


