#include <stdio.h>
#include <stdlib.h>

int validar(int ,int );
void ordenar(int [],int [],int);
int buscar(int [],int ,int );

int main()
{
    int p_venta[50]={11,7,10,18,20,12,9,20,12,5,18,6,12,9,11,4,8,17,17,15,2,15,6,12,5,17,7,17,18,5,7,9,16,18,9,8,9,10,16,4,7,1,20,12,12,7,9,5,17,3};
    int producto,mes,ventas,vVentas[12]={0},x,maxventas=0,maxmes=0,vVentasEnero[50]={0},maxvenE=0,maxprodE=0,i,pos=0,vprecio[50]={0},j,maxvenJ=0,maxprodJ=0,vproducto[50]={0},vVentas2[50]={0};

    printf("Ingrese numero de producto: ");
    producto=validar(0,50);
    while(producto!=0)
    {
        printf("Ingrese mes: ");
        mes=validar(1,12);
        printf("Ingrese ventas,(Por Cajones): ");
        do{
            scanf("%d",&ventas);
        }while(ventas<0);
        printf("\n");

        vVentas[mes-1]+=ventas;

        if(mes==1)
            vVentasEnero[producto-1]+=ventas;

        if(mes==7)
        {
            pos=buscar(p_venta,producto,50);
            vprecio[pos]*=ventas;
        }

        vproducto[producto-1]=producto;
        vVentas2[producto-1]+=ventas;

        printf("Ingrese numero de producto: ");
        producto=validar(0,50);
    }
    maxventas=vVentas[0];
    for(x=0;x<12;x++)
    {
        if(vVentas[x]>maxventas)
        {
            maxventas=vVentas[x];
            maxmes=x+1;
        }
    }
    printf("El mes que mas cajones se vendieron es el %d\n",maxmes);//punto 1

    maxvenE=vVentasEnero[0];
    for(i=0;i<50;i++)
    {
        if(vVentasEnero[i]>maxvenE)
        {
            maxvenE=vVentasEnero[i];
            maxprodE=i+1;
        }
    }
    printf("Del mes de enero el producto que mas vendio es: %d\n",maxprodE);//punto 2

    maxvenJ=vprecio[0];
    for(j=0;j<50;j++)
    {
        if(vprecio[j]>maxvenJ)
        {
            maxvenJ=vprecio[j];
            maxprodJ=j+1;
        }
    }
    printf("Del mes de julio el producto que mas recaudo es: %d\n",maxprodJ);//punto 3

    ordenar(vVentas2,vproducto,50);
    printf("Productos               Cajones\n");
    for(x=0;x<50;x++)
    {
        if(vVentas2[x]!=0)
            printf("%d              %d\n",vproducto[x],vVentas2[x]);//punto 4
    }

    return 0;
}
int validar(int min,int max)
{
    int dato;

    do{
        scanf("%d",&dato);
    }while(dato<min||dato>max);

    return dato;
};
int buscar(int v[],int a,int cant)
{
    int pos=-1,x=0;

    while(pos==-1&&x<cant)
    {
            if(a==v[x])
                pos=x;
            else
                x++;
    }

    return pos;
};
void ordenar(int v[],int c[],int cant)
{
    int sen=0,x,aux,aux2;

    while(sen==0)
    {
        sen=1;
        for(x=0;x<cant-1;x++)
        {
            if(v[x]<v[x+1])
            {
                aux=v[x];
                v[x]=v[x+1];
                v[x+1]=aux;

                aux2=c[x];
                c[x]=c[x+1];
                c[x+1]=aux2;

                sen=0;
            }
        }
        cant=cant-1;
    }
};
