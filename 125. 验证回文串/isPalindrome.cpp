class Solution {
public:
    bool isPalindrome(string s) {
        // 空字符串认为是回文
        if(s.size() == 0)
            return true;
        int i = 0, j = s.size() - 1;
        while(i < j) {
            // isalnum(char c):判断字符变量c是否为字母或数字，若是则返回非零，否则返回零
            while(i < j && !isalnum(s[i]))
                i++;
            while(i < j && !isalnum(s[j]))
                j--;
            // tolower(char c):把字母字符转换成小写,非字母字符不做出处理
            if(tolower(s[i++]) != tolower(s[j--]))
                return false;
        }
        return true;
    }
};
