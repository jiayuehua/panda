#include <stdlib.h>
#include <stdlib.h>
struct Node ;

struct Stats
{
  uint32_t  TimeUnit ;
  uint32_t 	TimeSeq ;
  uint32_t 	Packs ;
  uint32_t 	Bytes ;
  uint32_t 	Fragments ;
  uint32_t 	WLens ;
  uint32_t  WFlags;
  uint32_t  WSips ;

  uint32_t 	TcpInAcks ;
  uint32_t 	TcpInFins ;
  uint32_t 	TcpInPacks ;
  uint32_t 	TcpInRsts ;
  uint32_t 	TcpInSyns ;
  uint32_t 	TcpInbytes ;

  uint32_t 	TcpOutAcks ;
  uint32_t 	TcpOutFins ;
  uint32_t 	TcpOutPacks ;
  uint32_t 	TcpOutRsts ;
  uint32_t 	TcpOutSyns ;
  uint32_t 	TcpOutbytes ;


  uint32_t 	UdpInPacks ;
  uint32_t 	UdpInbytes ;

  uint32_t 	UdpOutPacks ;
  uint32_t 	UdpOutbytes ;


  uint32_t 	IcmpInPacks ;
  uint32_t 	IcmpInbytes ;

  uint32_t 	IcmpOutPacks ;
  uint32_t 	IcmpOutbytes ;


  uint32_t 	IgmpInPacks ;
  uint32_t 	IgmpInbytes ;

  uint32_t 	IgmpOutPacks ;
  uint32_t 	IgmpOutbytes ;

  uint32_t 	HttpInGet ;
  uint32_t  HttpInPost ;
  uint32_t  HttpInPut ;
  uint32_t  HttpInHead ;
  uint32_t  HttpInRes ;

  uint32_t 	HttpOutGet ;
  uint32_t  HttpOutPost ;
  uint32_t  HttpOutPut ;
  uint32_t  HttpOutHead ;
  uint32_t  HttpOutRes ;

  uint32_t 	HttpInGetBytes;
  uint32_t  HttpInPostBytes;
  uint32_t  HttpInPutBytes;
  uint32_t  HttpInHeadBytes;
  uint32_t  HttpInResBytes;

  uint32_t 	HttpOutGetBytes;
  uint32_t  HttpOutPostBytes;
  uint32_t  HttpOutPutBytes;
  uint32_t  HttpOutHeadBytes;
  uint32_t  HttpOutResBytes;
};
enum{NHASH =  9973;};

unsigned long HASH(int f_id)
{
  return (((unsigned long)f_id)%NHASH);
}

struct Node *fh[NHASH];
struct Node *fFreeHead = 0;
typedef void(Update*)(struct Node*);
struct Node {
  struct Node     *f_next; /* protected by hashlock */
  int             f_id;

  int             timestamp;
  int             morestuff;
  Stats           stats;
  /* ... more stuff here ... */
};

void Node_init()
{
  memset(fh, 0, NHASH);
}

void Node_traverse()
{

  {
    unsigned int i = 0;
    for (; i< NHASH; ++i)
    {
      struct Node*fp = fh[i] ;
      for (; fp; fp = fp->f_next)
      {
        printf("id %d", fp->f_id);
      }
    }
  }
}

void Node_free()
{
  unsigned int i = 0;
  struct Node* fq = 0;
  struct Node* fp = 0;
  for (; i< NHASH; ++i)
  {
    struct Node*fp = fh[i] ;
    for (; fp;fp=fq)
    {
      fq =  fp ->f_next ;
      free(fp);
    }
  }
}

void
Node_insert(int id) /* allocate the object */
{
  struct Node	*fp = 0;
  int			idx;

  idx = HASH(id);

  for (fp = fh[idx]; fp != NULL; fp = fp->f_next) {
    if (fp->f_id == id) {
      return;
    }
  }

  if ((fp = malloc(sizeof(struct Node))) != NULL) {
    fp->f_count = 0;
    fp->f_id = id;

    fp->released = 0;
    memset(&fp->stats, 0, sizeof(Node)- offsetof(fp,stats));


    fp->f_next = fh[idx];
    fh[idx] = fp;
  }
  return;
}

struct Node *
  Node_find(int id)
{
  struct Node	*fp = 0;
  int			idx;
  idx = HASH(id);
  for (fp = fh[idx]; fp ; fp = fp->f_next) {
    if (fp->f_id == id) {
      return fp;
    }
  }
  return 0;
}

int main()
{
  Node_init();
  Node_insert(120);
  Node_insert(110);
  Node_insert(1320);
  Node_insert(1240);
  Node_insert(1204);
  Node_insert(1220);
  Node_insert(1280);
  Node_insert(1210);
  Node_insert(1203);
  Node_insert(1201);
  Node_insert(1205);
  Node_insert(12340);
  Node_insert(12045);
  Node_insert(12033);
  Node_traverse();
  Node_free();
}
