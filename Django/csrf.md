# CSRF_TOKEN验证
用户发送post请求的时候，要求必须携带服务器之前发给用户的一个随机字符串，先get请求后，服务器返回给其一个随机字符串，下一次再发请求的时候必须携带这个字符串
处理的时候
在用户请求的过程中，要经过中间件，先执行每个中间件的request.找到视图方法但是不执行，回去，再次执行view并验证，
视图中
为什么用process_view
必须要先找到view函数才能做判断
在MIDDLEWARE中添加csrf表示全站使用

@csrf_protect表示这个函数需要认证
@csrf_exempt表示这个函数需要认证
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
