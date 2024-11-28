#include<stdio.h>
#include<math.h>
double arccos (double _abs,double long1,double long2);
int main()
{
    int x1,y1,z1,x2,y2,z2;
    double long1,long2,_abs,angle;
    while(scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2) != EOF)
    {
        long1 = sqrt(x1 * x1+y1 * y1+z1 * z1);
        long2 = sqrt(x2 * x2 + y2 * y2 + z2 * z2);
        _abs = abs(x1 * x2 + y1 * y2 + z1 * z2);
        if (long1 == 0 || long2 == 0)
        {
            printf("Careless little lazy otter!\n");
        }
        else
        {
            angle = arccos(_abs,long1,long2);
            printf("%.3f\n",angle);
        }
    }
}

double arccos(double _abs,double long1,double long2)
{
    double angle,cos ;
    cos = _abs/(long1*long2);
    angle = acos(cos);
    return angle;




    
}