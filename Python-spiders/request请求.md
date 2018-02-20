### request请求
用HTTP协议向浏览器发送请求获取信息的方式有四种
* GET
</br>GET就是你在上网在浏览器上网址栏输入后按下回车发送的请求。
</br>比如你要上百度，在网址栏输入 www.baidu.com 后按下回车，浏览器发送请求了，接着跳转到该网站
* POST

* PUT
* DELET

### requests的方法

* head()
* post()
*

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
</br>比如说百度

![](https://github.com/jiangyuwei666/Notes/blob/master/pictrue/Response%E5%AF%B9%E8%B1%A1%E7%9A%84%E5%B1%9E%E6%80%A7.jpg)
