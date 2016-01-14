#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "hashtbl.h"

int hashfunc(uint32_t id) {
  return ((uint32_t)id)%NHASH;
}
void
HashTblConstruct(HashTbl *h) 
{
  memset(h->fh, 0, sizeof(h->fh));
}
struct HashTblItem *
HashTblInsert(HashTbl *h, int id) 
{
  struct HashTblItem  *fp1 = 0, *fp = 0 ;
  int     idx = hashfunc(id) ;
  int existed = 0;

  for (fp = h->fh[idx]; fp != NULL; fp = fp->f_next) {
    if (fp->f_id == id) {
      existed = 1;
      free(fp1);
      break;
    }
  }

  if (!existed) {
    if ((fp1 = (struct HashTblItem *)malloc(sizeof(struct HashTblItem))) != NULL) {
      fp1->f_next = h->fh[idx];
      h->fh[idx] = fp1 ;
      fp1->f_id = idx;
    }
  }
  return (fp);
}


struct HashTblItem *
HashTblFind(HashTbl *h, int id) 
{
  struct HashTblItem  *fp = 0;
  int     idx;
  idx = hashfunc(id);

  for (fp = h->fh[idx]; fp != NULL; fp = fp->f_next) {
    if (fp->f_id == id) {
      printf("%d", fp->f_id);
      break;
    }
  }

  return (fp);
}

void
HashTblTranverse(HashTbl *h) 
{
  int     idx;
  struct HashTblItem*fp, *fq;
  int i = 0;

  for (; i < NHASH; ++i) {

    for (fp = h->fh[i]; fp; fp = fp ->f_next) {
      printf("finded: %d\n", fp->f_id);
    }
  }
}
void
HashTblRele(HashTbl *h) 
{
  int     idx;
  struct HashTblItem*fp, *fq;
  int i = 0;

  for (; i < NHASH; ++i) {

    for (fp = h->fh[i]; fp; fp = fq) {
      fq = fp->f_next;
      free(fp);
    }
  }
}
