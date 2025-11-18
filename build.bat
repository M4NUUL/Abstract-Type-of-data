g++ -std=c++17 -c main.cpp array/*.cpp double_list/*.cpp linked_list/*.cpp queue/*.cpp stack/*.cpp tree/*.cpp
g++ *.o -o main.exe 
echo Файл main.exe успешно создан.
del *.o