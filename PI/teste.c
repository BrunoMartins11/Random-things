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
printf("%d\n",j );
	return 0;
}
//3
int main()
{
	int i, soma=0, n=0;
	while (i!=0){
	scanf("%d",&i)
	soma+=i; n++;
}
i=soma/n
printf("%d\n",i );
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





//7
int qDig (int n) {
    int r = 0;
    while (n!=0){
        n=n/10; r++;
    }
    return r;

}

//9
char *mystrcat(char s1[], char s2[]) {
    int i,j; i=0, j=0;
    while(s1[i]!='\0'){
      i++;
    }
    while (s2[j]!='\0'){
      s1[i]=s2[j]; i++; j++;
    }
    s1[i]='\0';
    return s1;
}
//strstr
#include <string.h>


char *mystrstr (char s1[], char s2[]) {
    int i=0, j=0, a;
    if (s1[0]='\0') return s1
    while (s1[i]!='\0'){
        a=i;
        while (s2[j]==s1[a] && s2[j]!='\0'){
        	j++;a++;
        }
        if (s2[j]=='\0') return (s1+i);
           else i++; j=0;
       }
       return NULL;
}



// 16

int conta (char v[], char x){
	int i=0, j=0;
	while (s[i]!=0){
   	if (s[i]==x) {i++; j++;} 
   	   else i++; 
   	}
   	return j;
}




char charMaisfreq (char s[]){
   int i=0, c=0, cr=0; char r;
   while (s[i]!=0){
   	c=conta(s,s[i])
   	if (c>cr) {r=s[i]; cr=c; i++;} 
   	   else i++;

   }
   return r;
}



//17


int conta2 (v[], char x){
	int i=0, j=1;
		while (s[i]==s[i+1] && s[i+1]!=0){
   	if (s[i]==x) {i++; j++;} 
   	   else i++; 
   	}
   	return j;
}


int iguaisConsecutivos (char s[]){
   int i=0, j=0;
   while(s[i]!=0 && s[i+1]!=0){
   	if (conta2(s, s[i])>conta2(s,s[i+1])) {j=conta2(s, s[i]); i++;}
   	 else {j=conta2(s, s[i+1]); i++;}
   }
return j;
 }

// 19
int maiorPrefixo (char s1 [], char s2 []){
	int i=0;
	while (s1[i]!=0 && s2[i]!=0){
		if (s1[i]==s2[i]) i++;
		else break;
	}
	return i;
}

// 20
int maiorSufixo (char s1 [], char s2 []){
	int i, j, h; j=0;
	 i=(strlen(s2)-1);
	 h=(strlen(s1)-1);
	while (i!=0 && h!=0){
		if (s1[h]==s2[i]) {i--; h--;j++;}
		else break;
	}
	return j;
}

//21 erro
int sufPref (char s1[], char s2[]) {
    int i, j; j=(strlen(s1)-1); i=0;
    while (j>=0 && s2[i]!='\0'){
		if (s1[j]==s2[i]) {i++;j--;}
		else break;
	}
	return i;
}

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

// 23 feita na aula(facil)


//24 segmentation fault
int contida (char a[], char b[]){
	int i=0, j=0;
	while (a[0]!=b[i] && b[i]!=0 && a[0]!=0) i++;
	if (b[i]=0) return 0;
	while (a[j]!=0 && b[i]!=0){
		if (a[j]==b[i]) {j++;i++;}
		 else return 0;
	}
	if (b[i]=0 && a[j]!=0) return 0;
	 else return 1;

}

//25
 int mPalindrome(char s[]){
    int i,j;
    j=strlen(s)-1;
    for(i=0;i<j;i++,j--){
        if(s[i]!=s[j]){
            return 0;
        }
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
    return strlen(s);
}

//27

int limpaEspacos (char t[]){
	int j =i=0;
	while (t[i]!=0){
		if (t[i]==' ' && t[i+1]==' ') i++;
		 else t[j]=t[i];i++;j++;

	}
	t[j]='\0'
	return strlen(t);
}

//28

void insere (int v[], int N, int x){
	int guarda=0, i=0, l=0;
	while(i<N){
		if (v[i]>=x) {guarda = v[i]; v[i]=x; x=guarda; i++;}
		else i++;
	}
	s[i]=x;
}

//29
void merge (int r [], int a[], int b[], int na, int nb){
	int i=0, j=0, t=0;
	while (i<=(na-1) && j<=(nb-1)){
		if (a[i]<b[j]) {r[t]=a[i]; t++; i++;}
		 else {r[t]=b[j]; t++; j++;}

	}
	if (i>(na-1)) while (j<=(nb-1)){
      r[t]=b[j]; 
      t++;
      j++;
     }
     if (j>(nb-1)) while (i<=(na-1)){
      r[t]=a[i]; 
      t++;
      i++;
     }
}


//30

int crescente (int a[], int i, int j){
       if (i>j) return 0;
	while (i<j){
		if (a[i]<=a[i+1]) i++;
		 else return 0;
	}
	return 1;
}

//31 

int retiraNeg (int v[], int N){
	int i=0, g=0, j=N;
	while (i<N){
		if (v[i]<0) {i++;j--;}
		else {v[g]=v[i]; i++; g++;}
	}
	return j;
}

//32
int conta (int v[], int N) {
	int i=0;
  while (i<N){
  	if (v[i]==v[i+1])  i++;
  	 else break;
  }
  return i;
}






int menosFreq (int v[], int N) { 
	int i, r, t; t=N; i=0; r=v[i];
	while (i<N){
		if (t>conta(v+i, (N-i))) {r=v[i]; i=i+t; t=conta(v+i, (N-i));}
		 else while(v[i]==v[i+1]) i++;
		}
		return r;
	}





//34

  int maxCresc (int v[], int N){
 	int i, c, r; i=r=0; c=1;
 	while (i<N && (i+1)<=N){
 		if (v[i]<=v[i+1]) {i++; c++;}
 		 else   if (c>r) {r=c; i++; c=1;}
 		 	else {i++;c=1;}
 	
 	}
 return r;
 }

 //35 errada

 int elimRep (int v[], int n){
 int a,i; a=i=0;
	while (i<n){
		if (v[i]==v[i+1]) {a=i;
			while (a<n){
            v[a]=v[a+1]; a++;
		} i++;}
		else a++;
	}
 }


//36


int elimRepOrd (int v[], int N) {
    int r=N,i=0,j=0;
    while (i < N)
    {
        if (v[i]==v[i+1] && r !=1) {r--;i++;}
        else
        {v[j]=v[i];i++;j++;}
    }
    return r;
}

//37
int comunsOrd (int a[], int na, int b[], int nb){
	int i=0, j=0, r=0;
 while (i<na && j<nb){
 	if (a[i]==b[j]) {i++; j++; r++;}
 	  else if (a[i]>b[j]) j++;
 	            else i++;
 }

return r;
}

//38
int comuns (int a[], int na, int b[], int nb){

}


//39 
int minInd (int v[], int n){
	int i=0, r=0, int j=v[0];
	while (i<N){
          if (v[i]<j) {j=v[i]; r=i; i++;}
            else i++;
	}
	return r;
}

//40

void somasAc (int v[], int Ac [], int N){
	int i=0; soma=0;
	while (i<N){
		soma=soma+v[i];
		Ac[i]=soma;
        i++;
	}

}

//41
int triSup (int N, float m [N][N]){
	int i=1, j=N-2;
	while (i<N && j>0){
       if m[i][j]!=0
       	return 0;
       else i++; j--;
		

	}
	return 1;
}

//43
void addTo(int N, int M, int a[N][M], int b[N][M]) {
  int i;
  int j;

  for (i = 0; i < N; i++) {
    for (j = 0; j < M; j++) {
      a[i][j] = a[i][j] + b[i][j];
    }
  }
  return;
}
//44
void sumDiag(int N, int m [N][N]){
    int sum=0, i=0, j=0;
    while (i<N){
        while (j<N){
            sum+=m[i][j];
            j++;
        }
        m[i][i]=sum - m[i][i];
        i++;
       sum=0; 
       j=0;  
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
	int i=0;
	while (i<N){
		if(v1[i]>v2[i]) {r[i]=v1[i]; i++;}
		else {r[i]=v2[i]; i++;}
	}
return r;
}


//47
int intersectSet (int N, int v1[N], int v2[N], int r[N]){
	int i=0;
	while (i<N){
		if (v1[i]==v2[i]) {r[i]=v1[i]; i++;}
		 else {i++;}
	}
}

//48
int intersectMSet (int N, int v1[N], int v2[N], int r[N]){
	int i=0;
	while (i<N){
		if (v1[i]==v2[i] && v1[i]==1) {r[i]=1; i++;}
		 else {r[i]=0; i++;}
	}
}

//49

 int unionMSet (int N, int v1[N], int v2[N], int r[N]){
 	int i=0;
	while (i<N){
		if (v1[i]==1 || v2[i]==1) {r[i]=1; i++;}
		 else {r[i]=0; i++;}
	}

 }



//50
 int cardinalMSet (int N, int v[N]){
 	int i=0, r=0;
 	while (i<N){
 		r+=v[i]
 	}
 	return r;
 }















