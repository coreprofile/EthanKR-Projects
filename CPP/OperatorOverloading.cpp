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
    
    
    Vector2 Mul(const Vector2& other) const
    {
        return Vector2(x * other.x, y * other.y);
    }
      Vector2 operator*(const Vector2& other) const
    {
        return Mul(other);
    }
    
    
    
    Vector2 Sub(const Vector2& other) const
    {
        return Vector2(x - other.x, y - other.y);
    }
      Vector2 operator-(const Vector2& other) const
    {
        return Sub(other);
    }
    
    
    Vector2 Div(const Vector2& other) const
    {
        return Vector2(x / other.x, y / other.y);
    }
      Vector2 operator/(const Vector2& other) const
    {
        return Div(other);
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
    
    Vector2 Final = vec + vec2;
    
    cout<<Final<<endl;
    
    return 0;
}
