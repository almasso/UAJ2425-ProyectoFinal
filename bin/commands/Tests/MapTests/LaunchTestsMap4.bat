copy "..\..\Not executing\0Test5.edencm" "..\..\" /Y 
copy "..\..\Not executing\0Test5_2.edencm" "..\..\" /Y 
copy "..\..\Not executing\1Exit.edencm" "..\..\" /Y 

cd "..\..\.."
".\EDEN_Main.exe"

cd ".\commands\"

del ".\0Test5.edencm"
del ".\0Test5_2.edencm"
del ".\1Exit.edencm"

cd ".\Tests\MapTests\"