# Django ☞  Models
Django中的Models(模型)是用来对数据库中的数据进行操作的

Django对各种数据库提供了很好的支持，Django为这些数据库提供了统一的

## 开发流程
* 配置数据库
* 定义模型类
* 生成迁移文件
* 执行迁移，生成数据表
* 使用模型进行增删改查
## ORM 对象关系映射
辅助Django对数据进行操作的中间件：
* 根据对象类型生成表结构
* 将对象、列表的操作转换为sql语句，去操作数据
* 将sql语句执行后得到的结果转换为对象、列表并返回
## 定义模型
**一个模型类对应数据库中的一张表，类中定义的一个属性对应表中的一个字段**
## 定义属性
* 如果没有手动设置主键，Django会自动设置主键，并且自动增长
* 注意不要使用`__`等python的特殊关键字标识符
* 定义是需要设置字段类型（from django.db import models）
* 逻辑删除
    
    对于重要的数据都做逻辑删除，不做物理删除，实现方法是定义isdelete属性，类型也就是BooleanField，默认值设置成False
### 字段类型
* AutoField

    根据实际ID自动增长的IntegerFiled，通常不指定
* CharFiled(max_lenth=字符最大长度)

    字符串，默认的表单样式是TextInput(站点里显示的样式)
* TextField

    大文本字段，一般超过4000使用，默认的表单样式Textarea
* IntegerField
    
    整型
* DecimalField(max_digits=None, decimal_places=None)

    表示十进制的浮点数
    * max_digtis 位数总数
    * dicimal_places 小数点后有多少位
* FloatField

    浮点数
* BooleanField

    默认表单样式是CheckboxInput
* NullBooleanField

    支持null,true,false
* DateField([auto_now=False, auto_now_add=False])

    日期
    * auto_now 每次保存对象时自动设置该字段位当前时间(可以用于"最后一次修改时间：")
    * auto_now_add 当对象第一次被创建时，自动设置成当前时间（这样就没法自动设置时间）

    注意分开写，不能组合
* TimeField

    时间
* DataTimeField

    时间和日期
* FileField

    一个上传文件的字段
* ImageField

    图片类型字段
### 字段选项
字段类型都有的一些参数选项
* null

    默认False
* blank

    是否允许该字段为空，默认为False
* db_colunm

    可以修改数据库的字段列的名称，不用默认使用类属性的名称
* db_index

    为此字段创建一个索引
* defalut

    默认值
* primary_key

    是否为主键， 默认为False
* unique

    是否唯一，默认为False
### 关系
#### 定义
* ForeignKey 一对多，将字段定义在多的里面

    如班级和学生，学生多，就在学生的班级属性下使用该字段
    ```python
    sclass = models.ForeignKey("Class")
    ```
* ManyToManyField 多对多，将字段定义在两端
* OneToOneField 一对一，任意一段
#### 访问
* 用一访问多
    * 格式：对象.模型类(小写)_set
## 元选项
在*模型类*中定义的Meta类，用于设置信息，有两个参数
* db_table

    定义表在数据库中的表名，如果不设置默认为包名_类名
* ordering

    取出数据后的显示顺序，如
    ```python
    ordering = ['id']  # 按照id升序
    ordering = ['-id']  # 按照id降序
    ```
    注意：排序会增加数据库的开销
## 模型类成员
### 类属性
`objects`是Manage类的一个对象，用于与数据库交互的管理器

* 自定义管理类Manage

    通过重写类的方法如`get_queryset()`等用来对数据进行过滤，如
    ```python
    class StudentManage(models.Manage):
        def get_queryset(self):
            return super(StudentManage, self).get_queryset().filter(isDelete=False)
    ```
    这个自定义管理类就是查询时，过滤掉isDelete是True的 
## 创建模型对象
* 在自定义管理类Manage中添加方法创建
* 在模型类中添加类方法进行创建
## 模型查询
* 查询集表示从数据库中获取的对象的集合
* 查询集可以有多个过滤器`.filter()`
### 查询集
* 返回查询集的方法就叫过滤器
    * all()
    * filter() 返回符合条件的数据
    * exclude() 去除符合条件的数据
    * order_by() 排序
    * values() all()返回对象，这个方法直接返回数据
    
    返回单个数据：
    * get() 返回一个满足条件
        
        如果没有找到符合条件，就会引发异常

        如果找到多个对象，也会引发异常
    * count() 
    * first()
    * last()
    * exists() 判断查询集中是否有数据
* 在管理器类上调用过滤器方法返回查询集，并且可以链式调用
* 惰性执行：创建查询集时不访问数据，直到调用时才访问
* 查询集返回来的是一个列表，可以通过切片的方式来取数据
### 查询集缓存
每个查询集都包含一个缓存，以此最小化的对数据库访问

查询集首次为空，第一次查询集求职，会发生数据缓存，django会将查询出来的数据做一个缓存，并返回查询结构，以后的查询直接使用查询集缓存
### 字段查询
*  contains

    包含什么字段，属性名（字段名）__contains如
    ```python
    student_list = Students.objects.filter(sname__contains='a')
    ```
    获取名称属性包含'a'的查询集，模糊查询
* startswith 和 endswith

    以vlaue开头或者结尾，两个可以一起用
    ```python
    student_list = Students.objects.filter(sname__startswith='j', sname__endswith='i')
    ```
**注意：以上属性前加`i`就不区分大小写**。如：icontains和istartswith
* isnull 和 isnotnull

    是否为空
* in

    是否包含在范围内
* 比较
    * gt    大于
    * gte   大于等于
    * lt    小于
    * lte   小于等于
* 日期
    * year
    * month
    * day 
    * week_day
    * hour
    * minute
    * second
### 聚合函数
使用aggregate()函数返回聚合函数的值

此部分需要导入`django.db.models`
* Avg   平均值
* Max   最大值
* Min   最小值
* Count 计数
* Sum   求和
### F对象
* 可以使用的A属性和B属性进行比较
    ```python
    class_list = Class.objects.filter(cgirl_num__lt=F('cboy_num'))
    ```
    找出女生比男生多的班级
* 支持F对象的算术运算
    ```python
    class_list = Class.objects.filter(cgirl_num__lt=F('cboy_num') + 20)
    ```
    找出女生比男生多20个以上的班级

### Q对象
实现`filter()`的or关系
```python
student_list = Students.objects.filter(Q(sage__gt=10) | Q(sclass_id__gt=2))
```
选择班级id大于2或者学生年龄大于10的学生