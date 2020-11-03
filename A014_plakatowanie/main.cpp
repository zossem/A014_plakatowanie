#include <iostream>
#include<algorithm>

using namespace std;

struct blok
{
    long numer;
    long wysokosc;
};

bool jak(blok &a, blok b)
{
    if(a.wysokosc<b.wysokosc)
        return true;
    else if(a.wysokosc==b.wysokosc && a.numer<b.numer)
        return true;
    else
        return false;
}

int main()
{
    long wysokosc, dlugosc;
    long i, j, n, odp;
    blok *szeregowiec;
    long pomocny_szeregowiec[250000];
    bool a;

    scanf("%ld", &n);
    odp=n;

    if(n>0)
    {
        szeregowiec = new blok[n];
    }
    if(szeregowiec == NULL)
    {
        return 1;
    }

    for(i=0;i<n;i++)
    {
        scanf("%ld", &dlugosc);
        scanf("%ld", &wysokosc);
        szeregowiec[i].numer=i;
        szeregowiec[i].wysokosc=wysokosc;
        pomocny_szeregowiec[i]=wysokosc;
    }

    sort(szeregowiec, szeregowiec+n, jak);

    for(i=1;i<n;i++)
    {
        if(szeregowiec[i].wysokosc == szeregowiec[i-1].wysokosc)
        {
            a=true;
            for(j=((szeregowiec[i-1].numer)+1); j<szeregowiec[i].numer; j++)
            {
                if(pomocny_szeregowiec[j]<szeregowiec[i].wysokosc)
                    {
                        a=false;
                        break;
                    }
            }
            if(a == true)
                odp--;
        }
    }

    printf("%ld", odp);

    delete[] szeregowiec;
    szeregowiec=NULL;

    return 0;
}
