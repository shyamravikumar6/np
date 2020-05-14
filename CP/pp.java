import java.util.Scanner;
import java.util.Arrays;


//import java.io.*;

class pp{
 
static Scanner sc =  new Scanner(System.in);
static void swap(int a,int b){ int k=a;a=b;b=k;}
static void test(){
     int sum1=0,sum2=0;
    int arrs,k; arrs=sc.nextInt();k=sc.nextInt();
       int[]k1= new int[k];
       int[] k2 = new int[k];
     int[] A= new int[arrs+1];
      for(int i=1;i<=arrs;++i) A[i]=sc.nextInt();
        int B[]=A.clone();

        for(int i=2;i<=arrs;++i) B[i]+=B[i-1]; 
        Arrays.sort(A);
        for(int i=0,j=arrs;i!=j;i++,j--){swap(A[i],A[j]);}
        for(int i=2;i<=arrs;++i) A[i]+=A[i-1]; int p=0;
         while(p<k){
             k1[p]=sc.nextInt();k2[p]=sc.nextInt();
             sum1+=(B[k2[p]]-B[k1[p]-1]);
             sum2+=(A[k2[p]]-A[k1[p]-1]);
             p++;

         }
         System.out.println((sum1>sum2)?(sum1-sum2):(sum2-sum1));
}

public static void main(String args[]){
     int tt;
   tt= sc.nextInt();
    for(int i=0;i<tt;++i){
        test();
    }  
}


}



// import java.util.*;
// import java.math.*;
// public class pp {
//     public static void main(String args []){
//         Scanner s = new Scanner(System.in);

//         BigInteger x,i,fac = new BigInteger("1");
//         x = s.nextBigInteger();
//          for(i=new BigInteger("1");i.compareTo(x)<=0;i=i.add(BigInteger.ONE)){fac=fac.multiply((i));  }
//         System.out.println(fac);
//         s.close();
//     }
// }

