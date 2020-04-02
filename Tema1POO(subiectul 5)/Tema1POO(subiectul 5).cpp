#include <iostream>
#include "coada.h"

using namespace std;

int main()
{
    coada a(12, 301), b(a), c;
    cout << a.getTop() << "\n" << b.getBottom() << "\n";
    a.insertTop(100);
    b.insertBottom(40);
    cout << a.getTop() << "\n"<< b.getBottom()<< "\n";
    c.insertTop(69);
    cout << c.getTop() << "\n" << c.getBottom() << "\n"<< a.getSize();
    b.popTop();
    a.popBottom();
    cout << "\n" << b.getTop() << "\n" << a.getBottom()<<'\n';
    
    a.insertTop(20);
    a.insertBottom(80);
    cout << a.getTop() << " " << a.getBottom() << "\n";
    a.reverse();
    cout << a.getTop() << " " << a.getBottom() << "\n";

    coada x(1, 2), y(x);
    if (x == y) cout << "DA";
    else cout << "NU";
    cout << "\n";
    x.insertTop(5);
    if (x == y) cout << "DA";
    else cout << "NU";
    cout << "\n";
    y.insertTop(5);
    if (x > y)
        cout << "DA";
    else cout << "NU";
    cout << "\n";
    coada aaa(1,2);
    cout << aaa.getBottom()<<"\n";
    cout << aaa<<endl<< "input pentru coada 2 elem:";
    cin >> aaa;
    cout <<'\n'<< aaa;
    x = aaa;
    cout << '\n' << x;
}