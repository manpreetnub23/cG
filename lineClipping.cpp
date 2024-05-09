#include <iostream>
using namespace std;

const int INSIDE = 0, LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8;

int region_code(int x, int y, int xmin, int ymin, int xmax, int ymax) {
    int code = INSIDE;
    if (x < xmin) code |= LEFT;
    else if (x > xmax) code |= RIGHT;
    if (y < ymin) code |= BOTTOM;
    else if (y > ymax) code |= TOP;
    return code;
}

void clip_line(int &x1, int &y1, int &x2, int &y2, int xmin, int ymin, int xmax, int ymax) {
    int code1 = region_code(x1, y1, xmin, ymin, xmax, ymax);
    int code2 = region_code(x2, y2, xmin, ymin, xmax, ymax);
    bool accept = false;

    while (true) {
        if (!(code1 | code2)) {
            accept = true;
            break;
        } else if (code1 & code2) break;
        else {
            int code_out = code1 ? code1 : code2;
            int x, y;

            if (code_out & TOP) { x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1); y = ymax; }
            else if (code_out & BOTTOM) { x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1); y = ymin; }
            else if (code_out & RIGHT) { y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1); x = xmax; }
            else if (code_out & LEFT) { y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1); x = xmin; }

            if (code_out == code1) { x1 = x; y1 = y; code1 = region_code(x1, y1, xmin, ymin, xmax, ymax); }
            else { x2 = x; y2 = y; code2 = region_code(x2, y2, xmin, ymin, xmax, ymax); }
        }
    }

    if (accept) cout << "Line after clipping: (" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ")" << endl;
    else cout << "Line is completely outside the window and rejected." << endl;
}

int main() {
    int x1, y1, x2, y2;
    int xmin, ymin, xmax, ymax;

    cout << "Enter the endpoints of the line (x1, y1, x2, y2): ";
    cin >> x1 >> y1 >> x2 >> y2;

    cout << "Enter the coordinates of the window (xmin, ymin, xmax, ymax): ";
    cin >> xmin >> ymin >> xmax >> ymax;

    cout << "Original line: (" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ")" << endl;
    clip_line(x1, y1, x2, y2, xmin, ymin, xmax, ymax);

    return 0;
}
