# Android-Notes

1.首先要导包
2.在布局文件中加入RecycleView控件
和其他控件一样，id，width,height
```xml
<android.support.v7.app.AlertController.RecycleListView
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:id="@+id/recycle_view">
    </android.support.v7.app.AlertController.RecycleListView>
```
3.创建一个你要展示的类
```java
public class Person{
...
}
```
4.创建一个该类的适配器
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
        ViewHolder holder = new ViewHolder( view ) ;
        return holder ;
    }

    @Override
    public void onBindViewHolder ( ViewHolder holder , int position ) {
        Person person = PersonList.get( position ) ;
        holder.personName.setText( person.getName() ) ;
        holder.personImage.setImageResource( person.getImageId() ) ;
    }

    @Override
    public int getItemCount ( ) {
        return PersonList.size() ;
    }
}
```
