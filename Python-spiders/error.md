# error使用
爬虫的使用当中，异常处理是非常重要的，比如有个地方没考虑到，或者这个时候网络突然波动了，这个时候程序就会报错而终止，后面的代码就不能再运行了。使用error就能够有效的避免
## URLError
这一类error产生的原因是网页连接时出现了问题，导致不能跟网页正常的连接，比如：
* 网络没有连接，本机无法上网
* 连接不到指定服务器。服务器再国外，并且没有VPN
* 服务器不存在。没有这个网站

```URLError```类有个属性```reason```，可以返回出现错误的原因。

比如
```python
except error.URLError as e:
    print(e.reason)
```
## HTTPError
```HTTPError```是```URLError```的子类，只用于HTTP请求错误，只要状态码返回的时无法处理的，比如404（页面没有找到），403（请求被禁止），401（验证请求）无法完成请求，就会抛出```HTTPError```异常。

```HTTPError```有一下几个主要属性
* ```code```:HTTP状态码
* ```reason```:返回错误原因
* ```headers```:返回请求头

用法和父类的类对象一样。

因为```URLError```是```HTTPError```的父类，可以先选择先捕获子类异常再捕获父类异常。
```python
except error.HTTPError as e:
    print(e.code , e.reason , e.headers , seq = '\n' )
except error.URLError as e:
    print(e.reason)
```
参数```seq```表示在三个内容中间用```\n```隔开

有的时候```reason```的值不一定是返回的字符串作为原因，比如下面
```python
try:
    response = urllib.request.urlopen('https://www.baidu.com', timeout=0.01)
except urllib.error.URLError as e:
    print(type(e.reason))
    if isinstance(e.reason, socket.timeout):
        print('TIME OUT')
```
使用```isinstance()```来判断两个是不是同一个类型。