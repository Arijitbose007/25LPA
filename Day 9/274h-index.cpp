class Solution {
public:
    int hIndex(vector<int>& c) {
       
        int s = 0, e = c.size() - 1, avg;
       
        sort(begin(c), end(c));
       
        while (s <= e) {
            if (c[avg = (e + s) / 2] < c.size() - avg) s = avg + 1;
            else e = avg - 1;
        }
        return c.size() - s;
    }
};