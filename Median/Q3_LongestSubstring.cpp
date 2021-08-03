
// below and before the main function is the hash and hash map classes
class HashObj
{
    public:
        char key;
        int value;
        HashObj(char k, int v): key(k), value(v) {}
};

class HashTableMap
{
    public:
        HashObj** T1;
        HashTableMap()
        {
            T1 = new HashObj *[50000];
            for (int i=0; i<50000; i++)
            {
             T1[i] = NULL;
            }
        }


        int GetHaskKey(char key)
        {
            return (int(key)%50000);
        }
    
        void insertHashMap(char inKey, int inVal)
        {
            int hk = GetHaskKey(inKey);
            while (T1[hk] != NULL && T1[hk]->key != inKey)
            {
                hk = GetHaskKey(hk+1);
            }
            if (T1[hk] != NULL)
            {
                delete T1[hk];
            }
            T1[hk] = new HashObj(inKey, inVal);
        }
    
        int searchHashMap(char inKey)
        {
            int hk = GetHaskKey(inKey);
            while (T1[hk] != NULL && T1[hk]->key != inKey)
            {
                hk = GetHaskKey(hk+1);
            }
            
            if(T1[hk] == NULL)
            {
                return -1;
            }
            else
            {
                return T1[hk]->value;
            }        
        }
};


// main function
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // variable intialization
        HashTableMap htm;
        int ans=0;       //record the answer
        int count=0;     //count non-duplicate char count
        int ret;         // take the duplicate's index
        int lastbreak=0; // record last duplicate we found
        
        // go through each characters
        for (int i=0;i<s.length();i++)
        {
            // check if the cahr already exist and get the index (-1 means no existence)
            ret=htm.searchHashMap(s[i]);
            if(ret==-1 or ret < lastbreak)
            {
                // 1.the char does not exist or 
                // 2.the char exists before the last duplicate(means we dont care any more)
                // than we can increment the count
                count++;
            }
            else
            {
                //otherwise, it means we found a duplicate we care, then we
                //1. record the index as the lastbreak(new count starting point)
                //2. override the asn if current count is greater than it
                //3. get the current count we are going to use next, for example
                // 'dvdf' --> when we stop at the second 'd', we dont want to set the count=1
                //because after the fisrt 'd', 'vd' represnts 2 non-duplicate char, so when we going to 
                //start with the 'f', we would like count=2 (i-ret)
                
                lastbreak=ret;
                if(count>ans) {ans=count;}
                count=i-ret;
            }
            
            // make sure we update the hash map
            htm.insertHashMap(s[i],i);
        }
        
        // final check on the count and ans
        if(count>ans) {ans=count;}
        return ans;
    }
};
