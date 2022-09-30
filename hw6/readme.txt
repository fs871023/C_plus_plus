學號:406315017
姓名:鄧智宇
環境(哪一台工作站):linux.cs.ccu.edu.tw
E-mail:fs871023@gmail.com
簡介:
test.txt
投影片的測試資料

main.cpp:
複製PPT的程式碼，有就錯誤的地方(x1、y1誤植成x、y)進行更改。

Student.h
有四個class，其中English、History、Math都繼承Student
Student內有姓、名、和課程三個欄位，<<來印出名字，以及有參數和無參數的constructor
無參數的constructor是在實作動態陣列時須使用的，以及回傳課程名的getcourse function
另外還有兩個virtual function，分別是回傳期末成績和總平均
English、History、Math內的成員有各自的成績變數，
成員函式則都有自己的constructor和回傳期末成績和總平均的virtual function

Student.cpp
此部分的程式碼按照功能分開

constructor:無參數的Student是實作動態陣列時需宣告的，
有參數的Student則是在實作derived class的constructor時，把字串放進student member的
其他三個derived class(English,History,Math)的實作方式皆相同：參數是姓、名、課程、分數4個字串
先呼叫Student的constructor，放入姓名課程。再對分數字串做切割，把分數分別轉成整數或浮點數存入
Math的小考成績則是先把成績都存下來再做平均存入

avg()、getfinal():實作很簡單，回傳各分數的加權平均和回傳期末成績

<<:當引入Student變數時，印出學生名字。

main.cpp
grade()是把分數轉成字元用的
開始時會請使用者輸入要打開的檔案，上限是20個字元，檔案不存在會顯示錯誤訊息
然後用getline讀入測資數量，建立動態陣列
再來用for和getline把名字、課程、分數一一讀入，並傳入derived class constructor
接下來是輸入要輸出的檔案名稱，上限一樣是20字元，也會有錯誤訊息
再來使用for讀取陣列，如果課程名有對應到就印出學生資料，
	但這裡在實作時，發現沒辦法呼叫到derived class 的函式，以至於印出來的期末成績和總平均是呼叫Base class的結果
但constructor有成功建立
