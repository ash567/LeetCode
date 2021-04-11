            else {
                newPoints.push_back(getAngle(xp - location[0], yp - location[1]));
            }
        }
        sort(newPoints.begin(), newPoints.end());
        int newPointSize = newPoints.size();
        double startAngle = 0, endAngle = -angle;
        int idx = 0, maxPoints = 0, backPtr = 0;;
        while(idx < newPoints.size()) {
            startAngle = newPoints[idx];
            endAngle = startAngle - angle;
            while(endAngle > newPoints[backPtr]) {
                backPtr++;
            }
            idx++;
            maxPoints = max(maxPoints, idx - backPtr);
        }
        while(backPtr < newPoints.size()) {
            int idxUsed = idx % (int) newPoints.size();
            startAngle = newPoints[idxUsed] + 360;
            endAngle = startAngle - angle;
            while(backPtr < newPoints.size() && endAngle > newPoints[backPtr]) {
                backPtr++;
            }
            idx++;
            maxPoints = max(maxPoints, idx - backPtr);
        }
        return maxPoints + addExtra;
    }
};
