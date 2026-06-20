class Solution {
public:
    vector<int> segment;

    void build(int i, int l, int r, vector<int>& heights) {
        if (l == r) {
            segment[i] = l;
            return;
        }

        int mid = l + (r - l) / 2;

        build(2 * i + 1, l, mid, heights);
        build(2 * i + 2, mid + 1, r, heights);

        int left = segment[2 * i + 1];
        int right = segment[2 * i + 2];

        if (heights[left] >= heights[right]) {
            segment[i] = left;
        } else {
            segment[i] = right;
        }
    }

    int query(int i, int s, int e, int l, int r, vector<int>& heights) {
     
        if (r < s || e < l) {
            return -1;
        }

        if (l <= s && e <= r) {
            return segment[i];
        }

        int mid = s + (e - s) / 2;

        int leftIdx = query(2 * i + 1, s, mid, l, r, heights);
        int rightIdx = query(2 * i + 2, mid + 1, e, l, r, heights);

        if (leftIdx == -1) return rightIdx;
        if (rightIdx == -1) return leftIdx;

        if (heights[leftIdx] >= heights[rightIdx]) {
            return leftIdx;
        } else {
            return rightIdx;
        }
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();

        segment.resize(4 * n);
        build(0, 0, n - 1, heights);

        vector<int> ans;

        for (auto q : queries) {
            int s = q[0];
            int e = q[1];

           
            if (s > e) swap(s, e);

            if (s == e) {
                ans.push_back(s);
            }
            else if (heights[e] > heights[s]) {
                ans.push_back(e);
            }
            else {
                int l = e + 1;
                int r = n - 1;
                int result = -1;

                int target = max(heights[s], heights[e]);

                while (l <= r) {
                    int mid = l + (r - l) / 2;

                    int idx = query(0, 0, n - 1, l, mid, heights);

                    if (idx != -1 && heights[idx] > target) {
                        result = idx;
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }

                ans.push_back(result);
            }
        }

        return ans;
    }
};