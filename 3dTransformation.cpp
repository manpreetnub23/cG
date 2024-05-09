#include <iostream>
#include <cmath>

struct Point3D {
    float x, y, z;
};

// Translation function
void translate(Point3D& p, float tx, float ty, float tz) {
    p.x += tx;
    p.y += ty;
    p.z += tz;
}

// Rotation around X-axis function
void rotateX(Point3D& p, float angle) {
    float tempY = p.y;
    p.y = p.y * cos(angle) - p.z * sin(angle);
    p.z = tempY * sin(angle) + p.z * cos(angle);
}

// Rotation around Y-axis function
void rotateY(Point3D& p, float angle) {
    float tempX = p.x;
    p.x = p.x * cos(angle) + p.z * sin(angle);
    p.z = -tempX * sin(angle) + p.z * cos(angle);
}

// Rotation around Z-axis function
void rotateZ(Point3D& p, float angle) {
    float tempX = p.x;
    p.x = p.x * cos(angle) - p.y * sin(angle);
    p.y = tempX * sin(angle) + p.y * cos(angle);
}

// Scaling function
void scale(Point3D& p, float sx, float sy, float sz) {
    p.x *= sx;
    p.y *= sy;
    p.z *= sz;
}

// Parallel projection function
void parallelProjection(Point3D& p, float distance) {
    p.x /= (1 / distance);
    p.y /= (1 / distance);
}

// Perspective projection function
void perspectiveProjection(Point3D& p, float distance) {
    p.x /= (p.z / distance);
    p.y /= (p.z / distance);
}

int main() {
    // Define original 3D object
    Point3D object[] = {{1, 1, 1}, {2, 1, 1}, {2, 2, 1}, {1, 2, 1}, {1, 1, 2}, {2, 1, 2}, {2, 2, 2}, {1, 2, 2}};
    int n = sizeof(object) / sizeof(object[0]);

    // Apply transformations
    std::cout << "Original Object:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "Point " << i + 1 << ": (" << object[i].x << ", " << object[i].y << ", " << object[i].z << ")" << std::endl;
    }

    // Translate the object
    float tx = 1, ty = 1, tz = 1;
    for (int i = 0; i < n; i++) {
        translate(object[i], tx, ty, tz);
    }
    std::cout << "\nAfter Translation:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "Point " << i + 1 << ": (" << object[i].x << ", " << object[i].y << ", " << object[i].z << ")" << std::endl;
    }

    // Rotate the object around X-axis
    float angleX = M_PI / 4; // 45 degrees in radians
    for (int i = 0; i < n; i++) {
        rotateX(object[i], angleX);
    }
    std::cout << "\nAfter Rotation around X-axis:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "Point " << i + 1 << ": (" << object[i].x << ", " << object[i].y << ", " << object[i].z << ")" << std::endl;
    }

    // Scale the object
    float sx = 2, sy = 2, sz = 2;
    for (int i = 0; i < n; i++) {
        scale(object[i], sx, sy, sz);
    }
    std::cout << "\nAfter Scaling:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "Point " << i + 1 << ": (" << object[i].x << ", " << object[i].y << ", " << object[i].z << ")" << std::endl;
    }

    // Apply parallel projection
    float distance_parallel = 2;
    std::cout << "\nAfter Parallel Projection:" << std::endl;
    for (int i = 0; i < n; i++) {
        parallelProjection(object[i], distance_parallel);
        std::cout << "Point " << i + 1 << ": (" << object[i].x << ", " << object[i].y << ")" << std::endl;
    }

    // Apply perspective projection
    float distance_perspective = 5;
    std::cout << "\nAfter Perspective Projection:" << std::endl;
    for (int i = 0; i < n; i++) {
        perspectiveProjection(object[i], distance_perspective);
        std::cout << "Point " << i + 1 << ": (" << object[i].x << ", " << object[i].y << ")" << std::endl;
    }

    return 0;
}
