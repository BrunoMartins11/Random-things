//1
int main()
{
	int i, soma=0;
	while (i!=0){
	scanf("%d",&i)
	soma+=i;
}
	printf("%d\n",soma );
	return 0;
}
//2
int main()
{
	int i, j=0;
	while (i!=0){
	scanf("%d",&i)
	if (i>j) j=i;

}
	printf("%d\n",j);
	return 0;
}
//3
int main()
{
	int i, j=0, soma=0, r=0;
	while (i!=0){
	scanf("%d",&i)
	j++;
	soma+=i;
	}
	r=soma/j;
	printf("%d\n",r);
	return 0;
}
//4
int main()
{
	int i, elem; int v[2];
	while (i!=0){
	scanf("%d",&i)
	if (i>v[0]) v[0]=i;
	if (v[1]<v[0]) {elem=v[1]; v[1]=v[0]; v[0]=elem;}

}
printf("%d\n",v[0] );
}
//5
int bitsUm (int n){
    int r=0;
    while(n!=0){
        if (n%2==1) {n=n/2;r++;}
         else n=n/2;
    }
    return r;
}
//6
int trailingZ (unsigned int n) {
    int r=0;
    while(n!=0){
        if (n%2==0) {n=n/2;r++;}
         else break;
         
    }
    return r;
}
//7
int qDig (int n) {
    int r = 0;
    while(n!=0){
        n=n/10; r++;
    }
    return r;
}
//8
int mystrlen(char str[]) {
 int i=0;
 while(str[i]!=0){
     i++;
 }
    
    return i;
}
//9
char *mystrcat(char s1[], char s2[]) {
    int i, j=0;
    for(i=0;s1[i]!=0;i++);
    for(j=0;s2[j]!=0;j++){
    s1[i]=s2[j]; i++; 
    }
    s1[i]=0;
    return s1;
}
//10
char *mystrcpy(char s1[], const char s2[]) {
    int i=0;
    while(s2[i]!=0){
        s1[i]=s2[i];
        i++;
    }
    s1[i]=0;
    return s1;
}
//11
int mystrcmp(char s1[], char s2[]) {
    int i=0;
    while(s1[i]!=0 && s2[i]!=0){
        if (s1[i]==s2[i]) i++;
          else if (s1[i]<s2[i]) return -1;
                  else return 1;
    }
    if (s1[i]==0 && s2[i]==0) return 0;
     else if (s1[i]==0) return -1;
               else return 1;
}
//12
char *mystrstr (char s1[], char s2[]) {
    // substituir por uma definicao valida
    
    int i = 0;
    int j ;
    int a ;
    if (s1[0] == '\0') return s1;
    while (s1[i] != '\0') {
        a=i;
        j = 0 ;
        while ((s2[j] == s1[a]) && (s2[j] != '\0')) {
            j++;
            a++;
        }
        if (s2[j] == '\0') return (s1+i);
        else i++;

    }
    
    
 
    return NULL;
}
//13
void strrev (char s[]) {
    char aux[1000];
    int i=strlen(s)-1, j=0;
    while(i=!-1){
        aux[j]=s[i];
        j++;
        i--;
    }
    aux[j]=0;
    i=0;
    while(aux[i]!=0){
    s[i]=aux[i];
    i++;
}}
//14
void strnoV (char t[]){
    int j=0, i=0;
    while(t[i]!=0){
        if((t[i] == 'a') || (t[i] == 'e') || (t[i] == 'i') || (t[i] == 'o') || (t[i] == 'u') ||
      (t[i] == 'A') || (t[i] == 'E') || (t[i] == 'I') || (t[i] == 'O') || (t[i] == 'U'))
       i++;
       else {t[j]=t[i]; i++; j++;}
    }
    t[j]=0;
}
//15
REFAZER
void truncW (char t[], int n){
    int i=0, j=0, c=0;
    while (t[i]!=0){
        if(t[i]!=' '&& c<n) {t[j]=t[i];i++;j++;}
          else if (t[i]==' ') {c=0;j++;}
             else while(t[i]!=' ' && t[i]!=0){
                 i++;
             }
        if(t[i]==0) break;  
        j++;
    }
    t[j]=0;
}

//16
int conta(char s[], char x){
    int i=0, r=0;
    while (s[i]!=0){
        if (s[i]==x) {r++;i++;}
        else i++;
    }
    return r;
}



