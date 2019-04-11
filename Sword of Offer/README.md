# 剑指Offer的刷题笔记
所有代码都在[这里](https://github.com/jiangyuwei666/my-study-demo/tree/master/Algorithm/sword%20of%20offer)

* [2.二维数组中的查找](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/1.%E4%BA%8C%E7%BB%B4%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84%E6%9F%A5%E6%89%BE.py)
    ```
    二维数组，每一行从左往右增大，每一列从上往下增大，输入一个整数，判断数组中是否含有该整数。
    ```
    ![](https://images0.cnblogs.com/blog2015/381412/201508/172206497062111.png)
    从左下角或者右上角入手
    输入7返回Ture 输入5返回False
* [3.替换空格](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/2.%E6%9B%BF%E6%8D%A2%E7%A9%BA%E6%A0%BC.py)

    ```
    请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，则输出“We%20are%20happy.”。　
    ```

    这个题用Python实现没什么难度。。。

    但是要如果用别的语言实现的时候要考虑长度问题，空格占一个，%20占3个。
* [4.从头到尾打印链表](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/3.%E4%BB%8E%E5%A4%B4%E5%88%B0%E5%B0%BE%E6%89%93%E5%8D%B0%E9%93%BE%E8%A1%A8.py)
    ```
    输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
    ```
* [5.重建二叉树]()

    ```
    输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
    ```

    先通过前序遍历找到根节点(第一个)，再在中序遍历中将整个树分为左子树和右子树。再在前序遍历中找到左右子树，重复以上操作（递归）

* [6.用两个栈实现队列]()

    ```
    用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
    ```

    两个栈，一个是stack1，另外一个是stack2，首先将所有元素push进stack1里，再以此pop到stack2中，这样再从stack2中pop的
    时候就可以就能实现先进先出的。这里要注意的是，pop的时候，如果stack2中没有元素了，这个时候才将stack1中的所有元素pop到
    stack2中，push的时候，直接push到stack1中就行

    python中利用list的append和pop方法就能实现栈的功能
* [7.旋转数组中的最小数字]()
    ```
    把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
    ```