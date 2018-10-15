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
3. 属性多值匹配

    在我们获取标签文本内容时，有时候会出现一个标签下的某一属性有多个值而无法获取该标签下的内容

    比如说
    ```python
    from lxml import etree

    text = '''
    <li class="li1 li2">li_text</li>
    '''
    s = etree.HTML(text)
    print(s.xpath('//li[@class="li1"]/text()'))
    ```
    输出只有一个
    ```
    []
    ```
    这个时候要使用```contains()```函数
    ```python
    from lxml import etree

    text = '''
    <li class="li1 li2">li_text</li>
    '''
    s = etree.HTML(text)
    print(s.xpath('//li[contains(@class , "li1")]/text()'))
    ```
    这样就可以正确的获取内容，```contains()```里写属性的任何一个值都可以
    ```
    ['li_text']
    ```

    emmmm...突然发现直接这样写也行。
    ```python
    from lxml import etree

    text = '''
    <li class="li1 li2">li_text</li>
    '''
    s = etree.HTML(text)
    print(s.xpath('//li[@class="li1 li2"]/text()'))
    ```
    直接将所有的属性值全部写进去，当然时少的时候
4. 多属性匹配

    其实多属性的时候只需要写齐一个属性值就可以了，但是**没有筛选效果**，所以还是得使用```and```把他们连接起来，避免数据的不必要抓取
    
    比如下面这个例子
    ```python
    from lxml import etree

    text = '''
    <li class="li1 li2" href="h1">li_text1</li>
    <li class="li1 li2" href="h2">li_text2</li>
    '''
    s = etree.HTML(text)
    print(s.xpath('//li[contains(@class,"li1")]/text()'))
    print('***')
    print(s.xpath('//li[contains(@class,"li1") and @href="h2"]/text()'))
    ```
    结果如下就比较明显了
    ```
    ['li_text1', 'li_text2']
    ***
    ['li_text2']
    ```

    在xpath的表达式中不仅仅可以用```and```，很多运算符号都可以在xpath表达式中使用 

5. xpath节点轴
    
    在食用一般的路径表达式时，会遇到一些结构不太清晰分明的网站就不太好提取这个时候使用```节点轴```。通过节点轴选取，就是通过节点的位置和上下关系来定位一系列节点。
    
    通过代码来熟悉
    ```python
    from lxml import etree

    text = '''
    <div>
        <ul>
            <li>first li item</li>
            <li>second li item</li>
            <p>s</p>
            <li>fourth li item
            <a>href</a>
            </li>
            <li>fifth item</li>
        </ul>
    </div>
    '''

    html = etree.HTML(text)
    s = html.xpath('//li[1]')
    print(type(s[0]))
    index = 1
    s1 = html.xpath('//li[1]/following::*')
    s2 = html.xpath('//li[1]/following-sibling::*')
    s3 = html.xpath('//li[1]/ancestor::*')
    s4 = html.xpath('//li[1]/attribute::*')
    s5 = html.xpath('//li[1]/child::*')
    print(s1)
    print(s2)
    print(s3)
    print(s4)
    print(s5) 
    ```
    第一次调用了，```following```轴，能查找所有的兄弟节点及其子孙节点，有点像```//```后面接了两个冒号```::```冒号后面接了一个```*```表示选取所有，如果只选取所有子孙节点的a节点，xpath表达式应该```//li[1]/following::a```

    第二行调用了```following-sibling```轴，表示查找的所有兄弟节点

    第三行调用的是```ancestor```轴，能够查找所有的祖先节点

    第四行调用的是```attribute```匹配所有的属性值

    第五行调用了```child```轴，选取所有的子孙节点，其余用法都与上面所说的类似。
