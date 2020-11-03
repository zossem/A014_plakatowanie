#include <iostream>
#include<stack>

using namespace std;

int main()
{
    long wysokosc, dlugosc;
    long i, n, odp=0;
    stack<long> szeregowiec;

    scanf("%ld", &n);

    for(i=0;i<n;i++)
    {
        scanf("%ld", &dlugosc);
        scanf("%ld", &wysokosc);


        while(!(szeregowiec.empty()) && szeregowiec.top()>wysokosc)
        {
            szeregowiec.pop();
            odp++;
        }


        if(szeregowiec.empty() || wysokosc > szeregowiec.top())
        {
            szeregowiec.push(wysokosc);
        }
    }

    odp+=szeregowiec.size();

    printf("%ld", odp);

    return 0;
}
