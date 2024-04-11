class Solution {
public:
    string removeKdigits(string num, int k) {
        int size = num.size();
        string res = {};
        if(size <= k) 
            return "0";
        if(k == 0)
            return num;
        stack<char>st;
        st.push(num[0]);
        for(int i = 1; i<size ; i++)
        {
             while(k>0 && !st.empty() && num[i] < st.top())
             {
                k--;
                st.pop();
             }

             st.push(num[i]);

             if(st.size() == 1 && num[i] == '0')
                st.pop();
        }
        while(k && !st.empty())
        {
            k--;
            st.pop();
        }
         while(!st.empty())
        {
            res.push_back(st.top()); 
            st.pop(); 
        }

        reverse(res.begin(),res.end());
        if(res.length() == 0)
            return "0";
        return res;

       
    }
};