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
DATABASES = {
    'default': {
        'ENGINE': 'django.db.backends.mysql',
        'NAME': "first_django",
        'USER': "root",
        'PASSWORD': "root",
        'HOST': 'localhost',
        'PORT': 3306,
    }
}
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