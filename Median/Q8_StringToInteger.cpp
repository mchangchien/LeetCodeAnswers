#include <cstring>
#include <string>

class Solution {
public:
    int myAtoi(string s) {

        // initialize variables and give them default values
        long int ans = 0;
        bool sign = 1; 
        
        // handle the empty string first
        if(s.length() == 0)
        {
            // return 0;
            return int(ans);
        }
        else
        {
            // removing leading whitespace if any
            while(s[0] == ' ')
            {
                s.erase(0, 1);
            }
            
            // after leading whitespaces are removed, check the sign of the number
            if (s[0]=='-')
            {
                sign = 0;
                s.erase(0, 1);
            }
            else if (s[0]=='+')
            {
                s.erase(0, 1);
            }            

            // removing leading 0 if any
            while(s[0] == '0')
            {
                s.erase(0, 1);
            }
 
            // after removing whitespaces and 0's. Start to handle the string
            string ansStr;

            // start to go over each characters in the string
            for (int j=0;j<s.length();j++)
            {
                // convert character to the number respectively
                switch(s[j])
                {
                    case '0':
                        ansStr.push_back(s[j]);
                        ans*=10;
                        ans+=0;
                        break;
                    case '1':
                        ansStr.push_back(s[j]);
                        ans*=10;
                        ans+=1;
                        break;
                    case '2':
                        ansStr.push_back(s[j]);
                        ans*=10;
                        ans+=2;
                        break;
                    case '3':
                        ansStr.push_back(s[j]);
                        ans*=10;
                        ans+=3;
                        break;
                    case '4':
                        ansStr.push_back(s[j]);
                        ans*=10;
                        ans+=4;
                        break;
                    case '5':
                        ansStr.push_back(s[j]);
                        ans*=10;
                        ans+=5;
                        break;
                    case '6':
                        ansStr.push_back(s[j]);
                        ans*=10;
                        ans+=6;
                        break;
                    case '7':
                        ansStr.push_back(s[j]);
                        ans*=10;
                        ans+=7;
                        break;
                    case '8':
                        ansStr.push_back(s[j]);
                        ans*=10;
                        ans+=8;
                        break;
                    case '9':
                        ansStr.push_back(s[j]);
                        ans*=10;
                        ans+=9;
                        break;
                    default:
                        goto endings;
                }
                
                //if the number is more than 11 digits, then no need to continue any more, it must overflow as an int.
                if (ansStr.length()>11)
                {
                    goto endings;
                }
            }
            
            // final checking and processing
            // 1. check the sign
            // 2. check if it will overflow
            endings:
                {
                    if (sign)
                    {
                        if (ans > 2147483647)
                        {
                            return 2147483647;
                        }
                        else
                        {
                            return int(ans);                        
                        }
                    }
                    else
                    {
                        if (ans > 2147483648)
                        {
                            return -2147483648;
                        }
                        else
                        {
                            ans = int(ans);
                            int minus = ans;
                            ans-=minus;
                            ans-=minus;
                            return ans;                      
                        }
                    }                    
                }
        }
    }
};