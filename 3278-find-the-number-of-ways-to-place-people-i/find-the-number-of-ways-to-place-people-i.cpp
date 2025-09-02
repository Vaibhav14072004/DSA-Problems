class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        // Step 1: Sort points based on x, then y to simplify range checking
        sort(points.begin(), points.end());

        int n = points.size();
        int cnt = 0;

        // Step 2: Iterate over all unique pairs of points (i, j)
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                
                // Check if points[i] and points[j] form a valid vertical or horizontal alignment
                // points[i].x == points[j].x → vertical
                // points[i].y >= points[j].y → ensures proper orientation for rectangle
                if (points[i][0] == points[j][0] || points[i][1] >= points[j][1]) {

                    int temp = 0;

                    // Step 3: Check if any other point (not i or j) lies inside the rectangle formed by i and j
                    for (int k = 0; k < n; k++) {
                        if (k != i && k != j) {
                            int x = points[k][0];
                            int y = points[k][1];

                            int x1 = points[i][0];
                            int y1 = points[i][1];

                            int x2 = points[j][0];
                            int y2 = points[j][1];

                            // Check if point k lies within the rectangle formed by points i and j
                            if ((x1 <= x && x <= x2) && ((y2 <= y && y <= y1) || (y1 <= y && y <= y2)))
                                break; // Point is inside → not a valid pair
                            else
                                temp++;
                        }
                    }

                    // If no point was found inside the rectangle, this is a valid pair
                    if (temp == n - 2)
                        cnt++;
                }
            }
        }

        return cnt;
    }
};