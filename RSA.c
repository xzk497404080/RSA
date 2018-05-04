#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int data[]={1,2,3,4,6,7,8,9,12,13,14,16,17,18,19,21,23,24,26,27,28,29,39,31,32,34,36,37,38,39,41,42,43,46,47,48,49,51,52,53,54};//�������� 
	int RSA_data[sizeof(data)/sizeof(int)];//�������� 
	int Re_data[sizeof(data)/sizeof(int)];//�������� 
	int e_count[25];//����ָ���� 
	int p,q;//�û�ѡ������ 
	int n,Fn;
	int i,j,k;
	int e; 
	int d=1;
	
	printf("input p,q:");// �û�ѡ������ 
	scanf("%d,%d",&p,&q);

	n=p*q;//����ģ�� 
	Fn=(p-1)*(q-1);//����ŷ������ 
	printf("n=%d,Fn=%d\n",n,Fn);
	k=0;
	for(i=2;i<Fn;i++){//���������ָ���飬������ǰ25�� 
		if(gcd(i,Fn)==1){
			e_count[k]=i;
			k++;
			if(k>24){
				break;
			}
//			e=i;
//			k++;
//			if(k==5)
//			break;
		}
	}
	for(i=0;i<k;i++){
		printf("%d ",e_count[i]);
	}
	printf("\n");
	
	printf("chose e:");//ѡ��һ������ָ�� 
	scanf("%d",&e);

	
	while((e*d-1)%Fn!=0){//�������ָ�� 
		d++;
	}
	
	printf("e=%d\n",e);
	printf("d=%d\n",d);
	printf("RSA:");
	for(i=0;i<sizeof(data)/sizeof(int);i++){//���� 

		RSA_data[i]=RSA(data[i],e,n);
		printf("%d ",RSA_data[i]);
	}
	printf("\n");
	printf("ASR:");
	for(i=0;i<sizeof(RSA_data)/sizeof(int);i++){//���� 

		Re_data[i]=ASR(RSA_data[i],d,n);
		printf("%d ",Re_data[i]);
	}
	
	return 0;
}

int gcd(int a,int b){//�ж��Ƿ��� 
	if(b==0)
        return a;
    else 
        return gcd(b,a%b);
}//if(gcd(x,y)==1)         x,y���� 

int RSA(int X ,int e,int n)// Y=X^e mod n 
{
	int i,Y=1;
	for(i=0;i<e;i++){//ÿ���һ�α�ȡģ��ֹY��� 
		Y=(Y*X)%n;
	}
	return Y;
}
int ASR(int Y,int d,int n)//X= Y^e mod n 
{
	int i,X=1;
	for(i=0;i<d;i++)
	{
		X=(X*Y)%n;
	}
	return X;
}
