# Android-Notes

1.首先要导包
2.在布局文件中加入RecycleView控件
和其他控件一样，id，width,height
```xml
<android.support.v7.app.AlertController.RecycleListView
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
    </android.support.v7.app.AlertController.RecycleListView>
```
这里的宽和高必须写成match_paper如果写wrap_content，写出来的RecycleView就划不动
3.创建一个你要展示的类
```java
public class Person{
...
}
```
4.创建一个该类的适配器
重新创建一个 Java class 让他继承自RecyclerView.Adapter< PersonAdapter.ViewHolder >(尖括号的东西需要自己补充)
适配器就是可以将不同的图片和数据 放到我们的View里面，起到一个桥梁的作用
```java
public class PersonAdapter extends RecyclerView.Adapter< PersonAdapter.ViewHolder >  {
    private List< Person > PersonList ;

    static class ViewHolder extends RecyclerView.ViewHolder{
        ImageView personImage ;
        TextView personName ;
        public ViewHolder ( View view ) {
            super( view ) ;
            personImage = ( ImageView ) view.findViewById( R.id.person_image ) ;
            personName = ( TextView ) view.findViewById( R.id.person_name ) ;
        }
    }

    public PersonAdapter ( List< Person > personList ) {
        PersonList = personList ;
    }

    @Override
    public ViewHolder onCreateViewHolder ( ViewGroup parent , int viewType ) {
        View view = LayoutInflater.from( parent.getContext() ).inflate( R.layout.recycle_view , parent , false ) ;
        //先用from方法找到他的布局，再通过inflate方法把RecycleView加入到布局当中 
        ViewHolder holder = new ViewHolder( view ) ;
        return holder ;
    }

    @Override
    public void onBindViewHolder ( ViewHolder holder , int position ) {
        Person person = PersonList.get( position ) ;
        holder.personName.setText( person.getName() ) ;
        holder.personImage.setImageResource( person.getImageId() ) ;
        //把内容输入到RecyclerView 
    }

    @Override
    public int getItemCount ( ) {
        return PersonList.size() ;
    }
    //这个方法用来告诉RecyclerView有多少个数据
}
```
5.修改MainActivity中的代码
```java
public class MainActivity extends AppCompatActivity {

    private List< Person > personList = new ArrayList<> ( ) ;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        initPerson( ) ;
        RecyclerView recyclerView = ( RecyclerView ) findViewById( R.id.recycle_view ) ;

        StaggeredGridLayoutManager layoutManager = new StaggeredGridLayoutManager( 3 , StaggeredGridLayoutManager.VERTICAL ) ;//设置他的形式，可以有横向，纵向以及瀑布流的布局，第一个参数是其列数，第二个是排列的方向。
        recyclerView.setLayoutManager( layoutManager );
        PersonAdapter adapter = new PersonAdapter( personList ) ;
        recyclerView.setAdapter( adapter );
    }

    private void initPerson () {
        for ( int i = 0 ; i < 2 ; i ++ ) {//循环保证View的长度
            Person person1 = new Person(getRandomLengthName( "王天锐" ), R.drawable.img_2 );
            personList.add(person1);
            Person person2 = new Person(getRandomLengthName( "陈智彬" ), R.drawable.img_2 );
            personList.add(person2);
            Person person3 = new Person(getRandomLengthName( "和的亲"  ), R.drawable.img_2 );
            personList.add(person3);
            Person person4 = new Person(getRandomLengthName( "正好" ), R.drawable.img_2 );
            personList.add(person4);
            Person person5 = new Person(getRandomLengthName( "着离职" ), R.drawable.img_2 );
            personList.add(person5);
            Person person6 = new Person(getRandomLengthName( "蒋昱葳" ), R.drawable.img_2 );
            personList.add(person6);
            Person person7 = new Person(getRandomLengthName( "屌大音符" ), R.drawable.img_2 );
            personList.add(person7);
            Person person8 = new Person(getRandomLengthName( "奥特曼" ), R.drawable.img_2 );
            personList.add(person8);
        }
    }
    private String getRandomLengthName ( String name ) {
        Random random = new Random( ) ;
        int length = random.nextInt( 20 ) + 1 ;
        StringBuilder builder = new StringBuilder( ) ;
        for ( int i = 0 ; i < length ; i++ ) {
            builder.append ( name ) ;
        }
        return builder.toString() ;
    }//这个方法用于重复名字以达到瀑布流的效果
}
```
6.再RecyclerView中添加点击事件
思考，因为是要给每一项都设置事件监听器，也只有再适配器中能够操作，所以再Adapter类中的ViewHolder内部类的onCreateViewHolder方法添加以下代码
```java
final ViewHolder holder = new ViewHoler ( View ) ; 
holder.fruitView.setOnClickListener ( new View.OnClickListener ) {
   @Override
   public void onClick ( View v ) {
   int position = holder.getAdapterPosition( ) ;
   Person person = mPersonList.get( position ) ;//获得相应的那一个person的实例
   Toast.makeText ( v.getContext , "you click " + person.getName() ; Toast.LENGTH_SHORT ).show() ;
   ...
   }
}
```
