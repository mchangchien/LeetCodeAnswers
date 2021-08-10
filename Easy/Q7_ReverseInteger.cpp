
// the idea is to start from the most left digit and then put all the digits in a reverse order

class Solution {
public:
    int reverse(int x) {
        // initialize variables
        // IsPositive means whether the int "x" is positive or not1
        // ansArray is an array of int to hold the digits of int "x", set all the elements to 0 at first 
        // ansInt is the answer's placeholder
        bool IsPositive = 1;
        int * ansArray = new int[10];
        for (int i=0; i<=9;i++)
        {
            ansArray[i]=0;
        }
        int ansInt=0;
        
        // check if int x is negative or 0
        // if it's 0, then return 0 directly
        // if it's negative, check if it's negatively maximum(-2147483648) as 32 bit integer starts from -2147483648 to 2147483647
        // we exclude -2147483648 so that the rest starts from -2147483647 to 2147483647 because we are going to change it to positive
        // first by it minusing itself twice (if -2147483648 minus itself twice, it will go beyond the positive maximum)
        // for -2147483648, return 0 because the reverse of it overflows.
        if (x<0)
        {
            if(x == -2147483648)
            {
                return 0;
            }
            IsPositive=0;
            
            // minus itself twice to remain the same value but positive
            int minus=x;
            x-=minus;
            x-=minus;
        }
        else if (x==0)
        {
            return 0;
        }

        //initialize variables
        //string "ans" is for the final comparison for overflow because we can't use 64-bit integer
        // IsFirstDigitFound represents if we have met the first digit of non-zero value
        // j represents the digit of the ansInt
        string ans = "";
        bool IsFirstDigitFound=0;
        int j =0;
        
        // start from the nineth digit to the first digit ( 1,000,000,000, then 100,000,000 and then 10,000,000 ... 10, 1.)
        // to examine which int x's digits have non-zero value
        for (int i=9;i>=0;i--)
        {
            int y =int(pow(10,i));
            
            // we dont want something like 123 (which is basically 0,000,000,123 here) to become 3,210,000,000
            // so we've got to start incrementing "j" until we met the first digit of non-zero value
            // and after that, that's when we can count each following digit of 0 in.
            if((x/y)>0||IsFirstDigitFound)
            {
                IsFirstDigitFound=1;
                int k = x/y;
                ansArray[j]=k; // set the value for the correct digit
                //substrate what we have. For example 321, after we get the value 3 by dividing 321 to 100. we need to substract 321 with 300
                // so that in the next round, we wont divide 321 to 10 and get the weird result: 32
                x-=(y*k); 

                // below is to form a string "ans"
                switch(k)
                {
                    case 0:
                        ans.insert(0,"0");
                        break;
                    case 1:
                        ans.insert(0,"1");
                        break;
                    case 2:
                        ans.insert(0,"2");
                        break;
                    case 3:
                        ans.insert(0,"3");
                        break;
                    case 4:
                        ans.insert(0,"4");
                        break;
                    case 5:
                        ans.insert(0,"5");
                        break;
                    case 6:
                        ans.insert(0,"6");
                        break;
                    case 7:
                        ans.insert(0,"7");
                        break;
                    case 8:
                        ans.insert(0,"8");
                        break;
                    case 9:
                        ans.insert(0,"9");
                        break;
                }
                j++;
            }
        }
        
        // make up of the string to full 10 digit before comparison, otherwise 321>2147483647 in the comparison
        while (ans.length() <10)
        {
          ans.insert(0,"0");  
        }
        
        // if greater than 2147483647, means overflow happens, return 0
        if(ans>"2147483647")
        {
            return 0;
        }
        else
        {
            //esle, start to form the final answer by getting the value of each digit stored in ansArray
            for (int i=0; i<=9;i++)
            {
                ansInt+=(ansArray[i]*pow(10,i));
            }
            
            // adjust based on the sign - whether it's positive or negative
            if(IsPositive)
            {
                return ansInt;
            }
            else
            {
                int minus = ansInt;
                ansInt-=minus;
                ansInt-=minus;
                return ansInt;
            }
        }
    }
};