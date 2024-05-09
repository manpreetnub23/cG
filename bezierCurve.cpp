#include <iostream>
#include <vector>

// Function to compute Bezier curve point using de Casteljau's algorithm
std::pair<float, float> deCasteljau(const std::vector<std::pair<float, float>>& points, float t) {
    if (points.size() == 1) return points[0];
    std::vector<std::pair<float, float>> intermediate(points.size() - 1);
    for (size_t i = 0; i < intermediate.size(); ++i) {
        intermediate[i].first = (1 - t) * points[i].first + t * points[i + 1].first;
        intermediate[i].second = (1 - t) * points[i].second + t * points[i + 1].second;
    }
    return deCasteljau(intermediate, t);
}

int main() {
    // Define control points for the Bezier curve
    std::vector<std::pair<float, float>> controlPoints = {{100, 300}, {200, 100}, {400, 400}, {500, 200}};

    // Compute and print Bezier curve coordinates
    std::cout << "Bezier Curve Coordinates:" << std::endl;
    for (int i = 0; i <= 100; ++i) {
        float t = static_cast<float>(i) / 100;
        auto point = deCasteljau(controlPoints, t);
        std::cout << "(" << point.first << ", " << point.second << ")" << std::endl;
    }

    return 0;
}
