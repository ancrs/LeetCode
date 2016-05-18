Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

class Solution {
public:
    string simplifyPath(string path) {
         stack<string> ss;
         for(int i = 0;i < path.size();)
         {
             // 跳过斜线'/'
             while(i < path.size() && '/' == path[i])
                 ++ i;
             // 记录路径名
             string s = "";
             while(i < path.size() && path[i] != '/')
                 s += path[i ++];
             // 如果是".."则需要弹栈，否则入栈
             if(".." == s && !ss.empty())
                 ss.pop();
             else if(s != "" && s != "." && s != "..")
                 ss.push(s);
         }
         // 如果栈为空，说明为根目录，只有斜线'/'
         if(ss.empty())
             return "/";
         // 逐个连接栈里的路径名
         string s = "";
         while(!ss.empty())
         {
             s = "/" + ss.top() + s;
             ss.pop();
         }
         return s;
    }
};