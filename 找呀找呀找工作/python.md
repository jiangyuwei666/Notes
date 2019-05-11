

* 关于python中一切皆对象的继承关系

    ![type object和class的关系](http://ww1.sinaimg.cn/large/006BhB5Ogy1g2bh7x03mnj30q00h7jst.jpg)

    ```python
    >>> a = [1,2,3]
    >>> type(a)
    <class 'list'>
    >>> type(list)
    <class 'type'>
    >>> list.__bases__
    (<class 'object'>,)
    >>> type(object)
    <class 'type'>
    >>> object.__bases__
    ()
    >>> type.__base__
    <class 'object'>
    ```

* None(只有一个)
    ```python
    a = None
    b = None
    a == b # True
    ```

* python为什么慢，其中一个原因就是它的GIL锁，同一时刻只有一个线程在cpu上运行

    那么只要有这个GIL锁就是安全的吗？

    不是，GIL锁是会释放的，根据执行字节码的行数以及时间片进行释放

    并且遇到IO操作也会释放
* 自省

    通过一定的机制查询到对象的内部结构
    `__dict__()`魔法方法
* super()
    
    按照`__mro__`去找顺序
* bisect维护以排序的序列
* `__getattr__`查找不到某个属性的时候调用 而`__getattribute__`是不管如何都调用
* 通过下标访问，比如`nums[0]`是通过`__getitem__`魔术方法实现的
* 迭代器满足`__next__`和`__iter__`魔术方法，可迭代类型只满足`__iter__`这一个魔术方法
* `__iter__`和`__next__`分别对应内置函数`iter()`和`next()`
* 生成器内部实现了`__next__`所以可以通过`next()`