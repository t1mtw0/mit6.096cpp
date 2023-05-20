#include <vector>

template<class T> class Stack {
private:
    std::vector<T> item;
public:
    bool empty() const {
        return item.empty();
    }
    void push(const T &item) {
        item.push_back(item);
    }
    T &top() {
        return item.back();
    }
    void pop() {
        item.pop_back();
    }
}
