# Django ☞ Views
视图接收web请求，并且响应请求

## Url配置
* 指定根级url

    在settings.py文件中`ROOT_URLCONF`
    
    默认是项目下的url文件
* urlpatterns

    一个url实例列表，包含若干url对象
### 引入其他url配置
在每个应用中创建该应用的urls.py文件，用来定义本应用的url配置，在工程中的urls.py文件中使用`include()`方法引用。
```python
urlpatterns = [
    url(r'^admin/', admin.site.urls),
    url(r'^', include('myApp.urls'))
]
```
### url反向解析
## 视图函数
### 定义视图
视图本质就是一个函数
* 参数

    * 一个HttpRequests的实例
    * 通过正则表达式接收参数(括号里一个组))
* 位置：在应用的views.py定义
### 错误视图
* 404   NOTFOUND    
    * 不放在templates下的应用目录，直接放在templates
    * 需要修改settings.py
        ```python
        DEBUG = False

        ALLOWED_HOSTS = ['*']
        ```
        第一个如果填写True表示调试，则不会显示404.html；第二个表示允许所有的
* 500   视图代码出现错误(服务器代码)
* 400   错误是因为客户的操作(coockies,爬虫)
## HttpRequest对象 
服务器接收Http请求后，会根据报文创建一个`HttpRequest`对象，视图的第一个参数就是这个对象，然后Django调用视图函数，将这个对象传递个视图

一些属性如下：
* `path`        请求的完整路径，不包括域名和端口
* `method`      表示请求的方式（GET，POST）
* `encoding`    浏览器提交数据的编码方式
* `GET`         类似于字典的对象，包含了get请求的所有参数
* `POST`        同上，包含了post请求的所有参数
* `FILES`       同上，包含了所有上传的文件
* `COOKIES`     包含所有cookies
* `session`     表示当前会话

一些方法:
* is_ajax()     是否通过XMLHttpRequest发起的
### GET属性
获取浏览器传递过来给服务器的数据
比如网址
```
http://127.0.0.1:8000/get1/?a=python&b=123&c=qweaskj
```
这个时候浏览器会传递a,b,c三个参数过来，而使用GET就可以访问这三个参数
```python
def get1(request):
    a = request.GET.get('a')
    b = request.GET.get('b')
    c = request.GET.get('c')
    return HttpResponse(a + ' ' + b + ' ' + c)
```
如代码所示，使用`GET.get('a')`或者`GET['a']`就能获取

像输入网址
```
http://127.0.0.1:8000/get2/?a=jiangyuwei&a=123&c=qweaskj
```
当传递一个参数有多个值的时候，就使用`GET.getlist()`方法获取

```python
def get2(request):
    a = request.GET.getlist('a')
    c = request.GET.get('c')
    print(a)
    return HttpResponse(' '.join(a) + ' ' + c)
```
## POSt属性
使用表单实现POST请求