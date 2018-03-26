# Xpath
Xpath是一门用来在**XML**文件中选择节点的**语言**，也可以用在HTML上

## 安装
Xpath所在的模块是lxml中etree模块，安装和requests库一样，也有两种方式
* 使用pip包管理工具下，打开命令行输入
    ```
    pip install lxml 
    ```
    但是lxml在windows系统下使用pip是很难直接下载成功的，不知道是因为墙太硬了还是怎么回事，这个时候我们一般选择去[这个链接](https://www.lfd.uci.edu/~gohlke/pythonlibs/)下载lmxl包，再通过pip安装到我们的环境中
    </br>在里面找到你的python版本对应的lxml包下载下来

    ![lmxl下载](https://github.com/jiangyuwei666/Notes/blob/master/pictrue/lxml%E4%B8%8B%E8%BD%BD.png)

    比如我的python版本是3.6，64位就下载这个
    </br>再到下载目录，长按shift同时右键，点击**在此处打开命令窗口**就不用再cmd里一步一步cd过来
    </br>接着输入以下命令
    ```
    pip install lxml‑4.2.1‑cp36‑cp36m‑win_amd64.whl
    ```
    就是你的文件名
    这样就安装好了
* 当然更简单的还是下载anaconda([anaconda是什么](https://github.com/jiangyuwei666/Notes/blob/master/Python-spiders/Requests.md)) 里面已经下载好了


## 使用
1. 导入模块
    ```python
    from lxml import etree
    import requests
    ```
2. 获取选择器对象
    ```python
    r = requests.get(url) #根据需要选择是否需要头或者其他参数
    s = etree.HTML(r.text) #获取到了选择器
    ```
2. 使用Xpath抓取你想要的东西

    xpath其实就是通过路径找到你想要的东西，比如说你家住在胜利路牛逼小区a幢1单元1楼1号，通过这个我就能找到你，放在Xpath上，它就是通过选取XML文档的节点来一层一层的找到你想要的内容。

    * 绝对路径和相对路径的区别

        在了解Xpath语法之前，需要先弄清楚绝对路径和相对路径。

        绝对路径，故名思意，绝对路径就是必须一层一层的严格按照结构来。比如我要找你的话，我必须要通过 a国b省c市d区e街f小区g单元h楼i号，一层也不能少。

        但是如果全世界都只有一个小区叫牛逼小区，我们就不用前面的所有国，省，市，直接在牛逼小区中找g单元h楼i号。

        放在电脑路径中，比如在D盘中有个test文件夹里又有a,b两个文件夹两个文件夹里都有c这个文件，a中还有d文件。

        绝对路径D:\a\c这样找到a中的c文件 如果用相对路径找d D:\\d

        这里就用双斜杠，这就是绝对路径和相对路径的区别

        **注意：相对路径可以获取所有满足条件的东西，譬如，这里我们使用 D:\\c 这个就可以得到两个c文件**

    * xpath的一些简单的语法
        这里给出xpath语法的表达式

        ![语法表达式](https://github.com/jiangyuwei666/Notes/blob/master/pictrue/xpath%E8%AF%AD%E6%B3%95%E8%A1%A8%E8%BE%BE%E5%BC%8F.png)

        还有一些通配符

        ![语法通配符](https://github.com/jiangyuwei666/Notes/blob/master/pictrue/xpath%E9%80%9A%E9%85%8D%E7%AC%A6.png)
        
        但是这样看上去并不直观，给出以下例子(都是采用绝对路径)
        * 选取div节点中a中的所有元素(xpath返回的结果都是**列表** )
        ```python
        list = s.xpath('//div//a/text()') 
        ```
        * 选取div节点中属性class为abc的结果
        ```python
        list = s.xpath('//div[@class="abc"]/text()')
        ```
        * 选取div节点中，a节点的href属性的值
        ```python
        list = s.xpath('//div//a/@href')
        ```
        平时经常用到的就是这些了

        **注意：当获取的是标签的属性时就不加/text()，在获取标签的内容时就要加上text()**

