class Solution {
    map<int, pair<int , int> > dirInc = {{0, {0, 1}}, {1, {1, 0}}, {2, {0, -1}}, {3, {-1, 0}}};
    
    int updateDir(int dir, char c) {
        if(c == 'R')
            ++dir;
        else {
            --dir;
        }
        return (dir + 4) % 4;
    }
    
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0;
        int dir = 0;
        for(int i = 0; i < 4; i++) {
            for(char c : instructions) {
                if(c == 'G') {
                    x += dirInc[dir].first;
                    y += dirInc[dir].second;
                } else {
                    dir = updateDir(dir, c);
                }
            }
        }
        if(x != 0 || y != 0)
            return false;
        else
            return true;
    }
};
