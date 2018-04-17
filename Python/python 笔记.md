# Python

## 类
```python
class Human:
    # weight = 60    # 公有属性，跟java不同的是，属性在__init__方法中声明即可
    # __country = 'China'    # 私有属性,__也是属性名的一部分

    def __init__(self, weight, height, country):
        self.__weihgt = weight  # 类的成员变量在构造函数中定义
        self.__height = height
        self.__country = country

    def show(slef):
        print(slef.__weihgt, slef.__height, slef.__country)
```
这个类定义两个方法：
*  __ init __
</br>相当于java中的构造器，其中必须有的一个参数self,但是调用时不需要传入这个参数
* 其他的方法
</br>如show方法，如果需要调用类的成员变量，必须加入self参数，但是调用的时候也不用传入self
</br>**需要注意的是，python里面并没又重载方法**:
    </br>1. 变量类型发面：第一python可以接受任何类型的参数，如果函数的功能相同，即使是不同的参数类型，也是执行的同一代码。比如上面这个构造函数和show(),我们不论是传入整型，浮点型甚至字符串类型都可以执行。
    </br>2. 方法参数可变：python的缺省参数，可以选择使用或者不使用，所以也没有必要重载。
```python
if __name__ =='__main__':
    jiang = Human( 60 , 170 , 'China')
    jiang.show()
```
## 函数参数
### 设置默认参数
上面提到python中可以通过改变参数个数来实现方法的多态性就不用重载方法。而省缺参数之所以能够省缺是通过给方法的参数设置默认值。
</br>比如给出一个做加法的函数
```python
def add ( x , n ) :
    sum = 0
    for i in range( n ) :
        sum = sum + x
    return sum

a = add ( 2 , 5 )
print( a )
```
得到结果是
```
10
```
如果设置默认参数
```python
def add ( x , n = 2 ) :
    sum = 0
    for i in range( n ) :
        sum = sum + x
    return sum

a = add ( 2 )
b = add ( 2 , 5 )
print( a ， b )
```
得到的结果
```
4 10
```
### 可变参数
传入的参数是可变的，想想，可以把参数定为一个**列表**或者**元组**，然后在函数中用一个循环就可以遍历到所有导入的参数
</br>比如这样
```python
def add ( numbers ) :
    sum = 0
    for i in numbers:
        sum = sum + i 
    return sum

a = add ( [2] )
b = add ([2 , 3 , 4 , 5])
```
</br>但是这样的话每次调用之前就需要用列表或者元组将参数给包装起来，这样肯定是很麻烦的。
</br>所以可以用可变参数
```python
def add ( *numbers ) :
    sum = 0
    for i in numbers:
        sum = sum + i 
    return sum
```
这里的原理就是将所有参数包装成一个元组，然后在函数中遍历
</br>**这里注意，如果参数本身是一个列表和字典的时候，可以直接在参数前面加\***
</br>比如上面那个方法
```python
list = [ 1 , 2 , 3 ]
add( *list )
```
### 关键字参数
关键字参数比起可变参数，更加强大。
</br>关键字参数在函数调用时，直接将参数打包成一个字典，直接将自己需要的参数写进去，调用的时候通过字典```kwargs```调用
```python
def print_ ( ** kwargs ):
    print( kwargs )

print_( a = 123 , b = 'asd' , c = [1 , 2 , 3])
```
输出结果
```python
{'a': 123, 'b': 'asd', 'c': [1, 2, 3]}
```
## 函数返回值
python中一个方法允许返回多个值
```python
def aaa():
    return 1,2,3

a,b,c = aaa()
print( a,b,c )
```
输出得到
```
1 2 3
```
## 继承
```python
class man(Human):

    def__init__( self,weight,height,country,dick ):
        Human.__init__(self,weight,height,country)
        slef._dick = dick
```

## 坑
这里有一个坑
```python
>>> class Student:
...     grade = 1
...     def print_ (self):
...             print( 'print' )
...
>>> s = Student
>>> s.grade
1
```
可以看到，能够输出grade
</br>执行这个代码
```python
class Student :
    grade = 1
    def print_(self):
        print( 'print' )
s = Student
s.print_()
```
这里就会出错了
```
TypeError: print_() missing 1 required positional argument: 'self'
```
错误显示缺少了参数
</br>结果是因为我们相当于是直接把这个类又给了一个名字，并没有创建实例
```python
class Student :
    grade = 1
    def print_(self):
        print( 'print' )

s = Student()
s1 = Student
print ( s )
print( s1 )
print( Student )
```
结果
```
<__main__.Student object at 0x0000025666C490B8>
<class '__main__.Student'>
<class '__main__.Student'>
```