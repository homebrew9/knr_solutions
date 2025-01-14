#include <stdio.h>
#define XMAX 320
#define YMAX 200
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

// Global structs
struct point {
    int x;
    int y;
};
struct rect {
    struct point pt1;
    struct point pt2;
};

// Function section
struct point makepoint(int x, int y) {
    /* Make a point from x and y components */
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

struct point addpoints(struct point p1, struct point p2) {
    /* Important information:
     *     "We incremented the components in p1 rather than using an explicit
     *     temporary variable to emphasize that structure parameters are passed
     *     by value like any others." -- K&R 2nd Edition, Page 130
     */
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

struct rect canonrect(struct rect r) {
    /* canonrect: canonicalize coordinates of rectangle */
    struct rect temp;
    temp.pt1.x = min(r.pt1.x, r.pt2.x);
    temp.pt1.y = min(r.pt1.y, r.pt2.y);
    temp.pt2.x = max(r.pt1.x, r.pt2.x);
    temp.pt2.y = max(r.pt1.y, r.pt2.y);
    return temp;
}

void print_point(char *text, struct point p) {
    printf("%s (%d,%d)\n", text, p.x, p.y);
}

void print_rect(char *text, struct rect r) {
    printf("%s\n", text);
    print_point("\tVertex pt1:", r.pt1);
    print_point("\tVertex pt2:", r.pt2);
}

int is_point_in_rect(struct point p, struct rect r) {
    // First, canonicalize rect r
    r = canonrect(r);
    print_rect("After canonicalization, rect r =>", r);
    // We can also return a more fine-grained output like:
    // Case 1) Point is inside the rectangle  => return 1, or
    // Case 2) Point is on the side           => return 2, or
    // Case 3) Point is a vertex              => return 3, or
    // Case 4) Point is outside the rectangle => return 0
    // The following statement simply returns 1 if Cases 1,2,3 or 0 if Case 4.
    return ((r.pt1.x <= p.x && p.x <= r.pt2.x) &&
            (r.pt1.y <= p.y && p.y <= r.pt2.y));
}

// Main section
int main(int argc, char **args) {
    struct point origin;
    origin = makepoint(0, 0);
    print_point("Origin :", origin);
    printf("==================================================\n");
    struct rect screen;
    screen.pt1 = makepoint(0, 0);
    screen.pt2 = makepoint(XMAX, YMAX);
    struct point middle = makepoint((screen.pt1.x + screen.pt2.x)/2,
                                    (screen.pt1.y + screen.pt2.y)/2);
    print_rect("Rect screen =>", screen);
    print_point("Screen Midpoint:", middle);
    printf("==================================================\n");
    struct point p1 = makepoint(2, 4);
    struct point p2 = makepoint(9, 1);
    struct point p3 = addpoints(p1, p2);
    print_point("Point p1 :", p1);
    print_point("Point p2 :", p2);
    print_point("Add p1 and p2 to get point p3 :", p3);
    print_point("Did p1 change? Let's check p1 :", p1);
    printf("==================================================\n");

    // Transform a rectangle into canonical form.
    struct rect r;
    r.pt1 = makepoint(23, 79);
    r.pt2 = makepoint(-20, 120);
    print_rect("Before canonicalization: rect r =>", r);
    r = canonrect(r);
    print_rect("After canonicalization : rect r =>", r);
    printf("==================================================\n");
    // Try again with a different set of vertices
    r.pt1 = makepoint(2, -7);
    r.pt2 = makepoint(30, 10);
    print_rect("Before canonicalization: rect r =>", r);
    r = canonrect(r);
    print_rect("After canonicalization : rect r =>", r);
    printf("==================================================\n");

    // Test if a point is inside a rectangle
    struct point p;
    p = makepoint(0, 0);
    r.pt1 = makepoint(5, 1);
    r.pt2 = makepoint(-4, 4);
    print_point("Point p: ", p);
    print_rect("Rectangle r: ", r);
    printf("Is point p in rectangle r? => %d\n", is_point_in_rect(p, r));
    printf("==================================================\n");
    p = makepoint(3, 3);
    print_point("Point p: ", p);
    print_rect("Rectangle r: ", r);
    printf("Is point p in rectangle r? => %d\n", is_point_in_rect(p, r));

    return 0;
}

