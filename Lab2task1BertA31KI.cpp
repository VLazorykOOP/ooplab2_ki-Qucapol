#include <iostream>

using namespace std;

int main()
{
    cout << "Enter a, b, c, d: "<< endl;
    int x, y, a, b, c, d;
    cin >> a >> b >> c >> d;

    /* x - результат обчислення за допомогою побітових операцій
    *  y -результат обчислень звичайним способом(для перевірки правильності x)
    **/

    x=(a+(a<<4)+(c<<8)+(c<<5)+(c<<4)+(c<<3)>>5) -((b<<7)-(b<<3))+(d-(d<<7)); 
    y=((17*a+312*c)/32)-((b*120)+(d*127)); 
    cout << "x=" << x << endl;
    cout << "y=" << y << endl;
    return(0);
}
