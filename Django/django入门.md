# Django入门
## 创建项目
在合适目录下打开终端输入命令
```
django-admin startproject 项目名
```

## 目录层级说明
* manage.py

    命令行工具。可以使我们用多种方式对Django项目进行交互
* 项目目录
    * \_\_init\__.py    空文件
    * settings.py   配置文件
    * urls.py    url模拟器  项目的url声明
    * wsgi.py   项目与wsgi兼容的web服务器入口
## 基本操作
### 配置数据库
* 在\_\_init\__.py文件中导入`pymysql`
    ```python
    import pymysql
    pymysql.install_as_MySQLdb()
    ```
    因为在Django中，使用的是python2的`MySQLdb`库，而这一行代码是让Django把`pymysql`库当作`MySQLdb`来使用
* 在settings.py文件中修改数据库支持

    找到配置中的的数据库
    ```
    DATABASES = {
    'default': {
        'ENGINE': 'django.db.backends.sqlite3',
        'NAME': os.path.join(BASE_DIR, 'db.sqlite3'),
        }
    }
    ```
    可以看到默认支持的是sqlite3需要将其修改

    比如mysql
    ```
    DATABASES = {
    'default': {
        'ENGINE': 'django.db.backends.mysql',
        'NAME': "first_django", # 数据库名
        'USER': "root", # 用户名
        'PASSWORD': "root", # 用户密码
        'HOST': 'localhost', # 服务器ip地址
        'PORT': 3306, # 端口号
        }
    }
    ```
### 创建应用
在项目下输入
```
python manage.py startapp 应用名
```
如创建名为myApp的应用
```
python manage.py startapp myApp
```
#### 应用目录
* admin.py      站点配置
* models.py     模型
* views.py      视图
### 激活应用
在settings.py文件中将`myApp`应用添加到`INSTALLED_APPS`中

只需在最后面添加`'myApp'`如
```python
INSTALLED_APPS = [
    'django.contrib.admin',
    'django.contrib.auth',
    'django.contrib.contenttypes',
    'django.contrib.sessions',
    'django.contrib.messages',
    'django.contrib.staticfiles',
    'myApp'
]
```
### 定义模型
**一个数据表就对应一个模型**

在models.py文件中定义模型

不需要定义主键，在生成时自动添加，并且值是自动增加的

比如：
```python
class Students(models.Model):
    sname = models.CharField(max_length=20)  # 字符型，最大长度为20字节
    sgender = models.BooleanField(default=True)  # boolean类型 设置默认为True
    sage = models.IntegerField()  # 整型
    scomment = models.CharField(max_length=20)
    is_delete = models.BooleanField()
    # 关联外键
    sclass = models.ForeignKey("Class")
```
注意：不能写__init__()方法
### 在数据库中生成数据表
1. 生成迁移文件

    执行命令
    ```
    python manage.py makemigrations
    ```
    执行这一步之前一定要确保几点：
    * 是否将当前应用添加到`INSTALLED_APPS`中
    * 数据库是否连接，是否配置号
    * 数据库是否创建

    执行完成后会在`migrations`目录下，生成一个`0001_initial.py`的文件，其中的信息和之前models.py中的大致相同

    此时也会在数据库中生成一张表叫`django_migrations`

2. 执行迁移

    在相同目录下，执行命令
    ```
    python manage.py migrate
    ```
    这个时候检查数据库，就会发现生成了很多的表
    
    我们需要的创建的表就在其中

    相当于执行sql语句创建了表，只是表名改为`项目名_类名`
### 通过模型操作数据
首先进入终端
```
python manage.py shell
```
然后依次导入以下几个包
```
from myApp.models import Class, Students

from django.utils import timezone

from datetime import *
```
第一个是操作要用到的类
第二个是一个工具包
* 添加数据——创建一个模型类的对象实例
    
    创建类对象并且依次给对象的各个属性赋值

    然后保存到表中
    ```
    In [5]: class2 = Class()

    In [6]: class2.cname = 'baolaoshi'

    In [7]: class2.cdate = datetime(year = 2019, month=2, day=22)

    In [8]: class2.cgirl_num = 10

    In [9]: class2.cboy_num = 12

    In [10]: class2.is_delete = False

    In [11]: class2.save()
    ```
* 查询数据
    
    通过`类名.objects.all()`查看全部

    通过`类名.objects.all()`选择查询
* 修改数据

    通过对像修改并保存
* 删除数据

    通过对象进行物理删除
* 关联对象

    通过对象进行关联
    ```
    stu = Students()

    stu.sclass = class2
    ```
    如此就将其关联上，使stu属于class2（其中class2是已有对象，如果没有，需要先进行查找）
* 获取关联对象集合

    比如查询某班所有学生`（班级）对象名.类名_set.all()`
    ```python
    class2.students_set.all()
    ```
### 启动服务器
命令行中输入以下指令
```
python manage.py runserver ip:port
```
ip不写的话默认为本机， 端口号默认为8000

这是python写的轻量级的web服务器，仅仅在测试的时候使用
### Admin站点管理
* 内容发布

    负责添加，删除，修改内容
* 公告访问
1. 配置Admin应用

    settings.py中的INSTALLED_APPS添加，默认是添加了的
2. 创建管理员用户
    
    执行
    ```
    python manage.py createsuperuser
    ```
3. 自定义管理页面
在admin.py文件下进行修改
```python
from .models import Class, Students


# 创建时会选择添加若干个学生
class StudentInfo(admin.TabularInline):
    model = Students  # 关联类
    extra = 2  # 学生个数


@admin.register(Class)
class ClassAdmin(admin.ModelAdmin):
    inlines = [StudentInfo]
    # 列表页属性
    list_display = ['pk', 'cname', 'cdate', 'cgirl_num', 'cboy_num']  # 显示字段
    list_filter = ['cname']  # 过滤字段
    search_fields = ['cname']  # 搜索字段
    list_per_page = 5  # 分页，每5条一页
    # 添加、修改页
    # fields = []  # 属性的先后顺序
    fieldsets = [
        ("num", {"fields": ['cboy_num', 'cgirl_num']}),
        ("base", {"fields": ['cdate', 'cname', 'is_delete']})
    ]  # 给属性分组  两个属性不能同时使用


@admin.register(Students)
class StudentAdmin(admin.ModelAdmin):
    # 修改第一栏的显示
    def gender(self):
        if self.sgender:
            return '男'
        else:
            return '女'

    # 设置页面的列的名称
    gender.short_description = '性别哟栽种'
    list_display = ['pk', 'sname', 'sage', gender, 'scomment', 'sclass']

    list_per_page = 3

    # 执行动作的位置
    actions_on_bottom = True
    actions_on_top = False
```
## 视图
在Django中，视图对web请求进行回应。视图就是一个函数，在`views.py`中定义。
### 定义视图
### 配置url
* 修改project目录下的urls.py文件
* 在myApp应用目录下创建一个urls.py文件
## 模板
模板就是HTML界面，可以根据视图中传递过来的数据进行填充
### 创建模板
创建templates目录，在目录下创建对应项目的模板目录（比如：first_django_project/templates/myApp）
### 配置模板路径
* `修改settings.py`文件中的`TEMPLATES`的`DIR字段`

    BASE_DIR就是当前项目的路径，所以只需修改成如下
    ```python
    'DIRS': [os.path.join(BASE_DIR, 'templates')],
    ```