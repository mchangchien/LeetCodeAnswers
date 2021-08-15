#include<math.h>

class Solution {
public:
    bool isPalindrome(int x) {
        
        //we only handle positve integer because we already know the answer of zero and negative ones 
        if (x==0)
        {
            return true;
        }
        else if (x<0)
        {
            return false;
        }
        else if (x>0)
        {
            // the idea is to examine from left and right in the meantime to compare the digits
            // for the left, we use "/" to get the digit
            // for the right, we use % to get the digit
            //if we found a mismatch, we return false
            
            int leftIndex = 10;
            int rightIndex = 1;
            int leftDividend;
            int rightDividend;
            int leftDigit;
            int rightDigit;
            int left = x;
            int right = x;
            bool NotFoundFirstNonZero=true;
            
            while (leftIndex > rightIndex)
            {
                leftDividend = pow(10, leftIndex-1);
                rightDividend = pow(10, rightIndex);
                leftDigit = (left/leftDividend);
                
                if (leftDigit==0 && NotFoundFirstNonZero)
                {
                   leftIndex--;
                }
                else
                {
                    NotFoundFirstNonZero=false;
                    rightDigit=(right%rightDividend)/(rightDividend/10);
                    if (leftDigit!=rightDigit)
                    {
                        return false;
                    }
                    
                    left-=(leftDigit*leftDividend);
                    right-=(rightDigit*rightDividend/10);
                    leftIndex--;
                    rightIndex++;
                }
            }
        }
        return true;
    }
};