/*
gfg- Pairs of Non Coinciding Points
ques:-
In a given cartesian plane, there are N points. We need to find the Number of Pairs of  points(A, B) such that

Point A and Point B do not coincide.
Manhattan Distance and the Euclidean Distance between the points should be equal.
Note: Pair of 2 points(A,B) is considered same as Pair of 2 points(B ,A).
Manhattan Distance = |x2-x1|+|y2-y1|
Euclidean Distance   = ((x2-x1)^2 + (y2-y1)^2)^0.5, where points are (x1,y1) and (x2,y2).

 

Example 1:

Input:
N = 2
X = {1, 7}
Y = {1, 5}
Output:
0
Explanation:
None of the pairs of points have
equal Manhatten and Euclidean distance.
Example 2:

Input:
N = 3

X = {1, 2, 1}
Y = {2, 3, 3}
Output:
2
Explanation:
The pairs {(1,2), (1,3)}, and {(1,3), (2,3)}
have equal Manhatten and Euclidean distance.
*/

class Solution
{
public:
    int numOfPairs(int X[], int Y[], int N)
    {
        int count = 0;
        unordered_map<int, int> x;
        unordered_map<int, int> y;
        unordered_map<string, int> p;

        for (int i = 0; i < N; i++)
        {

            int px = X[i];
            int py = Y[i];

            if (x[px] > 0)
                count += x[px];
            x[px]++;

            if (y[py] > 0)
                count += y[py];
            y[py]++;

            string temp = to_string(px) + "#" + to_string(py);
            if (p[temp] > 0)
                count -= 2 * p[temp];

            p[temp]++;
        }
        return count;
    }
};