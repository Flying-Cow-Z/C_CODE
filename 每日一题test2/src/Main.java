//有这样一道智力题：“某商店规定：三个空汽水瓶可以换一瓶汽水。小张手上有十个空汽水瓶，她最多可以换多少瓶汽水喝？
// ”答案是5瓶，方法如下：先用9个空瓶子换3瓶汽水，喝掉3瓶满的，喝完以后4个空瓶子，用3个再换一瓶，喝掉这瓶满的，
// 这时候剩2个空瓶子。然后你让老板先借给你一瓶汽水，喝掉这瓶满的，喝完以后用3个空瓶子换一瓶满的还给老板。
// 如果小张手上有n个空汽水瓶，最多可以换多少瓶汽水喝？
import java.util.Scanner;

public class Main {

    public static void main(String []args){
        Scanner sc = new Scanner(System.in);
        int num2 = 0;
        int count = 0;
        while(sc.hasNext()){
                num2 = sc.nextInt();
                if(num2 == 0) break;
                count++;

              while(count>0){
                bottle(num2);
                count--;
            }
        }


        sc.close();
    }

    private static void bottle(int num2) {
        int num=0,num1=0,bnum=0,bnum1=0;
        num = num2;

        bnum1 = num/3;
        num = num%3;
        bnum = bnum1 + bnum;
        num1 = num + bnum1;

        while(num1>=3){
            num = num1%3;
            bnum1 = num1/3;
            bnum = bnum1 + bnum;
            num1 = num + bnum1;
        }
        if(num1==2)
            bnum++;
        System.out.println(bnum);

    }
}
