#include <iostream>
#include <cmath>

struct Point
{
    float x, y, z = 1;
};

void translate(Point &point, float tx, float ty)
{
    point.x += tx * point.z;
    point.y += ty * point.z;
}

void scale(Point &point, float sx, float sy)
{
    point.x *= sx;
    point.y *= sy;
}

void rotate(Point &point, float theta)
{
    float temp = point.x;
    point.x = point.x * cos(theta) - point.y * sin(theta);
    point.y = point.y * sin(theta) + temp * cos(theta);
}
void shear(Point &p, float shx, float shy)
{
    float tempX = p.x;
    p.x += shx * p.y;
    p.y += shy * tempX;
}

int main()
{
    Point point[4];
    float theta, tx, ty, sx, sy, shx, shy;
    int choice;

    std::cout << "Enter coordinates of 4 points (x y for each point):" << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        std::cout << "Point " << i + 1 << ": ";
        std::cin >> point[i].x >> point[i].y;
    }

    do
    {
        std::cout << "\nMenu:\n1. Translate\n2. Scale\n3. Rotate\n4. Shear\n5. Exit\nEnter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Enter translation in x & y direction: ";
            std::cin >> tx >> ty;
            for (int i = 0; i < 4; i++)
            {
                translate(point[i], tx, ty);
            }
            std::cout << "After translation:" << std::endl;
            break;

        case 2:
            std::cout << "Enter scaling in x & y direction: ";
            std::cin >> sx >> sy;
            for (int i = 0; i < 4; i++)
            {
                scale(point[i], sx, sy);
            }
            std::cout << "After scaling:" << std::endl;
            break;

        case 3:
            std::cout << "Enter rotation angle (in radians): ";
            std::cin >> theta;
            for (int i = 0; i < 4; i++)
            {
                rotate(point[i], theta);
            }
            std::cout << "After rotation:" << std::endl;
            break;
        case 4:
            std::cout << "Enter shear in x and y direction : " << std::endl;
            std::cin >> shx >> shy;
            for (int i = 0; i < 4; i++)
            {
                shear(point[i], shx, shy);
            }
            std::cout << "After shearing :" << std::endl;
            break;

        case 5:
            std::cout << "Exiting..." << std::endl;
            break;

        default:
            std::cout << "Invalid choice! Please enter a valid choice." << std::endl;
            break;
        }

        // Print points after each operation
        for (int i = 0; i < 4; i++)
        {
            std::cout << "Point " << i + 1 << ": (" << point[i].x << ", " << point[i].y << ")" << std::endl;
        }
    } while (choice != 5);

    return 0;
}
