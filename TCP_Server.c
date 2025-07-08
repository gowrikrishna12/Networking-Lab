#include&lt;stdio.h&gt;
int main(){
    int incoming, outgoing, buck_size, n, store = 0;
    printf(&quot;Enter bucket size, outgoing rate and no of inputs : &quot;);
    scanf(&quot;%d %d %d&quot;, &amp;buck_size, &amp;outgoing, &amp;n);
    while (n != 0) {
        printf(&quot;Enter the incoming packet size : &quot;);
        scanf(&quot;%d&quot;, &amp;incoming);
        printf(&quot;Incoming packet size %d\n&quot;, incoming);
        if (incoming &lt;= (buck_size - store)){
            store += incoming;
            printf(&quot;Bucket buffer size :  %d out of %d\n&quot;, store, buck_size);
        } else {
            printf(&quot;Dropped %d no of packets\n&quot;, incoming - (buck_size - store));
           
            store = buck_size;
            printf(&quot;Bucket buffer size :  %d out of %d\n&quot;, store, buck_size);
        }
       
        if(store&gt;=outgoing){
        store=outgoing-store;
        }
       
        if(store&lt;0){
        store=store*(-1);
        }
        printf(&quot;After outgoing ,  There are %d  out of %d packets left in buffer\n&quot;, store, buck_size);
        n--;
    }
}}
