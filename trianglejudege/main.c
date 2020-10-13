#include <stdio.h>
void main(){
    int p,q,r;
    scanf("%d%d%d",&p,&q,&r);
    printf("%s\n",
            (p+q>r&&q+r>p&&r+p>q?
                 (p==q||q==r||p==r?
                      (p==q&&q==r?
                          "equilateral triangle."
                          :"isoceles triangle."
                      )
                      :"triangle."
                 )
                 :"non-triangle."
            )
    );
}