char charMaisfreq (char s[]) {
    int i=0,aux=0; char r=s[0];
    while (s[i]!=0){
        if(aux<conta(s,s[i])) {r=s[i]; aux=conta(s,s[i]);i++;}
         else i++;
    }
    return r;
}
//17
int conta (char s[], char x){
    int i=0;
    while (s[i]==x)
        i++;
        return i;
    
}
int iguaisConsecutivos (char s[]) {
    int i=0, r=0;
    while (s[i]!=0 ){
        if(r<conta(s+i,s[i])) {r=conta(s+i,s[i]);i++;}
         else i++;
    }
    return r;
}
//18MAL
int conta (char s[], char x){
    int i=0;
    while (s[i+1]!=0 && s[i+1]!=x){
        i++;
        x=s[i];
    }
        return i+1;
}

int difConsecutivos(char s[]) 
{
int i=0, r=0;
    while (s[i]!=0 ){
        if(r<conta(s+i,s[i])) {r=conta(s+i,s[i]);i++;}
         else i++;
    }
    return r;
}
//19
int maiorPrefixo (char s1 [], char s2 []) {
    int i=0;
    while(s2[i]!=0 && s1[i]!=0 && s1[i]==s2[i]){
        i++;
    }
    return i;
}
//20
int maiorSufixo (char s1 [], char s2 []) {
    int i=(strlen(s1)-1), j=(strlen(s2)-1), r=0;
    while (i>-1 && j>-1 && s1[i]==s2[j]){
        i--;j--;
        r++;
    }
    return r;
}
//21 
REFAZER

//22
int contaPal (char s[]){
	int i=0, j=0;
	if (s[i]!=0 && s[i]!=' ' && s[i]!='\n') j=1;
	while (s[i]!=0){
		if (s[i]!=' ' && s[i-1]==' ' && s[i]!='\n') {j++;i++;}
		else i++;
	}
	return j;
}
//23
int contaVogais (char t[]) {
    int i=0, r=0;
    while (t[i]!=0){
        if((t[i] == 'a') || (t[i] == 'e') || (t[i] == 'i') || (t[i] == 'o') || (t[i] == 'u') ||
      (t[i] == 'A') || (t[i] == 'E') || (t[i] == 'I') || (t[i] == 'O') || (t[i] == 'U')) {r++; i++;}
      else i++;
    }
    return r;
}
//24
REVER
//25
int palindroma (char s[]) {
    int i=0, j=strlen(s)-1;
    while (s[i]!=0){
        if (s[i]!=s[j])  return 0;
            else {i++;j--;}
    }
    return 1;
}
//26
int remRep(char s[]){
    int w=i=0;
    while (s[i]!=0 && s[0]!=0){
        if(s[i]!=s[i+1]){
            s[w]=s[i];
            w++;
        }
        i++;
    }
    s[w]='\0';
    return w;
}
//27
int limpaEspacos (char t[]){
	int i=0, j=0;
	while (t[i]!=0){
		if (t[i]==' ' && t[i+1]==' ') i++;
		 else {t[j]=t[i];i++;j++;}

	}
	t[j]='\0';
	return j;
}
//28
void insere (int s[], int n, int x){
       int i=0, guarda=x;
    while(i<n){
       if (s[i]>=x) {guarda=s[i]; s[i]=x; x=guarda; i++;}
         else i++;
    }
          s[i]=x;
   }

//29
void merge (int r [], int a[], int b[], int na, int nb){
       int i=0, j=0, c=0;
       while(j!=na && i!=nb){
           if (a[j]>b[i]) {r[c]=b[i];c++;i++;}
             else {r[c]=a[j];c++;j++;}
       }
       if (j==na && i==nb) ;
       if (j==na && i!=nb) while(i!=nb){r[c]=b[i],c++;i++;}
       if (j!=na && i==nb) while(j!=na){r[c]=a[j],c++;j++;}
       
   }
//30
   int crescente (int a[], int i, int j){
       int r=0;
       for(r=0;r<i;r++) ;
       while(r<j){
           if (a[r]<=a[r+1]) r++;
            else return 0;
       }
       return 1;
   }
//31
  int retiraNeg (int v[], int N){
       int i=0, j=0, r=N;
       while (i!=N){
           if(v[i]<0) {i++;r--;}
             else {v[j]=v[i];i++;j++;}    
       }
       return r;
   }
