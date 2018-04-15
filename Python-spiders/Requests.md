# Requests HTTP for human
第三方库reuqests

## 安装
有两种方法安装requests
* 配置pip，在命令行输入
    ```
    pip install requests
    ```
    pip是python的包管理工具,安装python的时候就会配置好
* 下载Anaconda直接就会下载好，可以使用
    ```
    conda list
    ```
    查看
    </br>一个开源的python版本，爬虫需要的包基本都在里面

## 介绍

![HTTP发送请求](https://github.com/jiangyuwei666/Notes/blob/master/pictrue/HTTP%E5%8D%8F%E8%AE%AE%E5%AF%B9%E8%B5%84%E6%BA%90%E7%9A%84%E6%93%8D%E4%BD%9C.jpg)

用HTTP协议向浏览器发送请求获取信息的方式有四种
* GET
</br>GET就是你在上网在浏览器上网址栏输入后按下回车发送的请求。
</br>比如你要上百度，在网址栏输入 www.baidu.com 后按下回车，浏览器发送请求了，接着跳转到该网站
* POST
</br>填写表单或者提交信息的时候到网络服务端的请求，通常登陆的时候就是发送的post请求
</br>有一种说法就是，你发了一个post请求就是说，把这些信息保存的到服务器中。
* PUT
</br>更新一个对象
* DELET
</br>删除一个对象

### Requests的方法

![requests的方法](https://github.com/jiangyuwei666/Notes/blob/master/pictrue/requests%E5%BA%93%E7%9A%84%E4%B8%83%E4%B8%AA%E4%B8%BB%E8%A6%81%E6%96%B9%E6%B3%95.jpg)

需要说明的是
* request
</br>构造一个请求，支持其他请求的操作
* head
</br>与get相似，但是只是获取头部信息
* patch 
</br>局部修改请求(与put是有区别)
* 与获取信息的方式对应

### Requests异常
了解

![requests的一些异常](https://github.com/jiangyuwei666/Notes/blob/master/pictrue/Response%E5%BA%93%E5%BC%82%E5%B8%B8.jpg)

### Response对象
服务器返回的的对象，是Requests库里封装好的类
</br>Response对象的一些属性
* r.headers
    </br>返回头部信息
    ```python
    >>> url = 'http://www.baidu.com'
    >>> r = requests.get(url)
    >>> r.headers
    {'Server': 'bfe/1.0.8.18', 'Date': 'Tue, 27 Mar 2018 03:21:53 GMT', 'Content-Type': 'text/html', 'Last-Modified': 'Mon, 23 Jan 2017 13:27:36 GMT', 'Transfer-Encoding': 'chunked', 'Connection': 'Keep-Alive', 'Cache-Control': 'private, no-cache, no-store, proxy-revalidate, no-transform', 'Pragma': 'no-cache', 'Set-Cookie': 'BDORZ=27315; max-age=86400; domain=.baidu.com; path=/', 'Content-Encoding': 'gzip'}
    ```
    发现是一个字典，就通过键查看值
    ```python
    >>> r.headers['Date']
    'Tue, 27 Mar 2018 03:21:53 GMT'
    ```
* status_code()方法
    </br>查看当前的状态码，200为正常可以访问
    ```python
    >>> r.status_code
    200
    ```
* encoding和apparent_encoding编码方式
    </br>header中如果不存在charset字段,打印r.encoding,会发现编码为'ISO-8859-1',而r.apparent_ecoding会根据网页的内容分析出编码方式。比如百度的首页
    1. 先用r.status_code()看是不是200
    2. 用r.encoding或者r.apparent_encoding查看编码
    3. 如果是ISO-8859-1的话可以直接使用
        ```python
        r.encoding = r.apparent_encoding
        ```
        </br>比如说百度
        首先我们用requests.get方法获取response对象
        ```python
        import requests
        url = "http://www.baidu.com"
        r = requests.get( url )
        ```
        输出一下r.text，结果如下

        ![1](https://github.com/jiangyuwei666/Notes/blob/master/pictrue/%E7%99%BE%E5%BA%A6%E7%BC%96%E7%A0%811.png)

        打印一下编码和apparent_encoding

        ![2](https://github.com/jiangyuwei666/Notes/blob/master/pictrue/%E7%99%BE%E5%BA%A6%E7%BC%96%E7%A0%812.png)

        改写结果

        ![3](https://github.com/jiangyuwei666/Notes/blob/master/pictrue/%E7%99%BE%E5%BA%A6%E7%BC%96%E7%A0%813.png)

## 使用
1. 首先我们要导入这个模块
    ```python
    import requests
    ```
    然后需要个网址
    ```python
    url = "https://www.baidu.com/"
    ```
    直接使用
    ```python
    r = requests.get ( url )
    ```
    然后我们试着输出一下结果
    ```python
    print ( r )  
    ```
    这个输出
    ```python
    <Response [200]>
    ```
    这个r是什么类型呢？
    ```python
    print ( type ( r ) ) 
    ```
    打印发现是requests里封装好的类
    ```python
    <class 'requests.models.Response'>
    ```
    打印一下
    ```python
    print ( r.text ) #这里打印的是网页源码
    print ( type ( r.text ) ) #字符串类型
    ```
    到这里大概了解了requests.get()方法的大概用法
2. requests.get()的第二个参数，params
    ```python
    params = {} #这里的参数必须是一个字典
    r = requests.get ( url , params )
    ```
    这样就能把参数导进去，比如百度的界面，将参数进行设置，就能直接跳转到参数设定的搜索结果的界面
    比如    
    ```python
    params = { 'key1': 'value1' , 'key2': 'value2' }
    r = requests.get ( url , params )
    print ( r.url )
    ```
    打印得到
    ```
    https://www.baidu.com/?key2=value2&key1=value1
    ```
3. requests自带的json解析器
4. headers
    有的网站，具有反爬虫机制，会自动检测出你是不是爬虫，这个时候，就可以给自己的爬虫添加一个请求头headers将自己伪装成浏览器

    headers有很多，在百度上一搜就有很多
    ```python
    headers = {'user-agent': 'my-app/0.0.1'} #这只是其中一种
    r = requests.get( url , headers = headers ) 
    ```
    这样就可以了