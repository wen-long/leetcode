//============================================================================
// Max Points on a Line 
//
// Given n points on a 2D plane, find the maximum number of points that lie 
// on the same straight line.
//
//
// Complexity:
// O(n^2) time, O(n^2) space
//============================================================================


/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */


#include "iostream"
#include "string"
#include "algorithm"
#include "vector"
#include "sstream"
#include "iterator"
using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
	int maxPoints(vector<Point> &points) {
		// a * x + b * y = c
		if (points.size() < 3) return points.size();
		int max = 0, temp = 0;
		double min = 0.00001;
		double a = 0, b = 0, c = 0;
		for (int pos1 = 0; pos1 < points.size(); ++pos1) {
			for (int pos2 = pos1 +1; pos2 < points.size(); ++pos2) {
				temp = 0;
				if (points[pos1].x == points[pos2].x) {
					a = 1;
					b = 0;
					c = points[pos1].x;
					for (int i = 0; i < points.size(); ++i) {
						if (fabs(a * points[i].x + b * points[i].y - c) < min) {
							temp++;
						}
					}
					if (max < temp) max = temp;
					continue;
				}
				if (points[pos1].y == points[pos2].y) {
					a = 0;
					b = 1;
					c = points[pos1].y;
					for (int i = 0; i < points.size(); ++i) {
						if (fabs(a * points[i].x + b * points[i].y - c) < min) {
							temp++;
						}
					}
					if (max < temp) max = temp;
					continue;
				}
				else {
					double y1 = points[pos1].y;
					double y2 = points[pos2].y;
					double x1 = points[pos1].x;
					double x2 = points[pos2].x;
					a = y1 - y2;
					b = x2 - x1;
					c = y2 * (x2 - x1) - x2 * (y2 - y1);
					for (int i = 0; i < points.size(); ++i) {
						if (fabs(a * points[i].x + b * points[i].y - c) < min) {
							temp++;
						}
					}
					if (max < temp) max = temp;
					continue;
				}
			}
		}
		if (max < temp) max = temp;
		return max;
	}
};

int main(int argc, char const *argv[]) {
	vector<Point> points1({Point(0,-12),Point(5,2),Point(2,5),Point(0,-5),Point(1,5),Point(2,-2),Point(5,-4),Point(3,4),Point(-2,4),Point(-1,4),Point(0,-5),Point(0,-8),Point(-2,-1),Point(0,-11),Point(0,-9)});
	vector<Point> points2({Point(29,87),Point(145,227),Point(400,84),Point(800,179),Point(60,950),Point(560,122),Point(-6,5),Point(-87,-53),Point(-64,-118),Point(-204,-388),Point(720,160),Point(-232,-228),Point(-72,-135),Point(-102,-163),Point(-68,-88),Point(-116,-95),Point(-34,-13),Point(170,437),Point(40,103),Point(0,-38),Point(-10,-7),Point(-36,-114),Point(238,587),Point(-340,-140),Point(-7,2),Point(36,586),Point(60,950),Point(-42,-597),Point(-4,-6),Point(0,18),Point(36,586),Point(18,0),Point(-720,-182),Point(240,46),Point(5,-6),Point(261,367),Point(-203,-193),Point(240,46),Point(400,84),Point(72,114),Point(0,62),Point(-42,-597),Point(-170,-76),Point(-174,-158),Point(68,212),Point(-480,-125),Point(5,-6),Point(0,-38),Point(174,262),Point(34,137),Point(-232,-187),Point(-232,-228),Point(232,332),Point(-64,-118),Point(-240,-68),Point(272,662),Point(-40,-67),Point(203,158),Point(-203,-164),Point(272,662),Point(56,137),Point(4,-1),Point(-18,-233),Point(240,46),Point(-3,2),Point(640,141),Point(-480,-125),Point(-29,17),Point(-64,-118),Point(800,179),Point(-56,-101),Point(36,586),Point(-64,-118),Point(-87,-53),Point(-29,17),Point(320,65),Point(7,5),Point(40,103),Point(136,362),Point(-320,-87),Point(-5,5),Point(-340,-688),Point(-232,-228),Point(9,1),Point(-27,-95),Point(7,-5),Point(58,122),Point(48,120),Point(8,35),Point(-272,-538),Point(34,137),Point(-800,-201),Point(-68,-88),Point(29,87),Point(160,27),Point(72,171),Point(261,367),Point(-56,-101),Point(-9,-2),Point(0,52),Point(-6,-7),Point(170,437),Point(-261,-210),Point(-48,-84),Point(-63,-171),Point(-24,-33),Point(-68,-88),Point(-204,-388),Point(40,103),Point(34,137),Point(-204,-388),Point(-400,-106)});
	vector<Point> points3({Point(0,0),Point(1,1),Point(1,-1)});
	vector<Point> points4({Point(0,9),Point(138,429),Point(115,359),Point(115,359),Point(-30,-102),Point(230,709),Point(-150,-686),Point(-135,-613),Point(-60,-248),Point(-161,-481),Point(207,639),Point(23,79),Point(-230,-691),Point(-115,-341),Point(92,289),Point(60,336),Point(-105,-467),Point(135,701),Point(-90,-394),Point(-184,-551),Point(150,774)});
	vector<Point> points5({Point(0,0)});
	Solution s;
	cout << s.maxPoints(points1) << endl;
	cout << s.maxPoints(points2) << endl;
	cout << s.maxPoints(points3) << endl;
	cout << s.maxPoints(points4) << endl;
	cout << s.maxPoints(points5) << endl;
	return 0;
}