//32
   REVER
  int conta (int s[], int x){
    int i=0;
    while (s[i]==x)
        i++;
        return i;
    }

   int menosFreq (int v[], int N){
       int c=conta(v,v[0]), i=0;
       while(i<N){
           if (c<=conta(v+i,v[i])) {i++;}
            else {c=v[i];i++;}
       }
       return c;
   }
//33 IGUAL A CIMA
//34
REVER
//35
REVER
int pertence (int v[], int x, int N){
    int i=0;
    while(i<N){
        if(x==v[i]) return 0;
         else i++;
    }
return 1;
    
}

   int elimRep (int v[], int N) {
       int i=0, j=0, r=0;
       while(i<N){
           if(pertence(v,v[i],N)) i++;
            else {v[j]=v[i];i++; j++;r++;}
       }
       return r;
   }  

//36
int elimRepOrd (int v[], int N) {
       int i =0, j=0;
       while(i!=N){
           if(v[i]==v[i+1]) i++;
           else {v[j]=v[i];i++;j++;}
       }
       if (j==0) {v[j]=v[0];j++;}
       return j;
   }
//37
   int comunsOrd (int a[], int na, int b[], int nb){
       int i=0, j=0, r=0;
       while(i!=na && j!=nb){
           if(a[i]==b[j]) {i++;j++;r++;}
            else if(a[i]<b[j]) i++;
                else j++;
       }
       return r;
   }
   
//38
   int comuns(int a[], int na, int b[], int nb) {
    int r = 0;
    int i;

    for (i = 0; i < na; i++) {  //Neste ciclo "for" verifico se uma letra da lista "a" se encontra dentro da lista "b"
   s
        if (elem(nb, a[i], b)) { //nb é a dimensao de b, e a[i] é o carater da lista "a" que quero procurar
          r++;                   //dentro da lista "b"
        }
      }
    return r;
  }


 int elem (int n, int var, int v[n]){   //funçao elem verifica se um elemento "var" se encontra dentro da lista "v"
                                        //com dimensao "n"
      int i, value=0;
      for(i=0; i<n && value == 0; i++){
          if(v[i] == var) {  //caso o elemento na posiçao i do array v seja igual ao valor "var", entao o ciclo termina
              value = 1;     //e retorna "1".
              
      } 
        }
        
  return value; //caso no ciclo "for" da funçao "elem" nao apareça nenhum elemento do array "v" igual a "var", entao 
      } 
   //39
   int minInd (int v[], int n) {
   int r=0, i=0, aux=v[0];
   while(i!=n){
       if(v[i]<aux) {aux=v[i];r=i;i++;}
        else i++;
   }
   
   return r;
}

//40
void somasAc (int v[], int Ac [], int N){
   int i=0;
   Ac[i-1]=0;
   while(i!=N){
       Ac[i]=Ac[i-1]+v[i];
       i++;
   }
}
 
//41
int triSup (int N, float m [N][N]) {
    int i=1, j=0;
    while(i<N){
        j=0;
        while(j<i){
            if(m[i][j]==0) j++;
             else return 0;
        }
        i++;
    }
    return 1;
}
//42
void transposta (int N, float m [N][N]) {
    int i=0, j=0, c=0;
    while(i<N){
        j=0;
        while(j<i){
            c=m[j][i];
            m[j][i]=m[i][j];
            m[i][j]=c;
            j++;
        }
        i++;
    }
}
//43
void addTo(int N, int M, int a [N][M], int b[N][M]) {
    int i=0, j=0;
    while (i<N){
        j=0;
        while(j<M){
            a[i][j]+=b[i][j];
            j++;
        }
        i++;
    }
}
//44
void sumDiag(int N, int m [N][N]){
    int i=0, j=0, r=0;
    while(i<N){
        j=0;
        r=0;
        while(j<N){
            r+=m[i][j];
            j++;
        }
        m[i][i]=r-m[i][i];
        i++;
    }
   }
//45
   int main(){
	char i='A';
	while (i<='z'){
		printf("%d - %c\n",i,i );
		i++;
	}
}
//46
int unionSet (int N, int v1[N], int v2[N], int r[N]){
       int c=0, i=0;
       while(c<N){
           if (v1[c]!=0 || v2[c]!=0) {r[c]=1;i++;c++;}
            else {r[c]=0;c++;}
       }
       return i;
   }
