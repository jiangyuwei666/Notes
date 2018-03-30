# Python

* 类
```python
class Human:
        #weight = 60    # 公有属性，跟java不同的是，属性在__init__方法中声明即可
        #__country = 'China'     # 私有属性,__也是属性名的一部分

        def __init__(self,weight,height,country):  
              self.__weihgt = weight #类的成员变量在构造函数中定义
              self.__height = height
              self.__country = country

        def show(slef):
        print(slef.__weihgt ,slef.__height,slef.__country )
```
这个类定义两个方法：
*  __ init __
</br>相当于java中的构造器，其中必须有的一个参数self,但是调用时不需要传入这个参数
* 其他的方法
</br>如show方法，如果需要调用类的成员变量，必须加入self参数，但是调用的时候也不用传入self
</br>**需要注意的是，python里面并没又重载方法**:
        </br>1. 变量类型发面：第一python可以接受任何类型的参数，如果函数的功能相同，即使是不同的参数类型，也是执行的同一代码。比如上面这个构造函数和show(),我们不论是传入整型，浮点型甚至字符串类型都可以执行。
        </br>

```python
if __name__ =='__main__':
    jiang = Human( 60 , 170 , 'China')
    jiang.show
```
继承
```python
class man(Human):

        def__init__( self,weight,height,country,dick ):
             Human.__init__(self,weight,height,country)
             slef._dick = dick
```

·对于列表的处理方面上，有两种添加方式
(1)如果你想对列表添加若干个元素的话，使用append方法较好，代码如下：
```python
list = []
list.append(1)
print (list)
```
注意这个方法一次只能添加一个元素，不能一次添加多个元素如：
list.append(1,2)这种写法就是错误的
当然也可以添加列表，字典等：
```python
list.append([1])
list.append({1})
```
(2)如果你是想将两个列表拼接起来的话，那么可以采用 + 运算符来操作：
```python
list1 = [1,2]
list2 = [3,4]
print ( list1.append(list2) )
print ( list1 + list2 )
```
输出结果如下：
```python
[1,2,[3,4]]
[1,2,3,4]
```
很明显你就知道为什么用+不用append方法了

(3)列表的删除

很多时候，列表里的东西并不全是你想要的所以我们需要来删除一些

比如你要前5个元素
```pyhton
list = list[0:5] 

```
这里注意，列表和数组一样第一个元素的脚标为0

比如我们要后5个元素
```pyhton
list = list[-6:-1]
```
从后往前的一个是-1

如果我们看列表里面的某一个元素不顺眼就可以用

List.remove(元素名)

上诉两种方法的区别就在于append方法是在原列表上操作，没有创建新的列表，而通过运算符会创建新的列表

#——————————————————————————————

·字符串前面加r

字符串前加一个r的作用是为了让字符串中的一些转义字符如:  \r , \n,\t,\x之类的字符进行正常使用，不让他转义

#——————————————————————————————

文件操作

(1)使用open方法创建一个文件对象
```python
file = open ( 'd:\test\abc.txt' , 'r' , encoding = 'utf-8' )
```
第一个参数是你所要打开的文件路径，第二个是打开方式  r是只读  w是只写  wr 读写

第三个参数是编码方式

这样我们就得到了一个文件类对象

(2)使用和write()方法

比如我们已经建立了一个好了一个文件类对象file ,是以 w 方式打开，说明我们要往文件写一些东西的时候

用 file.write()

用这个方法的时候需要注意一点就是，它只能写 string 到文件里，所以一般要用  file.write( str () )这样写内容

(3)read(),readline(),readlines()三种方法的区别
```python
file = open ( 'd:\test\abc.txt' , 'w' )
file.read()#得到的就是文件的内容，并且它也是个字符串
file.readline()#只有这一行的话，就只输出第一行的内容
```
所以一般会加入循环使用
```python
for i in open( 'd:\test\abc.txt' , 'w' )
   print ( file.readline() ) #输出的依然全都是字符串
file.readlines(),是将文件的内容以列表的形式输出
```
#—————————————————————————————————
·pychram多个文件相互调用

1.要使用的应该再同一层，同一个文件夹下

2.使用之前要先导入该文件，和导包一样
```python
import aaa #aaa是文件名
```
3.使用该文件中的类或者方法的时候格式应该是  文件名.方法
```python
aaa.bbb()
```
