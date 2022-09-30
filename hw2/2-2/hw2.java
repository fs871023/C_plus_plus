import java.io.*;
import java.util.*;
public class hw2 {
	public static void main( String args[]) throws IOException{
        //File file=new File("data.txt");
        //Scanner scan = new Scanner(file);//以相對路徑讀檔
        Scanner scan = new Scanner(new File("C:\\Users\\user\\Desktop\\C++\\hw2\\2-2"));//以絕對路徑讀檔
        ArrayList<Integer> al = new ArrayList<Integer>();//宣告一個存取整數的arraylist
        while (scan.hasNextInt()) {
         al.add(scan.nextInt());//將讀到的數字存入arraylist
        }
        int[] num = new int[al.size()];//把arraylist裡面的資料存到整數陣列裡面來做運算
        for (int i = 0; i < num.length; i++) {
            num[i] = al.get(i);
        }

        int max=num[0];//讓最大連續和的初始值是第一個數
        int [] start;//紀錄最大連續和的起點和終點
        start= new int[num.length];
        int [] end;
        end= new int[num.length];

		for(int i=0 ; i<num.length ; i++){//從第i個開始加到第j個
            int sum=0;//每次都讓所有總和=0
			for(int j=i ; j<num.length ; j++){
                sum=sum+num[j];//從第i個到第j個的總和
                if(sum>max){//如果總和比目前最大的還要大
                    max=sum;//取代
                    start[0]=i;//記錄起終點
                    end[0]=j;
                }
			}
        }
        
        int count_max=1;//記錄起終點的位置，同時計算有幾個最大值
		for(int i=0 ; i<num.length ; i++){//找是否有相同的最大值
            int sum=0;//每次都讓所有總和=0
			for(int j=i ; j<num.length ; j++){
                sum=sum+num[j];//從第i個到第j個的總和
                if(sum==max&&(i!=start[0]||j!=end[0])){//如果總和等於最大值
                    start[count_max]=i;//記錄起終點
                    end[count_max]=j;
                    count_max++;
                }
			}
        }        

        for(int i=0;i<count_max;i++){
            for(int j=start[i];j<=end[i];j++)//印出結果
                System.out.print(num[j]+" ");
            System.out.println();
        }
    }
}
