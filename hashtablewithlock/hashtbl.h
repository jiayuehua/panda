#ifndef HASHTBL_H
#define HASHTBL_H
enum{
  NHASH = 5,
};

struct HashTblItem {
  struct HashTblItem     *f_next; 
  int             f_id;

};
struct sHashTbl {
  struct HashTblItem *fh[NHASH];
};
typedef struct sHashTbl HashTbl;

void
HashTblConstruct(HashTbl *h) ;
struct HashTblItem *
HashTblInsert(HashTbl *h, int id) ;
struct HashTblItem *
HashTblFind(HashTbl *h, int id) ;
void
HashTblTranverse(HashTbl *h) ;
void
HashTblRele(HashTbl *h) ;

#endif
