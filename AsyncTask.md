# 多线程——使用AsyncTask
***
AsyncTask是一个封装好的工具，用来在多线程中对UI进行操作

AsyncTask是一个抽象类，在继承他的时候需要指定三个泛型参数
* Params 执行是传入的
* Progress 显示进度用的
* Result 返回结果

有三个方法，因为是抽象类，所以要想调用必须要重写，在通过子类来调用
* onPreExecute()    
      这个方法是在后台任务执行之前调用，对界面进行初始化
* doInBackground( Params ... )
      这个参数后面这三个点表示他可以加入多个参数。这个方法自动在子线程中运行，最后加一个return,就成的第三个参数Request了，后面的方法可能会调用，但是泛型参数如果定的是void型就可以不用写return。注意这个方法不能用于UI操作
* onProgressUpdate( Progress ...)
      当后台调动了publishProgress之后这个方法就接着自己调用了，(publishProgress()用来通知下载进度的) ，就如其名对UI和进程进行更新
* onPostExecute( Result )
      上面的doInBackground()执行完了过后就会执行这个方法，并且doInBackground()返回的值也作为参数传入到这个方法中，然后进行一些UI操作
