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
* GET和POST区别

    1. GET请求中的参数会直接添加在URL中，比如百度搜索python，URL等价于[www.baidu.com/s?wd=python](http://www.baidu.com/s?wd=python)

        而POST直接将参数以表单的形式发给服务器，所以不存在信息泄露的的问题，比如账号密码登陆。
    2. GET请求提交的数据最多为1024字节，而POST没有限制。

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
    因为使用```r.text```网页返回的是字符串```str```，有的网页返回的这个字符串的格式是比较特殊的```json```格式，我们如果要解析它就使用```requests```自带的```json解析器```。
    
    使用```r.json```就可以了

4. headers
    有的网站，具有反爬虫机制，会自动检测出你是不是爬虫，这个时候，就可以给自己的爬虫添加一个请求头headers将自己伪装成浏览器

    headers有很多，在百度上一搜就有很多
    ```python
    headers = {'user-agent': 'my-app/0.0.1'} #这只是其中一种
    r = requests.get( url , headers = headers ) 
    ```
    这样就可以了

5. cookie

    cookie是某些网站为了**辨识用户进而进行会话跟踪在本地储存**的数据

    当客户端**第一次**请求服务器时，服务器会返回一个请求头中带有```Set-Cookie```字段的响应给客户端，用来标记是哪一个用户，客户端浏览器会把Cookies保存起来。当浏览器下一次再请求该网站时，浏览器会把此Cookies放到请求头一起提交给服务器，Cookies携带了**会话ID信息**，服务器检查该Cookies即可找到对应的会话是什么，然后再判断会话来以此来辨认用户状态。

    在成功登录某个网站时，服务器会告诉客户端设置哪些Cookies信息，在后续访问页面时客户端会把Cookies发送给服务器，服务器再找到对应的会话加以判断。如果会话中的某些设置登录状态的变量是有效的，那就证明用户处于登录状态，此时返回登录之后才可以查看的网页内容，浏览器再进行解析便可以看到了。

    反之，如果传给服务器的**Cookies是无效的，或者会话已经过期了，我们将不能继续访问页面，此时可能会收到错误的响应或者跳转到登录页面重新登录** 。

    所以，Cookies和会话需要配合，一个处于客户端，一个处于服务端，二者共同协作，就实现了登录会话控制。

    这就是在某个网页一次登陆过后就可以一直用很久，除非你很久没有再次登陆
    
    比如在用requests上知乎的首页是只是模拟浏览器是进不去的
    ```python
    import requests
    headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/68.0.3440.106 Safari/537.36',
    }

    url = 'http://www.zhihu.com'
    r = requests.get(url,headers = headers)
    print(r.status_code)
    ```
    返回的代码是```400```
    
    这里需要去浏览器打开开发者工具找到自己账号登陆过后的cookie，再重新改写```headers```
    ```python
    headers = {
    'cookie':'d_c0="ANAmu1oG0w2PTmwzw5JylMDHG2KuxDvWBds...
    'Host': 'www.zhihu.com',
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/68.0.3440.106 Safari/537.36',
    }
    ```
    现在重新发送请求就能通过了,返回代码为```200```

6. post
    
    ```get```是申请从网站获取东西，那么```post```就是提交表单

    使用```requests.post(url , files)```
    如
    ```python
    import requests

    file = {
        'file': open(r'F:\蒋昱葳\qwe.txt','rb')
    }

    url = 'http://httpbin.org/post'
    r = requests.post(url,files = file)

    print( r.text )
    ```
    这里打印后有这样的内容，就是我们上传的表单
    ```
    {
    "args": {}, 
    "data": "", 
    "files": {
        "file": ""
    }, 
    "form": {}, 
    "headers": {
        "Accept": "*/*", 
        "Accept-Encoding": "gzip, deflate", 
        "Connection": "close", 
        "Content-Length": "143", 
        "Content-Type": "multipart/form-data; boundary=5439dd85e58e4fc6866eb7a59efcaa3d", 
        "Host": "httpbin.org", 
        "User-Agent": "python-requests/2.18.4"
    }, 
    "json": null, 
    "origin": "202.99.210.131", 
    "url": "http://httpbin.org/post"
    }
    ```
    **其中files里的东西就是我们上传的二进制。但是如果上传的内容是空的，比如一个空的txt文件这里就什么都不会显示了**
7. 代理
8. 超时

    使用```timeout```这个参数来设置超时时间
    ```python
    import requests

    requests.get('http://www.baidu.com',timeout = 1)
    ```
    ```timeout```说明设置超时时间为1s，超过1s就会抛出异常

9. Cookies

    通过`cookies`属性查看服务器返回的cookie值

    ```python
    import requests

    url = "http://www.zhihu.com/explore"
    r = requests.get(url)
    print(r.cookies)
    print("--------")
    for key, value in r.cookies.items():
        print(key, value)
    ```

    ```
    <RequestsCookieJar[<Cookie _xsrf=v9ceb5eucLWhivXGU6o8y979B3VNtLWK for .zhihu.com/>, <Cookie tgw_l7_route=29b95235203ffc15742abb84032d7e75 for www.zhihu.com/>]>
    --------
    _xsrf v9ceb5eucLWhivXGU6o8y979B3VNtLWK
    tgw_l7_route 29b95235203ffc15742abb84032d7e75
    ```

10. SSL证书验证

    requests发送请求是，可以通过设置`verify`这个参数来控制是否检查SSL证书，默认值为`True`。
    ```python
    requests.get(url, verify=False)
    ```