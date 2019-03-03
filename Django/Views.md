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

首先需要一个注册界面，填完信息后返回给后台

![注册](http://ww1.sinaimg.cn/large/006BhB5Ogy1g0pfrm3qzwj319z0bqwf1.jpg)

```HTML
<form action="/register/" method="post">
        姓名:<input type="text" name="name" value=""/>
        <hr/>
        性别:<input type="radio" name="gender" value="1"/>男
            <input type="radio" name="gender" value="0"/>女
        <hr/>
        年龄:<input type="text" name="age" value=""/>
        <hr/>
        爱好:<input type="checkbox" name="hobby" value="football"/>足球
            <input type="checkbox" name="hobby" value="basketball"/>篮球
            <input type="checkbox" name="hobby" value="pingpang"/>乒乓球
        <hr/>
        <input type="submit" value="注册"/>
</form>
```
`action`表示点击后跳转的路径，`method`是请求方法

而视图这边则是需要一个显示注册表单，一个获取注册信息并显示
```python
def register(request):
    """
    获取表单并显示
    """
    name = request.POST.get('name')
    gender = request.POST.get('gender')
    age = request.POST.get('age')
    if 1 == int(gender):
        gender = '男'
    else:
        gender = '女'
    hobby = request.POST.getlist('hobby')
    print(request.POST)
    return HttpResponse('姓名:' + name + '\n' + '性别:' + gender + '\n' + '年龄:' + age + '\n' + '爱好:' + ','.join(hobby))


def showregister(request):
    """
    显示注册界面
    """
    return render(request, 'myApp/register.html')
```
## HttpResponse对象
给浏览器返回对象

HttpRequest对象是由Django创建的，而HttpResponse对象由开发人员创建
### 用法
* 不使用模板templates
    直接返回数据
* 调用模板：使用render方法
    * 原型：`render(request, templateName[, context)`
    * 作用： 结合数据和模板，返回一个完整的HTML界面
    * 参数：
        * request 请求体对象
        * templateName 模板名
        * context 传递给需要渲染再模板上的示例
### 属性
* content   表示响应内容的类型
* content-type  指定输出的MIME类型
* charset   表示响应内容的编码格式
* status_code   响应状态吗
### 方法
* init  使用页面的内容实例化HttpResponse对象
* write(content)    以文件的形式输出
* flush()   以文件的形式输出缓冲区
* set_cookie(key, value='', max_age=None, exprise=None)
* delete_cookie(key)    删除不存在时，什么都不会发生
### 子类HttpResponseRedirect
重定向，实现网页跳转
```python
def redirect1(request):
    return redirect('/redirect2')


def redirect2(request):
    return HttpResponse('重定向')
```
redirect()与HtttpResponseRedirect的关系类似render()与HttpResponse的关系
### 子类JsonResponse
返回json数据，一般用于异步请求
## 状态保持
因为http请求是无状态的，所以需要一些数据存在服务端和客户端实现状态保持
* cookie 所有的数据存在客户端
* session 所有的数据存储在服务端

在一段时间内跟踪请求者的状态，可以实现跨页面访问请求者的数据
### 启用session
settings.py中 INSTALLED_APPS和MIDDLEWARE中默认启用
### 使用session
启用后。每个HttpRequest对象都有一个session属性
* get(key, default=None) 根据键获取session值,如果没去到默认为None
* clear() 清空所有会话
* flush() 删除当前会话并删除会话的cookie

使用完后查看数据库的sessions表就会发现有数据添加进去，但是跟我们的存的值不一样是应为他使用base64编码，只需要解码就会发现是一样的。
```python
# session+重定向
def main(request):
    # 取出session
    username = request.session.get('username')
    if username:
        pass
    else:
        username = '未登录，请先登录'
    return render(request, 'myApp/main.html', {'username': username})


def login(request):
    return render(request, 'myApp/login.html')


def showmain(request):
    username = request.POST.get('username')
    print(username)
    # 储存session
    request.session['username'] = username
    return redirect('/main')


from django.contrib.auth import logout


def qt(request):
    # 清楚session
    logout(request)
    # request.session.clear()
    # request.session.flush()
    return redirect('/main')
```
### 设置过期时间
```
set_expiry(value)
```
如果不设置，默认两个星期后过期，这个value可以是
* 整数：表示秒数
* 时间对象
* 0：关闭浏览器时失效
* None：永不过期