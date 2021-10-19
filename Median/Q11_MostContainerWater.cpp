#include <algorithm>

class Solution {
public:
    int maxArea(vector<int>& height)
    {
      // use the 2 pointer approach
      int MaxWaterContent = 0;
      
      int i = 0;
      int j = height.size()-1;
      
      while(j>i)
      {
        int Min_height = min(height[i], height[j]);
        int waterContent = Min_height*(j-i);
        if (waterContent>MaxWaterContent)
        {
          MaxWaterContent = waterContent;
        }
        
        if(height[i]<height[j])
        {
          i++;
        }
        else
        {
          j--;
        }
      }
      
      /* Brutal solution
      for (int i = 0; i<height.size(); i++)
      {
        for (int j = i+1;j<height.size(); j++)
        {
          int Min_height = min(height[i], height[j]);
          int waterContent = Min_height*(j-i);
          if (waterContent>MaxWaterContent)
          {
            MaxWaterContent = waterContent;
          }
        }
      }
      */
      return MaxWaterContent;
      
    }
};