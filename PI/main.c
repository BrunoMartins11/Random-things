typedef struct lligada {
int valor;
struct lligada *prox;
} *LInt;


//1 certo
int length (LInt l){
    int r=0;
    if(l==NULL) return r;
    while (l!=NULL){
        r++;
        l=l->prox;
    }
    return r;
}
//2 certo
void freeL (LInt l){
	while(l!=NULL){
		free (l);
		l=l->prox;
	}
}
//3 certo
void imprimeL (LInt l){
	while(l!=NULL){
		printf("%d\n",l->valor);
		l=l->prox;

	}
}
//4 certa pinto
LInt reverseL (LInt l){
    LInt aux;
    LInt prev = NULL;
    LInt freed;

    while(l != NULL ) {

        aux = newLInt(l->valor, prev); //cria uma lista que aponta para a lista anterior
        prev = aux; //regista a nova lista anterior

        freed = l; //regista a lista que entra em desuso
        l = l->prox; //avança na lista inicial
        free(freed); //librta a memória desnecessária
    }

    return aux;

}



//5 certa
	void insertOrd (LInt *l, int x){
    LInt ant=NULL, nova, r=*l, aux=*l;
    while (aux!=NULL && x>aux->valor){
        ant=aux;
        aux=aux->prox;
    }
    nova=malloc(sizeof(struct lligada));
    nova->valor=x;
    nova->prox=aux;
    if (ant==NULL) r=nova;
     else ant->prox=nova;
     *l=r;
}
//6
int removeOneOrd (LInt *l, int x){
    LInt r, ant;
    ant=r;
    while(r!=NULL && r->valor<x){
        ant=r;
        r=r->prox;
    }
    if (r==NULL) return 1;
    else {ant->prox=r->prox; free(r);}
    return 0;
}


//8
void merge (LInt *r, LInt l1, LInt l2){
    LInt l=*r;
    while(l1!=NULL && l2!=NULL){
        if((l1->valor)>(l2->valor)) {l=malloc(sizeof(struct lligada));l->valor=l1->valor;l1=l1->prox;l=l->prox;}
               else  {l=malloc(sizeof(struct lligada));l->valor=l2->valor;l2=l2->prox;l=l->prox;}
}
    if (l1==NULL && l2==NULL) l==NULL;
       else if (l1==NULL) {l=malloc(sizeof(struct lligada));l=l2;}
            else {l=malloc(sizeof(struct lligada));l=l1;}
            
}
            
//9
LInt parteAmeio (LInt *l){
    int r=0, i=0; LInt n=*l, t=*l;
    if (n==NULL) return *l;
    while (n!=NULL){
        n=n->prox;
        i++;
    }
    r=i/2;
    i=0;
    while (i<=r){
        t=t->prox;
        i++;
    }
    *l=t->prox;
    t->prox=NULL;
    t=t->prox;
    
    return t;
}
//10 certo
int removeAll (LInt *el, int x){
    int i=0; LInt r, ant, l=*el; r=*el; ant=NULL;
    if (r==NULL) return 0;
    
    while (r!=NULL){
        if(r->valor==x && ant==NULL) {l=r->prox;r=r->prox;i++;}
          else {if (r->valor==x) {ant->prox=r->prox;i++;r=r->prox;}
                else {ant=r; r=r->prox;}
          }
    }
    *el=l;
    return i;
}
//13 certo
void init (LInt *l){
    LInt ant, v=*l; ant=NULL;
    while(v->prox!=NULL){
        ant=v;
        v=v->prox;
        
    }
    if (ant==NULL) v=NULL;
    if (v!=NULL)  {ant->prox=NULL; free(v);}
    if (v==NULL) return;
    
    
    
}
//14  certo
void appendL (LInt *l, int x){
    LInt aux, nova; aux=*l; 
    if (aux==NULL) {aux=malloc (sizeof (struct lligada)); aux->valor=x; aux->prox=NULL;}
    else{while(aux->prox!=NULL){
        aux=aux->prox;
    }
    aux->prox=nova;
    nova=malloc (sizeof (struct lligada));
     nova->valor=x; nova->prox=NULL;
}
    
}

//15 certo
void concatL (LInt *a, LInt b){
    LInt r=*a;
    if (r==NULL) *a=b;
    else{while(r->prox!=NULL)
    r=r->prox;
    r->prox=b;
    
    }
    ;
}

