class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr = -1, sc = -1;
        int litterCount = 0;

        vector<vector<int>> litterId(m, vector<int>(n, -1));

        // Find S and give each L a bit number.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    litterId[i][j] = litterCount++;
                }
            }
        }

        int totalMasks = 1 << litterCount;
        int allCollected = totalMasks - 1;

        /*
            best[r][c][mask] = maximum energy with which
            we have already reached (r, c) having this mask.

            If we reach the same state with less or equal energy,
            there is no reason to process it again.
        */
        vector<int> best(m * n * totalMasks, -1);

        auto index = [&](int r, int c, int mask) {
            return (r * n + c) * totalMasks + mask;
        };

        struct State {
            int r;
            int c;
            int mask;
            int energy;
        };

        queue<State> q;

        best[index(sr, sc, 0)] = energy;
        q.push({sr, sc, 0, energy});

        int moves = 0;

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                State cur = q.front();
                q.pop();

                int r = cur.r;
                int c = cur.c;
                int mask = cur.mask;
                int e = cur.energy;

                // All litter collected.
                if (mask == allCollected) {
                    return moves;
                }

                /*
                    If energy is 0, we can only continue from R.
                    R immediately restores energy.
                */
                if (e == 0) {
                    if (classroom[r][c] == 'R') {
                        e = energy;
                    } else {
                        continue;
                    }
                }

                for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    // Outside grid.
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                        continue;
                    }

                    // Obstacle.
                    if (classroom[nr][nc] == 'X') {
                        continue;
                    }

                    // Moving costs 1 energy.
                    int ne = e - 1;
                    int nmask = mask;

                    // Collect litter.
                    if (classroom[nr][nc] == 'L') {
                        int id = litterId[nr][nc];
                        nmask |= (1 << id);
                    }

                    // R resets energy immediately.
                    if (classroom[nr][nc] == 'R') {
                        ne = energy;
                    }

                    int idx = index(nr, nc, nmask);

                    /*
                        Dominance optimization:

                        If we have already reached this exact
                        position + mask with MORE energy,
                        this new state can never be better.
                    */
                    if (best[idx] >= ne) {
                        continue;
                    }

                    best[idx] = ne;

                    q.push({
                        nr,
                        nc,
                        nmask,
                        ne
                    });
                }
            }

            moves++;
        }

        return -1;
    }
};

