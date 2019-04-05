# 剑指Offer的刷题笔记
所有代码都在[这里](https://github.com/jiangyuwei666/my-study-demo/tree/master/Algorithm/sword%20of%20offer)

* [二维数组中的查找](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/1.%E4%BA%8C%E7%BB%B4%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84%E6%9F%A5%E6%89%BE.py)
    ```
    二维数组，每一行从左往右增大，每一列从上往下增大，输入一个整数，判断数组中是否含有该整数。
    ```
    ![](https://images0.cnblogs.com/blog2015/381412/201508/172206497062111.png)
    从左下角或者右上角入手
    输入7返回Ture 输入5返回False
* [替换空格](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/2.%E6%9B%BF%E6%8D%A2%E7%A9%BA%E6%A0%BC.py)

    ```
    请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，则输出“We%20are%20happy.”。　
    ```

    这个题用Python实现没什么难度。。。

    但是要如果用别的语言实现的时候要考虑长度问题，空格占一个，%20占3个。
* [从头到尾打印链表](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/3.%E4%BB%8E%E5%A4%B4%E5%88%B0%E5%B0%BE%E6%89%93%E5%8D%B0%E9%93%BE%E8%A1%A8.py)