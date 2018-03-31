# os模块的文件操作
1. 新建一个文件夹，使用os.mkdir()方法
这个方法有两个参数，第一个是路径path，第二个是mode为目录设置的权限数字模式，默认为0777(一般不用管)
    ```python
    os.mkdir("d:\test")
    ```
    跑一下，此时已经创建好了名为test的文件夹
    </br>如果上一级目标不存在的话，则会报错，比如：

    ```python
    os.mkdir(r"d:\test\test1") 
    ```
    如果之前没有创建test文件夹的话则会报错

2. 所以如果要创建多个目录，也就是一次创建多层文件夹就要用os.makedirs()方法
    其他的东西都与上面类似
    ```python
    os.makedirs(r"d:\test\test1") 
    ```
    先在D盘中创建test文件夹，再在test文件夹里面创建test1文件夹

3. 拼接路径与文件名 os.path.join()
    ```python
    os.path.join(r'd:\\test','a.txt')
    ```
    前面是路径，后面是文件名。(其实就是字符串的拼接)
4. 删除
    </br>删除路径所对应的文件或者文件夹
    * 删除a.txt
        ```python
        os.remove( r'f:\test\a.txt')
        ```
    * 删除目录文件夹
        ```python
        os.rmdir( r'f:\test' )
        ```
5. os与urllib.request.urlretrieve方法的使用
    ```python
    urlretrieve(url, filename=None, reporthook=None, data=None)
        Retrieve a URL into a temporary location on disk.
    ```
