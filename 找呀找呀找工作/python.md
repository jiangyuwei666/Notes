

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