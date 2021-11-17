
/**
 * SwapDemo
 */
public class SwapDemo {

    public static void main(String[] args) {
        int[] arr={3,4};
        //swap(arr[0], arr[1]);
        swapArr(arr, 0, 1);
        System.out.println("arr[0]="+arr[0]);
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