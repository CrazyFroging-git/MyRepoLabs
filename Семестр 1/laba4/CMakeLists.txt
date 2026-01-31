cmake_minimum_required(VERSION 3.15) # Проверка версии CMake.
									 # Если версия установленой программы
									 # старее указаной, произайдёт аварийный выход.

<<<<<<< HEAD
set(PROJECT_NAME laba4) 			 # задать значение PROJECT_NAME		 
=======
set(PROJECT_NAME LABA4) 			 # задать значение PROJECT_NAME		 
>>>>>>> be59f25cb587e6b78e5e8fa0812c9ba102450c22
project("${PROJECT_NAME}")           # установить имя проекта


set(CMAKE_CXX_STANDARD 20)			 # устанавливаем 17 стандарт языка

# Сказать программе, что должен быть исполняемый файл
add_executable("${PROJECT_NAME}" laba_04.cpp)