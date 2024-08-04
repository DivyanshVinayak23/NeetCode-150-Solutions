//20. Valid Parentheses - https://leetcode.com/problems/valid-parentheses/description/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;  
        for(auto i:s)  
        {
            if(i == '(' || i== '{' || i == '[')
				st.push(i);
            else 
            {
                if(st.empty() or (st.top()=='(' and i!=')') or (st.top()=='{' and i!='}') or (st.top()=='[' and i!=']')) 
                    return false;
                    st.pop();  
            }
        }
        return st.empty();  
    }
};


//155. Min Stack - https://leetcode.com/problems/min-stack/
class MinStack {
public:

    stack<int> x;
    int topElement;
    stack<int> minStack;
    MinStack() {
        
    }
    
    void push(int val) {
        x.push(val);
        if(minStack.empty() || val <= minStack.top())
          minStack.push(val);
    }
    
    void pop() {
      if(x.top() == minStack.top())
        minStack.pop();
      x.pop();
    }
    
    int top() {
        return x.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

//150. Evaluate Reverse Polish Notation - https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

class Solution {
public:
    stack<int> st;
    void operation(string& op){
        if (st.empty()) return;
        
        int n2=st.top();
        st.pop();
        
        if (st.empty()) return;
        
        int n1=st.top();
        st.pop();
        
        int x;
        switch(op[0]){
            case '+': x=n1+n2; break;
            case '-': x=n1-n2; break;
            case '*': x=n1*n2; break;
            case '/': x=n1/n2; break;
        }
        st.push(x);
    }
    int evalRPN(vector<string>& tokens) {
         for(string& s: tokens){
            if (s=="+"|| s=="-" || s=="*"|| s=="/")
                operation(s);
            else{
                int x=stoi(s);
                st.push(x);
            }            
        }
        if (st.empty()) return 0;
        
        return st.top();
    }
};


//22. Generate Parentheses - https://leetcode.com/problems/generate-parentheses/description/

class Solution{
public:
	
	void solve(string op, int open, int close, vector<string>& ans){
		if(open == 0 && close == 0)
		{
			ans.push_back(op);
			return;
		}
		if(open == close)
		{
			string op1 = op;
			op1.push_back('(');
			solve(op1,open-1,close,ans);
		}
		else if (open == 0)
		{
			string op1 = op;
			op1.push_back(')');
			solve(op1,open,close-1,ans);
		}
		else if (close == 0)		
		{
			string op1 = op;
			op1.push_back('(');
			solve(op1,open-1,close,ans);
		}
		else
		{
			string op1 = op, op2 = op;
			op1.push_back('(');
			op2.push_back(')');
			solve(op1,open-1,close,ans);
			solve(op2,open,close-1,ans);
		}

	}




	vector<string> generateParenthesis(int n){
		int open = n;
		int close = n;
		vector<string> ans;
		string op = "";
		solve(op, open, close,ans);
		return ans;
	
	}


};


//739. Daily Temperatures - https://leetcode.com/problems/daily-temperatures/description/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> x;
        vector<int> ans(temperatures.size(),0);
        for(int i = 0; i < temperatures.size(); i++)
        {
            while(!x.empty() && temperatures[x.top()] < temperatures[i])
            {
                int temp = x.top();
                ans[temp] = i - temp;
                x.pop();
            }
            x.push(i);
        }
        return ans;
    }
};


//853. Car Fleet - https://leetcode.com/problems/car-fleet/description/
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }


        sort(cars.begin(), cars.end(), greater<pair<int, int>>());

        stack<float> fleetTimes;
        for (auto& car : cars) {
            float time = (float)(target - car.first) / car.second;
            if (!fleetTimes.empty() && fleetTimes.top() >= time) {

                continue;
            }

            fleetTimes.push(time);
        }

        return fleetTimes.size();
    }
};

//84. Largest Rectangle in Histogram - https://leetcode.com/problems/largest-rectangle-in-histogram/description/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> x;
        int n = heights.size();
        vector<int> left(n), right(n, n);
        

        for(int i = 0; i < n; i++) {
            while(!x.empty() && heights[x.top()] >= heights[i])
                x.pop();
            left[i] = x.empty() ? 0 : x.top() + 1;
            x.push(i);
        }
        

        while(!x.empty()) x.pop();

        for(int i = n - 1; i >= 0; i--) {
            while(!x.empty() && heights[x.top()] >= heights[i])
                x.pop();
            right[i] = x.empty() ? n : x.top();
            x.push(i);
        }
        
        int maxA = 0;
        for(int i = 0; i < n; i++) {
            maxA = max(maxA, (right[i] - left[i]) * heights[i]);
        }
        return maxA;
    }
};