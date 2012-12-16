#include<iostream>
#define MAX 100
using namespace std;

struct tklijent{
       int vrijeme_izmedju,vrijeme_obrade,prioritet,tip_transakcije,rbroj;
       char ime[20],prezime[30];
       short dan,mjesec,godina;
       int tekuci,devizni;
       };
       
struct tred{
       tklijent *elementi[MAX];
       int celo,zacelje;
       };
int AddOne(int index){
         return((index+1)%MAX);     
         }//vrti indekse 
               
bool IsEmptyQ(tred *red){
    if(AddOne(red->zacelje)==red->celo) return true;
    else return false;
}   

void InitQ(tred *red){      
     red->celo=0;
     red->zacelje=MAX-1;
     }

tklijent* FrontQ(tred *red){   
         return red->elementi[red->celo];
         }//red
        
void EnQueueQ(tklijent *klijent,tred *red){
     if(AddOne(AddOne(red->zacelje))==red->celo) cout<<"Red je pun !!! \n";
     else{
          red->zacelje=AddOne(red->zacelje);
          red->elementi[red->zacelje]=klijent;

          }//else
     }//dodaj na kraj reda
     
void DeQueue(tred *red){
      red->celo=AddOne(red->celo);
     }//brise element s cela reda
