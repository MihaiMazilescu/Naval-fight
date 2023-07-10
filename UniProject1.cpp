#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Spaceship {

    string mName;
    int mAttack, mShield;
public:
    Spaceship()
    {
        mName = "nedefinit";
        mAttack = 0;
        mShield = 0;
    }

    Spaceship(string a, int b, int c)
    {
        mName = a;
        mAttack = b;
        mShield = c;
    }

    Spaceship(const Spaceship& a)
    {
        mName = a.mName;
        mAttack = a.mAttack;
        mShield = a.mShield;
    }

    string getName() const
    {
        return mName;
    }

    int getAttack() const
    {
        return mAttack;
    }

    int getShield() const
    {
        return mShield;
    }

    void setName(string a)
    {
        mName = a;
    }

    void setAttack(int a)
    {
        mAttack = a;
    }

    void setShield(int a)
    {
        mShield = a;
    }

    Spaceship operator= (const Spaceship& a)
    {
        mName = a.mName;
        mAttack = a.mAttack;
        mShield = a.mShield;
        return *this;

    }

    Spaceship operator+= (const Spaceship& a)
    {
        mAttack = mAttack + a.mAttack;
        mShield = mShield + a.mShield;
        return *this;
    }

    Spaceship operator-= (const Spaceship& a)
    {
        mShield = mShield - a.mAttack;
        return *this;
    }

    Spaceship operator^ (const Spaceship& a)
    {
        Spaceship copie1(*this);
        Spaceship copie2(a);

        while (copie1.mShield > 0 && copie2.mShield > 0)
        {
            copie1 -= copie2;
            if (copie1.mShield < 0) return copie2;
            else copie2 -= copie1;
        }

        return copie1;
    }

};

int find_nava(vector <Spaceship> a, int n, string k)
{
    for (int j = 0; j < n; j++)
    {
        if (a[j].getName() == k) return j;
    }
    return 0;
}


int main()
{
    int n;
    cin >> n;
    vector <Spaceship> nave;
    string a;
    int b, c;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        Spaceship nava(a, b, c);
        nave.push_back(nava);
    }

    int k;
    cin >> k;
    string comanda;
    string n1, n2;
    for (int i = 0; i < k; i++)
    {
        cin >> comanda >> n1 >> n2;
        if (comanda == "lupta") nave[find_nava(nave, n, n1)] ^ nave[find_nava(nave, n, n2)];
        else nave[find_nava(nave, n, n1)] += nave[find_nava(nave, n, n2)];
    }

    int max = 0;
    int index = 0;

    for (int i = 0; i < n; i++)
    {
        if (nave[i].getAttack() + nave[i].getShield() > max)
        {
            max = nave[i].getAttack() + nave[i].getShield();
            index = i;
        }
    }

    cout << nave[index].getName();

    return 0;
}