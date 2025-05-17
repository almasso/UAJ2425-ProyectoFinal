copy "..\..\Not executing\0Test2.edencm" "..\..\" /Y 
copy "..\..\Not executing\0Test2_2.edencm" "..\..\" /Y 
copy "..\..\Not executing\1Exit.edencm" "..\..\" /Y 

cd "..\..\.."
".\EDEN_Main.exe"

cd ".\commands\"

del ".\0Test2.edencm"
del ".\0Test2_2.edencm"
del ".\1Exit.edencm"

cd ".\Tests\MapTests\"
