class Solution { 
public: 
    bool checkOverlap(int radius, int xCenter, int yCenter,int x1, int y1, int x2, int y2) { 
 
        if (xCenter >= x1 && xCenter <= x2 && yCenter >= y1 && yCenter <= y2) 
            return true; 
 
        if (abs(xCenter - x1) <= radius && yCenter >= y1 && yCenter <= y2) 
            return true; 
 
        if (abs(xCenter - x2) <= radius && yCenter >= y1 && yCenter <= y2) 
            return true; 
 
        if (abs(yCenter - y1) <= radius && xCenter >= x1 && xCenter <= x2) 
            return true; 
 
        if (abs(yCenter - y2) <= radius && xCenter >= x1 && xCenter <= x2) 
            return true; 
 
        if ((xCenter - x1) * (xCenter - x1) + (yCenter - y1) * (yCenter - y1) <= radius * radius) 
            return true; 
 
        if ((xCenter - x1) * (xCenter - x1) + (yCenter - y2) * (yCenter - y2) <= radius * radius) 
            return true; 
 
        if ((xCenter - x2) * (xCenter - x2) + (yCenter - y1) * (yCenter - y1) <= radius * radius) 
            return true; 
 
        if ((xCenter - x2) * (xCenter - x2) +(yCenter - y2) * (yCenter - y2) <= radius * radius) 
            return true; 
 
        return false; 
    } 
};