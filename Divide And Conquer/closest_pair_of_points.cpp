#include<bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

bool compareY(Point a, Point b) {return a.y < b.y;}
bool compareX(Point a, Point b) {return a.x < b.x;}
float distance(Point a, Point b) {return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));}

float smallProblem(Point p[], int start, int end) {
    float minDist = FLT_MAX;
    for(int i = start ; i < end ; i++) {
        for(int j = i+1; j < end ; j++) {
            minDist = min(minDist, distance(p[i], p[j]));
        }
    }
    return minDist;
}

/* 
    stripClosest may seem quadratic, but it's actually linear since inner loop 
    runs a few countable iterations only.
*/
float stripClosest(Point* strip, int n, float d) {
    float minAns = d;
    sort(strip, strip + n, compareY);

    for(int i = 0 ; i < n; i++) 
        for(int j = i+1; j < n && (strip[j].y - strip[i].y) < minAns ; j++) 
            if(distance(strip[i], strip[j]) < minAns)
                minAns = distance(strip[i], strip[j]);
    return minAns;
}

float findClosest(Point p[], int start, int end) {
    if(end - start <= 2) {
        return smallProblem(p, start, end);
    }
    int mid = (end + start)/2;
    Point midPoint = p[mid];
    float leftClosest = findClosest(p, start, mid);
    float rightClosest = findClosest(p, mid+1, end);
    float minAns = min(leftClosest, rightClosest);

    Point* strip = new Point[end - start + 1];
    int j = 0;
    for(int i = 0 ; i < end - start + 1 ; i++) 
        if(abs(p[i].x - midPoint.x) < minAns) strip[j++] = p[i];
    
    float combinedAns = stripClosest(strip, j, minAns);
    delete[] strip;
    return min(combinedAns, minAns);
}

int main() {
    Point points[] = {{2, 3}, {12, 30}, {40, 50}, {1, 1}, {12, 10}, {5, 4}};
    int n = sizeof(points)/sizeof(points[0]);
    sort(points, points + n, compareX);
    cout <<  findClosest(points, 0, n-1) << endl;
    return 0;
}