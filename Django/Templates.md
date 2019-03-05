# Django ☞ Templates
## 定义模板
模板能调用对象的方法，但不能传递参数
* 标签
    
    作用：在输出中创建文本；控制逻辑和循环
    * if:
        ```HTML
        {%if%}
        ...
        {%else%}
        ...
        {%endif%}
        ```
    * for:
        ```HTML
        {%for%}
        ...
        {%endfor%}
        ```
        若循环的列表为空时，执行empty内容
        ```HTML
        {%for%}
        ...
        {%empty%}
        ...
        {%endfor%}
        ```
    * commnet:注释多行
        ```HTML
        {%comment%}
        ...
        {%endcomment%}
        ```
    * ifequal/ifnotequal:
        ```HTML
        {% ifequal 'a' 'a' %}
        <h1>asd</h1>
        {% endifequal %}
        ```
    * include:
        ```HTML
        {% include '模板目录' 参数1 参数2 %}
        ```
    * url：反向解析{%url'namespace:name' p1 p2%}
        ```HTML
        <a href="{% url 'app:xioshengwaer' %}">链接</a>
        ```
    * csrf_token:用于跨站去办公区域伪造保护
        * 跨站请求伪造
            某些恶意网站包含
    * block,extends：用于模板继承
        * block在父模板中预留区域，子模板填充
            ```HTML
            <div id="main">
                {% block main %}
                {% endblock main %}
            </div>
            ```
        * extends继承模板，需要写在模板文件第一行
            ```HTML
            {% extends 'myApp/base.html' %}

            {% block main %}
                <h1>
                    NICE
                </h1>
            {% endblock main %}
            ```
    * autoescape：用于模板标签转义
### 过滤器
在显示前修改
* upper:大写
* lower:小写
* 过滤器可以传递参数
    ```HTML
    <h1>{{ test_list|join:'@' }}</h1>
    ```
* 如果一个变量不存在或者为False、空，可以使用默认值、
    ```HTML
    <h1>{{ test1|default:'没有' }}</h1>
    ```
* 根据给定格式转换日期为字符串
    ```HTML
    {{date|date:'y-m-d'}}
    ```
* HTML转义
### 验证码
