#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)

struct stdnt{
	int stdno;
	char name[20];
	char surname[20];
	char adress[20];
	int year;
};

struct item{
	struct item *next;
	struct stdnt std; 
};

struct list{
	struct item *list;
};
//ilk düðümü oluþturan fonksiyon
struct list *Create_List(struct list *pl){
	pl = (struct list*)malloc(sizeof(struct list));
	pl->list = 0;
	return pl;
}
//listedeki elemanlarý karþýlaþtýran fonksiyon
int compare(struct stdnt std, struct list *pl){	
    struct item *prv, *pt = pl->list;
    
	if((pt)&&(pt->std.stdno==std.stdno)){
		return 1;
	}
	else if(pt==0)
	    return 0;
	while(pt){
		if(pt->std.stdno==std.stdno)
		    return 1;
		prv = pt;
		pt = pt->next;    
	}    
	    

	return 0;  
}
//listeye sýrayla eleman ekleyen fonksiyon
void insert(struct stdnt std, struct list *pl){
	struct item *temp1,*temp2, *pt = (struct item*)malloc(sizeof(struct item));
	pt->std = std;
	temp1 = pl->list;
	if(!temp1){
		pt->next = 0;
		pl->list = pt;
		printf("bolum 1");
		return;	
	}
	while(temp1){
		//
		if(std.stdno<temp1->std.stdno){
	    	if(temp1==pl->list){
				pt->next = temp1;
				pl->list = pt;
				//printf("%d\n%d\n%d\n",temp2->std.stdno, pt->std.stdno, temp1->std.stdno);
				return;
		    }
			else{
				pt->next = temp1;
				temp1 = temp1->next;
				temp2->next =pt;
				return;
			}
			
		}
		else{
			temp2 = temp1;
			temp1 = temp1->next; 
		}
		        
	}
	temp2->next = pt;
	pt->next = temp1;
	return;
}
//listedeki son elemanýn adresini döndüren fonksiyon
struct item *atEnd(struct list *pl){
	struct item *curr;
	curr = pl->list;
	while(curr->next)
		curr = curr->next;
	return curr;	
	
	
}

//listeden eleman silen fonksiyon
void removeElm(struct stdnt std, struct list *pl){
	struct item *prv, *pt = pl->list;
	if((pt)&&(pt->std.stdno==std.stdno)){
		pl->list = pt->next;
		free(pt);
		return;
	}
	for(prv=pt,pt=pt->next;((pt)&&(pt->std.stdno!=std.stdno));prv=pt,pt=pt->next);
	if(pt->std.stdno==std.stdno){
		printf("No:%d...%d",pt->std.stdno,prv->std.stdno);
		prv->next = pt->next;
		free(pt);
	}
}
//listedeki eleman sayýsýný bulan fonksiyon
int Lenght(struct list *pl){
	int i = 0;
	struct item *pt = pl->list;
	while(pt){
		i++;
		pt = pt->next;
	}
	return i;
}
//listedeki elemanlarý yazdýran fonksiyon
void display(struct list *pl){
	struct item *pt = pl->list;
	while(pt){
		printf("\nListede bulunan ogrenciler:");
		printf("\nogrenci no:%d",pt->std.stdno);
		printf("\tisim: %s",pt->std.name);
		printf("\tsoyisim: %s",pt->std.surname);
		printf("\ttarih: %d\n",pt->std.year);
	pt = pt->next;		
	}
}


int main() {
	struct list *pl;
	struct stdnt std;
	char s;
	pl = Create_List(pl);
	while(1){
		printf("Kayit: K, silme: S, Yazdirma Y\n Kayit sayisi: L, Cikis C\n");
		printf("seciminiz:");
		scanf("\n%c",&s);
		switch(s){
			case 'K': printf("Ogrenci bilgilerini giriniz:\n ogrenci no, isim, soyisim, kayit tarihi:\n ");
					  scanf("%d",&std.stdno);
					  scanf("%s",&std.name);
					  scanf("%s",&std.surname);
					  scanf("%d",&std.year);
					  if(compare(std,pl)){
					  	printf("Bu numarayla kayitli baska ogrenci var. Tekrar deneyiniz\n");
					  	break;
					  }
					  else
					  	insert(std,pl);
					  break;	
			case'Y':  display(pl);
			          break;
			
			case'S':  printf("Silinecek ogrenci no:");
			          scanf("%d",&std.stdno);		   	
				      removeElm(std,pl);
					  break;
			
			case'L':  printf("Listedeki ogrenci sayisi: %d\n",Lenght(pl));
					  break;
			
			case'C':  exit(0);	  			  				
		}
				
	}
	
	return 0;
}
