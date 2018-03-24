### request请求

![](https://github.com/jiangyuwei666/Notes/blob/master/pictrue/HTTP%E5%8D%8F%E8%AE%AE%E5%AF%B9%E8%B5%84%E6%BA%90%E7%9A%84%E6%93%8D%E4%BD%9C.jpg)

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

### requests的方法

![](https://github.com/jiangyuwei666/Notes/blob/master/pictrue/requests%E5%BA%93%E7%9A%84%E4%B8%83%E4%B8%AA%E4%B8%BB%E8%A6%81%E6%96%B9%E6%B3%95.jpg)
需要说明的是
* request
</br>构造一个请求，支持其他请求的操作
* head
</br>与get相似，但是只是获取头部信息
* patch 
</br>局部修改请求(与put是有区别)

### requests异常

##### Response对象
服务器返回的的对象
</br>Response对象的一些属性
* status_code()方法
    </br>查看当前的状态码，200为正常可以访问
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

    ![](https://github.com/jiangyuwei666/Notes/blob/master/pictrue/%E7%99%BE%E5%BA%A6%E7%BC%96%E7%A0%813.png)