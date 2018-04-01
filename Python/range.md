# range
range函数，嵌套循环非常好用的一个函数，python2中返回的是一个列表。python3中返回一个range类对象,实际上是一个整数序列。
</br>可以使用
```python
list(range())
```
实现列表的输出
```python
>>> range(10)
range(0, 10)
>>> list(range(10))
[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
```
### range的参数选择
```python
range( start , stop , step )
```
* start 
    </br>表示开始的整数，包括本身，默认为0
* stop
    </br>结束的整数，不包括本身，使用range()函数的时候必须写
* step
    </br>步长，默认为1，比如
    ```python
    >>> list(range(5))
    [0, 1, 2, 3, 4]
    >>> list(range(0,5,2))
    [0, 2, 4]
    ```