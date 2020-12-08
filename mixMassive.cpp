#include "iostream"
#include <cstdlib>
#include <time.h>

using namespace std;

int Random(int min, int max) {
  return min + rand() % (max - min);
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    int mas[10];
    for (int i = 0; i < 10; i++) mas[i] = i; 
    for (int i = 0; i < 10; i++) cout << mas[i] << "    ";
    cout << " " << endl;
    cout << " " << endl;

    int j = 0;
    int tmp = 0;

    for (int i = 0; i < 10; i++)
    {
        
        tmp = mas[i];
        cout << "tmp = " << tmp; 
        cout << "   i = " << i;
        cout << "   mas[i] = " << mas[i];
        j = Random(i, 10);
        cout << "   j = " << j << "    j in "<< i << " to " << 10 << endl;
        mas[i] = mas[j];
       mas[j] = tmp;
    }

    cout << " " << endl;
    cout << " " << endl;
    for (int i = 0; i < 10; i++) cout << mas[i] << "    ";
    cout << " " << endl;

    return 0;
}
