# 在RecyclerView中scroll
scroll是用来控制RecyclerView滑动的。

在最近遇到了这样的一个情况

做了一个像某团外卖的两个RecyclerView,前面的是种类，后面的是具体的物品类，像这样。

![图片举例]()

在处理到监听点击左边的item处理右边的RecyclerView的滑动的时候，发现，不管是```smoothScrollToPosition()```方法还是```ScrollToPosition()```方法，还有一个方法是```scrollBy()```，这是通过自己控制移动的距离。它们处理的机制都是，当某一个位置的出现在界面上就停止了。比如从上面的水果类切换到蔬菜类的时候，它只会将蔬菜类的第一个显示在最下面。

但是这样并不是我们想要的效果，比如我们选择了素菜类，就想把蔬菜类从第一个开始置顶在界面上，而不是放在底部。

这里就要换一个思路，我们要显示的项在当前界面的前面？后面？还是在界面上，却没有在最上面。

这是写在左侧RecyclerView的Item点击事件里的逻辑
```java
int first = mLinearLayoutManager.findFirstVisibleItemPosition() ;
int last = mLinearLayoutManager.findLastVisibleItemPosition();
if ( titlePois.get(position) <= first ){
    goodsRecyclerView.smoothScrollToPosition( titlePois.get(position) );
}
else if ( titlePois.get(position) <= last ){
    int top = goodsRecyclerView.getChildAt(titlePois.get(position)-first).getTop();
    goodsRecyclerView.scrollBy( 0 , top );
}
else {
    goodsRecyclerView.smoothScrollToPosition( titlePois.get(position) + last - first );
}
```

titlePois是当前点击的item的第几个。

我们先获取到当前界面的第一个和最后一个的position

首先判定，当我们想要显示的项在目前界面的前面时，那就可以直接滚动，当到显示出来的时候刚好就是第一项。

如果不是的话，再看他是否在当前页面上？如果在的话就先计算出他到最上面差了多少，再用```scrollBy()```方法来让他跑到最上面。

如果不在当前页面上，也就是在当前界面的下方，那么它必然会向下滑动直到那一项显示出来。这样也就是说直接调用上面说的两种方法的话它必然会显示在最下方。那我们要做的就是然他再多移动当前界面显示的几格就行了，也就是多移动```last-first```。