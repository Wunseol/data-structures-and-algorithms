#include "self_test.h"
#include "../src/queue/circular_queue/08_circular_queue.h"

int main(void) {
    TEST_BEGIN("Circular Queue");

    SqQueue Q;
    QElemType e;

    InitQueue(&Q);
    ASSERT_TRUE(QueueEmpty(&Q));
    ASSERT_FALSE(QueueFull(&Q));
    ASSERT_EQ(QueueLength(&Q), 0);

    ASSERT_TRUE(EnQueue(&Q, 10));
    ASSERT_TRUE(EnQueue(&Q, 20));
    ASSERT_TRUE(EnQueue(&Q, 30));
    ASSERT_FALSE(QueueEmpty(&Q));
    ASSERT_EQ(QueueLength(&Q), 3);

    ASSERT_TRUE(GetHead(&Q, &e));
    ASSERT_EQ(e, 10);

    ASSERT_TRUE(DeQueue(&Q, &e));
    ASSERT_EQ(e, 10);
    ASSERT_EQ(QueueLength(&Q), 2);

    ASSERT_TRUE(DeQueue(&Q, &e));
    ASSERT_EQ(e, 20);
    ASSERT_TRUE(DeQueue(&Q, &e));
    ASSERT_EQ(e, 30);
    ASSERT_TRUE(QueueEmpty(&Q));
    ASSERT_EQ(QueueLength(&Q), 0);

    ASSERT_FALSE(DeQueue(&Q, &e));

    InitQueue(&Q);
    for (int i = 1; i <= MAXSIZE - 1; i++) {
        ASSERT_TRUE(EnQueue(&Q, i));
    }
    ASSERT_TRUE(QueueFull(&Q));
    ASSERT_EQ(QueueLength(&Q), MAXSIZE - 1);
    ASSERT_FALSE(EnQueue(&Q, 999));

    ASSERT_TRUE(DeQueue(&Q, &e));
    ASSERT_EQ(e, 1);
    ASSERT_TRUE(EnQueue(&Q, 100));
    ASSERT_TRUE(QueueFull(&Q));

    ASSERT_TRUE(DeQueue(&Q, &e));
    ASSERT_EQ(e, 2);
    ASSERT_TRUE(EnQueue(&Q, 200));
    ASSERT_TRUE(QueueFull(&Q));

    ASSERT_TRUE(DeQueue(&Q, &e));
    ASSERT_EQ(e, 3);
    ASSERT_TRUE(DeQueue(&Q, &e));
    ASSERT_EQ(e, 4);
    ASSERT_TRUE(EnQueue(&Q, 300));
    ASSERT_TRUE(EnQueue(&Q, 400));
    ASSERT_TRUE(QueueFull(&Q));

    TEST_END();
}
