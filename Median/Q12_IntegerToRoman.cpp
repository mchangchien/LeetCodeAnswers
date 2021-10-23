class Solution {
public:
  
  
    string intToRoman(int num) 
    {
      map<int, string> Roman_nums_map;
      Roman_nums_map[0] = "";
      Roman_nums_map[1] = "I";
      Roman_nums_map[2] = "II";
      Roman_nums_map[3] = "III";
      Roman_nums_map[4] = "IV";
      Roman_nums_map[5] = "V";
      Roman_nums_map[6] = "VI";
      Roman_nums_map[7] = "VII";
      Roman_nums_map[8] = "VIII";
      Roman_nums_map[9] = "IX";
      Roman_nums_map[10] = "X";
      Roman_nums_map[20] = "XX";
      Roman_nums_map[30] = "XXX";
      Roman_nums_map[40] = "XL";
      Roman_nums_map[50] = "L";
      Roman_nums_map[60] = "LX";
      Roman_nums_map[70] = "LXX";
      Roman_nums_map[80] = "LXXX";
      Roman_nums_map[90] = "XC";
      Roman_nums_map[100] = "C";
      Roman_nums_map[200] = "CC";
      Roman_nums_map[300] = "CCC";
      Roman_nums_map[400] = "CD";
      Roman_nums_map[500] = "D";
      Roman_nums_map[600] = "DC";
      Roman_nums_map[700] = "DCC";
      Roman_nums_map[800] = "DCCC";
      Roman_nums_map[900] = "CM";
      Roman_nums_map[1000] = "M";
      Roman_nums_map[2000] = "MM";
      Roman_nums_map[3000] = "MMM";
      
      string ans = "";
      for (int i =1; i<=4;i++)
      {
        ans = Roman_nums_map[(num%int(pow(10,i)))] + ans;
        num-=(num%int(pow(10,i)));
      }
           
      return ans;
    }
};