# 美汤
beautifulsoup解析HTML或者XML文档,传入网址url,得到一个标签树,再进过处理返回一个beautifulsoup对象,对这个对象进行处理就是对网址处理

## 介绍
* BeautifulSoup库的解析器

![bs解析器]()

* BeautifulSoup的一些属性
![bs的属性](https://github.com/jiangyuwei666/Notes/blob/master/pictrue/Beautiful%20Soup%E7%9A%84%E5%B1%9E%E6%80%A7.png)

## BeautifulSoup的基本用法

</br>1. 使用是先要导入BeautifulSoup这个模块 
```python
from bs4 import BeautifulSoup
```
</br>2. BeautifulSoup是可以和requests模块一起使用的
```python
url = "https://www.baidu.com/"
r = requests.get( url )
r.encoding = 'utf-8'
bs = BeautifulSoup( r.text , "html.parser" ) #后边的参数是解析器，有多种，html.parser是python自带的
```
我们可以打印一下
```python
print ( bs ) #这个打印出来是网页源码
print ( type ( bs ) ) #这个打印是出来是<class 'bs4.BeautifulSoup'> 是bs4里定义的类 
```
</br>3. 获取标签
</br>比如获取P标签直接就是
```python
print ( bs.p ) #这里打印出来就是整个p标签，包括其标签头和标签内容，以及其中的属性
print ( bs.p.string ) #获取标签内容
print ( bs.p.name )#获取标签名称 就是p
print ( bs.p.parent.name ) #获取父节点的名称
```
但是这些方法都只能得到从上到下的第一个节点，如果想要获取到整个网站上的某一类就要用到下面的方法

</br>4. find和find_all 方法
find方法其实在爬虫上面没什么卵用，主要是find_all方法的用法
比如我们要获取一个网址上所有的a标签
```python
List = bs.find_all ( 'a' ) 
```
这样我们就得到了所有a标签
但是有的a标签并不是我们想要的，比如我们只想要class 属性为abc的a标签
```python
List = bs.find_all ( 'a' , class_ = 'abc') #这里注意，因为class是Python的关键字，所以为了避免电脑瓜皮，要加个_
```
再进一步，如果我们要的是a标签中某个属性的值 ,比如href属性
```python
List2 = []
for i in List :
List2.append( i.get ( 'href' ) ) 
```
这样就将所需要的东西放到了List2 中

</br>3. 通过循环遍历所有标签:分为上序遍历,下序遍历,平行便利
</br>先煮汤
```python
r = requets.get( url )
soup = beautifulsoup( r.text , "html.parese" )
```
* 上序遍历(假设a标签是底层标签)
```python
for parent in soup.a.parents:
    print ( parent )#parent是上一个,parents是所有父节点
```
* 下序遍历(html为顶层标签)
```python
for children in soup.html.children
    print ( children )
```
* 平行遍历
平行遍历主要是分为两种:遍历前面的节点和遍历后面的节点

![平行遍历的方法](https://github.com/jiangyuwei666/Notes/blob/master/pictrue/%E5%B9%B3%E8%A1%8C%E9%81%8D%E5%8E%86.png)

```python
#遍历后续节点
for sibling in soup.a.next_siblings:
    print( sibling ) 
```
```python
#遍历后序节点
for sibling in soup.aprevious_sublings:
    print( sibling )
```

![平行遍历划分](https://github.com/jiangyuwei666/Notes/blob/master/pictrue/bs%E5%B9%B3%E8%A1%8C%E9%81%8D%E5%8E%86%E6%A0%87%E7%AD%BE.png)

* prettify()
可以将乱的源码改成树形结构，但是有Chrome时没求用