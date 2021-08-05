class Solution {
public:
    // the idea is Manacher algorithm
    // for each element, use the element as the center, do:
    // check whether the its left element and right element is the same char as itself. if yes, group it together and go one more left or right until we hit a differernt char.
    
    // after we done with getting the same adjacent chars, we start to check whether the left and the right char is the same, and the next left and next right until we find them not the same.
    //record the string and compare it to the longest substring we have so far to see if we should update the longest substring or not
    //go on with the next element.
    
    string longestPalindrome(string s) {

        string ans=s.substr(0,1);
        int length=1;
        if (s.length()==2)
        {
            if (s[0]==s[1])
            {
                ans = s;
            }
        }
        else if (s.length() > 2)
        {

            string candidate="";
            for (int i=1; i<=s.length()-1;i++)
            {
                candidate="";
                candidate.append(s.substr(i,1));
                int j=i-1;
                int k=i+1;

                while ( j>=0 )
                {
                    if (s[j]==s[i])
                    {
                        candidate.insert(0,s.substr(j,1));
                        j--;
                    }
                    else
                    {
                        break;
                    }                      
                }
                
                while(k <= s.length()-1)
                {
                    if (s[i]==s[k])
                    {
                        candidate.append(s.substr(k,1));
                        k++;                        
                    }
                    else
                    {
                        break;
                    }                    
                }
                
                while (j>=0 && k <= s.length()-1)
                {
                    
                    if(s[j]==s[k])
                    {
                        candidate.insert(0,s.substr(j,1));
                        candidate.append(s.substr(k,1));
                        j--;
                        k++;
                    }
                    else
                    {
                        break;
                    }
                }
                
                if (candidate.length() > length)
                {
                    ans = candidate;
                    length=candidate.length();
                }
            }
        }
            
        return ans;
    }
};