//47
   int intersectSet (int N, int v1[N], int v2[N], int r[N]){
      
       int c=0, i=0;
       while(c<N){
           if (v1[c]!=0 && v2[c]!=0) {r[c]=1;i++;c++;}
            else {r[c]=0;c++;}
       }
       return i;
   }
//48
    int intersectMSet (int N, int v1[N], int v2[N], int r[N]){
	int i=0;
	while (i<N){
		if (v1[i]!=0 && v2[i]!=0) if (v1[i]<v2[i]) {r[i]=v1[i];i++;} else {r[i]=v2[i];i++;}
		 else i++;
	}
}
 
//49
int unioMSet (int N, int v1[N], int v2[N], int r[N]){
	int i=0;
	while (i<N){
		if (v1[i]!=0 && v2[i]!=0) {r[i]=v1[i]+v2[i]; i++;}
		 else if (v1[i]!=0) {r[i]=v1[i]; i++;}
		  else {r[i]=v2[i]; i++;}
	}
}   

//50
int cardinalMSet (int N, int v[N]){
 	int i=0, r=0;
 	while (i<N){
 		r+=v[i];i++;
 	}
 	return r;
 }
 													SEGUNDAS 50 PEGUNTAS
//1
 int length (LInt l){
    int r=0;
    while(l!=NULL){
        r++;
        l=l->prox;
    }
        
    return r;
}
//2
void freeL (LInt){
	LInt aux;
	while(l!=NULL){
		aux=l;
		l=l->prox;
		free(aux);
	}
}
//3
void imprimeL (LInt){
	while(l!=NULL){
		printf("%d\n",l->valor);
		l=l->prox;
	}
}
//4 
REFAZER

//5
void insertOrd (LInt *l, int x){
    LInt ant=NULL, nova, r=*l, aux=*l;
    while (aux!=NULL && x>aux->valor){
        ant=aux;
        aux=aux->prox;
    }
    nova=malloc(sizeof(struct lligada));
    nova->valor=x;
    nova->prox=aux;
    if (ant==NULL) *l=nova;
     else ant->prox=nova;
     
}
//6
int removeOneOrd (LInt *l, int x){
    LInt r=*l, aux=*l, ant=NULL;
    while(aux!=NULL && aux->valor<x){
        ant=aux;
        aux=aux->prox;
    }
    if (aux==NULL || aux->valor >x) return 1;
    if (ant==NULL) {*l=aux->prox; free(aux);}
           else {ant->prox=aux->prox; free(aux);}
     return 0;
}
//7
REFAZER
//8
void splitMS (LInt l, int x, LInt *mx, LInt *Mx){
    while(l!=NULL){
     if(l->valor<x){
         if (*mx!=NULL) {(*mx)->prox=l;mx=&(*mx)->prox;}
          else *mx=l;
     } 
     else {
         if(*Mx==NULL) *Mx=l;
         else {(*Mx)->prox=l;Mx=&(*Mx)->prox;}
     }
     l=l->prox;
     
}
if(*mx!=NULL) (*mx)->prox=NULL;
if(*Mx!=NULL) (*Mx)->prox=NULL;
}

//9
LInt parteAmeio (LInt *l){
    LInt r=*l, y=r, ant=NULL;
    int i=0, j=length(r);
    if(r==NULL || r->prox==NULL) return NULL;
    while(i<j/2){
        i++;
        ant=r;
        r=r->prox;
    }
    *l=r;
    ant->prox=NULL;
        
    
    return y;
}
//10
int removeAll (LInt *r, int x){
    LInt l=*r, ant=NULL, aux; int i=0;
    while(l!=NULL){
        if(l->valor==x){
        if (ant!=NULL) ant->prox=l->prox;
               else *r=l->prox;
               i++; free(l);
}
        else ant=l;
        l=l->prox;
        
        
    }
    return i;
    
}
//11
int removeDups (LInt *l){
    int i=0;
    while(*l!=NULL){
        i=+removeAll(&((*l)->prox),(*l)->valor);
        l=&((*l)->prox);
    }
    return i;
}
//12
int removeMaiorL (LInt *l){
    int m;                         
    LInt aux, ant = NULL;         
    aux = *l;
    m = 0;   

    while( aux != NULL) {             
        if(aux->valor > m)
            m = aux->valor;
        aux = aux->prox;
    }

    aux = *l;  
    while(aux->valor!=m){
        ant=aux;
        aux=aux->prox;
    }
    if(ant==NULL) {free(*l);*l=aux->prox;}
     else {ant->prox=aux->prox;free(aux);}
return m;
}
//13

