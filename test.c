#include "exercise4.h"
#include <assert.h>
int main(){
    queue q;

    init_queue(&q);

    enqueue(&q,2);
    int y = dequeue(&q);

    assert(y==2);

    int x0 = 5;
    int x1 = 6;
    enqueue(&q, x0);
    enqueue(&q, x1);
    int y0 = dequeue(&q);
    int y1 = dequeue(&q);

    assert(x0 == y0);
    assert(y1==x1);
}