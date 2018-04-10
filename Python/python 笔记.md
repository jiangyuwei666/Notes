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