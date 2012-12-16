#include<iostream>
#define MAX 100

struct tklijent{
       int vrijeme_izmedju,vrijeme_obrade,prioritet,tip_transakcije,rbroj;
       char ime[20],prezime[30];
       short dan,mjesec,godina;
       int tekuci,devizni;
       tklijent*sljedeci;
       };
       
struct tred {
    tklijent* front,*rear;
};
int AddOne(int n) {
    return((n+1)%MAX);
}
int InitQ(tred*red) {
    tklijent*glava=new tklijent;
    glava->sljedeci=NULL;
    red->front=glava;
    red->rear=glava;
}
bool IsEmptyQ(tred*red) {
    if(red->rear==red->front)return 1;
    return 0;
}
void EnQueueQ(tklijent*klijent,tred*red) {
    red->rear->sljedeci=klijent;
    klijent->sljedeci=NULL;
    red->rear=klijent;
}
tklijent*FrontQ(tred*red) {
    tklijent*klijent;
    klijent=red->front->sljedeci;
    return klijent;
}
void DeQueue(tred*red) {
    tklijent*glava=new tklijent;
    glava=red->front;
    red->front=glava->sljedeci;
    delete glava;
}
