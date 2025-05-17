copy "..\..\Not executing\0Test3.edencm" "..\..\" /Y 
copy "..\..\Not executing\0Test3_2.edencm" "..\..\" /Y 
copy "..\..\Not executing\1Exit.edencm" "..\..\" /Y 

cd "..\..\.."
".\EDEN_Main.exe"

cd ".\commands\"

del ".\0Test3.edencm"
del ".\0Test3_2.edencm"
del ".\1Exit.edencm"

cd ".\Tests\MapTests\"