void init (LInt *l){
    LInt aux=*l, ant=NULL;
    while(aux->prox!=NULL){
        ant=aux;
        aux=aux->prox;
    }
    if(ant==NULL) {*l=NULL;free(aux);}
     else{ant->prox=NULL; free(aux);}
}
//14
void appendL (LInt *l, int x){
    LInt aux=*l, nova;
    nova=malloc(sizeof(struct lligada));
    nova->valor=x;
    nova->prox=NULL;
    if(aux==NULL) *l=nova;
     else{ while(aux->prox!=NULL){
        aux=aux->prox;
        }
        aux->prox=nova;
}}
//15
void concatL (LInt *a, LInt b){
    LInt l=*a;
    if (l==NULL) *a=b;
    else{
    while(l->prox!=NULL){
        l=l->prox;
    }
    l->prox=b;
}}
//16
clone que saiu no teste
//17
LInt cloneRev (LInt l){
    LInt r=NULL, aux;
    if (l==NULL)
    return NULL;
    while(l!=NULL){
    aux=malloc(sizeof(struct lligada));
    aux->valor=l->valor;
    aux->prox=r;
    r=aux;
    l=l->prox;
}
return aux;
}
//18
int maximo (LInt l){
    int i=0;
    while(l!=NULL){
        if(l->valor<i) ;
         else i=l->valor;
         l=l->prox;
    }
    return i;
}
//19
int take (int n, LInt *l){
    int i=0; LInt aux=*l, ant=NULL;
    while(aux!=NULL && i<n){
        ant=aux;
        aux=aux->prox;
        i++;
    }
    if(aux==NULL) return i;
    ant->prox=NULL;
    
    while(aux!=NULL){
        free(aux);
        aux=aux->prox;
        
    }
    return i;
}
//20
int drop (int n, LInt *r){
    LInt l=*r; int i=0;
    while(l!=NULL && i!=n){
        free(l);
        l=l->prox;
        i++;;
    }
    *r=l;
    
    return i;
}
//21
LInt NForward (LInt l, int N){
    while(N!=0){
        l=l->prox;
        N--;
    }
    return l;
}
//22
int listToArray (LInt l, int v[], int N){
    int i=0;
    while(l!=NULL && N!=0){
        v[i]=l->valor;
        l=l->prox;
        i++;
        N--;
    }
    return i;
}
//23
LInt arrayToList (int v[], int N){
    LInt l, in, nova,ant; int i=0;
    l=malloc(sizeof(struct lligada));
    in=l;
    if (N==0) return NULL;
    while(i!=N){
        nova=malloc(sizeof(struct lligada));
        l->valor=v[i];
        l->prox=nova;
        ant=l;
        l=nova;
        i++;
        
    }
    ant->prox=NULL;

    return in;
}
//24
LInt somasAcL (LInt b) {
    LInt l=b, r=malloc(sizeof(struct lligada)), a=r,nova; int i=0;
    if (l==NULL || l->prox==NULL) return l;
    while(l!=NULL){
        i+=l->valor;
        r->valor=i;
        r->prox=nova;
        r=malloc(sizeof(struct lligada));
        l=l->prox;
    }
    
    return a;
}
   
//25
void remreps (LInt l){
    LInt aux=NULL;
    while(l!=NULL){
        if(l->prox!=NULL && l->prox->valor==l->valor){
            aux=l->prox;
            l->prox=aux->prox;
            free(aux);
        }
     else   l=l->prox;
    }

}
//26
LInt rotateL (LInt l){
    LInt r=l, in; 
    if(l==NULL || l->prox==NULL) return l;
    in=l->prox;
    while(l->prox!=NULL){
        l=l->prox;
    }
    l->prox=r;
    r->prox=NULL;
    return in;
}

//27
LInt parte (LInt l){
    int x=1; LInt in,l1, l2; in=l2;
    if(l==NULL) return in1=NULL;
    while(l!=NULL){
        if(x%2==0) {l1=l; l1=l1->prox;x++;}
         else {l2=l; l2=l2->prox;x++;}
    }
    l1=NULL;
    l2=NULL;
    l=in2;
    return in1;
}
REFAZER MAL
                                           //ARVORES BiNARIAS


