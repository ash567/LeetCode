        }
        l1.push_back(*it);
        l2.erase(it);
        
        pair<int, int> x1, x2, x3, x4;
        x1 = *(l1.begin());
        l1.erase(l1.begin());
        x3 = *(l1.begin());
        x2 = *(l2.begin());
        l2.erase(l2.begin());
        x4 = *(l2.begin());
        
//         Checkes
        if(findDistanceSquare(x1, x3) != findDistanceSquare(x2, x4) || \
           findDistanceSquare(x1, x2) != findDistanceSquare(x1, x4) || \
           findDistanceSquare(x3, x2) != findDistanceSquare(x3, x4) || \
           findDistanceSquare(x1, x2) != findDistanceSquare(x3, x2) || \
           findDistanceSquare(x3, x2) == 0 || \
           findDistanceSquare(x3, x1) <= findDistanceSquare(x3, x2)
          )
            return false;
        else return true;
    }
};
