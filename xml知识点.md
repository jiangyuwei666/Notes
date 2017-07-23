1.weight比重的使用
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
