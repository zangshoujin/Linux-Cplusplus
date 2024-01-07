#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <list>
#include <stack>
#include <memory>
#include <algorithm>
#include <functional>
#include <thread>
#include <mutex>
#include <concepts>
#include <type_traits>

using namespace std;

// 一个约束T只能是整数类型的concept，整数类型包括 char, unsigned char, short, ushort, int, unsinged int, long等。
template <typename T>
concept integral = std::is_integral_v<T>;

// 整型才能匹配add函数的T
template <integral T>
T add(T a, T b) {
    return a + b;
}

int main() {
    add(1, -2);  // 匹配成功, T => int
}