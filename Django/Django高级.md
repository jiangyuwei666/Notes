# Django ☞ 高级
## 静态文件
## 中间件
一个轻量级得底层插件，可以介入Django的请求喝响应

本质是一个Python类

* 方法：
    * \_\_init__() 
        
        不需要传递参数，服务器响应第一个请求的时候自动调用，用于是否启用该中间件
    * process_request() 
        
        在执行视图之前调用（分配url匹配视图之前），每个请求都会调用，返回None或者HttpResponse对象 
    * process_view()

        调用视图之前调用，每个请求都会调用，返回None或者HttpResponse对象 
    * process_template()

        在视图刚好执行完后调用，每个请求都会调用，返回None或者HttpResponse对象 

        使用render()返回模板
    * process_response()

        所有响应返回浏览器之前调用，每个请求都会调用，返回HttpResponse对象 
    * process_exception()

        当视图发生异常的时候调用
* 自定义中间件
    
    在项目目录项创建middleware目录，并创建应用目录
    ```python
    from django.utils.deprecation import MiddlewareMixin


    class MyMiddle(MiddlewareMixin):
        def process_request(self, request):
            print('get参数为：', request.GET.get('a'))
    ```
    并在配置文件的`MIDDLEWARE`中添加路径
## 上传文件
文件上传时文件数据存储在request.FILES属性中。先通过POST请求传上文件，再在request对象的FILES中拿出来，最后写入到服务器的指定目录下。
## 分页
* Paginator对象
    * 创建对象Paginator([],int) 
        
        列表是所有信息，int是每页几个。返回一个分页对象
    * 属性
        * count 对象总数（列表）
        * num_pages 页面总数
        * page_range 页码列表([1,2,3,4,5] 从1开始)
    * 方法
        * page(num)     
            
            获得一个page对象如果提供的页码不存在会抛出一个异常
* Page对象
## ajax
动态生成，返回json
## 富文本
丰富文本，比如加粗、倾斜、字体、颜色等
```
pip install django-tinymce
```
## celery
* 应用场景：
    * 用户发起request请求，并且等待response返回，但是在视图中，有一些耗时的操作，导致用户需要一定的时间接收response。因此用户体验不好
    * 网站每隔一段时间同步信息，但是http请求需要触发的(刷新)
* 解决：
    * 将耗时的操作放到celery执行
    * 使用celery定时执行
* celery
    * 任务：本质是一个函数，将操作封装成函数
    * 队列：将要执行的任务放在队列
    * 工人：负责执行队列中的任务
    * 代理：负责调度
* 安装：
```
pip install celery
pip install celery-with-redis
pip install django-celery
```
* 配置setting.py
    
    INSTALL_APPS添加`djcelery`并且初始化等配置
* 在应用目录下创建task.py 文件
* 迁移，生成celery需要的数据库表
    ```
    python manage.py migrate
    ``
    直接迁移
* 在工程目录下\_\_init__.py文件中添加