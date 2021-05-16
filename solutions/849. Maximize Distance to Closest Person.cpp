class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int front = 0, back = -1, ans = 1;
        while(front < seats.size()) {
            while(front < seats.size() && seats[front] == 0) {
                front++;
            }
            int betweenPeople = (front - back - 1);
            if(betweenPeople > 0) {
                if(back != -1 && front != seats.size())
                    ans = max(ans, (betweenPeople - 1)/2 + 1);
                else
                    ans = max(ans, betweenPeople);
            }
            back = front;
            front++;
        }
        return ans;
    }
};
