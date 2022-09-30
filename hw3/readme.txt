學號:406315017
姓名:鄧智宇
環境(哪一台工作站):linux.cs.ccu.edu.tw
E-mail:fs871023@gmail.com
簡介:

main.cpp:
老師作業上的檔案，無需特別說明

Diamond.h
裡面有clas Diamond的所有function 的定義(public)，
有得到邊長、得到周長、得到面積、邊長+1、邊長-1、更改邊界符號、更改內容物符號、畫出菱形、總整理等
其中不會更改物件內容的function如GetSize(得到邊長)、Perimeter(周長)、Area(面積)、Draw(畫出)等是const

Diamond.cpp
實作標頭檔裡的funtion
在建立物件和刪除物件時，會出現提醒訊息來告訴使用者，所以會比老師指定的輸出多幾行
在建立物件或是更改物件內容時，皆會確認是否合法(邊長需介於1-39、字元需是ascII)
面積計算方式是以「兩正三角形面積*2」的方式去計算的
