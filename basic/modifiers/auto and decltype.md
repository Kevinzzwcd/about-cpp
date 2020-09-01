## auto
1. 用途
(1)自动类型判断
当变量类型过长或难以判断时，让编译器通过初始值来**推算**变量类型。**推算**是指表达会被执行。
(2)搭配decltype追踪泛型函数返回类型。
2. 判别规则
(1)复合类型
使用复合类型作为初值，如指针和引用，由于参与初始化的值其实是被引用的对象，所以此时auto类型是对象的类型。
```c++
int i = 0, &r = i;
auto a = r;	//a是int类型
```
(2)常量
auto会忽略顶层const（对象本身为常量），保留底层const。
```c++
const int ci = i;
auto b = ci;	//b为整型，顶层const被忽略
auto c = &i;	//c为整型指针
auto d = &ci;	//d为指向整型常量的指针，保留底层const
```

## decltype
1. 用途
(1)需要从表达式或结构体的类型**推断**需要定义的变量类型，但是又不需要将该表达式值作为初值。**推断**是指表达式并未被执行。
(2)搭配auto追踪泛型函数返回类型。
```c++
template <typename T>
auto multiply(T x, T y)->decltype(x*y)	//auto为返回值占位符
{
    return x*y;
}
```
2. 判别规则
(1)若为变量，则所见即所得。
```c++
const int ci = 0, &cj = ci;
decltype(ci) x = 0;	//x类型为const int
decltype(cj) y = 0;	//y类型为const int&
```
(2)当表达式非变量时，得表达式结果对应类型。
```c++
int i = 42, *p = &i, &r = i, arr[5] = {0};
decltype(r + 0) b;	//b类型为加法表达式的结果，即int
decltype(*p) c;	//c类型为解引用表达式结果，即int&
decltype(arr[1]) d;	//d类型为取下标表达式返回的左值
```
(3)若变量名加上括号，则认为是左值表达式，类型为引用类型。
