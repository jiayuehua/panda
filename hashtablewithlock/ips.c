#include <stdlib.h>
#include <pthread.h>
#include "detect.h"
struct Node ;

enum{NHASH =  9973;};

unsigned long HASH(int f_id)
{
  return (((unsigned long)f_id)%NHASH);
}

struct Node *fh[NHASH];
struct Node *fFreeHead = 0;
pthread_rwlock_t hashlock = PTHREAD_RWLOCK_INITIALIZER;
typedef void(Update*)(struct Node*);
struct Node {
  pthread_rwlock_t f_lock;
  struct Node     *f_next; /* protected by hashlock */
  int             released; /* hashlock */
  int             f_id;
  int             f_count; /* protected by f_lock */

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

  pthread_rwlock_rdlock(&hashlock);
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
  pthread_rwlock_unlock(&hashlock);
}


void
Node_insert(int id) /* allocate the object */
{
  struct Node	*fp = 0;
  int			idx;

  idx = HASH(id);
  pthread_rwlock_wrlock(&hashlock);

  for (fp = fh[idx]; fp != NULL; fp = fp->f_next) {
    if (fp->f_id == id) {
      pthread_rwlock_unlock(&hashlock);
      return;
    }
  }

  if ((fp = malloc(sizeof(struct Node))) != NULL) {
    fp->f_count = 0;
    fp->f_id = id;
    
    fp->released = 0;
    memset(&fp->stats, 0, sizeof(Node)- offsetof(fp,stats));
    
    if (pthread_rwlock_init(&fp->f_lock, NULL) != 0) {
      free(fp);
      return(-1);
    }

    fp->f_next = fh[idx];
    fh[idx] = fp;
  }
  pthread_rwlock_unlock(&hashlock);
  return(0);
}

void
Node_releRef(struct Node *fp) /* decrement a reference to the object */
{
  if (fp)
  {
    fp->f_count--;
    pthread_rwlock_unlock(&fp->f_lock);
  }
}

struct Node *
Node_find(int id) /* find a existing object */
{
  struct Node	*fp = 0;
  int			idx;

  idx = HASH(id);
  pthread_rwlock_rdlock(&hashlock);

  for (fp = fh[idx]; fp ; fp = fp->f_next) {
    if (fp->f_id == id&& !fp->released) {
      pthread_rwlock_wrlock(fp->f_lock)
      fp->f_count++;

      break;
    }
  }
  pthread_rwlock_unlock(&hashlock);
  return(fp);
}

void
Node_release(int id) 
{
  struct Node	*tfp;
  struct Node	*fp;
  int			idx;

  pthread_rwlock_wrlock(&hashlock);
  idx = HASH(id);
  tfp = fh[idx];
  if (tfp->f_id == id) {
    fh[idx] = tfp->f_next;
  } else {

    while (tfp->f_next ) {
      if (tfp->f_next->f_id == id) {
        fp = tfp->f_next;
        tfp->f_next = tfp->f_next->f_next;

        pthread_rwlock_unlock(&hashlock);
        fp->f_next = fFreeHead;
        fFreeHead = fp;
        return;
      } else {
        tfp = tfp->f_next;
      }
    }

    pthread_rwlock_unlock(&hashlock);
  }
}

void 
Node_free(void)
{
  struct Node* fp = fFreeHead;
  struct Node* fq = fFreeHead;
  for (fp )
  {
    if (fp->released
      && 0==pthread_rwlock_tryrdlock(&fp->f_lock)
      && fp->f_count == 0 )
    {
      if (fp == fFreeHead)
      {
        fFreeHead = fp->f_next;
        pthread_rwlock_unlock(&fp->f_lock);
        pthread_mutex_destroy(&fp->f_lock);
        free(fp);
        fp = fFreeHead;
        fq = fFreeHead;
      }
      else
      {
        fq->f_next = fp->f_next;
        pthread_rwlock_unlock(&fp->f_lock);
        pthread_mutex_destroy(&fp->f_lock);
        free(fp);
        fp = fq->f_next;
      }
    }
    else
    {
      fq = fp;
      fp = fp->f_next;
    }
  }
}


void
Node_erase(int id) /* erase the object */
{
  struct Node	*fp;
  int			idx;

  idx = HASH(id);
  pthread_rwlock_wrlock(&hashlock);

  for (fp = fh[idx]; fp != NULL; fp = fp->f_next) {
    if (fp->f_id == id) {

      fp->released = 1;
      break;
    }
  }
  pthread_rwlock_unlock(&hashlock);
}