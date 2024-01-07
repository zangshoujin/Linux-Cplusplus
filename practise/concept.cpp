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

// 一个永远都能匹配成功的concept
template <typename T>
T mul(T a, T b) {
    return a * b;
}

template <typename T>
requires std::is_integral<T>::value
T add(T a, T b) {
    return a + b;
}

// 一个约束T只能是整数类型，并且是有符号的concept
template <typename T>
requires std::integral<T> && std::is_signed_v<T>
T subtract(T a, T b) {
    return a - b;
}

int main() {
    mul(1, 2); // 匹配成功, T => int
    mul(1.0f, 2.0f);  // 匹配成功，T => float

    cout << add(1, -2) << endl;  // 匹配成功, T => int

    // // add(1.0f, 2.0f); // 匹配失败, T => float，而T必须是整型
    // // subtract(1U, 2U); // 匹配失败，T => unsigned int,而T必须是有符号整型
    subtract(1, 2); // 匹配成功, T => int
}