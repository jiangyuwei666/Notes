# mitmproxy
mitmproxy和charles一样，都是抓包工具，端口号为`8080`。只是这一款工具没有可视化的使用界面(window下什么都没有，linux和mac上可以用命令控制mitmproxy进行一些操作。)

那为什么会选择这个东西呢？

因为可以用mitmdump对接Python脚本对抓到的包进行实时抓取。

所以爬取app一般都是用charles分析请求的接口，在用appium自动操作，用mitmdump拿数据。

## mitmdump
mitmdump是mitmproxy的命令行接口。其与python脚本对接的功能很好用。

python脚本写好
```python
# test.py


def request(flow):
    flow.request.headers['User-Agent'] = 'MitmProxy'
    print(flow.request.headers)
```
解释下代码。定义了一个`request`方法，传入的参数是`flow`，这其实是一个`HTTPflow`对象，通过属性`request`如`flow.request`就可以获取当前的请求对象。

这个时候在命令行运行

```
mitmdump -s test.py
```
就可以抓取请求头，并且把头的`'User-Agent'`给修改了。

输出如下
```
Headers[(b'Host', b'utp-dmp.ucweb.com'), (b'Connection', b'keep-alive'), (b'Content-Length', b'4'), (b'Cache-Control', b'max-age=
0'), (b'Origin', b'https://utp.ucweb.com'), (b'User-Agent', b'MitmProxy'), (b'Content-Type', b'text/plain;charset=UTF-8'), (b'Acc
ept', b'*/*'), (b'Accept-Encoding', b'gzip, deflate, br'), (b'Accept-Language', b'zh-CN,en-US;q=0.8')]
```

* 日志

    mitmproxy里有封装好的日志类，可以通过不同的等级输出不同颜色的信息。
    ```python
    from mitmproxy import ctx


    def request(flow):
        flow.request.headers['User-Agent'] = 'MitmProxy'
        ctx.log.info(str(flow.request.headers))
        ctx.log.warn(str(flow.request.headers))
        ctx.log.error(str(flow.request.headers))
    ```
    还是刚刚的程序。这里返回的是`<class 'mitmproxy.net.http.headers.Headers'>`这样一个对象，所以这里用上`str`。
* request

    request的一些常用功能
    ```python
    def request(flow):
        r = flow.request
        info = ctx.log.info
        info("我透————" + r.url)
        info("请求头headers————" + str(r.headers))
        info("cookies————" + str(r.cookies))
        info("主机host————" + r.host)
        info("请求方法method ————" + r.method)
        info("port端口————" + str(r.port))
        info("请求方式scheme————" + r.scheme)
    ```
    如果要修改的话，直接对该属性赋值就行了。
    ```python
    r.url = "xxx"
    ```

* response

    使用response方法就能查看响应的内容
    ```python
    def response(flow):
        r = flow.response
        info = ctx.log.info
        info("status_code::::::" + str(r.status_code))
        info("header:::::" + str(r.headers))
        info("cookies::::" + str(r.cookies))
        info("text:::::" + str(r.text))
    ```