LJMP     C:0029             //检测按键K1是否按下   
JB       k1(0x90.7),C:0015//消除抖动 一般大约10ms
MOV      R7,#0xE81000   //消除抖动 一般大约10ms 
MOV      R6,#0x031000   //消除抖动 一般大约10ms
LCALL    delay(C:0035)
JB       k1(0x90.7),C:0012  //再次判断按键是否按下
CPL      led(0xA0.0)ed=~led;         //led状态取反
JNB      k1(0x90.7),C:0012  //检测按键是否松开 》� 
JB       k2(0xB0.0),main(C:0003)
MOV      R7,#0xE81000   //消除抖动 一般大约10ms 
MOV      R6,#0x031000   //消除抖动 一般大约10ms
LCALL    delay(C:0035);   //消除抖动 一般大约10ms
JB       k2(0xB0.0),C:0024  //再次判断按键是否按下
CPL      led(0xA0.0)ed=~led;         //led状态取反
JB       k2(0xB0.0),main(C:0003)     //led状态取反
SJMP     C:0024
         
MOV      R0,#0x7F0,main(C:0003)     //led状态取反 
CLR      A		 
MOV      @R0,A	 
DJNZ     R0,C:002C,main(C:0003)     //led状态取反 		 
MOV      SP(0x81),#0x07n(C:0003)     //led状态取反 
LJMP     main(C:0003)07n(C:0003)     //led状态取反 
MOV      A,R7(C:0003)07n(C:0003)     //led状态取反 		 
DEC      R7R7(C:0003)07n(C:0003)     //led状态取反 	 
MOV      R4,0x06000307n(C:0003)     //led状态取反 	 
JNZ      C:003C6000307n(C:0003)     //led状态取反 	 
DEC      R6003C6000307n(C:0003)     //led状态取反 	 
ORL      A,R43C6000307n(C:0003)     //led状态取反 	 
JNZ      delay(C:0035)7n(C:0003)     //led状态取反 	 
RET      delay(C:0035)7n(C:0003)     //led状态取反  
		 
		 
		 
		 
END		   