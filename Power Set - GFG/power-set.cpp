//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    void rec(vector<string>&ans,int i,string &s,string temp)
	    {
	        if(i>=s.size())
	        {
	            if(temp.size()!=0)
	            ans.push_back(temp);
	            return;
	        }
	       rec(ans,i+1,s,temp);
	       temp.push_back(s[i]);
	       rec(ans,i+1,s,temp);
	    }
		vector<string> AllPossibleStrings(string s){
		    vector<string>ans;
		    string temp;
		    rec(ans,0,s,temp);
		    sort(ans.begin(),ans.end());
		    return ans;
		    // Code here
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends