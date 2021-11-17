import java.util.Scanner;

public class DayOfYear {

    public static void main(String[] args) {//dumb "public static void main(String[] args)" 
        /***





        */
        int day,month,year;
        Scanner sc=new Scanner(System.in);
        System.out.print("输入年月日:");
        year=sc.nextInt();
        month=sc.nextInt();
        day=sc.nextInt();
        int sum;
        sum=DaysOfAYear.DayOfYr(year, month, day);
        System.out.print("\n");
        System.out.println("该日为"+year+"年的\n第"+sum+"天");
        sc.close();
        System.gc();//clean up
        System.exit(0);//just like "return 0" or "std::exit(0)" in c/c++
        
    }
}


class DaysOfAYear {

    //int Days[][]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
    
    private static final int DaySum[][]={{0,0,31,59,90,120,151,181,212,243,273,304,334,365},{0,0,31,60,91,121,152,182,213,244,274,305,335,366}};//invaild month, 1.0(invaild day),1.31, 2.28/29, 3.31, 4.30, 5.31, 6.30, 7.31, 8.31, 9.30, 10.31, 11.30, 12.31(unused array elements)
    public static int DayOfYr(int yr, int month, int day)
    {
        int IsLeapYear=0;//yep, boolean in java is dumb, can't cast into int(whille bool in c++, _Bool in c can cast into int) 
        if((yr%4==0&&yr%100!=0)||(yr%400==0)) IsLeapYear=1;//read comment above
        int ret_val=DaySum[IsLeapYear][month]+day;
        return ret_val;




    }



}
