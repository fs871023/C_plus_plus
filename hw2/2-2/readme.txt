學號:406315017
姓名:鄧智宇
環境(哪一台工作站):linux.cs.ccu.edu.tw
E-mail:fs871023@gmail.com
簡介:

hw2.java是最大子序列的java程式，從絕對路徑開啟，因為一開始是在windows上編譯的，所以路徑是用windows的。
方法如下：
1.宣告一個ArrayList來動態儲存檔案的數字
2.把ArrayList內的資料轉到一般陣列來做運算
3.先找出最大值，從第i個加到第j個，找到最大的區間
4.知道最大值後，再從頭找一次，看有沒有多個答案，如果有，就存到起終點的陣列裡面，最後印出來

2_3_ring.cpp ring.h
函式、class定義放在.h檔內
1.print_the_ring功能是印出整個串列
2.read_recursively先宣告一個變數來存取從檔案讀到的字元，然後看是不是換行或EOF，
如果是的話，就把現在的作為尾端，連結到第一個node，return 0
如果不是，就把字元存入linked list，然後遞迴
計算有幾個node的方式是回傳遞迴值+1，因為這樣每次遞迴回傳時都會+1(除了最後一個EOF或換行)，這樣就可以知道有幾個node了
3.在2_3_ring.cpp裡面，則包含main，main裡面會先讀檔，然後就跑read_recursively

delete_node.cpp
方法是如果現在的參考(指標)的next不是指到NULL的話，就前進一格，然後把原來的刪掉，刪完進入遞迴
最後遞迴指到NULL，代表資料都刪光了