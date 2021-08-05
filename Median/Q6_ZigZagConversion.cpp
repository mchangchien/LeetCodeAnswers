class Solution {
public:
    // the idea is to think of this way:
    // "PAYPALISHIRING", numRows=3 means we can give it index for each characters as below
    // "12321232123212"
    // and if we gather the same index of character togethers in an ascending order, then we get
    // "PAHNAPLSIIGYIR"
    // "11112222222333"
    
    
    string convert(string s, int numRows) {
        
        // initialize the variables, we need to have our index from 1 to "numRows"
        // so we create a string array with length=numRows as a placeholder for string that holds characters with the same index
        string * StrArray= new string [numRows];
        string ans;
        
        // special case, if numRows = 1, meaning the string we should return is the same string as input.
        if (numRows==1)
        {
            ans=s;
        }
        // if numRows is greater than 1
        else
        {
            // initialize the strings for all the index
            for (int j=0;j<numRows;j++)
            {
               StrArray[j]=""; 
            }

            // index is given in ascending, then descending, e.g. 1232123..
            // so we need k and add to help us remember when we should increment the index and when we should decrement
            int k=1;
            int add=1;
            for (int i= 0;i<s.length();i++)
            {
                // put the character into the string that belongs to its index
                StrArray[k-1].append(s.substr(i,1));
                
                // if we hit the numRows, it's when we should turn into descending
                if (k == numRows)
                {
                    add = -1;
                }
                // if we hit the 1, it's when we should turn into ascending
                if(k==1)
                {
                    add=1;
                }
                k+=add;
            }

            //combine the string for all the index together, and we will have the final answer. 
            for (int j=0;j<numRows;j++)
            {
               ans.append(StrArray[j]); 
            }
        }
        //clean up and return
        delete [] StrArray;
        return ans; 
    }
};