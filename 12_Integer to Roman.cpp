Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.


void helper (char* ans, int* curp, int step, int one, int five, int ten) {
    char ch[]={'I','V','X','L','C','D','M'};
    int offset=0;
    if (step==1000) offset=6;
    else if (step==100) offset=4;
    else if (step==10) offset=2;
    else offset=0;

    if (one==-1) ans[(*curp)++] = ch[offset];
    if (ten==1)  ans[(*curp)++] = ch[offset+2];
    if (five==1) ans[(*curp)++] = ch[offset+1];
    while (one-->0) ans[(*curp)++] = ch[offset];
}

char* intToRoman(int num) {
    char *ans = malloc(sizeof(char)*16);
    int i=0, step=1000, digit=0;
    int one=0,five=0,ten=0;
    int curp=0;
    while (num>0) {
        digit=num/step;
        if (digit==9) {one=-1;five=0;ten=1;}
        else if (digit>=5) {one=digit-5;five=1;ten=0;}
        else if (digit==4) {one=-1;five=1;ten=0;}
        else if (digit==0) {one=0;five=0;ten=0;}
        else {one=digit;five=0;ten=0;}
        helper(ans,&curp,step,one,five,ten);
        num-=digit*step;
        step/=10;
    }
    ans[curp]='\0';
    return ans;
}