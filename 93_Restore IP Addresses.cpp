Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)


class Solution {
public:
    vector<string> restore(string s, int n, bool &flag)
	{
		vector<string> res;
		if(s.length() < n) {flag = false; return res;}
		if(n==1)
		{
			if(s.length()>3){flag=false;return res;}//maybe larger than int
			int ip = stoi(s);
			if(ip==0 && s.length() >1) flag = false;
			else if(ip>0 && s[0] == '0') flag = false;
			else if((ip >= 0) && (ip < 256))
			{
				res.push_back(s);
				flag = true;
			}else
				flag = false;
			return res;
		}
		int loop = s.length() - n +1;//garuntee every ip address is no less than one bit
		loop = min(loop,3);
		for(int i = 1; i <= loop; i++)
		{
			string ipstr = s.substr(0,i);
			int ip = stoi(ipstr);
			if(ip==0 && ipstr.length() >1)break;
			if(ip>0 && ipstr[0] == '0')break;
			if((ip>=0) && (ip < 256))
			{
				string suffix = s.substr(i);
				bool f = false;
				vector<string> tmp = restore(suffix,n-1,f);
				if(f)
				{
					flag = true;
					for(int k = 0; k < tmp.size(); k++)
						res.push_back(ipstr + '.' + tmp[k]);
				}
			}
		}
		return res;
	}
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
		bool flag = false;
		res=restore(s,4,flag);
		return res;
    }
};