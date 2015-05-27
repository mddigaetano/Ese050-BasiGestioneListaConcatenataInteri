#include <stdio.h>
#include <stdlib.h>

typedef struct s_elemento{
    int v;
    struct s_elemento* next;
}elemento;

elemento* aggiungiElementoTesta(elemento*);
void StampaLista(elemento*);
void SvuotaLista(elemento*);

int main(int argc, char** argv) {
    elemento* primo=NULL;
    char ctrl[2]="s";
    
    while(strcmp(ctrl,"n")){
        primo=aggiungiElementoTesta(primo);
        if(primo==NULL){
            fprintf(stderr,"Errore nell'aggiunta di un elemento");
            exit(1);
        }
        printf("Vuoi aggiungere altri elementi alla lista? (s/n): ");
        scanf("%s",ctrl);
        printf("\n");
    }
    
    StampaLista(primo);
    
    SvuotaLista(primo);
    

    return (EXIT_SUCCESS);
}

elemento* aggiungiElementoTesta(elemento* testa){
   elemento* temp=NULL;
   temp=(elemento*)malloc(sizeof(elemento));
   
   if(temp==NULL){
        fprintf(stderr,"Errore aggiunta elemento");
        return NULL;
   }
   
   printf("Inserisci il valore: ");
   scanf("%d",&(temp->v));   
   temp->next=testa;
   testa=temp;
   
   return testa;
}

void StampaLista(elemento* testa){
    int i=1;
    elemento* temp;
    
    while(testa){
        printf("%d° valore: %d\n",i,testa->v);        
        testa=testa->next;        
        i++;
    }
}

void SvuotaLista(elemento* testa){
    elemento* temp=NULL;
    
    while(testa){
        temp=testa->next;
        free(testa);
        testa=temp;
    }
}