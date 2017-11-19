# SharedPreference
---
SharedPreference相当于是一个轻量的数据库，在整个App中都能使用，本质上是一个xml
1. 首先先获取对象
```java
SharedPreference sharedPreference = context.getSharedPreference( "操" , Context.MODE_PRIVATE );
//创建时先要获取上下文，在调用getSharedPreference方法
//第一个参数是这个数据库的名称，随便写写就行
//第二个参数是数据的类型，私有公有等等，一般不用管
```
2. 传入数据
</br>获取Editor对象
```java
Editor editor = sharedPreference.edit();
```
传值，只能传本来有的数据类，不能传自己定义的类对象
</br>并且传入的时候是使用键值对的形式传入
```java
editor.putBoolean(key,value);
editor.putString(key,value);
editor.putInt(key,value);
editor.putLong(key,value);
editor.putStringSet(ket , String<Set> value ) ;//也可以传入集合
```
提交
```java
editor.commit();
```
3. 数据获取
</br>在其他活动中想要用到这些数据的时候就可以直接按照上面，先创建一个sharedPreference对象，在调用其方法
```java
sharedPreference.getString( key , null ) ;
//key 就是之前传入的时候的key,null就不用管他了
```
4. 直接写
```java
sharedPreference.edit().putInt(key , value).commit();
```
