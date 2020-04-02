#pragma once
#include<iostream>
class coada {
    struct elem {
        int val;
        elem* prev, * next;
    }*top, * bottom;
    int size;

public:
    coada();
    coada(int nrTop, int nrBottom=NULL);
    coada(const coada& obj);
    ~coada();
    coada operator=(const coada& obj);
    bool operator==(const coada& obj);
    bool operator>(const coada& obj);
    bool operator<(const coada& obj);
    int getTop();
    int getBottom();
    void insertTop(int nr);
    void insertBottom(int nr);
    void popTop();
    void popBottom();
    int getSize();
    bool isVoid();
    void reverse();
    friend std::ostream& operator<<(std::ostream& out, const coada& obj);
    friend std::istream& operator>>(std::istream& in, coada& obj);
};