#include<stdio.h>
#include<string.h>
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    char s1[405],s2[405],temp1[405],temp2[405],temp3[405],temp4[405];
    int c1[405],c2[405];
    int j,l1,l2,l,cur1,cur2,count,count1,count2,cnt,sign;
    scanf("%s %s",s1,s2)£» 
        l1=strlen(s1)-1;
        l2=strlen(s2)-1;
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        cur2=cur1=count=0;
        sign=1;
        for(j=1;j<=l1;j++){
            if(s1[j]=='.'){
                cur1=j;
                break;
            }
        }
        for(j=1;j<=l2;j++){
            if(s2[j]=='.'){
                cur2=j;
                break;
            }
        }
        if(cur1!=0){
            for(j=0;j<cur1;j++){
                temp1[j]=s1[j];
            }
        }    
        else{
            for(j=0;j<=l1;j++){
                temp1[j]=s1[j];
            }
        }
        temp1[j]='\0'; 
        if(cur2!=0){
            for(j=0;j<cur2;j++){
                temp2[j]=s2[j];
            }
        }
        else{
            for(j=0;j<=l2;j++){
                temp2[j]=s2[j];
            }
        }
        temp2[j]='\0';
        for(j=cur1+1;j<=l1;j++){
            temp3[count++]=s1[j];
        }
        temp3[count]='\0';
        count=0;
        for(j=cur2+1;j<=l2;j++){
            temp4[count++]=s2[j];
        }
        temp4[count]='\0';
        
        
        l1=strlen(temp3)-1;
        l2=strlen(temp4)-1;
        l=max(l1,l2);
        count1=count2=0;
        c1[count1]=c2[count2]=0;
        if(cur2==0&&cur1==0){
            c2[count2]=0;
            count2++;
        }
        else if(cur1==0){
            for(j=l2;j>=0;j--){
                c2[count2]+=temp4[j]-'0';
                count2++;
            }
        }
        else if(cur2==0){
            for(j=l1;j>=0;j--){
                c2[count2]+=temp3[j]-'0';
                count2++;
            }
        }
        else{
            for(j=l;j>=0;j--){
                if(l1<j)
                    c2[count2]+=temp4[j]-'0';
                else if(l2<j)
                    c2[count2]+=temp3[j]-'0';
                else
                    c2[count2]+=temp3[j]+temp4[j]-2*'0';            
                c2[count2+1]=c2[count2]/10;
                c2[count2]%=10;
                count2++;
            }
        }
        if(c2[count2]>0){
            c1[count1]=c2[count2];
        }
        count2--;
        
        l1=strlen(temp1)-1;
        l2=strlen(temp2)-1;
        for(;l1>=0||l2>=0;l1--,l2--){
            if(l1<0){
                c1[count1]+=temp2[l2]-'0';
            }
            else if(l2<0){
                c1[count1]+=temp1[l1]-'0';
            }
            else{
                c1[count1]+=temp1[l1]+temp2[l2]-2*'0';
            }
            c1[count1+1]=c1[count1]/10;
            c1[count1]%=10;
            count1++;
        }
        if(c1[count1]==0)
            count1--;
        for(j=0;j<=count2;j++){
            if(c2[j]!=0){
                break;
            }
        }
        cnt=j-1;
        if(j>count2)
            sign=0;
        for(j=count1;j>=0;j--){
                printf("%d",c1[j]);
            }
        if(sign==1){
            printf(".");
            for(j=count2;j>cnt;j--){
                printf("%d",c2[j]);
            }
        }
		printf("\n");
}
