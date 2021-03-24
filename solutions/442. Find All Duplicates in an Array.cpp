            } while(hare != turtle && nums[hare] > 0);
            if(nums[hare] < 0) {
                while(nums[turtle] > 0)
                    turtle = nums[turtle] - 1;
                ans.push_back(turtle + 1);
            } else {
                turtle = i;
                while(turtle != hare) {
                    hare = nums[hare] - 1;
                    turtle = nums[turtle] - 1;            
                }
                ans.push_back(turtle + 1);
            }
            int markTurtle = i;
            while(markTurtle >= 0 && nums[markTurtle] > 0) {
                int k = nums[markTurtle] - 1;
                nums[markTurtle] = -nums[markTurtle];
                markTurtle = k;
            }   
        }*/
        
        int i = 0;
        while(i < nums.size()) {
            if(nums[i] < 0) {
                i++;
                continue;
            }
            int idx = nums[i] - 1;
            if(idx == i) {
                nums[i] = -nums[i];
                i++;
            } else {
                if(nums[idx] > 0) {
                    nums[i] = -nums[i];
                    swap(nums[i], nums[idx]);
                } else if(-nums[idx] == nums[i]) {
                    ans.push_back(nums[i]);
                    nums[i] = -nums[i];
                    i++;
                } else {
                    nums[i] = -nums[i];
                    swap(nums[i], nums[idx]);
                }
            }
        }
        return ans;
    }
};
