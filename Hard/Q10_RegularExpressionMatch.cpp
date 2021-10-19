class Solution 
{
    public:
        bool CheckMatchRecursiveFunc(string s, string p)
        {
            int S_index = 0;
            int P_index = 0;
            if((p == ".*") || (s.length()==0 && p.length()==0))
            {
              return 1;
            }
            else if (s.length()==0)
            {
              if((p.length()>1) && (p[P_index+1] == '*')) // make sure we have more than 1 char in the string and check if it's a *
              {
                string sub_Str = p.substr(2,p.length()-2);
                return CheckMatchRecursiveFunc(s,sub_Str); // call recursively
              }
         // if we go here, the p string must have one single char left and that means the matching fails (because we have run out all char in s)
              else 
              {
                return 0;
              }
            }
            else
            {
              
              // since the * can represent 0 char, we need to consider 2 scenarios if we match the char or a .
              // 1. one char in s is matched and removed
              // 2. the char in s is not matched and removed here
              // for example
              // (aca, a*aca*) ---> (ca, aca*) or (aca, aca*)
              if ((p.length()>1) && (p[P_index+1] == '*')) // make sure we have more than 1 char in the string and check if it's a *
              {
                // if we know the second char is a *, 2 scenarios here we need to handle differently
                /*(if(p[P_index] == '.')
                {
                  bool NotMatch = 1;
                  int s_ind = 0;
                  while(NotMatch && s_ind<s.length())
                  {
                    string sub_Str_S = s.substr(s_ind,s.length()-s_ind);
                    string sub_Str_P = p.substr(2,p.length()-1);
                    NotMatch = !(CheckMatchRecursiveFunc(sub_Str_S,sub_Str_P));
                    s_ind++;
                  }
                  
                  return !(NotMatch);
                }
                else
                {*/
                  if(p[P_index] == s[S_index] || (p[P_index] == '.'))
                  {
                    // if the first char matches (gghbca and g*hbca, remove the first char from s and keep the original p) 
                    // becasue there's a * and s might still have 'g'
                    string sub_Str_S = s.substr(1,s.length()-1);
                    string sub_Str_P = p.substr(2,p.length()-2);
                    return (CheckMatchRecursiveFunc(sub_Str_S,p) ||CheckMatchRecursiveFunc(s,sub_Str_P));                    
                  }
                  else
                  {
                    // not match, (hbca and g*hbca) but since there's a '*', it can represent 0 of the precedent element, so we keep trying
                    string sub_Str_P = p.substr(2,p.length()-2);
                    return CheckMatchRecursiveFunc(s,sub_Str_P);                    
                  }
                //}
              }
              else
              {
                // if the second char is not a *, we need to compare the char or see if the p char is .
                if ((p[P_index] == '.') || (p[P_index] == s[S_index] ))
                {
                  // matched, continue with the rest of string s and p
                  string sub_Str_S = "";
                  string sub_Str_P = "";

                  if(s.length()>1)
                  {
                    sub_Str_S = s.substr(1,s.length()-1);
                  }
                  if(p.length()>1 )
                  {
                    sub_Str_P = p.substr(1,p.length()-1);
                  }
                  return CheckMatchRecursiveFunc(sub_Str_S,sub_Str_P);                    
                }
                else
                {
                  // not matched, return false
                  return 0;                  
                }
                
              }
            }          
        }
  
        // the function is try to process those strings that are not quite correct in terms of regex
        // for example (a*aab) => (aaa*b), we always keep the * behind to represent
        string processUsertypeRegex(string s)
        {
          string correct_Str = "";
          for (int i = 0; i<s.length(); i++)
          {
            if(s[i] == '*')
            {
              // Now we encounter a *, keep looking for the same char after * until we reach a different one
              // then we put * back
              int j = i;
              while((j+1<s.length()) && (s[j+1]==s[i-1]))
              {
                correct_Str.push_back(s[i-1]);
                j++;
              }
              correct_Str.push_back(s[i]); // put the * back after the while loop
              i = j;
            }
            else
            {
              correct_Str.push_back(s[i]);
            }
          }
          
          return correct_Str;
        }
  
  
        bool isMatch(string s, string p) 
        {
          string correct_P = processUsertypeRegex(p);
          return CheckMatchRecursiveFunc(s,p);
        }
};