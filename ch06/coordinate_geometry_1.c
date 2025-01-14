/*
 * Name : coordinate_geometry_1.c
 * Desc : This program is similar to "coordinate_geometry.c" except that it
 *        uses pointers to structures at all places.
 * By   : prat
 * On   : 10/08/2018
 */
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
void makepoint(struct point *p, int x, int y) {
    /* Make a point from x and y components */
    p->x = x;
    p->y = y;
}

void addpoints(struct point *p1, struct point *p2) {
    /* Important information:
     *     "We incremented the components in p1 rather than using an explicit
     *     temporary variable to emphasize that structure parameters are passed
     *     by value like any others." -- K&R 2nd Edition, Page 130
     */
    // Note that this function will affect the coordinates of point p1. The
    // statement above does not hold true here.
    p1->x += p2->x;
    p1->y += p2->y;
}

void canonrect(struct rect *r) {
    /* canonrect: canonicalize coordinates of rectangle */
    // I think we cannot update pt1.x, pt1.y etc. directly. We need temp variables.
    int a = min(r->pt1.x, r->pt2.x);
    int b = min(r->pt1.y, r->pt2.y);
    int c = max(r->pt1.x, r->pt2.x);
    int d = max(r->pt1.y, r->pt2.y);
    r->pt1.x = a;
    r->pt1.y = b;
    r->pt2.x = c;
    r->pt2.y = d;
}

void print_point(char *text, struct point *p) {
    printf("%s (%d,%d)\n", text, p->x, p->y);
}

void print_rect(char *text, struct rect *r) {
    printf("%s\n", text);
    print_point("\tVertex pt1:", &r->pt1);
    print_point("\tVertex pt2:", &r->pt2);
}

int is_point_in_rect(struct point *p, struct rect *r) {
    // First, canonicalize rect r
    canonrect(r);
    print_rect("After canonicalization, rect r =>", r);
    // We can also return a more fine-grained output like:
    // Case 1) Point is inside the rectangle  => return 1, or
    // Case 2) Point is on the side           => return 2, or
    // Case 3) Point is a vertex              => return 3, or
    // Case 4) Point is outside the rectangle => return 0
    // The following statement simply returns 1 if Cases 1,2,3 or 0 if Case 4.
    return ((r->pt1.x <= p->x && p->x <= r->pt2.x) &&
            (r->pt1.y <= p->y && p->y <= r->pt2.y));
}

// Main section
int main(int argc, char **args) {
    struct point origin;
    makepoint(&origin, 0, 0);
    print_point("Origin :", &origin);
    printf("==================================================\n");
    struct rect screen;
    makepoint(&screen.pt1, 0, 0);
    makepoint(&screen.pt2, XMAX, YMAX);
    struct point middle;
    makepoint(&middle, (screen.pt1.x + screen.pt2.x)/2,
                       (screen.pt1.y + screen.pt2.y)/2);
    print_rect("Rect screen =>", &screen);
    print_point("Screen Midpoint:", &middle);
    printf("==================================================\n");
    struct point p1, p2;
    makepoint(&p1, 2, 4);
    makepoint(&p2, 9, 1);
    print_point("Point p1 :", &p1);
    print_point("Point p2 :", &p2);
    printf("Add p1 and p2 to get updated point p1. There is no point p3 here.\n");
    addpoints(&p1, &p2);
    print_point("Did p1 change? Let's check p1 :", &p1);
    printf("==================================================\n");

    // Transform a rectangle into canonical form.
    struct rect r;
    makepoint(&r.pt1, 23, 79);
    makepoint(&r.pt2, -20, 120);
    print_rect("Before canonicalization: rect r =>", &r);
    canonrect(&r);
    print_rect("After canonicalization : rect r =>", &r);
    printf("==================================================\n");
    // Try again with a different set of vertices
    makepoint(&r.pt1, 2, -7);
    makepoint(&r.pt2, 30, 10);
    print_rect("Before canonicalization: rect r =>", &r);
    canonrect(&r);
    print_rect("After canonicalization : rect r =>", &r);
    printf("==================================================\n");

    // Test if a point is inside a rectangle
    struct point p;
    makepoint(&p, 0, 0);
    makepoint(&r.pt1, 5, 1);
    makepoint(&r.pt2, -4, 4);
    print_point("Point p: ", &p);
    print_rect("Rectangle r: ", &r);
    printf("Is point p in rectangle r? => %d\n", is_point_in_rect(&p, &r));
    printf("==================================================\n");
    makepoint(&p, 3, 3);
    print_point("Point p: ", &p);
    print_rect("Rectangle r: ", &r);
    printf("Is point p in rectangle r? => %d\n", is_point_in_rect(&p, &r));

    return 0;
}

