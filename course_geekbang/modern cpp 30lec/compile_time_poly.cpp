#include<iostream>
#include <vector>
#include <cstring>


using namespace std;

// 函数模板
template<typename T>
bool isEqual(T t1, T t2) {
    cout << "函数模板" << endl;
    return t1 == t2;
}

// 函数模板全特化
template<>
bool isEqual(const char *t1, const char *t2) {
    cout << "函数模板全特化" << endl;
    return strcmp(t1, t2);
}

// 改为重载
template<typename T>
bool isEqual(T t1, char t2) {
    cout << "函数重载" << endl;
    return strcmp(t1, t2);
}

/// =============================================================

// 类模板
template<class T>
class comp {
public:
    bool isEqual(T t1, T t2) {
        cout << "类模板" << endl;
        return t1 == t2;
    }
};

// 类模板全特化
template<>
class comp<const char *> {
public:
    bool isEqual(const char *t1, const char *t2) {
        cout << "类模板全特化" << endl;
        return strcmp(t1, t2);
    }
};

// 类模板偏特化
template<typename T>
class comp<T *> {
public:
    bool isEqual(T *t1, T *t2) {
        cout << "类模板偏特化" << endl;
        return strcmp(t1, t2);
    }
};

int main() {
    isEqual(1, 2);       // 实例化的时候做类型检查
    isEqual(1, 2.1);
    isEqual("qwqw", "asd");
    comp<int> c;
    c.isEqual(10, 11);
    comp<const char *> cc;
    cc.isEqual("he", "lo");
    comp<char *> p;
    p.isEqual("he", "ll");
}
