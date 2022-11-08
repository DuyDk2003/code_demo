#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define MAX 10
#define inputfile "D:/test.txt"
struct DOTHI{
	int n;
	int a[MAX][MAX];
};
int DocMaTranKe( char TenFile[100],DOTHI &g){
	FILE *f;
	f = fopen(TenFile,"rt");
	if(f == NULL){
		printf("Khong mo duoc file\n");
		return 0;
	}
	fscanf(f,"%d",&g.n);
	int i,j;
	for(i=0;i<g.n;i++){
		for(j=0;j<g.n;j++)
		{
			fscanf(f,"%d",&g.a[i][j]);
		}
	}
	fclose(f);
	printf("Da doc xong file\n");
	return 1;
}
void XuatMaTranKe(DOTHI &g){
	printf("\nSo dinh cua do thi la %d\n",g.n);
	printf("Ma tran ke cua do thi la\n");
	for(int i=0;i<g.n;i++){
		//printf("\t");
		for(int j=0;j<g.n;j++){
			printf("%4d",g.a[i][j]);
		}
		printf("\n");
	}
}
int KiemTraMaTranKeHopLe(DOTHI g){
	int i;
	for(i=0;i<g.n;i++){
		if(g.a[i][i] != 0)
			return 0;
	}
	return 1;
}
int KiemTraDoThiVoHuong(DOTHI g){
	int i,j;
	for(i=0;i<g.n;i++){
		for(j=0;j<g.n;j++){
			if(g.a[i][j] != g.a[j][i])	
				return 0;
		}
	}
	return 1;
}
void DiTimCacDinhLienThong(DOTHI g,int nhan[MAX],int i){
	for(int j=0;j<g.n;j++){
		if(g.a[i][j] != 0 && nhan[j] != nhan[i])
		{
			nhan[j] = nhan[i];
			DiTimCacDinhLienThong(g,nhan,j);
		}
	}
}
void XetLienThong(DOTHI g){
	int Nhan[MAX];
	int i;
	for(i=0;i<g.n;i++)
		Nhan[i] = 0;
	int SoThanhPhanLT = 0;
	for(i=0;i<g.n;i++)
	{
		if(Nhan[i] == 0)
		{
			SoThanhPhanLT++;
			Nhan[i] = SoThanhPhanLT;
			DiTimCacDinhLienThong(g,Nhan,i);
		}
		}	
	//	if(SoThanhPhanLT >= 1){
		printf("So thanh phan lien thong la %d\n",SoThanhPhanLT);
		for(int k = 1;k<= SoThanhPhanLT;k++)
		{
			printf("\nThanh phan lien thong thu %d gom cac dinh ",k);
			for(int j=0;j<g.n;j++)
				if(Nhan[j] == k)	printf("%3d",j);
			
		}
	
}
int main(){
	DOTHI g;
	system("cls");
	if(DocMaTranKe(inputfile,g) == 1)
	{
		printf("Da lay thong tin do thi tu file thanh cong.\n\n");
		XuatMaTranKe(g);
		printf("Bam 1 pham bat ky de tien hanh kiem tra do thi...\n\n");
		getch();
		if(KiemTraMaTranKeHopLe(g) == 1)
			printf("Do thi hop le.\n");
		else
			printf("Do thi khong hop le.\n");
		if(KiemTraDoThiVoHuong(g) == 1)
			printf("Do thi vo huong.\n");
		else
			printf("Do thi co huong.\n");	
		XetLienThong(g);
				
	}
//	getch();
	
	return 0;
	
	
}



























