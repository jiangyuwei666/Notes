# CSRF验证
## CSRF简介
CSRF（Cross-site request forgery），跨站请求伪造。
## CSRF攻击原理
摘自[http://www.cnblogs.com/hyddd/archive/2009/04/09/1432744.html](http://www.cnblogs.com/hyddd/archive/2009/04/09/1432744.html)
![](http://ww1.sinaimg.cn/large/006BhB5Oly1g0wgmubq3wj30t80ghqjo.jpg)
## 作用原理
csrf要求用户在发送post,put或delete请求的时候，是先以get方式发送请求，服务端响应时会分配一个随机字符串给用户(浏览器)，用户第二次发送post,put或delete请求时携带上次分配的随机字符串到服务端进行校验
处理的时候。
## Django中间件作用过程
Django中间件的调用过程如下：
![django中间件的调用过程](http://ww1.sinaimg.cn/large/006BhB5Oly1g0wgxqe2dyj30wc0hxabh.jpg)
在用户请求的过程中，要经过中间件，先执行每个中间件的request，做路由匹配，找到视图方法但是不执行，回去，再次执行view并验证。

为什么用process_view？
```
必须要先找到view函数才能做判断
在MIDDLEWARE中添加csrf表示全站使用
```
## 使用CSRF验证
* 在配置文件中的中间件MIDDLEWARE中添加CSRF表示全体使用
    ```
    'django.middleware.csrf.CsrfViewMiddleware',
    ```
    全局使用时，使用@csrf_exempt装饰器表示这个函数不需要认证

    全局使用时，使用@csrf_protect装饰器表示这个函数需要认证

    使用下面两种方式是对CBV使用中的部分方法使用装饰器

    ```python
    from django.views.decorators.csrf import csrf_protect, csrf_exempt
    from django.utils.decorators import method_decorator


    # Create your views here.
    class StudentView(View):

        @method_decorator(csrf_exempt)
        def dispatch(self, request, *args, **kwargs):
            return super(StudentView, self).dispatch(request, *args, **kwargs)

        def get(self, request, *args, **kwargs):
            return HttpResponse('GET')

        @csrf_protect
        def post(self, request, *args, **kwargs):
            return HttpResponse('POST')

        def put(self, request, *args, **kwargs):
            return HttpResponse('PUT')

        def delete(self, request, *args, **kwargs):
            return HttpResponse('DELETE')
    ```
    ```python
    from django.views.decorators.csrf import csrf_protect, csrf_exempt
    from django.utils.decorators import method_decorator


    # Create your views here.
    @method_decorator(csrf_exempt, name='dispatch')
    class StudentView(View):

        def get(self, request, *args, **kwargs):
            return HttpResponse('GET')

        @csrf_protect
        def post(self, request, *args, **kwargs):
            return HttpResponse('POST')

        def put(self, request, *args, **kwargs):
            return HttpResponse('PUT')

        def delete(self, request, *args, **kwargs):
            return HttpResponse('DELETE')
    ```
