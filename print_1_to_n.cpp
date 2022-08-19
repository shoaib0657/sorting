#include <iostream>
using namespace std;

void fun(int n)
{
    if(n == 0)
    {
        return;
    }
    fun(n-1);
    cout << n << " ";
}

int main() {

    int n;
    cout << "Enter n " << endl;
    cin >> n;
    fun(n);

    return 0;
}
