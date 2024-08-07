unordered_map<int, string> belowTen = { {0, ""}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"} };
unordered_map<int, string> belowTwenty = { {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"} };
unordered_map<int, string> belowHundred = { {1, "Ten"}, {2, "Twenty"}, {3, "Thirty"}, {4, "Forty"}, {5, "Fifty"}, {6, "Sixty"}, {7, "Seventy"}, {8, "Eighty"}, {9, "Ninety"} };

string func(int num){
    if(num < 10){
        return belowTen[num];
    }
    if(num < 20){
        return belowTwenty[num];
    }
    if(num < 100){
        return belowHundred[num/10] + ((num%10) != 0 ? " "+func(num%10): "");
    }
    if(num < 1000){
        return func(num/100) + " Hundred" + ((num%100) != 0 ? " "+func(num%100) : "");
    }
    if(num < 1000000){
        return func(num/1000) + " Thousand" + ((num%1000) != 0 ? " "+func(num%1000) : "");
    }
    if(num < 1000000000){
        return func(num/1000000) + " Million" + ((num%1000000) != 0 ? " "+func(num%1000000) : "");
    }
    return func(num/1000000000) + " Billion" + ((num%1000000000) != 0 ? " "+func(num%1000000000) : "");

}

class Solution {
public:
    string numberToWords(int num) {
        if(num == 0){
            return "Zero";
        }
        return func(num);
    }
};




// In we have to ans interms of crore and lakhs..... 
// 1 Billion -> 100 crore
// 1 Million -> 10 lakh

/*

class Solution {
public:
   string ones[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
   "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

    string tens[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    string completeWord(int n, string s)
    {
        string ans= "";
        if(n < 20)
        {
            ans+= ones[n];
        }

        else
        {
            ans+= tens[n/10];
            if(n % 10)
            {
               ans+= " " + ones[n % 10];
            } 
        }

        if(n)
        {
            if (!ans.empty())
            {
               ans += " ";
            }
            ans+= s;
        }
      return ans;  
    }


    string numberToWords(int no) 
    {
        // base case
        if(no== 0)
        {
            return "Zero";
        }

        string result= "";

        string croreStr = completeWord((no/10000000),"Crore");
        if(!croreStr.empty())
        {
            result+= croreStr+ " ";
        }

        string lakhStr = completeWord((no/100000)% 100, "Lakh");
        if(!lakhStr.empty())
        {
           result+= lakhStr+ " "; 
        }

        string thousandStr = completeWord((no/1000) % 100, "Thousand");
        if(!thousandStr.empty())
        {
            result+= thousandStr + " ";
        }

        string hundredStr = completeWord((no/100) % 10, "Hundred");
        if(!hundredStr.empty())
        {
            result+= hundredStr + " ";
        }
        
        // if we have to insert "AND" inbetween Ex- Fourty five crore and seven hundred and ten...
        // if(n > 100 && n % 100)
        // {
        //     ans+= " and ";
        // }

        result+= completeWord(no % 100, "");

        // Remove back spaces if any...
        while(!result.empty() && result.back()== ' ')
        {
            result.pop_back();
        }

        return result;
    }
};

*/