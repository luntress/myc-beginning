#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    double a = 1;
    double bound = 1.3 * sqrt(a);
    double step = 0.05;

    for (double y = bound; y >= -bound; y -= step)
    {
        for (double x = -bound; x <= bound; x += 0.5*step)
        {
double result = pow(pow(x, 2) + pow(y, 2) - a, 3) - (pow(x, 2) * pow(y, 3));
            if (result <= 0)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }

    cin.get(); // 等待用户输入，防止窗口关闭
    return 0;
}
