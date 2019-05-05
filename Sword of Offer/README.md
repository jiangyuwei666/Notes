# 剑指Offer的刷题笔记
所有代码都在[这里](https://github.com/jiangyuwei666/my-study-demo/tree/master/Algorithm/sword%20of%20offer)

* [1.二维数组中的查找](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/1.%E4%BA%8C%E7%BB%B4%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84%E6%9F%A5%E6%89%BE.py)
    ```
    二维数组，每一行从左往右增大，每一列从上往下增大，输入一个整数，判断数组中是否含有该整数。
    ```
    ![](https://images0.cnblogs.com/blog2015/381412/201508/172206497062111.png)
    从左下角或者右上角入手
    输入7返回Ture 输入5返回False
* [2.替换空格](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/2.%E6%9B%BF%E6%8D%A2%E7%A9%BA%E6%A0%BC.py)

    ```
    请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，则输出“We%20are%20happy.”。　
    ```

    这个题用Python实现没什么难度。。。

    但是要如果用别的语言实现的时候要考虑长度问题，空格占一个，%20占3个。
* [3.从头到尾打印链表](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/3.%E4%BB%8E%E5%A4%B4%E5%88%B0%E5%B0%BE%E6%89%93%E5%8D%B0%E9%93%BE%E8%A1%A8.py)
    ```
    输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
    ```
* [4.重建二叉树](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/4.%E9%87%8D%E5%BB%BA%E4%BA%8C%E5%8F%89%E6%A0%91.py)

    ```
    输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
    ```

    先通过前序遍历找到根节点(第一个)，再在中序遍历中将整个树分为左子树和右子树。再在前序遍历中找到左右子树，重复以上操作（递归）

* [5.用两个栈实现队列](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/5.%E7%94%A8%E4%B8%A4%E4%B8%AA%E6%A0%88%E5%AE%9E%E7%8E%B0%E9%98%9F%E5%88%97.py)

    ```
    用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
    ```

    两个栈，一个是stack1，另外一个是stack2，首先将所有元素push进stack1里，再以此pop到stack2中，这样再从stack2中pop的
    时候就可以就能实现先进先出的。这里要注意的是，pop的时候，如果stack2中没有元素了，这个时候才将stack1中的所有元素pop到
    stack2中，push的时候，直接push到stack1中就行

    python中利用list的append和pop方法就能实现栈的功能
* [6.旋转数组中的最小数字](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/6.%E6%97%8B%E8%BD%AC%E6%95%B0%E7%BB%84%E4%B8%AD%E6%9C%80%E5%B0%8F%E7%9A%84%E6%95%B0%E5%AD%97.py)
    ```
    把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
    ```
* [7.斐波那契数列](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/7.斐波那契数列.py)
* [8.跳台阶](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/8.跳台阶.py)
    ```
    一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
    ```
* [9.变态跳台阶](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/9.变态跳台阶.py)
    ```
    青蛙可以一次跳n级台阶
    ```
* [10.矩形覆盖](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/10.矩形覆盖.py)
    ```
    我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
    ```
* [11.二进制中1的个数](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/11.二进制中1的个数.py)
    ```
    输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
    ```
* [12.数值的整数次方](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/12.数值的整数次方.py)
    ```
    给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
    ```
* [13.调整数组顺序使奇数位于偶数前面](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/13.调整数组顺序使奇数位于偶数前面.py)
    ```
    输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
    ```
* [14.链表中倒数第k个结点](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/14.链表中倒数第k个结点.py)
    ```
    输入一个链表，输出该链表中倒数第k个结点。
    ```
    ![](https://images2015.cnblogs.com/blog/936002/201604/936002-20160414184635848-1331750727.png)
* [15.反转链表](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/15.反转链表.py)
    ```
    输入一个链表，反转链表后，输出新链表的表头
    ```
* [16.合并两个排序的链表](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/16.合并两个排序的链表.py)
    ```
    输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
    ```
* [17.树的子结构](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/17.树的子结构.py)
    ```
    输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
    ```
* [18.二叉树的镜像](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/18.二叉树的镜像.py)

* [19.顺时针打印矩阵](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/19.顺时针打印矩阵.py)
    ```
    输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.即画圈圈打印
    ```
* [20.包含min函数的栈](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/20.包含min函数的栈.py)
    ```
    定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
    ```
* [21.栈的压入、弹出序列](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/21.栈的压入、弹出序列.py)
    ```
    输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
    ```

* [22.从上往下打印二叉树](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/22.从上往下打印二叉树.py)
    ```
    从上往下打印出二叉树的每个节点，同层节点从左至右打印。
    ```二叉搜索树的后序遍历序列
* [23.二叉搜索树的后序遍历序列](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/23.二叉搜索树的后序遍历序列.py)
    ```
    
    ```
* [24.二叉树中和为某一值的路径](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/24.二叉树中和为某一值的路径.py)
    ```
    输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
    ```复杂链表的复制
* [25.复杂链表的复制](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/25.复杂链表的复制.py)
    ```
    输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
    ```
* [26.二叉搜索树与双向链表](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/26.二叉搜索树与双向链表.py)
    ```
    输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
    ```
* [27.字符串的排列](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/27.字符串的排列.py)
    ```
    输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
    ```
* [28.数组中出现次数超过一半的数字](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/27.字符串的排列.py)
    ```
    数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
    ```
* [27.字符串的排列](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/27.字符串的排列.py)
    ```
    输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
    ```
* [29.最小的K个数](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/29.最小的K个数.py)
    ```
    输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
    ```
* [30.连续子数组的最大和](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/30.连续子数组的最大和.py)
    ```
    输入一个整型数组，数组里有正数也有负数。数组中一个或连续的多个整数组成一个子数组。求所有子数组的和的最大值。要求时间复杂度为 O(n)。
    ```

* [31.整数中1出现的次数(从1到n整数中1出现的次数)](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/31.整数中1出现的次数(从1到n整数中1出现的次数).py)
    ```
    求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。
    ```

    
* [32.把数组排成最小的数](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/32.把数组排成最小的数.py)
    ```
    输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
    ```
* [33.丑数](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/33.丑数.py)
    ```
    把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含质因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
    ```


* [34.第一个只出现一次的字符位置](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/34.第一个只出现一次的字符位置.py)
    ```
    在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.
    ```

* [35.数组中的逆序对](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/35.数组中的逆序对.py)
    ```
    在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P
    ```
* [36.两个链表的第一个公共结点](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/36.两个链表的第一个公共结点.py)
    ```
    输入两个链表，找出它们的第一个公共结点。
    ```
* [37.数字在排序数组中出现的次数](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/37.数字在排序数组中出现的次数.py)
    ```
    统计一个数字在排序数组中出现的次数。
    ```
* [38.二叉树的深度](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/38.二叉树的深度.py)
    ```
    输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
    ```
* [39.数组中只出现一次的数字](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/39.数组中只出现一次的数字.py)
    ```
    一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
    ```

* [40.和为S的连续正数序列](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/40.和为S的连续正数序列.py)
    ```
    小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? 
    ```
* [41.和为S的两个数字](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/41.和为S的两个数字.py)
    ```
    输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
    ```

* [42.左旋转字符串](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/42.左旋转字符串.py)
    ```
    汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
    ```

* [43.翻转单词顺序列](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/43.翻转单词顺序列.py)
    ```
    牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
    ```
    
* [44.扑克牌顺子](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/44.扑克牌顺子.py)
    ```
    LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿！！“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....LL不高兴了,他想了想,决定大\小 王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。LL决定去买体育彩票啦。 现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何， 如果牌能组成顺子就输出true，否则就输出false。为了方便起见,你可以认为大小王是0。
    ```
* [45.孩子们的游戏(圆圈中最后剩下的数)](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/45.孩子们的游戏(圆圈中最后剩下的数).py)
    ```
    ```

* [46.求1+2+3+...+n](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/46.求1+2+3+...+n.py)
    ```
    求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
    ```
47.不用加减乘除做加法
48.把字符串转换成整数
49.数组中重复的数字

* [50.构建乘积数组](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/50.构建乘积数组.py)
    ```
    给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
    ```
    
* [54.链表中环的入口结点](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/54.链表中环的入口结点.py)
    ```
    给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
    ```