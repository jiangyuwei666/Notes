用来把别的布局加到主要的布局之中，比如像一些Title

1.首先获取LayoutInflate实例
```java
LayoutInfalte layoutinflate = LayoutInfalte.from( context ) ;
```
2.使用Inflate方法加载布局
```java
layoutinfalte.infalte( resourceId , parent ) ;
```
resourceId是要加载的的布局的id,通过 R.Layout.xxxx查找
parent 是给这个布局的外面再嵌套一个布局
这个方法返回一个 View类的对象
这个时候已经完成了布局的加载，然后就可以把它放到别的布局当中了
4.首先需要一个主要的布局，比如 main_layout
先把他转化成LayoutInflate对象
```java
mainlayout = ( LayoutInflate ) findViewById ( R.id.main_layout ) ;
```
然后再用addView方法把它上面加载的布局放到主布局中
```java
mainlayout.addView( mainlayout ) ;
```
