

public class BubbleSortDemo {

    public static void main(String[] args) {
        int[] arr1={36,12,25,45,65,89,87};
        BubbleSortInt.sort(arr1);
        for (int i = 0; i < arr1.length; i++) {
            System.out.println(arr1[i]);
        }
    }
    
}
class BubbleSortInt {
   public static void sort(int arr[]) {
    int Arrlength=arr.length;
    for (int i = 0; i < Arrlength-1; i++) {
        if(!bubble(arr, i)) break;
    }
   }
   static boolean bubble(int arr[],int i){
       boolean IsSwapped=false;
       int Arrlength=arr.length;
       for (int index = 0; index < Arrlength-i-1; index++) {
           if(arr[index]>arr[index+1]){
                //swap(arr[index], arr[index+1]); //not working with warpper class
               swapArr(arr, index, index+1);
               IsSwapped=true;
           }
       }
       return IsSwapped;
   }
   static void swap(Integer a1, Integer a2){
       Integer temp=a1;
       a1=a2;
       a2=temp;
   }
   static void swapArr(int[] arr,int pos1,int pos2)
   {
       int temp=arr[pos1];
       arr[pos1]=arr[pos2];
       arr[pos2]=temp;
   }
    
}