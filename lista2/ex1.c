
#include <stdio.h>
void calcula(float l,float *area,float *perimetro)
{
    *area=l*l;
    *perimetro=l*4;
}
int main(int argc,char **argv)
{
    float area;
    float l;
    float perimetro;
    l=0;
    printf("informe o Lado de um quadrado: ");
    scanf("%f",&l);
    perimetro=0;
    area=0;
    
    calcula(l,&area,&perimetro);
    printf("Lado: %.2f \nPerimetro: %.2f \nArea: %.2f",l,perimetro,area);
}