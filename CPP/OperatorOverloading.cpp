//LEARN MORE ABOUT OSTREAM AND WHAT IT DOES IN THIS PROGRAM
//HEAVILY INFLUENCED BY THE CHERNO
#include<iostream>

using namespace std;

struct Vector2
{
    float x;
    float y;
    Vector2(float x, float y)
    
    :x(x), y(y)
    {}
    
    Vector2 Add(const Vector2& other) const
    {
        return Vector2(x + other.x, y + other.y);
    }
    
    Vector2 operator+(const Vector2& other) const
    {
        return Add(other);
    }
    friend ostream& operator<<(ostream& stream, const Vector2& other)
    {
        stream<<other.x<<", "<<other.y<<endl;
        return stream;
    }
};

int main()
{
    Vector2 vec(1.0f, 0.0f);
    Vector2 vec2(50.0f, 1.0f);
    
    
    
    cout<<vec + vec2<<endl;
    
    return 0;
}
