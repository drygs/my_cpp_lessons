#include <iostream>
using namespace std;




void equacao() 
{
    float x1, x2, y1, y2;
    cout << "Enter coordinates of the first point (x1 x2): ";
    cin >> x1 >> x2;
    cout << "Enter coordinates of the second point (y1 y2): ";
    cin >> y1 >> y2;

    float midX = (x1 + x2) / 2;
    float midY = (y1 + y2) / 2;

    cout << "The midpoint is: (" << midX << ", " << midY << ")" << endl;

}
int main() 
{
    equacao();
    return 0;
}
