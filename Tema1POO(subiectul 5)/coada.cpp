#include "coada.h"
#include <iostream>

    coada::coada()
    {
        size = 0;
        top = NULL;
        bottom = NULL;
    }
    coada::coada(int nrTop, int nrBottom)
    {
        if (nrBottom != NULL)
        {
            top = new elem;
            bottom = new elem;
            top->val = nrTop;
            bottom->val = nrBottom;
            top->prev = bottom;
            bottom->next = top;
            top->next = NULL;
            bottom->prev = NULL;
            size = 2;
        }
        else
        {
            top = new elem;
            top->val = nrTop;
            top->next = NULL;
            top->prev = NULL;
            bottom = top;
            size = 1;
        }
    }
    coada::coada(const coada& obj)
    {
        this->size = obj.size;
        elem* source = obj.top;
        elem* dest = new elem;
        top = new elem;
        top->next = NULL;
        top->val = obj.top->val;
        top->prev = dest;
        elem* lastVisit = top;
        source = obj.top->prev;
        while (source != obj.bottom)
        {
            dest->val = source->val;
            dest->next = lastVisit;
            source = source->prev;
            lastVisit = dest;
            dest = new elem;
        }
        bottom = dest;
        bottom->prev = NULL;
        bottom->val = source->val;
        bottom->next = lastVisit;
    }
    coada::~coada() {
        elem* current = new elem;
        current = top->prev;
        for (int i = 1; i < size; i++)
        {
            delete current->next;
            current = current->prev;
        }
        top = NULL;
        bottom = NULL;
    }
    coada coada::operator=(const coada& obj) {//
        this->size = obj.size;
        elem* source = obj.top;
        elem* dest = new elem;
        top->next = NULL;
        top->val = obj.top->val;
        top->prev = dest;
        elem* lastVisit = top;
        source = obj.top->prev;
        while (source != obj.bottom)
        {
            dest->val = source->val;
            dest->next = lastVisit;
            source = source->prev;
            lastVisit = dest;
            dest = new elem;
        }
        bottom = dest;
        bottom->prev = NULL;
        bottom->val = source->val;
        bottom->next = lastVisit;
        return *this;
    }
    bool coada::operator==(const coada& obj)
    {
        if (this->size != obj.size)
            return false;
        else
        {
            elem* current1, * current2 = new elem;
            current1 = this->top;
            current2 = obj.top;
            for (int i = 1; i <= size; i++)
            {
                if (current1->val != current2->val)
                    return false;
                current1 = current1->prev;
                current2 = current2->prev;
            }
        }
        return true;
    }
    bool coada::operator>(const coada& obj)
    {
        int sizeMax;
        if (size > obj.size)
            sizeMax = size;
        else
            sizeMax = obj.size;
        elem* current1, * current2 = new elem;
        current1 = this->top;
        current2 = obj.top;
        for (int i = 1; i <= sizeMax; i++)
        {
            if (current1 != NULL and current2 != NULL)
            {
                if (current1->val < current2->val) return false;
                if (current1->val > current2->val) return true;
            }
            else
            {
                if (current1 == NULL) return false;
                else return true;
            }
            current1 = current1->prev;
            current2 = current2->prev;
        }
        return false;
    }
    bool coada::operator<(const coada& obj)
    {
        int sizeMax;
        if (size > obj.size)
            sizeMax = size;
        else
            sizeMax = obj.size;
        elem* current1, * current2 = new elem;
        current1 = this->top;
        current2 = obj.top;
        for (int i = 1; i <= sizeMax; i++)
        {
            if (current1 != NULL and current2 != NULL)
            {
                if (current1->val > current2->val) return false;
                if (current1->val < current2->val) return true;
            }
            else
            {
                if (current2 == NULL) return false;
                else return true;
            }
            current1 = current1->prev;
            current2 = current2->prev;
        }
        return false;
    }
    int coada::getTop() {
        if (top != NULL)
            return top->val;
        else
            throw "Coada goala";
    }
    int coada::getBottom() {
        if (bottom != NULL)
            return bottom->val;
        else
            throw "Coada goala";
    }
    void coada::insertTop(int nr) {
        size++;
        elem* newTop = new elem;
        newTop->val = nr;
        newTop->next = NULL;
        newTop->prev = top;
        if (top != NULL) top->next = newTop;
        else bottom = newTop;
        top = newTop;

    }
    void coada::insertBottom(int nr) {
        size++;
        elem* newBottom = new elem;
        newBottom->val = nr;
        newBottom->prev = NULL;
        newBottom->next = bottom;
        if (bottom != NULL) bottom->prev = newBottom;
        else top = newBottom;
        bottom = newBottom;
    }
    void coada::popTop() {
        if (top != NULL)
        {
            size--;
            top = top->prev;
            if (top == NULL) delete bottom;
            else delete top->next;
        }
    }
    void coada::popBottom() {
        if (bottom != NULL)
        {
            size--;
            bottom = bottom->next;
            if (bottom == NULL) delete top;
            else delete bottom->prev;
        }
    }
    int coada::getSize() {
        return size;
    }
    bool coada::isVoid() {
        if (size == 0)
            return true;
        return false;
    }
    void coada::reverse() {
        elem* current = new elem;
        current = top;
        int sizeSave = size;
        for (int i = 1; i <= sizeSave; i++)
        {
            insertTop(current->val);
            current = current->prev;
        }
        sizeSave = size / 2;
        for (int i = 1; i <= sizeSave; i++)
        {
            popBottom();
        }
    }
    std::ostream& operator<<(std::ostream& out, const coada& obj)//
    {
        coada::elem* current = obj.top;
        for (int i = 0; i < obj.size; i++) {
            out << current->val<< " ";
            current = current->prev;
        }
        return out;
    }
    std::istream& operator>>(std::istream& in, coada& obj)//
    {
        coada::elem* current = obj.top;
        for (int i = 0; i < obj.size; i++) {
            in >> current->val;
            current = current->prev;
        }
        return in;
    }
    