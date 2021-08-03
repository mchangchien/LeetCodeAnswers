Answer
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalSize= nums1.size()+nums2.size();
        int medianIndex=0;

        bool IsSizeOdd;
        double ans;
        if(totalSize==0) // if we don’t even have a single element
        {
            ans=0;
        }
        else if(totalSize%2) // if total size is odd
        {
            medianIndex=totalSize/2; // get the median index of combine arrays
  
            // if the combined array is actually nums2, then get the median of nums2           
            if(nums1.size()==0)
            {
                ans = double(nums2[medianIndex]);
            }
            // if the combined array is actually nums1, then get the median of nums1 
            else if (nums2.size()==0)
            {
                ans = double(nums1[medianIndex]);             
            }
            else // combined array consist of nums1 and nums2
            {   
                // initialize some variables, num1 and nums2 index is to keep track of these 2 arrays
                //current is to keep track of combined array, last is to record which array that the median is in
                int num1Index=-1;
                int num2Index=-1;
                int current =-1;
                int last; 

                // from index=-1, start to pick element and record which array of element is in 
                while ((current<medianIndex) && ((num1Index+1)<nums1.size()) && ((num2Index+1)<nums2.size()))
                {
                    if (nums1[num1Index+1]<nums2[num2Index+1])
                    {
                        
                        num1Index++;
                        last=1;
                    }
                    else
                    {
                        num2Index++;
                        last=2;
                    }
                    current++;
                }

               // if we already arrive at median index, check it's in nums1 or nums2
                if(current==medianIndex)
                {
                    if(last==1)
                    {
                        ans = double(nums1[num1Index]);
                    }
                    else
                    {
                        ans = double(nums2[num2Index]);
                    }                    
                }
                // if we haven't reach the median and we have run out of nums2, so stick to nums1 and keep looking for elements
                else if ((num1Index+1)<nums1.size())
                {
                    while ((current<medianIndex))
                    {
                        num1Index++;
                        current++;
                    }
                    ans = double(nums1[num1Index]);
                }
                // if we haven't reach the median and we have run out of nums1, so stick to nums2 and keep looking for elements
                else
                {
                    while ((current<medianIndex))
                    {
                        num2Index++;
                        current++;
                    }
                    ans = double(nums2[num2Index]);                    
                }
            }    
        }
        else  // if the combined array size is even
        {
            medianIndex=totalSize/2;
            // if the combined array is actually nums2, then get the median of nums2    
            if(nums1.size()==0)
            {
                ans = double(nums2[medianIndex-1]+nums2[medianIndex])/2;
            }
            // if the combined array is actually nums2, then get the median of nums2    
            else if (nums2.size()==0)
            {
                ans = double(nums1[medianIndex-1]+nums1[medianIndex])/2;
            }
            else // combined array consist of nums1 and nums2
            {   

                // initialize some variables, num1 and nums2 index is to keep track of these 2 arrays
                //current is to keep track of combined array
                //we don’t have last here is because when size is even, median is the average of 2 median numbers, so no point of using 'last'

                int num1Index=-1;
                int num2Index=-1;
                int current =-1;
// from index=-1, start to pick element and record which array of element is in 
                while (current<medianIndex && ((num1Index+1)<nums1.size()) && ((num2Index+1)<nums2.size()))
                {
                    if (nums1[num1Index+1]<nums2[num2Index+1])
                    {
                        num1Index++;
                    }
                    else
                    {
                        num2Index++;
                    }
                    current++;
                }
                // if we already arrive at median index, check it's in nums1 or nums2
                if(current==medianIndex)
                {
                    //below we try 2 get the correct 2 number to average, because we only have median index, need to find the other one. 2 scenarios
                    // 1. if all the elements in combined array before and including the medians are all from nums1 or we have more than 1 elements are picked into combined array and current element of nums1 and its previous one are all smaller than current element of nums2 --> then the median is the average of current element of nums1 and its previous element
                    // 2. vice versa
                    // 3. if not above scenario, median must be the average of current element of nums1 and the one of nums2
                              
                    if ((num2Index<0) || (num1Index>0 &&(nums2[num2Index]<nums1[num1Index-1]) && (nums2[num2Index]<nums1[num1Index]) ))
                    {
                        ans = double(nums1[num1Index]+nums1[num1Index-1])/2;
                    }
                    else if((num1Index<0) || (num2Index>0 &&(nums1[num1Index]<nums2[num2Index-1]) && (nums1[num1Index]<nums2[num2Index]) ))
                    {
                        ans = double(nums2[num2Index]+nums2[num2Index-1])/2;
                    }
                    else
                    {
                        ans = double(nums1[num1Index]+nums2[num2Index])/2; 
                    }
                                     
                }
                // if we haven't reach the median and we already run out of nums2, we keeping go down with nums1 until we reach the median
                else if ((num1Index+1)<nums1.size())
                {
                    int count=0;
                    while ((current<medianIndex))
                    {
                        num1Index++;
                        count++;
                        current++;
                    }
                    
                    // if it takes more than 1 elements before the we reach the median, the median is the average of the last 2 element of nums1
                    if(count>1)
                    {
                        ans = double(nums1[num1Index]+nums1[num1Index-1])/2;
                    }
                    //otherwise, the median is the average of current elements of nums1 and nums2
                    else
                    {
                       ans = double(nums1[num1Index]+nums2[num2Index])/2; 
                    }
                }
                // if we haven't reach the median and we already run out of nums1, we keeping go down with nums2 until we reach the median
                else
                {
                    int count=0;
                    while ((current<medianIndex))
                    {
                        num2Index++;
                        count++;
                        current++;
                    }
                    
                    // if it takes more than 1 elements before the we reach the median, the median is the average of the last 2 element of nums1
                    if(count>1)
                    {
                        ans = double(nums2[num2Index]+nums2[num2Index-1])/2;
                    }
                    //otherwise, the median is the average of current elements of nums1 and nums2
                    else
                    {
                       ans = double(nums1[num1Index]+nums2[num2Index])/2; 
                    }                 
                }              
            }               
        }
        
        return ans;
    }
};

