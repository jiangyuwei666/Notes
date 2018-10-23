## 题目地址
[1](https://leetcode-cn.com/problems/implement-strstr/description/)
## 我的思路
利用python的`in`关键字查看该字符串是否是字串，如果是，就查找匹配第一个字符相等的，如果第一字符相等了就取字串长度的字串，判断是否相等，相等就返回1，不等就下一个。如果循环完没找的就返回-1。
```python
class Solution:
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if needle == '':
            return 0
        if needle in haystack:
            for i in range(len(haystack)):
                if haystack[i] == needle[0]:
                    if haystack[i:len(needle) + i] == needle:
                        return i
            return -1 
        return -1
```