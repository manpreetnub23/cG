#include <iostream>
#include <cmath>

struct Point
{
    float x, y, w;
};

// Translation function
void translate(Point &p, float tx, float ty)
{
    p.x += tx * p.w;
    p.y += ty * p.w;
}

// Rotation function (around origin)
void rotate(Point &p, float theta)
{
    float tempX = p.x;
    p.x = p.x * cos(theta) - p.y * sin(theta);
    p.y = tempX * sin(theta) + p.y * cos(theta);
}

// Scaling function (with respect to origin)
void scale(Point &p, float sx, float sy)
{
    p.x *= sx;
    p.y *= sy;
}

// Shearing function
void shear(Point &p, float shx, float shy)
{
    float tempX = p.x;
    p.x += shx * p.y;
    p.y += shy * tempX;
}

int main()
{
    // Define original object
    Point object[] = {{50, 50, 1}, {100, 50, 1}, {100, 100, 1}, {50, 100, 1}};
    int n = sizeof(object) / sizeof(object[0]);

    // Apply transformations
    std::cout << "Original Object:" << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << "Point " << i + 1 << ": (" << object[i].x << ", " << object[i].y << ")" << std::endl;
    }

    // Translate the object
    float tx = 50, ty = 50;
    for (int i = 0; i < n; i++)
    {
        translate(object[i], tx, ty);
    }
    std::cout << "\nAfter Translation:" << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << "Point " << i + 1 << ": (" << object[i].x << ", " << object[i].y << ")" << std::endl;
    }

    // Rotate the object (45 degrees)
    float theta = M_PI / 4; // 45 degrees in radians
    for (int i = 0; i < n; i++)
    {
        rotate(object[i], theta);
    }
    std::cout << "\nAfter Rotation:" << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << "Point " << i + 1 << ": (" << object[i].x << ", " << object[i].y << ")" << std::endl;
    }

    // Scale the object
    float sx = 1.5, sy = 0.5;
    for (int i = 0; i < n; i++)
    {
        scale(object[i], sx, sy);
    }
    std::cout << "\nAfter Scaling:" << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << "Point " << i + 1 << ": (" << object[i].x << ", " << object[i].y << ")" << std::endl;
    }

    // Shear the object
    float shx = 0.5, shy = 0.2;
    for (int i = 0; i < n; i++)
    {
        shear(object[i], shx, shy);
    }
    std::cout << "\nAfter Shearing:" << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << "Point " << i + 1 << ": (" << object[i].x << ", " << object[i].y << ")" << std::endl;
    }

    return 0;
}
