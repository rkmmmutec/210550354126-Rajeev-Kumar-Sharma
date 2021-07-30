#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>    /* For O_* constants */
#include <sys/stat.h> /* For mode constants */
#include <mqueue.h>
#include <string.h>

#define SIZE 15
mqd_t dictmq;
struct mq_attr dictmq_attr;


char ch[10];

int main()
{
    dictmq_attr.mq_flags = 0;
    dictmq_attr.mq_maxmsg = 4;
    dictmq_attr.mq_msgsize = 128;
    dictmq_attr.mq_curmsgs = 0;

    dictmq = mq_open("/word", O_RDONLY | S_IRUSR | S_IWUSR, &dictmq_attr);

    int *p=fopen("word.txt","r");
    if(p==NULL)
    {
     perror("Error in opening file :\n");
     exit(1);
    }

    while(1)
    {
      if(ch != EOF)
      {

      fscanf(p,%s,ch); //reading from file


    //  ch = fgetc(p); /* read from file*/
      if(strcmp(ch,'m')==0)  //comparing first word of buffer with word "m"
      mq_send(dictmq, "ch",SIZE, 0);  // sending the buffer word start with word ch

      break;
      }
    }


    mq_close(dictmq);
    return 0;
}
