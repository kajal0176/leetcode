class Solution {
public:
    // Compute the difference between the lower area and upper area given the cut at 'mid'
    double isp(const vector<pair<int,int>>& yc, double mid) {
        double lower = 0, upper = 0;
        for (const auto &p : yc) {
            double y1 = p.first, y2 = p.second;
            double len = y2 - y1;
            if (y2 <= mid) { 
                // Entire square is below mid.
                lower += len * len;
            } else if (y1 >= mid) { 
                // Entire square is above mid.
                upper += len * len;
            } else {  
                // The square is split by mid.
                double below = mid - y1;
                double above = y2 - mid;
                lower += below * len;
                upper += above * len;
            }
        }
        return lower - upper;  // We want lower == upper (i.e. diff == 0)
    }
    
    double separateSquares(vector<vector<int>>& squares) {
        vector<pair<int,int>> yc;
        double low = 1e18, high = -1e18;
        
        for (const auto& sq : squares) {
            low = min(low, static_cast<double>(sq[1]));
            high = max(high, static_cast<double>(sq[1] + sq[2]));
        }
        // Build a vector of (y, y+len) pairs for each square.
        for (int i = 0; i < squares.size(); i++){
            yc.push_back({squares[i][1], squares[i][1] + squares[i][2]});
        }
        
        double i_val = low, j_val = high;
        double eps = 1e-5;
       
        while (j_val - i_val > eps) {
            double mid = (i_val + j_val) / 2;
            
            if (isp(yc, mid) < 0) {
                i_val = mid;
            } else {
                j_val = mid;
            }
        }
        return i_val;
    }
};
