    class Solution {
    public:
        void join(vector<int>& leader, int left, int right) {
            leader[find(leader, right)] = find(leader, left);
        }

        int find(vector<int>& leader, int node) {
            if (leader[node] != node)
                leader[node] = find(leader, leader[node]);

            return leader[node];
        }
        int latestDayToCross(int R, int C, vector<vector<int>>& cells) {
            vector<int> leader(R * C + 2);
            for (int i = 0; i < R * C + 2; i++) {
                leader[i] = i;
            }
            vector<bool> water(R * C + 2, false);
            int days = 0;
            vector<int> d1 = {-1, -1, -1, 0, 0, 1, 1, 1};
            vector<int> d2 = {-1, 0, 1, -1, 1, -1, 0, 1};
            for (vector<int> cell : cells) {
                int row = cell[0];
                int col = cell[1];
                row--;
                col--;
                for (int i = 0; i < 8; i++) {
                    int dr = row + d1[i];
                    int dc = col + d2[i];
                    if (dr >= 0 && dc >= 0 && dr < R && dc < C &&
                        water[dr * C + dc ]) {
                        join(leader, row * C+col , dr * C + dc);
                    }
                }
                if (col == 0) {
                    join(leader, 0, row * C + col );
                }
                if (col == C - 1) {
                    join(leader, R * C , row *C+col );
                }
                if (leader[find(leader, 0)] == leader[find(leader, R * C )])
                    break;
                water[row * C + col] = true;
                days++;
            }

            return days;
        }
    };