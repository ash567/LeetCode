class Solution {
    map<int, pair<int , int> > dirInc = {{0, {0, 1}}, {1, {1, 0}}, {2, {0, -1}}, {3, {-1, 0}}};
    
    // int updateDir(int dir, char c) {
    //     if(c == 'R')
    //         ++dir;
    //     else {
    //         --dir;
    //     }
    //     return (dir + 4) % 4;
    // }
    
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0;
        int dir = 0;
//         You can also run it 4 times and find out if it comes to origin.
        for(char c : instructions) {
            if(c == 'G') {
                x += dirInc[dir].first;
                y += dirInc[dir].second;
            } else {
                if(c == 'L')
                    dir++;
                else
                    dir--;
                dir += 4;
                dir %= 4;
                // dir = updateDir(dir, c);
            }
        }
        if((x == 0 and y == 0) or (dir != 0))
            return true;
        else
            return false;
    }
};
