#include "s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {

  s21_big_decimal our_copy={0};
  big_initialization(src,&our_copy);
    
  int error = 0;
  int sign = 1;
  if(big_getBit(our_copy,223)){
    sign=0;
    big_setBit(&our_copy,223,0);
  }
     printf("\n%u\n\n", our_copy.bits[0]);
  while((our_copy.bits[0]/(int)pow(10,8))!=0&&find_out_the_degree(our_copy)!=0){
    demotion_scale(&our_copy);
  }
 

  if(our_copy.bits[2]||our_copy.bits[1]||our_copy.bits[3]||our_copy.bits[4]||our_copy.bits[5]){
    error=1;
    while(our_copy.bits[0]/pow(10,8)!=0){
      demotion_scale(&our_copy);
    }
    
  }

    if(our_copy.bits[0]%10>=5&&find_out_the_degree(our_copy)>7){
      demotion_scale(&our_copy);
      big_addition(our_copy,one_big_decimal,&our_copy);
    }
    
    else if(find_out_the_degree(our_copy)>7){
      demotion_scale(&our_copy);
    }
      
    if(find_out_the_degree(our_copy)==0){
      *dst=our_copy.bits[0];
    }
    else{
      int count=find_out_the_degree(our_copy);
      int my_res=our_copy.bits[0];
      
      while(count){
        my_res/=10;
        count--;
      }
      
      *dst+=my_res;
      // printf("\n%u\n",our_copy.bits[0]%10000);
      double tmp_res=our_copy.bits[0]%(int)pow(10,find_out_the_degree(our_copy));
      tmp_res/=pow(10,find_out_the_degree(our_copy));
      *dst+=tmp_res;
      if(!sign){
        *dst=-*dst;
      }
    }
    return error;
  
}
 