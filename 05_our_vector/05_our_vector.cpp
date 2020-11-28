// 05_our_vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

template<typename T>
class Vector
{
private:
    T* myData = new T[2]; //namų darbe - nullptr;
    size_t mySize = 0;
    size_t myCapacity = 2;

    void EnsureCapacity(size_t newCapacity) {
        //TODO NAMŲ DARBAS (2) - realizuoti. Laikome, kad tik didinam.
        //2.1. Sukurti naują masyvą, dvigubai didesnės talpos
        myCapacity = newCapacity * 2;
        T* newData = new T[myCapacity];
        //2.2. Perkelti senus elementus į naują masyvą
        for (int i = 0; i < mySize; i++) {
            newData[i] = myData[i];
        }
        
        
        //2.4. Priskiriam naujas reikšmes
        T* myData = newData;
       
        //2.3. Išvalom seną masyvą
        delete[] newData;
    }

public:
    Vector() {
        EnsureCapacity(2);
    }

    constexpr size_t Size() const { return mySize; }

    T& operator[](size_t index) { return myData[index]; }
    const T& operator[](size_t index) const { return myData[index]; }

    T* Data() { return myData; }
    const T* Data() const { return myData; }

    void PushBack(const T& value) {
        //TODO NAMŲ DARBAS (1) - reikia patikrinti, ar užtenka talpos
        if (mySize > myCapacity) {
            EnsureCapacity(myCapacity);
        }
        myData[mySize++] = value;
        
    }
};

template<typename T>
void Print(const Vector<T>& data) {
    for (size_t i = 0; i < data.Size(); i++)
    {
        cout << data[i] << endl;
    }
}

int main()
{
    Vector<int> data;

    data.PushBack(2020);
    data.PushBack(11);
    data.PushBack(27);
/*
    for (size_t i = 0; i < data.Size(); i++)
    {
        cout << data[i] << endl;
    }
*/
    data[2] = 28;

    Print(data);

    cout << endl << "Namų darbas " << endl;
    data.PushBack(1);
    data.PushBack(2);
    data.PushBack(3);
    data.PushBack(4);
    data.PushBack(5);
    data.PushBack(6);
    data.PushBack(7);
    data.PushBack(8);
    data.PushBack(9);
    Print(data);
}
