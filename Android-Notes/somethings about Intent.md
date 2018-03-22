# Intent
---
Intent 译为 意图，目的；用来协助应用与应用，应用与活动，活动与活动之间的交互。包括对活动服务广播等的使用。
### 使用Intent调用文件管理器
我们可以通过对一个button设置点击事件来达到调用的目的,在注册点击事件的代码里写
```java
Intent intent = new Intent ( Intent.ACTION_GET_CONTENT );
intent.setType("*/*");//全部的后缀，所有的文件格式都支持
startActivityForResult ( intent , 1 );
```
ACTION_GET_CONTENT参数，允许用户选择特殊种类的数据，并返回

</br>还可以指定文件类型
```java
intent.setType("image/*");//选择图片
intent.setType("video/*");//选择视频
intent.setType("audio/*");//选择音频
intent.setType("image/*;video/*");//同时选择视频和图片
```
然后重写回调方法onActivityResult
```java
@Override
protected void onActivityResult(int requestCode, int resultCode, Intent data) {
    super.onActivityResult(requestCode, resultCode, data);
    Uri uri = data.getData() ;
    if ( "file".equalsIgnoreCase( uri.getScheme() )) {
        path = uri.getPath() ;
        textView.setText( path );
        Toast.makeText( this , "succeed" , Toast.LENGTH_SHORT ).show();
    }
    if (Build.VERSION.SDK_INT > Build.VERSION_CODES.KITKAT) {
        path = uri.getPath() ;
        textView.setText( path );
        Toast.makeText( this , "succeed2" , Toast.LENGTH_SHORT ).show();
    }
    else {
        path = getRealPathFromURI( uri ) ;//小于4.4系统的方法
        textView.setText( path ) ;
        Toast.makeText( this, "succeed3" ,Toast.LENGTH_SHORT) .show();
    }
```
这个方法用于响应选择完后的操作
</br>下面是小于4.4所调用的方法
```java
//cursor译为光标
public String getRealPathFromURI (Uri contentUri){
    String res = null ;
    String[] proj = {MediaStore.Images.Media.DATA} ;
    Cursor cursor = getContentResolver().query( contentUri , proj ,null , null,null ) ;
    if ( null != cursor&&cursor.moveToFirst()) {
        int index = cursor.getColumnIndexOrThrow(MediaStore.Images.Media.DATA) ;
        res = cursor.getString(index) ;
    }
    return res ;
}
```