//18 certo
int maximo (LInt l){
    int x=l->valor;
    while(l!=NULL){
        if (x>l->valor) l=l->prox;
         else {x=l->valor; l=l->prox;}
    }
    return x;
}
//19 6 certos
int take (int n, LInt *l){
    LInt v, ant; 
    int i=0;
    ant=*l; v=*l;
    while(n>0){
        if (v==NULL) return i;
        else {v=v->prox;i++;n--;}
    }
    while(v!=NULL){
        v=v->prox; free(ant);
    }
    return i;
}
//20 certo
int drop (int n, LInt *l){
    LInt v, ant; int i=0;v=ant=*l;
    while(v!=NULL && n>0){
        ant=v;
        v=v->prox; free(ant);
        i++;
        n--;
        
    }
    *l=v;
    return i;
    
}
//21 certo
LInt NForward (LInt l, int N){
    while (N!=0){
    l=l->prox;
    N--;
    }
    return l;
}
//22 certo
int listToArray (LInt l, int v[], int N){
    int i=0; v[N];
    while (l!=NULL  && i<N){
        v[i]=l->valor;
        l=l->prox;
        i++;
        
    }
    return i;
}
//23 certo
LInt arrayToList (int v[], int N){
    LInt l , r , nova , ant;
    int i = 0;
    l = malloc (sizeof (struct lligada));
    r = l;
    if (N==0) return NULL;
    while ( N>0) {
        nova = malloc (sizeof (struct lligada));
        l->valor = v[i];
        l->prox = nova;
        ant = l;
        l = nova;
        N--;
        i++;
    }
    ant->prox = NULL;
    return r;
}
//24 mal
LInt somasAcL (LInt l) {
    LInt in=l, ant;
    if (l==NULL || l->prox==NULL) return l;
       else {ant=l;
    l=l->prox;
    while (l!=NULL){
        l->valor=l->valor + ant->valor;
        ant=l;
        l=l->prox;
         }
       }
    return in;
}
//26 certo
LInt rotateL (LInt l){
    
    LInt aux = l;
    LInt r = l;
    LInt ant = NULL;
    
   
    
    if  (l == NULL) r = NULL;
    else {
        if (l->prox == NULL) return r;
        else {
            r = r->prox;
            l = l->prox;
            aux->prox = NULL;
            
            
            while ( l != NULL) {
                ant = l;
                l = l->prox;
            }
            ant->prox = aux;
        }
    }
    
   
    
    
    return r;
}


// ARVORES BINARIAS




//28 certo
int max(int x,int y){
    if (x<y) return y;
     else return x;
}

int altura (ABin a){
    int r=0;
    if (a==NULL) r=0;
     else r=1+max(altura(a->esq),altura(a->dir));
	return r;
}

//29 certo
ABin cloneAB (ABin a) {
    ABin b;
    if (a==NULL) b=NULL;
     else { b=malloc(sizeof(struct nodo)); b->valor=a->valor; b->esq=cloneAB(a->esq); b->dir=cloneAB(a->dir);}
    return b;
}
//30 certo
void mirror (ABin *a) {
    ABin r=*a, temp=r;
    if (r==NULL) ;
    else {mirror(&r->dir); mirror(&r->esq);temp=r->dir;r->dir=r->esq; r->esq=temp;} 
}
//31 seg fault
 

//32 mal
int depth (ABin a, int x) {
    int i=1;
    if (a == NULL) return 0;
    if (a->valor==x) return i;
    else i=1+depth(a->esq,x)+depth(a->dir,x);
    return -1;
}

//34 mal
int depth (ABin a, int x) {
    int i=1;
     if (a->esq==NULL && a->dir==NULL) return -1;
else if (a->dir==NULL) {depth(a->esq,x);i++;}
 else if (a->esq==NULL) {depth(a->dir,x);i++;}
    else if (a->valor==x) {i++;return i;}
       else { i++;depth(a->esq,x);depth(a->dir,x);}
   
   
  
}

//35 certo
int freeAB (ABin a) {
    int r=0;
    if (a!=NULL){
        
        r=1+freeAB(a->esq)+freeAB(a->dir);
        free(a);
        
    }
   
    return r;
}
//37 certa!!!!
int iguaisAB (ABin a, ABin b) {
    if(a==NULL && b==NULL) return 1;
    if (a!=NULL && b!=NULL) return (a->valor==b->valor&&iguaisAB(a->esq,b->esq)&&iguaisAB(a->dir,b->dir));
 return 0;
}
//39 certa
int nivelV (ABin a, int n, int v[]) {
    int i=0;
    if (a == NULL)
        return 0;

    if ( n == 1) {
        v[i] = a->valor; 
        return 1;
    }
    else {
        i = nivelV(a->esq, n - 1, v);
        return i + nivelV(a->dir, n - 1, v+i);
    }
}



//42 certa
int contaFolhas (ABin a) {
    int r = 0;
    if ( a == NULL) r = 0;
    else {
        if (a->dir == NULL && a->esq == NULL) r++;
        else r = contaFolhas(a->dir) + contaFolhas(a->esq);
    }
    return r;
}
//43 certa
ABin cloneMirror (ABin a) {
    ABin r;
    if ( a == NULL) r = NULL;
    else {
        r = malloc(sizeof(struct nodo));
        r->valor = a->valor;
        r->esq = cloneMirror(a->dir);
        r->dir = cloneMirror(a->esq);
    }
    return r;
}
//45 certa
int lookupAB (ABin a, int x) {
    int r=0;
    if (a==NULL || x!=a->valor) return 0;
      else if (a->valor==x) return 1;
          else if (a->valor<x) r=lookupAB(a->dir,x);
              else r=lookupAB(a->esq,x);
    
    return r;
}

//46 certa
int depthOrd (ABin a, int x) {
    int r=1;
    while(a!=NULL){
        if (a->valor==x) return r;
         else if (a->valor<x) {a=a->dir,r++;}
            else {a=a->esq; r++;}
    }
    if (a==NULL)
    return -1;
}

//47 certa
int maiorAB (ABin a) {
    int r;
    while(a!=NULL){
         r=a->valor;
         a=a->dir;
         
     }
     return r;
}
//49 certa
int quantosMaiores (ABin a, int x) {

    if ( a == NULL)
        return 0;
    else if ( a->valor <= x)
        return quantosMaiores(a->dir, x);
    else
        return 1 + quantosMaiores(a->dir, x) + quantosMaiores(a->esq, x);
}

