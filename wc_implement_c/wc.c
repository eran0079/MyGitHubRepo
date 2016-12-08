#include <stdio.h>
int main(int argc,char **argv){
	FILE * fr;
	int i,words=0,chars=0,lines=0,flag=1;
	int total[3]={0,0,0};
	char cha;
	char *str;

	for(i = 1; i<argc ;i++){
        str=argv[i];
        fr = fopen (argv[i], "r");
		if(fr!=NULL){
        	rewind(fr);

       		while((cha=fgetc(fr))!=EOF){
       	    if(flag){
        	        if((cha != 10) && (cha != 32) && (cha != 9)){
           	     	words++;
           	     	flag=0;
                    }
         	   }
         	   if((cha == 10) || (cha == 32) || (cha == 9)){
           	     if(cha == 10){
           	     lines++;
            	    }
            	    flag=1;
           		 }
           	 chars++;
       	 }
       		total[0]+=lines;
       		total[1]+=words;
        	total[2]+=chars;
        	printf("%d\t%d\t%d\t%s\n",lines,words,chars,str);
			lines=0; words=0; chars=0;
		}
		else{
		printf("%s: %s: No such file or directory\n",argv[0],argv[i]);
		}
	}
	if(argc>2){
		printf("%d\t%d\t%d\ttotal\n",total[0],total[1],total[2]);
	}
	fclose(fr);
    return 0;
}

