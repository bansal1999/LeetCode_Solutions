class Solution {
public:
    int minSwaps(string str) {

     stack<char> st;
        
    for(int i =0; i< str.size(); i++)
    {
        char ch = str[i];
        //open bracket case
        if(ch == '[')
            st.push(ch);
        else
        {
            // closed bracket found
            if(!st.empty() && st.top() == '[')
            {
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }
    }
    int a = 0,  b = 0;
        while(!st.empty())
        {
            if(st.top() == '[')
                a++;
            else
                b++;
            
            st.pop();
        }
        
        int ans = (a + 1)/2 + (b + 1)/2;
        return ans/2;
}
};