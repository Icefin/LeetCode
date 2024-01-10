/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dimensions = binaryMatrix.dimensions();
        
        pair<int, int> pos = {0, dimensions[1] - 1};
        while (true) {
            if (pos.first >= dimensions[0] || pos.second < 0)
                break;
            
            if (binaryMatrix.get(pos.first, pos.second) == 1)
                pos.second--;
            else
                pos.first++;
        }
        if (pos.second == dimensions[1] - 1)
            return -1;
        return pos.second + 1;
    }
};