/**
 * Iterator Pattern
 * 
 * Lets you traverse elements of a collection without exposing its underlying
 * representation (list, stack, tree, etc.).
 */
#include <iostream>
#include <vector>
#include <string>

template <typename T, typename U>
class Iterator {
public:
    typedef typename std::vector<T>::iterator iter_type;
    Iterator(U* p_data, bool reverse = false) : m_p_data_(p_data) {
        m_it_ = m_p_data_->m_data_.begin();
    }
    void first() { m_it_ = m_p_data_->m_data_.begin(); }
    void next() { m_it_++; }
    bool isDone() { return (m_it_ == m_p_data_->m_data_.end()); }
    iter_type current() { return m_it_; }

private:
    U* m_p_data_;
    iter_type m_it_;
};

template <class T>
class Container {
    friend class Iterator<T, Container>;
public:
    void add(T a) { m_data_.push_back(a); }
    Iterator<T, Container>* createIterator() { return new Iterator<T, Container>(this); }
private:
    std::vector<T> m_data_;
};

int main() {
    Container<int> cont;
    for (int i = 0; i < 5; i++) cont.add(i);

    Iterator<int, Container<int>>* it = cont.createIterator();
    for (it->first(); !it->isDone(); it->next()) {
        std::cout << *it->current() << std::endl;
    }

    delete it;
    return 0;
}
