# restframework ☞ FBV CBV
FBV(function base views)和CBV(class base views)分别指在视图中使用函数和类处理请求
## FBV
在视图中写一个一个的方法，一个方法对应一个url，处理一个请求，不再赘述。
## CBV
在视图中通过写一个类，一个类对应一个url，一个类可以处理多种类型的请求。

定义如下
```python
# 使用restframework继承自APIView
from rest_framework.views import APIView
class StudentView(APIView):

    def get(self, request, *args, **kwargs):
        return HttpResponse('GET')

    def post(self, request, *args, **kwargs):
        return HttpResponse('POST')

    def put(self, request, *args, **kwargs):
        return HttpResponse('PUT')

    def delete(self, request, *args, **kwargs):
        return HttpResponse('DELETE')
```
url定义如下
```python
url(r'^student/', views.StudentView.as_view(), name='wonima'),
```
## CBV作用原理
CBV通过 **反射** 来处理不同的请求。具体实现查看源码后可以发现是通过`dispatch()`方法来实现的。)

部分源码（是APIView的源码，较为简单的在View里）
```python
# Get the appropriate handler method
if request.method.lower() in self.http_method_names:
    handler = getattr(self, request.method.lower(),self.http_method_not_allowed)
else:
    handler = self.http_method_not_allowed

# response是请求方法,request是加工后的request
response = handler(request, *args, **kwargs)
```
这个`method_name`是已经定好的，说明它只支持以下的访问方式
```python
http_method_names = ['get', 'post', 'put', 'patch', 'delete', 'head', 'options', 'trace']
```
## 验证
## 权限控制
## 访问频率

