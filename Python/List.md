# List 列表
python的列表可以类比其他语言的数组，但是不一样的在于，列表更加灵活，并且一个列表可以容纳不同数据类型的元素。
## 列表的一些方法

* 列表的扩充
</br>如果你想对列表添加若干个元素的话，使用append方法较好，代码如下：
    ```python
    list = []
    list.append(1)
    print (list)
    ```
    注意这个方法一次只能添加一个元素，不能一次添加多个元素如：
    ```python
    list.append(1,2)
    ```
    这种写法就是错误的
</br>当然也可以添加列表，字典等：
    ```python
    list.append([1])
    list.append({1})
    ```
* 列表的拼接
    如果你是想将两个列表拼接起来的话，那么可以采用 + 运算符来操作：
    ```python
    list1 = [1,2]
    list2 = [3,4]
    print ( list1.append(list2) )
    print ( list1 + list2 )
    ```
    输出结果如下：
    ```python
    [1,2,[3,4]]
    [1,2,3,4]
    ```
    很明显你就知道为什么用+不用append方法了

    </br>上诉两种方法的区别就在于**append方法是在原列表上操作，没有创建新的列表，而通过运算符会创建新的列表**

* 列表的删除
    </br>很多时候，列表里的东西并不全是你想要的所以我们需要来删除一些
    </br>比如你要前5个元素
    ```pyhton
    list = list[0:5] 
    ```
    这里注意，列表和数组一样第一个元素的脚标为0
    </br>比如我们要后5个元素
    ```pyhton
    list = list[-6:-1]
    ```
    从后往前的一个是-1
    </br>如果我们看列表里面的某一个元素不顺眼就可以用
    ```python
    List.remove(元素名)
    ```
    比如
    ```python
    >>> a = [1,1,2,3,4]
    >>> a.remove(2)
    >>> a
    [1, 1, 3, 4]
    >>> a.remove(1)
    >>> a
    [1, 3, 4]
    ```
    这里发现为什么还有一个1
    </br>使用help查看一下
    ```python
    >>> help(list.remove)
    Help on method_descriptor:

    remove(...)
    L.remove(value) -> None -- remove first occurrence of value.
    Raises ValueError if the value is not present.
    ```
    原来他是删除第一个匹配出来的元素
    </br>还有一种删除方法
    ```python
    list.pop(脚标)
    #移除list[脚标]的值，并且会返回这个值
    ```
    比如
    ```python
    >>> a = [1,1,2,3,4]
    >>> a.pop(3)
    3
    >>> a
    [1, 1, 2, 4]
    >>> a.pop(4)
    Traceback (most recent call last):
    File "<stdin>", line 1, in <module>
    IndexError: pop index out of range
    ```
    可以看出，与其他语言的数组一样，从零开始。
* 列表插入
    ```python
    list.insert( index , obj )
    #第一个参数是你要在哪个位置后面插入。第二个是你要插入的东西
    ```
    比如
    ```python
    >>> a
    [4, 3, 2, 1]
    >>> a.insert(1 , 'asd')
    >>> a
    [4, 'asd', 3, 2, 1]
    ```
* 列表反转
    ```python
    list.reverse()
    ```
    比如
    ```python
    >>> a = [1,2,3,4]
    >>> a.reverse()
    >>> a
    [4, 3, 2, 1]
    ```
* 列表排序
    </br>按照从小到大的顺序排序
    ```python
    list.sort()
    ```
    比如
    ```python
    >>> a = [2,3,5,0,4,9]
    >>> a.sort()
    >>> a
    [0, 2, 3, 4, 5, 9]
    ```