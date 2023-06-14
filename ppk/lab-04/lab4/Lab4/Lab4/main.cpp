#include <iostream>
#include <random>

using namespace std;

int rand_int(int low = 0, int high = 99)
{
    static std::default_random_engine re{ std::random_device{}() };
    using Dist = std::uniform_int_distribution<int>;
    static Dist uid{};
    return uid(re, Dist::param_type{ low,high });
}

void zad1()
{
    constexpr int rozmiar = 5;
    int t[rozmiar];
    int mini=0;
    int poz = 0;
    int pom=0;
    
    for (int i = 0; i < rozmiar; i++)
    {
        t[i] = rand_int();
    }

    /*
    for (int i = 0; i < rozmiar; i++)
    {
        t[i] = rand_int();
        if (i == 0)
            mini = t[i];
        else if (mini > t[i])
        {
            mini = t[i];
            poz = i;
        }
    }

    pom = t[0];
    t[0] = t[poz];
    t[poz] = pom;
    */
    cout << "\n\n";
    for (int i = 0; i < rozmiar; i++)
    {
        cout << "t[" << i << "]= " << t[i] << endl;
    }
    
    cout << "\n\n";
    
    int j;
    for (int i = 0; i < rozmiar-1; i++)
    {
        poz = i;
        mini = t[i];
        for (j = i+1; j < rozmiar; j++)
        {
            if (mini > t[j])
            {
                mini = t[j];
                poz = j;
            }
        }
        pom = t[i];
        t[i] = t[poz];
        t[poz] = pom;
    }

    for (int i = 0; i < rozmiar; i++)
    {
        cout << "t[" << i << "]= " << t[i] << endl;
    }
    cout << "\n\n";
}
void zad2()
{
    constexpr int szerokosc=6;
    constexpr int wysokosc=4;
    int t[wysokosc][szerokosc];
    for (int i = 0; i < wysokosc; i++)
    {
        for (int j = 0; j < szerokosc; j++)
        {
            t[i][j] = rand_int();
        }
    }
    
    for (int i = 0; i < wysokosc; i++)
    {
        for (int j = 0; j < szerokosc; j++)
        {
            cout<<t[i][j]<<" ";

        }
        cout << endl;
    }
    cout << "\n\n";
    for (int i = 0; i < szerokosc; i++)
    {
        for (int j = 0; j < wysokosc; j++)
        {
            cout << t[j][i] << " ";

        }
        cout << endl;
    }
}

static const int rozmiar = 6;
constexpr int szerokosc = rozmiar;
constexpr int wysokosc = rozmiar;
int t[wysokosc][szerokosc];

void gora(int n)
{
    for (int i = 0; i < rozmiar-(2*n); i++)
    {
        if (n == 0) t[n][n + i] = i + 1;
        else t[n][n+i] = t[rozmiar-n][n-1] + rozmiar - (n * 2) + i + 1;
    }
}

void dol(int n)
{
    for (int i = 0; i < rozmiar-(2*n); i++)
    {
        t[rozmiar - n - 1][rozmiar - 1 - i-n] = t[n][rozmiar - n - 1] + rozmiar - ((n + 1) * 2) + i + 1;
    }
}

void prawo(int n)
{
    for (int i = 1; i < rozmiar - 1 - (2*n); i++)
    {
        t[i+n][rozmiar - 1 - n] = t[n][rozmiar - n - 1] + i;
    }
}

void lewo(int n)
{
    for (int i = 1; i < rozmiar - 1 - (2 * n); i++)
    {
        t[rozmiar - i - n - 1][n] = t[rozmiar - n - 1][n] + i;
    }
}

void zad3()
{
    for (int i = 0;i < rozmiar;i++)
    {
        for (int j = 0;j < rozmiar;j++)
        {
            t[i][j] = 0;
        }
    }

    for (int i = 0; i < rozmiar / 2; i++)
    {
        gora(i);
        prawo(i);
        dol(i);
        lewo(i);
    }

    for (int i = 0;i < rozmiar;i++)
    {
        for (int j = 0;j < rozmiar;j++)
        {
            cout << t[i][j]<<"\t";
        }
        cout << endl;
    }
    


    
}
int main()
{
    //zad1();
    //zad2();
    zad3();
}