#include <iostream>

struct Point {
    int x, y;
};

// Helper function to calculate the direction of a point relative to a line
int direction(Point a, Point b, Point c) {
    return ((b.x - a.x) * (c.y - a.y)) - ((c.x - a.x) * (b.y - a.y));
}

// Function to check if a point is inside the clip boundary
bool inside(Point p, Point clipMin, Point clipMax) {
    return (p.x >= clipMin.x && p.x <= clipMax.x && p.y >= clipMin.y && p.y <= clipMax.y);
}

// Function to clip a polygon using Sutherland-Hodgman algorithm
void sutherlandHodgman(Point* polygon, int n, Point clipMin, Point clipMax) {
    Point result[100];
    int k = 0;

    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        // If the line segment from polygon[i] to polygon[j] is inside the clip boundary
        if (inside(polygon[i], clipMin, clipMax)) {
            result[k++] = polygon[i];
        }
        // If the line segment crosses the clip boundary, add the intersection point
        if (direction(polygon[i], polygon[j], clipMin) * direction(polygon[i], polygon[j], clipMax) < 0) {
            Point intersect;
            intersect.x = polygon[i].x + (polygon[j].x - polygon[i].x) * (clipMin.y - polygon[i].y) / (polygon[j].y - polygon[i].y);
            intersect.y = clipMin.y;
            result[k++] = intersect;
        }
        if (direction(polygon[i], polygon[j], clipMax) * direction(polygon[i], polygon[j], clipMin) < 0) {
            Point intersect;
            intersect.x = polygon[i].x + (polygon[j].x - polygon[i].x) * (clipMax.y - polygon[i].y) / (polygon[j].y - polygon[i].y);
            intersect.y = clipMax.y;
            result[k++] = intersect;
        }
    }

    // Output the clipped polygon
    std::cout << "Clipped polygon:" << std::endl;
    for (int i = 0; i < k; i++) {
        std::cout << "(" << result[i].x << ", " << result[i].y << ")" << std::endl;
    }
}

int main() {
    // Define the polygon and clipping window
    Point polygon[] = {{50, 150}, {200, 50}, {350, 150}, {350, 300}, {250, 300}, {200, 250}, {150, 350}, {100, 250}, {100, 200}};
    Point clipMin = {100, 100};
    Point clipMax = {300, 300};
    int n = sizeof(polygon) / sizeof(polygon[0]);

    // Perform polygon clipping
    sutherlandHodgman(polygon, n, clipMin, clipMax);

    return 0;
}
