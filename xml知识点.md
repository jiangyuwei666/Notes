1.padding
表示给控件的周围加上补白
```xml
android:paddingTop="15dp"
```
这个表示给控件上面留15个单位的空白，类似的还有left right bottom

2.weight比重的使用
```xml
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"  
    xmlns:tools="http://schemas.android.com/tools"  
    android:layout_width="match_parent"  
    android:layout_height="match_parent"  
    android:gravity="bottom|center_horizontal" >  
  
    <Button  
        android:id="@+id/button_1"  
        android:layout_width="0dp"  
        android:layout_height="wrap_content"  
        android:layout_weight="1"  
        android:text="left" />  
  
    <Button  
        android:id="@+id/button_2"  
        android:layout_width="0dp"  
        android:layout_height="wrap_content"  
        android:layout_weight="3"  
        android:text="right" />  
  
</LinearLayout>  

```
先在LineraLayout让它放在底部中间，然后在每个控件中，宽度都调为0dp，设置比重，第一个button为1 ，第二个为3  ，所以，怎个上面的控件，第一个占1/4
第二个占3/4。
如果不设置比重那么width就不能设置成0
如果你只给其中一个设置比重比如像下面
```xml
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"  
    xmlns:tools="http://schemas.android.com/tools"  
    android:layout_width="match_parent"  
    android:layout_height="match_parent"  
    android:gravity="bottom|center_horizontal" >  
  
    <Button  
        android:id="@+id/button_1"  
        android:layout_width="0dp"  
        android:layout_height="wrap_content"  
        android:layout_weight="1"  
        android:text="left" />  
  
    <Button  
        android:id="@+id/button_2"  
        android:layout_width="wrap_content"  
        android:layout_height="wrap_content"  
        android:text="right" />  
  
</LinearLayout>  

```
目前我测试的是：横着的时候默认3：1；竖着的时候默认10：1
有的时候当RecyclerView和Edit在一起的时候 使用weight时要注意，比如
```xml
<LinearLayout
    xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:orientation="vertical"
    android:background="#6ecfd12e"
    tools:context="com.example.myapplication.MainActivity">

    <android.support.v7.widget.RecyclerView
        android:id="@+id/recycler_view"
        android:layout_width="match_parent"
        android:layout_height="0dp"
        android:layout_weight="1"></android.support.v7.widget.RecyclerView>

    <LinearLayout
        android:layout_width="match_parent"
        android:layout_height="wrap_content">

        <EditText
            android:id="@+id/input_text"
            android:layout_width="match_parent"
            android:layout_height="wrap_content"
            android:layout_weight="1"
            android:hint="Type something here"
            android:maxLines="2" />

        <Button
            android:id="@+id/send"
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:text="Send" />

    </LinearLayout>


</LinearLayout>
```
这里面的与recyclerview在同一层的LinearLayout的height属性必须时wrap_cotent  最好不要设置成比重，不然当软键盘弹出来的时候就会把EditView挡住

3.ellipsize
设定当文本内容超过控件的宽度时，文本的缩略方式
```xml
android:ellipsize="end"
```
这里是在尾部进行缩略，
还有start，在首部缩略。middle在中间缩略。
