#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>

#define SIZE 15
mqd_t dictmq;
struct mq_attr dictmq_attr;
char buff[128];
int msg_prio;


int main()
{
    dictmq_attr.mq_flags = 0;
    dictmq_attr.mq_maxmsg = 4;
    dictmq_attr.mq_msgsize = 128;
    dictmq_attr.mq_curmsgs = 0;

    dictmq = mq_open("/word", O_RDONLY | S_IRUSR | S_IWUSR, &dictmq_attr);

    while(1)
    {
      
    mq_receive(dictmq, buff, 128, &msg_prio);
    printf("Dictionary word: %s\n", buff);
    }
    mq_close(dictmq);
    return 0;
}