//28
int max(int x,int y){
    if (x<y) return y;
     else return x;
}

int altura (ABin a){
    int x=0;
    if(a==NULL) return 0;
    x=1 + max(altura(a->esq),altura(a->dir));
    
	return x;
}

//29
ABin cloneAB (ABin a) {
    ABin b;
    if(a==NULL) b=NULL;
    else {b=malloc(sizeof(struct nodo)); b->valor=a->valor; b->esq=cloneAB(a->esq); b->dir=cloneAB(a->dir);}
    return b;
    
}
//30
void mirror (ABin *r) {
    ABin a=*r, temp;
    if(a==NULL) a=NULL;
    else {mirror(&(a->esq)); mirror(&(a->dir));temp=a->esq;a->esq=a->dir;a->dir=temp;}
    
    
}
//31 32 33 listas 
REVER

//34
REVER
//35
int freeAB (ABin a) {
    if (a==NULL) return 0;
     else free(a);
    return 1+freeAB(a->esq)+freeAB(a->dir);
}
//36
REVER
//37
int iguaisAB (ABin a, ABin b) {
    if(a==NULL && b==NULL) return 1;
    if(a!=NULL && b!=NULL) return a->valor==b->valor&&iguaisAB(a->esq,b->esq)&&iguaisAB(a->dir,b->dir);
    return 0;
}
//38
REVER
//39
int nivelV (ABin a, int n, int v[]) {
    int i=0;
    if (a==NULL) return 0;
    if (n==1) {v[i]=a->valor; return 1;}
    else i=nivelV(a->esq,n-1,v);
    
    return i+nivelV(a->dir,n-1,v+i);
}
//42
int contaFolhas (ABin a) {
    int i=0;
    if(a==NULL) return 0;
    if(a->esq==NULL && a->dir==NULL) return 1;
     else i+=contaFolhas(a->esq)+contaFolhas(a->dir);
    return i;
}
//43
ABin cloneMirror (ABin a) {
    ABin b;
    if (a==NULL) return NULL;
    b=malloc(sizeof(struct nodo));
    b->valor=a->valor;
    b->esq=cloneMirror(a->dir);
    b->dir=cloneMirror(a->esq);
    return b;
}
//44
int addOrd(ABin *a, int x){
	ABin b=*a;
	while(b!=NULL && b->valor != x){
		if(b->valor > x) b=b->esq;
			else b=b->dir;
	}
	if(b==NULL){
		ABin aux = (ABin)malloc(sizeof(struct nodo));
		aux->valor = x;
		aux->esq = NULL;
		aux->dir = NULL;
		b = aux;
		return 0;
	}
	else return 1;
}
//45
int lookupAB (ABin a, int x) {
    if (a==NULL) return 0;
    if(x==a->valor) return 1;
     else if(a->valor<x) return lookupAB(a->dir,x);
         else return lookupAB(a->esq,x);
    
}
//46
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
//47
int maiorAB (ABin a) {
    
    while(a->dir!=NULL)
    a=a->dir;
    return a->valor;
}
//48
void removeMaiorA (ABin *a){
     while((*a)->dir!=NULL){
        a=&((*a)->dir);
    }
    *a=(*a)->esq;
     
}
//49
int quantosMaiores (ABin a, int x) {

    if ( a == NULL)
        return 0;
    else if ( a->valor <= x)
        return quantosMaiores(a->dir, x);
    else
        return 1 + quantosMaiores(a->dir, x) + quantosMaiores(a->esq, x);
}

//50
void listToBTree(LInt l, ABin *a){
	if(l!=NULL){
		ABin aux = (ABin)malloc(sizeof(struct nodo));
		aux->valor = l->valor;
		aux->esq = NULL; aux->dir=NULL;
		*a=aux;
		listToBTree(l->prox, &((*a)->dir));
	}
}
//51
int deProcura (ABin a) {
    if ( a == NULL) return 1;
    else {
        if(a->esq != NULL && (a->esq->valor > a->valor || a->esq->dir != NULL && a->esq->dir->valor > a->valor))
            return 0;
        if(a->dir != NULL && (a->dir->valor <= a->valor|| a->dir->esq != NULL && a->dir->esq->valor <= a->valor))
            return 0;
    }

    return deProcura(a->esq) && deProcura(a->dir);
}




 
















































